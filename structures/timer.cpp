#include "timer.h"
#include <iostream>
#include <time.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <sys/time.h>
#include <chrono>
#endif

using namespace std;

Timer::Timer() {
  this->PCFreq = 0.0;
  this->CounterStart = 0;
}

void Timer::startCounter() {
#ifdef _WIN32
  LARGE_INTEGER li;
  if (!QueryPerformanceFrequency(&li))
    cout << "QueryPerformanceFrequency failed!\n";

  PCFreq = double(li.QuadPart) / 1000.0;

  QueryPerformanceCounter(&li);
  CounterStart = li.QuadPart;
#else
  // macOS/Linux implementation using high_resolution_clock
  auto now = chrono::high_resolution_clock::now();
  CounterStart = chrono::duration_cast<chrono::nanoseconds>(now.time_since_epoch()).count();
  PCFreq = 1000000.0; // Convert nanoseconds to milliseconds
#endif
}

double Timer::getCounter() {
#ifdef _WIN32
  LARGE_INTEGER li;
  QueryPerformanceCounter(&li);
  return double(li.QuadPart - CounterStart) / PCFreq;
#else
  auto now = chrono::high_resolution_clock::now();
  long long currentTime = chrono::duration_cast<chrono::nanoseconds>(now.time_since_epoch()).count();
  return double(currentTime - CounterStart) / PCFreq;
#endif
}
