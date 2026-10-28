cmake_minimum_required(VERSION 3.16)
project(DataStructuresPerformanceBenchmark LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(data_structures
  structures/array.cpp
  structures/bintree.cpp
  structures/linkedlist.cpp
  structures/maxheap.cpp
  structures/queue.cpp
  structures/stack.cpp
  structures/timer.cpp
)
target_include_directories(data_structures PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

if(MSVC)
  target_compile_options(data_structures PRIVATE /W4 /permissive-)
else()
  target_compile_options(data_structures PRIVATE -Wall -Wextra -Wpedantic)
endif()

add_executable(benchmark main.cpp)
target_compile_definitions(benchmark PRIVATE BENCHMARK_USE_LIBRARY)
target_link_libraries(benchmark PRIVATE data_structures)

add_executable(benchmarkRAM mainRAM.cpp memory_usage.cpp)
target_compile_definitions(benchmarkRAM PRIVATE BENCHMARK_USE_LIBRARY)
target_link_libraries(benchmarkRAM PRIVATE data_structures)
if(WIN32)
  target_link_libraries(benchmarkRAM PRIVATE Psapi)
endif()

include(CTest)
if(BUILD_TESTING)
  add_executable(structures_test tests/structures_test.cpp)
  target_link_libraries(structures_test PRIVATE data_structures)
  add_test(NAME structures COMMAND structures_test)
endif()
