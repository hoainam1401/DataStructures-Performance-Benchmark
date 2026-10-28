#pragma once

#include <cstddef>
#include <memory>
#include <optional>

class Stack {
public:
  ~Stack();
  void push(float value);
  [[nodiscard]] std::optional<float> pop() noexcept;
  [[nodiscard]] std::optional<float> peek() const noexcept;
  [[nodiscard]] std::optional<float> calculateAverage() const noexcept;
  void clear() noexcept;
  [[nodiscard]] bool isEmpty() const noexcept;
  [[nodiscard]] std::size_t size() const noexcept;

private:
  struct Node {
    float data;
    std::unique_ptr<Node> next;
  };

  std::unique_ptr<Node> root_;
  std::size_t size_ = 0;
};
