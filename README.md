# Data Structures Performance Benchmark

A C++20 benchmark comparing operation time and resident-memory usage for a dynamic array, stack, circular queue, binary search tree, doubly linked list, and max heap. The project builds on Windows, Linux, and macOS.

## Requirements

- CMake 3.16 or newer
- A C++20 compiler (MSVC, GCC, or Clang)

## Build and test

For the quickest local run, compile either entrypoint directly:

```sh
clang++ -std=c++20 main.cpp -o benchmark-local
./benchmark-local

clang++ -std=c++20 mainRAM.cpp -o benchmarkRAM-local
./benchmarkRAM-local --prefill 100000
```

Use `g++` instead of `clang++` when using GCC. The entrypoint includes its required implementations automatically; do not also list files from `structures/` in these direct commands.

For tests and normal development, use CMake:

```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --config Release
ctest --test-dir build -C Release --output-on-failure
```

With a single-config generator, executables are written to `build/`. Visual Studio places Release executables in `build/Release/`.

## Run

```sh
./build/benchmark --iterations 1000 --prefill 12
./build/benchmarkRAM --prefill 100000
```

On Windows with the Visual Studio generator, use `build\Release\benchmark.exe` and `build\Release\benchmarkRAM.exe`.

- `benchmark` reports average elapsed milliseconds. Random inputs are generated before timed regions with a fixed seed so runs are reproducible.
- `benchmarkRAM` reports the process's current resident set size. Small allocations may show a zero delta because operating systems and allocators work in pages and retain freed memory.
- Use `--help` to show supported options. The programs are non-interactive.

## Platform implementation

RAM usage uses `GetProcessMemoryInfo` on Windows, Mach `task_info` on macOS, and `/proc/self/statm` on Linux. GitHub Actions builds, tests, and smoke-runs both programs on all three platforms.

## Layout

- `structures/`: data-structure implementations and the steady-clock timer
- `main.cpp`: time benchmark runner
- `mainRAM.cpp`, `memory_usage.cpp`: resident-memory benchmark runner
- `tests/structures_test.cpp`: correctness checks for all structures
