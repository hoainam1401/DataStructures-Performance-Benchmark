#pragma once

#include <cstddef>

// Returns the process's current resident set size in bytes.
[[nodiscard]] std::size_t currentResidentMemory() noexcept;
