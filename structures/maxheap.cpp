#include "maxheap.h"
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

Heap::Heap() { this->cnt = 0; }

Heap::~Heap() { deleteHeap(); }

void Heap::swap(float *firstElement, float *secondElement) {
  float temp = *secondElement;
  *secondElement = *firstElement;
  *firstElement = temp;
}

void Heap::heapify(int index, float heapType) {
  int size = this->maxHeap.size();
  int threshold = index;
  int left = 2 * index + 1;
  int right = 2 * index + 2;

  // Max heap
  if (heapType == 0) {
    if (left < size && this->maxHeap[left] >= this->maxHeap[threshold])
      threshold = left;
    if (right < size && this->maxHeap[right] >= this->maxHeap[threshold])
      threshold = right;
  }

  if (threshold != index) {
    if (heapType == 0) {
      swap(&this->maxHeap[index], &this->maxHeap[threshold]);
    }
    heapify(threshold, heapType);
  }
}

void Heap::insertNodeMaxHeap(float data) {
  this->maxHeap.push_back(data);
  int size = this->maxHeap.size();
  for (int i = size / 2 - 1; i >= 0; i--) {
    heapify(i, 0);
  }
}

void Heap::deleteNodeMaxHeap() {
  int size = this->maxHeap.size();

  swap(&this->maxHeap[0], &this->maxHeap[size - 1]);
  this->maxHeap.pop_back();

  for (int i = size / 2 - 1; i >= 0; i--) {
    heapify(i, 0);
  }
}

float Heap::calculateAverage() {
  float sum = 0.0;
  for (int i = 0; i < this->maxHeap.size(); ++i) {
    sum += this->maxHeap[i];
  }
  return (sum / this->maxHeap.size());
}

void Heap::displayHeap() {
  for (int i = 0; i < this->maxHeap.size(); ++i)
    cout << this->maxHeap[i] << " ";
  cout << endl;
}

void Heap::deleteHeap() {
  this->maxHeap.clear();
  this->cnt = 0;
}
