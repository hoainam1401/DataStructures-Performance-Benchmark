#include <iostream>
#include <vector>
using namespace std;

class Heap {
private:
  vector<float> maxHeap;
  int cnt = 0;

public:
  Heap();
  ~Heap();

  // Calculate average of all the value of node in heap
  float calculateAverage();

  // Swap node in heap
  void swap(float *firstElement, float *secondElement);

  void heapify(int index, float heapType);

  // Add new node to heap
  void insertNodeMaxHeap(float data);

  // Remove node from heap
  void deleteNodeMaxHeap();
  void displayHeap();

  // Delete all the heap
  void deleteHeap();
};
