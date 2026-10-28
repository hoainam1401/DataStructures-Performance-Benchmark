#include "bintree.h"

BST::~BST() { clear(); }

void BST::insert(float value) {
  auto *link = &root_;
  while (*link) {
    link = value > (*link)->data ? &(*link)->right : &(*link)->left;
  }
  *link = std::make_unique<Node>(Node{value, nullptr, nullptr});
  ++size_;
}

bool BST::erase(float value) noexcept {
  if (!eraseNode(root_, value)) {
    return false;
  }
  --size_;
  return true;
}

bool BST::eraseRoot() noexcept {
  return root_ ? erase(root_->data) : false;
}

bool BST::eraseNode(std::unique_ptr<Node> &node, float value) noexcept {
  if (!node) {
    return false;
  }
  if (value < node->data) {
    return eraseNode(node->left, value);
  }
  if (value > node->data) {
    return eraseNode(node->right, value);
  }
  if (!node->left) {
    node = std::move(node->right);
  } else if (!node->right) {
    node = std::move(node->left);
  } else {
    auto *successor = &node->right;
    while ((*successor)->left) {
      successor = &(*successor)->left;
    }
    node->data = (*successor)->data;
    if ((*successor)->right) {
      *successor = std::move((*successor)->right);
    } else {
      successor->reset();
    }
  }
  return true;
}

std::optional<float> BST::calculateAverage() const noexcept {
  if (!root_) {
    return std::nullopt;
  }

  double sum = 0.0;
  std::size_t count = 0;
  const auto visit = [&sum, &count](const auto &self, const Node *node) -> void {
    if (!node) {
      return;
    }
    sum += node->data;
    ++count;
    self(self, node->left.get());
    self(self, node->right.get());
  };
  visit(visit, root_.get());
  return static_cast<float>(sum / static_cast<double>(count));
}

void BST::clear() noexcept {
  // Iterative erasure avoids recursive destruction of a badly skewed tree.
  while (root_) {
    if (root_->left) {
      auto left = std::move(root_->left);
      root_->left = std::move(left->right);
      left->right = std::move(root_);
      root_ = std::move(left);
    } else {
      root_ = std::move(root_->right);
    }
  }
  size_ = 0;
}

std::size_t BST::size() const noexcept { return size_; }
