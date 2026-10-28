#include "array.h"

#include <algorithm>

void Array::insertValue(float value) {
  auto replacement = std::make_unique<float[]>(size_ + 1);
  if (size_ > 0) {
    std::copy_n(data_.get(), size_, replacement.get());
  }
  replacement[size_] = value;
  data_ = std::move(replacement);
  ++size_;
}

std::optional<float> Array::removeFromIndex(std::size_t index) {
  if (index >= size_) {
    return std::nullopt;
  }

  const float removed = data_[index];
  auto replacement = size_ > 1 ? std::make_unique<float[]>(size_ - 1) : nullptr;
  if (size_ > 1) {
    std::copy_n(data_.get(), index, replacement.get());
    std::copy(data_.get() + index + 1, data_.get() + size_,
              replacement.get() + index);
  }
  data_ = std::move(replacement);
  --size_;
  return removed;
}

std::optional<float> Array::calculateAverage() const {
  if (size_ == 0) {
    return std::nullopt;
  }
  double sum = 0.0;
  for (std::size_t i = 0; i < size_; ++i) {
    sum += data_[i];
  }
  return static_cast<float>(sum / static_cast<double>(size_));
}

void Array::cleanArray() noexcept {
  data_.reset();
  size_ = 0;
}

std::size_t Array::getSize() const noexcept { return size_; }
