#include <iostream>
#include <time.h>

using namespace std;

class Timer {
private:
  double PCFreq;
  __int64 CounterStart;

public:
  // Constructor
  Timer();

  // Starts Counter
  void startCounter();

  // Returns time of execution
  double getCounter();
};
