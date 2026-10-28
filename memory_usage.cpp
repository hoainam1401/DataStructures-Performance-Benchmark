#include "memory_usage.h"

#if defined(_WIN32)
#define NOMINMAX
#include <windows.h>
#include <psapi.h>
#elif defined(__APPLE__)
#include <mach/mach.h>
#elif defined(__linux__)
#include <fstream>
#include <unistd.h>
#else
#error "Resident memory measurement is not implemented for this platform"
#endif

std::size_t currentResidentMemory() noexcept {
#if defined(_WIN32)
  PROCESS_MEMORY_COUNTERS counters{};
  if (!GetProcessMemoryInfo(GetCurrentProcess(), &counters,
                            sizeof(counters))) {
    return 0;
  }
  return static_cast<std::size_t>(counters.WorkingSetSize);
#elif defined(__APPLE__)
  mach_task_basic_info info{};
  mach_msg_type_number_t count = MACH_TASK_BASIC_INFO_COUNT;
  if (task_info(mach_task_self(), MACH_TASK_BASIC_INFO,
                reinterpret_cast<task_info_t>(&info), &count) != KERN_SUCCESS) {
    return 0;
  }
  return static_cast<std::size_t>(info.resident_size);
#elif defined(__linux__)
  std::ifstream statm("/proc/self/statm");
  std::size_t totalPages = 0;
  std::size_t residentPages = 0;
  if (!(statm >> totalPages >> residentPages)) {
    return 0;
  }
  const long pageSize = sysconf(_SC_PAGESIZE);
  return pageSize > 0 ? residentPages * static_cast<std::size_t>(pageSize) : 0;
#endif
}
