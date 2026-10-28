#pragma once

#include <cstddef>
#include <optional>
#include <vector>

class Heap {
public:
  void insertNodeMaxHeap(float value);
  [[nodiscard]] std::optional<float> deleteNodeMaxHeap();
  [[nodiscard]] std::optional<float> calculateAverage() const noexcept;
  void deleteHeap() noexcept;
  [[nodiscard]] std::size_t size() const noexcept;

private:
  std::vector<float> values_;
};
