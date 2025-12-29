# DataStructures Performance Benchmark

A comprehensive benchmarking suite for comparing the performance of common data structures in C++. **Now cross-platform compatible** (Windows, macOS, Linux).

## Overview

This project provides an empirical analysis of time complexity and RAM usage for common operations across six fundamental data structures:

- Array
- Stack
- Queue
- Binary Search Tree (BST)
- Linked List
- Max Heap

Each data structure is tested for various operations to help developers understand real-world performance implications beyond theoretical time complexity.

## Features

- **Cross-Platform Support**: Works on Windows, macOS, and Linux
- **Standardized Testing Framework**: All data structures are tested under identical conditions
- **Comprehensive Operation Testing**:
  - Creation of new instances
  - Deletion of prefilled instances
  - Adding elements to empty structures
  - Adding elements to prefilled structures
  - Removing elements from structures
  - Calculating averages of elements
- **Dual Benchmarking**: Measure both time complexity and RAM usage
- **Statistical Validity**: Each operation is tested multiple times (default: 1000) to ensure reliable results
- **Easy Comparison**: Results are displayed in a consistent format for simple comparison

## Build Instructions

Compile the project using g++:

### Time Benchmarks
```bash
g++ -o benchmark main.cpp structures/array.cpp structures/linkedlist.cpp structures/queue.cpp structures/timer.cpp structures/bintree.cpp structures/maxheap.cpp structures/stack.cpp
```

### RAM Usage Benchmarks
```bash
g++ -o benchmarkRAM mainRAM.cpp structures/array.cpp structures/linkedlist.cpp structures/queue.cpp structures/timer.cpp structures/bintree.cpp structures/maxheap.cpp structures/stack.cpp
```

## Usage

Run the compiled executables:

```bash
# Time benchmarks
./benchmark

# RAM usage benchmarks
./benchmarkRAM
```

The programs will run all tests and display performance metrics for each operation on each data structure.

## Test Parameters

- **Test Units**: 1000 iterations per operation (configurable)
- **Prefill Size**: 12 elements (configurable)
- **Random Values**: Float values between 0 and 100

## Interpreting Results

- **Time benchmarks**: Results are reported as average execution times in milliseconds (scaled by 100000 for precision). Lower values indicate better performance.
- **RAM benchmarks**: Results show memory usage before and after operations in bytes (B). Lower differences indicate better memory efficiency.

## Project Structure

```
├── main.cpp                 # Time performance benchmarking
├── mainRAM.cpp              # RAM usage benchmarking
├── structures/
│   ├── array.h/cpp          # Dynamic array implementation
│   ├── bintree.h/cpp        # Binary search tree implementation
│   ├── linkedlist.h/cpp     # Linked list implementation
│   ├── maxheap.h/cpp        # Max heap implementation
│   ├── queue.h/cpp          # Queue implementation
│   ├── stack.h/cpp          # Stack implementation
│   └── timer.h/cpp          # Cross-platform timer utility
├── analysis.xlsx            # Performance analysis results
└── README.md                # Project documentation
```

## Platform Compatibility

This project is designed to work across multiple platforms:

- **Windows**: Full support for both time and RAM benchmarks
- **macOS**: Full support using Mach kernel APIs for memory measurement
- **Linux**: Full support using POSIX APIs (can be extended)

The codebase uses conditional compilation (`#ifdef _WIN32`) to provide platform-specific implementations where needed.

## Contributing

Contributions are welcome! Consider adding:
- Additional data structures
- More test cases
- Visualization of results
- Performance optimization tips based on results

## Images
![Test Image1](ExampleOfTimeMeasureTest.PNG)
