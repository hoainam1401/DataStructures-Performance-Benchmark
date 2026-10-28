#include "linkedlist.h"

LinkedList::~LinkedList() { cleanList(); }

void LinkedList::insertValue(float value) {
  auto *node = new Node{value, nullptr, tail_};
  if (tail_) {
    tail_->next = node;
  } else {
    head_ = node;
  }
  tail_ = node;
  ++size_;
}

std::optional<float> LinkedList::removeFromIndex(std::size_t index) {
  if (index >= size_) {
    return std::nullopt;
  }
  if (index == 0) {
    return removeFirst();
  }
  if (index + 1 == size_) {
    return removeLast();
  }

  Node *node = head_;
  for (std::size_t i = 0; i < index; ++i) {
    node = node->next;
  }
  node->previous->next = node->next;
  node->next->previous = node->previous;
  const float value = node->data;
  delete node;
  --size_;
  return value;
}

std::optional<float> LinkedList::removeFirst() noexcept {
  if (!head_) {
    return std::nullopt;
  }
  Node *removed = head_;
  const float value = removed->data;
  head_ = removed->next;
  if (head_) {
    head_->previous = nullptr;
  } else {
    tail_ = nullptr;
  }
  delete removed;
  --size_;
  return value;
}

std::optional<float> LinkedList::removeLast() noexcept {
  if (!tail_) {
    return std::nullopt;
  }
  Node *removed = tail_;
  const float value = removed->data;
  tail_ = removed->previous;
  if (tail_) {
    tail_->next = nullptr;
  } else {
    head_ = nullptr;
  }
  delete removed;
  --size_;
  return value;
}

std::optional<float> LinkedList::calculateAverage() const noexcept {
  if (!head_) {
    return std::nullopt;
  }
  double sum = 0.0;
  for (Node *node = head_; node != nullptr; node = node->next) {
    sum += node->data;
  }
  return static_cast<float>(sum / static_cast<double>(size_));
}

void LinkedList::cleanList() noexcept {
  while (head_) {
    Node *next = head_->next;
    delete head_;
    head_ = next;
  }
  tail_ = nullptr;
  size_ = 0;
}

std::size_t LinkedList::size() const noexcept { return size_; }
