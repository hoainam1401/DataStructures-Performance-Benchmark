#include <iostream>
using namespace std;
class Queue {
private:
  int size, capacity;
  int front, back;
  float *qArray;

public:
  // Creates queue of given capacity
  Queue *createQueue(int);
  ~Queue();

  // Returns true when queue is full, else false
  bool isFull(Queue *);

  // Returns true when queue is empty, else false
  bool isEmpty(Queue *);

  // Adds new float to the back of the queue, if Queue is full it dequeues first
  // item, then adds
  void enqueue(Queue *, float);

  // Removes first element from queue returning its value. If empty returns
  // lowest temperature possible
  float dequeue(Queue *);

  // Calculates AVG of all objects inside structure
  float calculateAverage(Queue *);

  // Prints values of items stored in structure
  void printQueue(Queue *);

  // Removes all items from queue
  void cleanQueue(Queue *);
};
