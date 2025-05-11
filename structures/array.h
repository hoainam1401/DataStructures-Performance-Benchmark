
#include <iostream>
using namespace std;

class Array {
private:
  int size;
  float *Arr;

public:
  // Constructor
  Array();

  // Destructor
  ~Array();

  // Prints values of items stored in structure
  void printArray();

  // Adds new item of given value to the end of the structure
  void insertValue(float);

  // Removes Nth item from list(counting from start)
  float removeFromIndex(int);

  // Calculates AVG of all objects inside structure
  float calculateAverage();

  // Removes all items from array
  void cleanArray();

  // Returns size of array
  int getSize();
};
