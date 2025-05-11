#include "psapi.h"
#include "windows.h"
#include <conio.h>
#include <iostream>

#include "structures/array.h"
#include "structures/bintree.h"
#include "structures/linkedlist.h"
#include "structures/maxheap.h"
#include "structures/queue.h"
#include "structures/stack.h"

using namespace std;
/*
https://stackoverflow.com/questions/63166/how-to-determine-cpu-and-memory-consumption-from-inside-a-process
https://docs.microsoft.com/en-us/windows/win32/api/sysinfoapi/ns-sysinfoapi-memorystatusex
*/
// returns how many ram is currently used (B)
SIZE_T get_RAM_USAGE() {
  PROCESS_MEMORY_COUNTERS_EX pmc;
  GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS *)&pmc,
                       sizeof(pmc));
  SIZE_T virtualMemUsedByMe = pmc.PrivateUsage;
  return pmc.WorkingSetSize;
}

// conducts ram tests for stack
void stack(int howManyTestUnits, int howManyValuesToPrefill) {

  SIZE_T sumBefore = 0.0;
  SIZE_T sumAfter = 0.0;
  float randomValue;

  for (int i = 0; i < howManyTestUnits; i++) {

    sumBefore += get_RAM_USAGE();
    Stack *myStack = new Stack();
    sumAfter += get_RAM_USAGE();
    myStack->deleteStack(myStack->root);
    free(myStack);
    delete myStack;
  }
  cout << endl
       << "Average RAM usage BEFORE creating STACK: "
       << sumBefore / howManyTestUnits << " B" << endl;
  cout << endl
       << "Average RAM usage AFTER creating STACK: "
       << sumAfter / howManyTestUnits << " B" << endl;
  sumAfter = 0.0;
  sumBefore = 0.0;

  for (int i = 0; i < howManyTestUnits; i++) {

    srand(time(NULL));
    randomValue = ((100.0 - 0.0) * ((float)rand() / RAND_MAX)) + 0.0;
    Stack *myStack = new Stack();
    sumBefore += get_RAM_USAGE();

    myStack->push(&myStack->root, randomValue);
    sumAfter += get_RAM_USAGE();

    myStack->deleteStack(myStack->root);
    free(myStack);
    delete myStack;
  }
  cout << endl
       << "Average RAM usage BEFORE adding one element to STACK: "
       << sumBefore / howManyTestUnits << " B" << endl;
  cout << endl
       << "Average RAM usage AFTER adding one element to STACK: "
       << sumAfter / howManyTestUnits << " B" << endl;
  sumAfter = 0.0;
  sumBefore = 0.0;

  for (int i = 0; i < howManyTestUnits; i++) {

    randomValue = 0.0;
    srand(time(NULL));
    Stack *myStack = new Stack();
    sumBefore += get_RAM_USAGE();
    for (int j = 0; j < howManyValuesToPrefill; j++) {
      randomValue = ((100.0 - 0.0) * ((float)rand() / RAND_MAX)) + 0.0;
      myStack->push(&myStack->root, randomValue);
    }
    sumAfter += get_RAM_USAGE();

    myStack->deleteStack(myStack->root);
    free(myStack);
    delete myStack;
  }
  cout << endl
       << "Average RAM usage BEFORE filling half of STACK: "
       << sumBefore / howManyTestUnits << " B" << endl;
  cout << endl
       << "Average RAM usage AFTER filling half of STACK: "
       << sumAfter / howManyTestUnits << " B" << endl;
  sumAfter = 0.0;
  sumBefore = 0.0;
}

// conducts ram tests for bst
void bst(int howManyTestUnits, int howManyValuesToPrefill) {

  SIZE_T sumBefore = 0.0;
  SIZE_T sumAfter = 0.0;
  float randomValue;

  for (int i = 0; i < howManyTestUnits; i++) {

    sumBefore += get_RAM_USAGE();
    BST *myTree = new BST();
    NodeTree *root = myTree->getRoot();
    sumAfter += get_RAM_USAGE();
    myTree->deleteTree(myTree->getRoot());
    free(myTree);
    free(root);
    delete myTree, root;
  }
  cout << endl
       << "Average RAM usage BEFORE creating BST: "
       << sumBefore / howManyTestUnits << " B" << endl;
  cout << endl
       << "Average RAM usage AFTER creating BST: "
       << sumAfter / howManyTestUnits << " B" << endl;
  sumAfter = 0.0;
  sumBefore = 0.0;

  for (int i = 0; i < howManyTestUnits; i++) {

    srand(time(NULL));

    BST *myTree = new BST();
    NodeTree *root = myTree->getRoot();
    randomValue = ((100.0 - 0.0) * ((float)rand() / RAND_MAX)) + 0.0;
    sumBefore += get_RAM_USAGE();

    root = myTree->insertNodeTree(root, randomValue);
    sumAfter += get_RAM_USAGE();

    myTree->deleteTree(myTree->getRoot());
    free(myTree);
    free(root);
    delete myTree, root;
  }
  cout << endl
       << "Average RAM usage BEFORE adding one element to BST: "
       << sumBefore / howManyTestUnits << " B" << endl;
  cout << endl
       << "Average RAM usage AFTER adding one element to BST: "
       << sumAfter / howManyTestUnits << " B" << endl;
  sumAfter = 0.0;
  sumBefore = 0.0;

  for (int i = 0; i < howManyTestUnits; i++) {

    randomValue = 0.0;
    srand(time(NULL));
    BST *myTree = new BST();
    NodeTree *root = myTree->getRoot();
    sumBefore += get_RAM_USAGE();
    for (int j = 0; j < howManyValuesToPrefill; j++) {
      randomValue = ((100.0 - 0.0) * ((float)rand() / RAND_MAX)) + 0.0;
      root = myTree->insertNodeTree(root, randomValue);
    }
    sumAfter += get_RAM_USAGE();

    myTree->deleteTree(myTree->getRoot());
    free(myTree);
    free(root);
    delete myTree, root;
  }
  cout << endl
       << "Average RAM usage BEFORE filling half of BST: "
       << sumBefore / howManyTestUnits << " B" << endl;
  cout << endl
       << "Average RAM usage AFTER filling half of BST: "
       << sumAfter / howManyTestUnits << " B" << endl;
  sumAfter = 0.0;
  sumBefore = 0.0;
}

// conducts ram tests for linkedlist
void linkedlist(int howManyTestUnits, int howManyValuesToPrefill) {

  SIZE_T sumBefore = 0.0;
  SIZE_T sumAfter = 0.0;

  float randomValue;

  for (int i = 0; i < howManyTestUnits; i++) {

    sumBefore += get_RAM_USAGE();
    LinkedList *myList = new LinkedList();
    sumAfter += get_RAM_USAGE();

    myList->cleanList();
    free(myList);
    delete myList;
  }
  cout << endl
       << "Average RAM usage BEFORE creating LINKEDLIST: "
       << sumBefore / howManyTestUnits << " B" << endl;
  cout << endl
       << "Average RAM usage AFTER creating LINKEDLIST: "
       << sumAfter / howManyTestUnits << " B" << endl;
  sumAfter = 0.0;
  sumBefore = 0.0;

  for (int i = 0; i < howManyTestUnits; i++) {

    srand(time(NULL));
    randomValue = ((100.0 - 0.0) * ((float)rand() / RAND_MAX)) + 0.0;
    LinkedList *myList = new LinkedList();
    sumBefore += get_RAM_USAGE();

    myList->insertValue(myList->getTailPointer(), randomValue);
    sumAfter += get_RAM_USAGE();

    myList->cleanList();
    free(myList);
    delete myList;
  }
  cout << endl
       << "Average RAM usage BEFORE adding one element to LINKEDLIST: "
       << sumBefore / howManyTestUnits << " B" << endl;
  cout << endl
       << "Average RAM usage AFTER adding one element to LINKEDLIST: "
       << sumAfter / howManyTestUnits << " B" << endl;
  sumAfter = 0.0;
  sumBefore = 0.0;

  for (int i = 0; i < howManyTestUnits; i++) {

    randomValue = 0.0;
    srand(time(NULL));
    LinkedList *myList = new LinkedList();
    sumBefore += get_RAM_USAGE();
    for (int j = 0; j < howManyValuesToPrefill; j++) {
      randomValue = ((100.0 - 0.0) * ((float)rand() / RAND_MAX)) + 0.0;
      myList->insertValue(myList->getTailPointer(), randomValue);
    }
    sumAfter += get_RAM_USAGE();

    myList->cleanList();
    free(myList);
    delete myList;
  }
  cout << endl
       << "Average RAM usage BEFORE filling half of LINKEDLIST: "
       << sumBefore / howManyTestUnits << " B" << endl;
  cout << endl
       << "Average RAM usage AFTER filling half of LINKEDLIST: "
       << sumAfter / howManyTestUnits << " B" << endl;
  sumAfter = 0.0;
  sumBefore = 0.0;
}

// conducts ram tests for heap
void heap(int howManyTestUnits, int howManyValuesToPrefill) {

  SIZE_T sumBefore = 0.0;
  SIZE_T sumAfter = 0.0;

  float randomValue;

  for (int i = 0; i < howManyTestUnits; i++) {

    sumBefore += get_RAM_USAGE();
    Heap *myHeap = new Heap();
    sumAfter += get_RAM_USAGE();

    myHeap->deleteHeap();
    free(myHeap);
    delete myHeap;
  }
  cout << endl
       << "Average RAM usage BEFORE creating HEAP: "
       << sumBefore / howManyTestUnits << " B" << endl;
  cout << endl
       << "Average RAM usage AFTER creating HEAP: "
       << sumAfter / howManyTestUnits << " B" << endl;
  sumAfter = 0.0;
  sumBefore = 0.0;

  for (int i = 0; i < howManyTestUnits; i++) {

    srand(time(NULL));
    randomValue = ((100.0 - 0.0) * ((float)rand() / RAND_MAX)) + 0.0;
    Heap *myHeap = new Heap();
    sumBefore += get_RAM_USAGE();

    myHeap->insertNodeMaxHeap(randomValue);
    sumAfter += get_RAM_USAGE();

    myHeap->deleteHeap();
    free(myHeap);
    delete myHeap;
  }
  cout << endl
       << "Average RAM usage BEFORE adding one element to HEAP: "
       << sumBefore / howManyTestUnits << " B" << endl;
  cout << endl
       << "Average RAM usage AFTER adding one element to HEAP: "
       << sumAfter / howManyTestUnits << " B" << endl;
  sumAfter = 0.0;
  sumBefore = 0.0;

  for (int i = 0; i < howManyTestUnits; i++) {

    randomValue = 0.0;
    srand(time(NULL));
    Heap *myHeap = new Heap();
    sumBefore += get_RAM_USAGE();
    for (int j = 0; j < howManyValuesToPrefill; j++) {
      randomValue = ((100.0 - 0.0) * ((float)rand() / RAND_MAX)) + 0.0;
      myHeap->insertNodeMaxHeap(randomValue);
    }
    sumAfter += get_RAM_USAGE();

    myHeap->deleteHeap();
    free(myHeap);
    delete myHeap;
  }
  cout << endl
       << "Average RAM usage BEFORE filling half of HEAP: "
       << sumBefore / howManyTestUnits << " B" << endl;
  cout << endl
       << "Average RAM usage AFTER filling half of HEAP: "
       << sumAfter / howManyTestUnits << " B" << endl;
  sumAfter = 0.0;
  sumBefore = 0.0;
}

// conducts ram tests for queue
void queue(int howManyTestUnits, int howManyValuesToPrefill) {

  SIZE_T sumBefore = 0.0;
  SIZE_T sumAfter = 0.0;
  float randomValue;

  for (int i = 0; i < howManyTestUnits; i++) {

    sumBefore += get_RAM_USAGE();
    Queue *myQueue = myQueue->createQueue(24);
    sumAfter += get_RAM_USAGE();

    myQueue->cleanQueue(myQueue);
    free(myQueue);
    delete myQueue;
  }
  cout << endl
       << "Average RAM usage BEFORE creating QUEUE: "
       << sumBefore / howManyTestUnits << " B" << endl;
  cout << endl
       << "Average RAM usage AFTER creating QUEUE: "
       << sumAfter / howManyTestUnits << " B" << endl;
  sumAfter = 0.0;
  sumBefore = 0.0;

  for (int i = 0; i < howManyTestUnits; i++) {

    srand(time(NULL));
    randomValue = ((100.0 - 0.0) * ((float)rand() / RAND_MAX)) + 0.0;
    Queue *myQueue = myQueue->createQueue(24);
    sumBefore += get_RAM_USAGE();

    myQueue->enqueue(myQueue, randomValue);
    sumAfter += get_RAM_USAGE();

    myQueue->cleanQueue(myQueue);
    free(myQueue);
    delete myQueue;
  }
  cout << endl
       << "Average RAM usage BEFORE adding one element to QUEUE: "
       << sumBefore / howManyTestUnits << " B" << endl;
  cout << endl
       << "Average RAM usage AFTER adding one element to QUEUE: "
       << sumAfter / howManyTestUnits << " B" << endl;
  sumAfter = 0.0;
  sumBefore = 0.0;

  for (int i = 0; i < howManyTestUnits; i++) {

    randomValue = 0.0;
    srand(time(NULL));
    Queue *myQueue = myQueue->createQueue(24);
    sumBefore += get_RAM_USAGE();
    for (int j = 0; j < howManyValuesToPrefill; j++) {
      randomValue = ((100.0 - 0.0) * ((float)rand() / RAND_MAX)) + 0.0;
      myQueue->enqueue(myQueue, randomValue);
    }
    sumAfter += get_RAM_USAGE();

    myQueue->cleanQueue(myQueue);
    free(myQueue);
    delete myQueue;
  }
  cout << endl
       << "Average RAM usage BEFORE filling half of QUEUE: "
       << sumBefore / howManyTestUnits << " B" << endl;
  cout << endl
       << "Average RAM usage AFTER filling half of QUEUE: "
       << sumAfter / howManyTestUnits << " B" << endl;
  sumAfter = 0.0;
  sumBefore = 0.0;
}

// conducts ram tests for array
void array(int howManyTestUnits, int howManyValuesToPrefill) {

  SIZE_T sumBefore = 0.0;
  SIZE_T sumAfter = 0.0;
  float randomValue;

  for (int i = 0; i < howManyTestUnits; i++) {

    sumBefore += get_RAM_USAGE();
    Array *myTab = new Array();
    sumAfter += get_RAM_USAGE();

    myTab->cleanArray();
    free(myTab);
    delete myTab;
  }
  cout << endl
       << "Average RAM usage BEFORE creating ARRAY: "
       << sumBefore / howManyTestUnits << " B" << endl;
  cout << endl
       << "Average RAM usage AFTER creating ARRAY: "
       << sumAfter / howManyTestUnits << " B" << endl;
  sumAfter = 0.0;
  sumBefore = 0.0;

  for (int i = 0; i < howManyTestUnits; i++) {

    srand(time(NULL));
    randomValue = ((100.0 - 0.0) * ((float)rand() / RAND_MAX)) + 0.0;
    Array *myTab = new Array();
    sumBefore += get_RAM_USAGE();

    myTab->insertValue(randomValue);
    sumAfter += get_RAM_USAGE();

    myTab->cleanArray();
    free(myTab);
    delete myTab;
  }
  cout << endl
       << "Average RAM usage BEFORE adding one element to ARRAY: "
       << sumBefore / howManyTestUnits << " B" << endl;
  cout << endl
       << "Average RAM usage AFTER adding one element to ARRAY: "
       << sumAfter / howManyTestUnits << " B" << endl;
  sumAfter = 0.0;
  sumBefore = 0.0;

  for (int i = 0; i < howManyTestUnits; i++) {

    randomValue = 0.0;
    srand(time(NULL));
    Array *myTab = new Array();
    sumBefore += get_RAM_USAGE();
    for (int j = 0; j < howManyValuesToPrefill; j++) {
      randomValue = ((100.0 - 0.0) * ((float)rand() / RAND_MAX)) + 0.0;
      myTab->insertValue(randomValue);
    }
    sumAfter += get_RAM_USAGE();

    myTab->cleanArray();
    free(myTab);
    delete myTab;
  }
  cout << endl
       << "Average RAM usage BEFORE filling half of ARRAY: "
       << sumBefore / howManyTestUnits << " B" << endl;
  cout << endl
       << "Average RAM usage AFTER filling half of ARRAY: "
       << sumAfter / howManyTestUnits << " B" << endl;
  sumAfter = 0.0;
  sumBefore = 0.0;
}

int main(int argc, char *argv[]) {
  cout << "===================================================================="
          "================="
       << endl;
  cout << "*** Measure times for Queue ***" << endl;
  queue(1000, 12);

  cout << "===================================================================="
          "================="
       << endl;
  cout << "*** Measure usage for Stack ***" << endl;
  stack(1000, 12);

  cout << "===================================================================="
          "================="
       << endl;
  cout << "*** Measure times for LinkedList ***" << endl;
  linkedlist(1000, 12);

  cout << "===================================================================="
          "================="
       << endl;
  cout << "*** Measure times for Binary Tree ***" << endl;
  bst(1000, 12);

  cout << "===================================================================="
          "================="
       << endl;
  cout << "*** Measure times for Heap ***" << endl;
  heap(1000, 12);

  cout << "===================================================================="
          "================="
       << endl;
  cout << "*** Measure times for Array ***" << endl;
  array(1000, 12);
  cout << "===================================================================="
          "================="
       << endl;

  int x;
  cin >> x;

  return 0;
  // compile with: g++ -o mainRAM.exe mainRAM.cpp structures/array.cpp
  // structures/linkedlist.cpp structures/queue.cpp structures/timer.cpp
  // structures/bintree.cpp structures/maxheap.cpp structures/stack.cpp
}
