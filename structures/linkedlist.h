#pragma once

#include <cstddef>
#include <optional>

class LinkedList {
public:
  LinkedList() = default;
  ~LinkedList();
  LinkedList(const LinkedList &) = delete;
  LinkedList &operator=(const LinkedList &) = delete;

  void insertValue(float value);
  [[nodiscard]] std::optional<float> removeFromIndex(std::size_t index);
  [[nodiscard]] std::optional<float> removeFirst() noexcept;
  [[nodiscard]] std::optional<float> removeLast() noexcept;
  [[nodiscard]] std::optional<float> calculateAverage() const noexcept;
  void cleanList() noexcept;
  [[nodiscard]] std::size_t size() const noexcept;

private:
  struct Node {
    float data;
    Node *next = nullptr;
    Node *previous = nullptr;
  };

  Node *head_ = nullptr;
  Node *tail_ = nullptr;
  std::size_t size_ = 0;
};
