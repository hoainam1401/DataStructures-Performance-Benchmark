#include "maxheap.h"

#include <algorithm>
#include <functional>

void Heap::insertNodeMaxHeap(float value) {
  values_.push_back(value);
  std::push_heap(values_.begin(), values_.end());
}

std::optional<float> Heap::deleteNodeMaxHeap() {
  if (values_.empty()) {
    return std::nullopt;
  }
  std::pop_heap(values_.begin(), values_.end());
  const float value = values_.back();
  values_.pop_back();
  return value;
}

std::optional<float> Heap::calculateAverage() const noexcept {
  if (values_.empty()) {
    return std::nullopt;
  }
  double sum = 0.0;
  for (float value : values_) {
    sum += value;
  }
  return static_cast<float>(sum / static_cast<double>(values_.size()));
}

void Heap::deleteHeap() noexcept {
  values_.clear();
  values_.shrink_to_fit();
}

std::size_t Heap::size() const noexcept { return values_.size(); }
