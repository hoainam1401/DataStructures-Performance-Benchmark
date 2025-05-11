#include "queue.h"
#include <iostream>
using namespace std;

Queue *Queue::createQueue(int capacity) {
  Queue *q = new Queue();
  q->capacity = capacity;
  q->front = 0;
  q->size = 0;

  q->back = capacity - 1;
  q->qArray = new float[q->capacity];
  return q;
}

Queue::~Queue() {

  delete[] qArray;
  delete qArray;
  this->size = 0;
  this->capacity = 0;
  this->front = 0;
  this->back = 0;
}

bool Queue::isFull(Queue *q) {
  if (q->size == q->capacity) {
    return true;
  }
  return false;
}

bool Queue::isEmpty(Queue *q) {
  if (q->size == 0) {
    return true;
  }
  return false;
}

void Queue::enqueue(Queue *q, float val) {
  if (isFull(q)) {
    dequeue(q);
    return enqueue(q, val);
  }
  q->back = (q->back + 1) % q->capacity;
  q->qArray[q->back] = val;
  q->size += 1;
}

float Queue::dequeue(Queue *q) {
  if (isEmpty(q)) {
    return -273.15;
  }
  float res = q->qArray[q->front];
  q->front = (q->front + 1) % q->capacity;
  q->size -= 1;
  return res;
}

void Queue::printQueue(Queue *q) {
  if (q->front < q->back) {
    for (int i = q->front; i < q->back + 1; i++) {
      cout << q->qArray[i] << " ";
    }
  } else {
    for (int i = q->front; i < size; i++) {
      cout << q->qArray[i] << " ";
    }
    for (int i = q->back; i < q->front; i++) {
      cout << q->qArray[i] << " ";
    }
  }

  cout << endl;
}

float Queue::calculateAverage(Queue *q) {
  float sum = 0.0;
  int amount = 0;
  if (q->front < q->back) {
    for (int i = q->front; i < q->back + 1; i++) {
      sum += q->qArray[i];
      amount++;
    }
  } else {
    for (int i = q->front; i < size; i++) {
      sum += q->qArray[i];
      amount++;
    }
    for (int i = q->back; i < q->front; i++) {
      sum += q->qArray[i];
      amount++;
    }
  }

  return (sum / amount);
}

void Queue::cleanQueue(Queue *q) {
  while (q->isEmpty(q) != true) {
    q->dequeue(q);
  }
}
