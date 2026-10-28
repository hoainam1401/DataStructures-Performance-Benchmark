#include "queue.h"

#include <stdexcept>

Queue::Queue(std::size_t capacity) : data_(capacity) {
  if (capacity == 0) {
    throw std::invalid_argument("queue capacity must be greater than zero");
  }
}

bool Queue::isFull() const noexcept { return size_ == data_.size(); }

bool Queue::isEmpty() const noexcept { return size_ == 0; }

void Queue::enqueue(float value) {
  if (isFull()) {
    static_cast<void>(dequeue());
  }
  data_[(front_ + size_) % data_.size()] = value;
  ++size_;
}

std::optional<float> Queue::dequeue() noexcept {
  if (isEmpty()) {
    return std::nullopt;
  }
  const float value = data_[front_];
  front_ = (front_ + 1) % data_.size();
  --size_;
  return value;
}

std::optional<float> Queue::calculateAverage() const noexcept {
  if (isEmpty()) {
    return std::nullopt;
  }
  double sum = 0.0;
  for (std::size_t i = 0; i < size_; ++i) {
    sum += data_[(front_ + i) % data_.size()];
  }
  return static_cast<float>(sum / static_cast<double>(size_));
}

void Queue::cleanQueue() noexcept {
  front_ = 0;
  size_ = 0;
}

std::size_t Queue::size() const noexcept { return size_; }

std::size_t Queue::capacity() const noexcept { return data_.size(); }
