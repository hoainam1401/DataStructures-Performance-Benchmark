#pragma once

#include <chrono>

class Timer {
public:
  void startCounter() noexcept;
  [[nodiscard]] double getCounter() const noexcept;

private:
  std::chrono::steady_clock::time_point start_ = std::chrono::steady_clock::now();
};
