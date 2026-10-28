#include "stack.h"

Stack::~Stack() { clear(); }

void Stack::push(float value) {
  root_ = std::make_unique<Node>(Node{value, std::move(root_)});
  ++size_;
}

std::optional<float> Stack::pop() noexcept {
  if (!root_) {
    return std::nullopt;
  }
  const float value = root_->data;
  root_ = std::move(root_->next);
  --size_;
  return value;
}

std::optional<float> Stack::peek() const noexcept {
  return root_ ? std::optional<float>{root_->data} : std::nullopt;
}

std::optional<float> Stack::calculateAverage() const noexcept {
  if (!root_) {
    return std::nullopt;
  }
  double sum = 0.0;
  for (auto *node = root_.get(); node != nullptr; node = node->next.get()) {
    sum += node->data;
  }
  return static_cast<float>(sum / static_cast<double>(size_));
}

void Stack::clear() noexcept {
  while (root_) {
    root_ = std::move(root_->next);
  }
  size_ = 0;
}

bool Stack::isEmpty() const noexcept { return size_ == 0; }

std::size_t Stack::size() const noexcept { return size_; }
