#include "benchmark_options.h"
#include "memory_usage.h"
#include "structures/array.h"
#include "structures/bintree.h"
#include "structures/linkedlist.h"
#include "structures/maxheap.h"
#include "structures/queue.h"
#include "structures/stack.h"

#include <algorithm>
#include <cstddef>
#include <iomanip>
#include <iostream>
#include <memory>
#include <random>
#include <string_view>
#include <vector>

namespace {
struct MemorySamples {
  std::size_t before;
  std::size_t created;
  std::size_t oneElement;
  std::size_t filled;
};

std::ptrdiff_t difference(std::size_t after, std::size_t before) {
  return static_cast<std::ptrdiff_t>(after) -
         static_cast<std::ptrdiff_t>(before);
}

template <typename Factory, typename Insert>
MemorySamples sampleMemory(Factory factory, Insert insert,
                           const std::vector<float> &values) {
  const std::size_t before = currentResidentMemory();
  auto structure = factory();
  const std::size_t created = currentResidentMemory();
  insert(*structure, values.front());
  const std::size_t oneElement = currentResidentMemory();
  for (auto iterator = values.begin() + 1; iterator != values.end(); ++iterator) {
    insert(*structure, *iterator);
  }
  const std::size_t filled = currentResidentMemory();
  return {before, created, oneElement, filled};
}

void printSamples(std::string_view name, const MemorySamples &samples) {
  std::cout << "\n" << name << "\n"
            << "  baseline:      " << samples.before << " B\n"
            << "  after create:  " << samples.created << " B ("
            << std::showpos << difference(samples.created, samples.before)
            << std::noshowpos << ")\n"
            << "  after one:     " << samples.oneElement << " B ("
            << std::showpos << difference(samples.oneElement, samples.created)
            << std::noshowpos << ")\n"
            << "  after prefill: " << samples.filled << " B ("
            << std::showpos << difference(samples.filled, samples.created)
            << std::noshowpos << ")\n";
}
} // namespace

int main(int argc, char *argv[]) {
  try {
    BenchmarkOptions options = parseOptions(argc, argv);
    if (options.help) {
      std::cout << "Usage: benchmarkRAM [--prefill N]\n";
      return 0;
    }

    std::mt19937 engine(0xC0FFEEU);
    std::uniform_real_distribution<float> distribution(0.0F, 100.0F);
    std::vector<float> values(options.prefill);
    std::generate(values.begin(), values.end(),
                  [&] { return distribution(engine); });

    std::cout << "Current resident-memory samples; prefill=" << options.prefill
              << "\nSmall allocations may be hidden by allocator and page granularity.\n";

    printSamples("Array", sampleMemory(
                              [] { return std::make_unique<Array>(); },
                              [](Array &value, float item) {
                                value.insertValue(item);
                              },
                              values));
    printSamples("Stack", sampleMemory(
                              [] { return std::make_unique<Stack>(); },
                              [](Stack &value, float item) { value.push(item); },
                              values));
    printSamples("Queue", sampleMemory(
                              [&] {
                                return std::make_unique<Queue>(
                                    std::max<std::size_t>(24, options.prefill));
                              },
                              [](Queue &value, float item) {
                                value.enqueue(item);
                              },
                              values));
    printSamples("Binary search tree",
                 sampleMemory(
                     [] { return std::make_unique<BST>(); },
                     [](BST &value, float item) { value.insert(item); }, values));
    printSamples("Linked list",
                 sampleMemory(
                     [] { return std::make_unique<LinkedList>(); },
                     [](LinkedList &value, float item) {
                       value.insertValue(item);
                     },
                     values));
    printSamples("Max heap",
                 sampleMemory(
                     [] { return std::make_unique<Heap>(); },
                     [](Heap &value, float item) {
                       value.insertNodeMaxHeap(item);
                     },
                     values));
  } catch (const std::exception &error) {
    std::cerr << "error: " << error.what() << '\n';
    return 1;
  }
}

// Allow this entrypoint to be compiled directly without listing every source
// file. CMake defines BENCHMARK_USE_LIBRARY and links the same sources normally.
#ifndef BENCHMARK_USE_LIBRARY
#include "memory_usage.cpp"
#include "structures/array.cpp"
#include "structures/bintree.cpp"
#include "structures/linkedlist.cpp"
#include "structures/maxheap.cpp"
#include "structures/queue.cpp"
#include "structures/stack.cpp"
#include "structures/timer.cpp"
#endif
