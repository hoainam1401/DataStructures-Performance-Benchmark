#include "benchmark_options.h"
#include "structures/array.h"
#include "structures/bintree.h"
#include "structures/linkedlist.h"
#include "structures/maxheap.h"
#include "structures/queue.h"
#include "structures/stack.h"
#include "structures/timer.h"

#include <algorithm>
#include <cstddef>
#include <functional>
#include <iomanip>
#include <iostream>
#include <memory>
#include <optional>
#include <random>
#include <string_view>
#include <type_traits>
#include <utility>
#include <vector>

namespace {
volatile float resultSink = 0.0F;

template <typename Result> void consume(const Result &result) {
  if constexpr (std::is_same_v<Result, std::optional<float>>) {
    if (result) {
      resultSink = resultSink + *result;
    }
  } else if constexpr (std::is_same_v<Result, bool>) {
    resultSink = resultSink + (result ? 1.0F : 0.0F);
  }
}

template <typename Factory>
double measureCreation(std::size_t iterations, Factory factory) {
  Timer timer;
  double total = 0.0;
  for (std::size_t i = 0; i < iterations; ++i) {
    timer.startCounter();
    auto structure = factory();
    total += timer.getCounter();
    resultSink = resultSink + (structure ? 1.0F : 0.0F);
  }
  return total / static_cast<double>(iterations);
}

template <typename Factory, typename Setup, typename Operation>
double measureOperation(std::size_t iterations, Factory factory, Setup setup,
                        Operation operation) {
  Timer timer;
  double total = 0.0;
  for (std::size_t i = 0; i < iterations; ++i) {
    auto structure = factory();
    setup(*structure, i);
    timer.startCounter();
    if constexpr (std::is_void_v<decltype(std::invoke(operation, *structure,
                                                      i))>) {
      std::invoke(operation, *structure, i);
      total += timer.getCounter();
    } else {
      const auto result = std::invoke(operation, *structure, i);
      total += timer.getCounter();
      consume(result);
    }
  }
  return total / static_cast<double>(iterations);
}

template <typename Factory, typename Insert, typename Remove, typename Average,
          typename Clear>
void runSuite(std::string_view name, std::size_t iterations,
              std::size_t prefill, const std::vector<float> &values,
              Factory factory, Insert insert, Remove remove, Average average,
              Clear clear) {
  const auto emptySetup = [](auto &, std::size_t) {};
  const auto filledSetup = [&](auto &structure, std::size_t iteration) {
    const std::size_t offset = iteration * (prefill + 1);
    for (std::size_t i = 0; i < prefill; ++i) {
      insert(structure, values[offset + i]);
    }
  };
  const auto add = [&](auto &structure, std::size_t iteration) {
    insert(structure, values[iteration * (prefill + 1) + prefill]);
  };

  std::cout << "\n"
            << name << "\n"
            << "  create:          " << measureCreation(iterations, factory)
            << " ms\n"
            << "  insert empty:    "
            << measureOperation(iterations, factory, emptySetup, add) << " ms\n"
            << "  insert prefilled:" << std::setw(10)
            << measureOperation(iterations, factory, filledSetup, add)
            << " ms\n"
            << "  remove:          "
            << measureOperation(
                   iterations, factory, filledSetup,
                   [&](auto &value, std::size_t) { return remove(value); })
            << " ms\n"
            << "  average:         "
            << measureOperation(
                   iterations, factory, filledSetup,
                   [&](auto &value, std::size_t) { return average(value); })
            << " ms\n"
            << "  clear:           "
            << measureOperation(iterations, factory, filledSetup,
                                [&](auto &value, std::size_t) { clear(value); })
            << " ms\n";
}

std::vector<float> randomValues(std::size_t count) {
  std::mt19937 engine(0xC0FFEEU);
  std::uniform_real_distribution<float> distribution(0.0F, 100.0F);
  std::vector<float> values(count);
  std::generate(values.begin(), values.end(),
                [&] { return distribution(engine); });
  return values;
}
} // namespace

int main(int argc, char *argv[]) {
  try {
    const BenchmarkOptions options = parseOptions(argc, argv);
    if (options.help) {
      std::cout << "Usage: benchmark [--iterations N] [--prefill N]\n";
      return 0;
    }

    const auto values =
        randomValues(options.iterations * (options.prefill + 1));
    std::cout << std::fixed << std::setprecision(6)
              << "Average operation time over " << options.iterations
              << " iterations; prefill=" << options.prefill << "\n";

    runSuite(
        "Array", options.iterations, options.prefill, values,
        [] { return std::make_unique<Array>(); },
        [](Array &value, float item) { value.insertValue(item); },
        [](Array &value) { return value.removeFromIndex(value.getSize() / 2); },
        [](const Array &value) { return value.calculateAverage(); },
        [](Array &value) { value.cleanArray(); });

    runSuite(
        "Stack", options.iterations, options.prefill, values,
        [] { return std::make_unique<Stack>(); },
        [](Stack &value, float item) { value.push(item); },
        [](Stack &value) { return value.pop(); },
        [](const Stack &value) { return value.calculateAverage(); },
        [](Stack &value) { value.clear(); });

    runSuite(
        "Queue", options.iterations, options.prefill, values,
        [&] {
          return std::make_unique<Queue>(
              std::max<std::size_t>(24, options.prefill + 1));
        },
        [](Queue &value, float item) { value.enqueue(item); },
        [](Queue &value) { return value.dequeue(); },
        [](const Queue &value) { return value.calculateAverage(); },
        [](Queue &value) { value.cleanQueue(); });

    runSuite(
        "Binary search tree", options.iterations, options.prefill, values,
        [] { return std::make_unique<BST>(); },
        [](BST &value, float item) { value.insert(item); },
        [](BST &value) { return value.eraseRoot(); },
        [](const BST &value) { return value.calculateAverage(); },
        [](BST &value) { value.clear(); });

    runSuite(
        "Linked list", options.iterations, options.prefill, values,
        [] { return std::make_unique<LinkedList>(); },
        [](LinkedList &value, float item) { value.insertValue(item); },
        [](LinkedList &value) {
          return value.removeFromIndex(value.size() / 2);
        },
        [](const LinkedList &value) { return value.calculateAverage(); },
        [](LinkedList &value) { value.cleanList(); });

    runSuite(
        "Max heap", options.iterations, options.prefill, values,
        [] { return std::make_unique<Heap>(); },
        [](Heap &value, float item) { value.insertNodeMaxHeap(item); },
        [](Heap &value) { return value.deleteNodeMaxHeap(); },
        [](const Heap &value) { return value.calculateAverage(); },
        [](Heap &value) { value.deleteHeap(); });
  } catch (const std::exception &error) {
    std::cerr << "error: " << error.what() << '\n';
    return 1;
  }
}

// Allow this entrypoint to be compiled directly without listing every source
// file. CMake defines BENCHMARK_USE_LIBRARY and links the same sources
// normally.
#ifndef BENCHMARK_USE_LIBRARY
#include "structures/array.cpp"
#include "structures/bintree.cpp"
#include "structures/linkedlist.cpp"
#include "structures/maxheap.cpp"
#include "structures/queue.cpp"
#include "structures/stack.cpp"
#include "structures/timer.cpp"
#endif
