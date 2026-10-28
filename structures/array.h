#pragma once

#include <cstddef>
#include <memory>
#include <optional>

class Array {
public:
  Array() = default;
  Array(const Array &) = delete;
  Array &operator=(const Array &) = delete;
  Array(Array &&) noexcept = default;
  Array &operator=(Array &&) noexcept = default;

  void insertValue(float value);
  [[nodiscard]] std::optional<float> removeFromIndex(std::size_t index);
  [[nodiscard]] std::optional<float> calculateAverage() const;
  void cleanArray() noexcept;
  [[nodiscard]] std::size_t getSize() const noexcept;

private:
  std::unique_ptr<float[]> data_;
  std::size_t size_ = 0;
};
