#include "array.h"
#include <fstream>
#include <iostream>
using namespace std;

Array::Array() {
  size = 0;
  this->Arr = new float[size];
}

Array::~Array() {
  cleanArray();
  delete[] Arr;
  delete Arr;
}

void Array::insertValue(float value) {
  float *temp = new float[size + 1];
  for (int i = 0; i < size; i++) {
    temp[i] = Arr[i];
  }
  size++;
  delete[] Arr;
  Arr = temp;
  Arr[size - 1] = value;
}

float Array::removeFromIndex(int index) {

  if (index > size - 1 || index < 0) {
    return -99.99;
  }
  float *temp = new float[size - 1];
  for (int i = 0; i < index; i++) {
    temp[i] = Arr[i];
  }
  for (int i = index + 1; i < size; i++) {
    temp[i - 1] = Arr[i];
  }
  float ret = Arr[index];
  size--;
  delete[] Arr;
  Arr = temp;
  return ret;
}

float Array::calculateAverage() {
  float sum = 0.0;
  for (int i = 0; i < size; i++) {
    sum += Arr[i];
  }
  return (sum / size);
}

void Array::cleanArray() {
  float *temp = new float[0];
  delete[] Arr;
  Arr = temp;
  this->size = 0;
}

int Array::getSize() { return this->size; }

void Array::printArray() {
  for (int i = 0; i < size; i++) {
    cout << Arr[i] << " ";
  }
  cout << endl;
}
