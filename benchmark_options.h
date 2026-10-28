#pragma once

#include <charconv>
#include <cstddef>
#include <stdexcept>
#include <string>
#include <string_view>

struct BenchmarkOptions {
  std::size_t iterations = 1000;
  std::size_t prefill = 12;
  bool help = false;
};

inline std::size_t parsePositiveNumber(std::string_view text,
                                       std::string_view option) {
  std::size_t value = 0;
  const auto [end, error] =
      std::from_chars(text.data(), text.data() + text.size(), value);
  if (error != std::errc{} || end != text.data() + text.size() || value == 0) {
    throw std::invalid_argument(std::string(option) +
                                " requires a positive integer");
  }
  return value;
}

inline BenchmarkOptions parseOptions(int argc, char *argv[]) {
  BenchmarkOptions options;
  for (int i = 1; i < argc; ++i) {
    const std::string_view argument = argv[i];
    if (argument == "--help" || argument == "-h") {
      options.help = true;
    } else if (argument == "--iterations" && i + 1 < argc) {
      options.iterations = parsePositiveNumber(argv[++i], argument);
    } else if (argument == "--prefill" && i + 1 < argc) {
      options.prefill = parsePositiveNumber(argv[++i], argument);
    } else {
      throw std::invalid_argument("unknown or incomplete option: " +
                                  std::string(argument));
    }
  }
  return options;
}
