#pragma once

#include <cstddef>
#include <memory>
#include <optional>

class BST {
public:
  ~BST();
  void insert(float value);
  [[nodiscard]] bool erase(float value) noexcept;
  [[nodiscard]] bool eraseRoot() noexcept;
  [[nodiscard]] std::optional<float> calculateAverage() const noexcept;
  void clear() noexcept;
  [[nodiscard]] std::size_t size() const noexcept;

private:
  struct Node {
    float data;
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;
  };

  static bool eraseNode(std::unique_ptr<Node> &node, float value) noexcept;
  std::unique_ptr<Node> root_;
  std::size_t size_ = 0;
};
