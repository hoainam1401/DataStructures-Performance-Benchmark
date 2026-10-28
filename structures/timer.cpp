#include "timer.h"

void Timer::startCounter() noexcept { start_ = std::chrono::steady_clock::now(); }

double Timer::getCounter() const noexcept {
  const auto elapsed = std::chrono::steady_clock::now() - start_;
  return std::chrono::duration<double, std::milli>(elapsed).count();
}
