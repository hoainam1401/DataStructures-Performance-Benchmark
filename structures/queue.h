#pragma once

#include <cstddef>
#include <optional>
#include <vector>

class Queue {
public:
  explicit Queue(std::size_t capacity = 24);

  [[nodiscard]] bool isFull() const noexcept;
  [[nodiscard]] bool isEmpty() const noexcept;
  void enqueue(float value);
  [[nodiscard]] std::optional<float> dequeue() noexcept;
  [[nodiscard]] std::optional<float> calculateAverage() const noexcept;
  void cleanQueue() noexcept;
  [[nodiscard]] std::size_t size() const noexcept;
  [[nodiscard]] std::size_t capacity() const noexcept;

private:
  std::vector<float> data_;
  std::size_t front_ = 0;
  std::size_t size_ = 0;
};
