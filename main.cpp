#include "structures/array.h"
#include "structures/bintree.h"
#include "structures/linkedlist.h"
#include "structures/maxheap.h"
#include "structures/queue.h"
#include "structures/stack.h"
#include "structures/timer.h"
#include <iostream>

using namespace std;

// conducts time tests for stack
void stack(int howManyTestUnits, int howManyValuesToPrefill) {
  Timer timer;
  double sumValue = 0.0;
  float randomValue;

  for (int i = 0; i < howManyTestUnits; i++) {

    timer.startCounter();
    Stack *myStack = new Stack();
    sumValue += (timer.getCounter()) * 100000;

    myStack->deleteStack(myStack->root);
    free(myStack);
  }
  cout << endl
       << "Average time of creating new stack instance: "
       << sumValue / howManyTestUnits << "ms /100000" << endl;
  sumValue = 0.0;

  for (int i = 0; i < howManyTestUnits; i++) {

    Stack *myStack = new Stack();
    randomValue = 0.0;
    srand(time(NULL));
    for (int j = 0; j < howManyValuesToPrefill; j++) {
      randomValue = ((100.0 - 0.0) * ((float)rand() / RAND_MAX)) + 0.0;
      myStack->push(&myStack->root, randomValue);
    }

    timer.startCounter();
    myStack->deleteStack(myStack->root);
    free(myStack);

    sumValue += (timer.getCounter()) * 100000;
  }
  cout << endl
       << "Average time of deleting prefilled stack instance: "
       << sumValue / howManyTestUnits << "ms /100000" << endl;
  sumValue = 0.0;

  for (int i = 0; i < howManyTestUnits; i++) {
    Stack *myStack = new Stack();

    srand(time(NULL));
    randomValue = ((100.0 - 0.0) * ((float)rand() / RAND_MAX)) + 0.0;
    timer.startCounter();
    myStack->push(&myStack->root, randomValue);
    sumValue += (timer.getCounter()) * 100000;

    myStack->deleteStack(myStack->root);
    free(myStack);
  }
  cout << endl
       << "Average time of adding random value to empty stack is: "
       << sumValue / howManyTestUnits << "ms /100000" << endl;

  sumValue = 0.0;
  for (int i = 0; i < howManyTestUnits; i++) {
    Stack *myStack = new Stack();
    randomValue = 0.0;
    srand(time(NULL));
    for (int j = 0; j < howManyValuesToPrefill; j++) {
      randomValue = ((100.0 - 0.0) * ((float)rand() / RAND_MAX)) + 0.0;
      myStack->push(&myStack->root, randomValue);
    }

    randomValue = ((100.0 - 0.0) * ((float)rand() / RAND_MAX)) + 0.0;
    timer.startCounter();
    myStack->push(&myStack->root, randomValue);
    sumValue += (timer.getCounter()) * 100000;

    myStack->deleteStack(myStack->root);
    free(myStack);
  }
  cout << endl
       << "Average time of adding random value to prefilled stack is: "
       << sumValue / howManyTestUnits << "ms /100000" << endl;

  sumValue = 0.0;

  for (int i = 0; i < howManyTestUnits; i++) {
    Stack *myStack = new Stack();
    randomValue = 0.0;
    srand(time(NULL));
    for (int j = 0; j < howManyValuesToPrefill; j++) {
      randomValue = ((100.0 - 0.0) * ((float)rand() / RAND_MAX)) + 0.0;
      myStack->push(&myStack->root, randomValue);
    }

    randomValue = ((100.0 - 0.0) * ((float)rand() / RAND_MAX)) + 0.0;
    timer.startCounter();
    myStack->pop(&myStack->root);
    sumValue += (timer.getCounter()) * 100000;

    myStack->deleteStack(myStack->root);
    free(myStack);
  }
  cout << endl
       << "Average time of deleting value from prefilled stack is: "
       << sumValue / howManyTestUnits << "ms /100000" << endl;
  sumValue = 0.0;
  for (int i = 0; i < howManyTestUnits; i++) {
    Stack *myStack = new Stack();
    randomValue = 0.0;
    srand(time(NULL));
    for (int j = 0; j < howManyValuesToPrefill; j++) {
      randomValue = ((100.0 - 0.0) * ((float)rand() / RAND_MAX)) + 0.0;
      myStack->push(&myStack->root, randomValue);
    }

    randomValue = ((100.0 - 0.0) * ((float)rand() / RAND_MAX)) + 0.0;
    timer.startCounter();
    myStack->calculateAverage(myStack->root);
    sumValue += (timer.getCounter()) * 100000;

    myStack->deleteStack(myStack->root);
    free(myStack);
  }
  cout << endl
       << "Average time of calculating average of random value of prefilled "
          "stack is: "
       << sumValue / howManyTestUnits << "ms /100000" << endl;
}

// conducts time tests for bst
void bst(int howManyTestUnits, int howManyValuesToPrefill) {
  Timer timer;
  double sumValue = 0.0;
  float randomValue;

  for (int i = 0; i < howManyTestUnits; i++) {

    timer.startCounter();
    BST *myTree = new BST();
    NodeTree *root = myTree->getRoot();
    sumValue += (timer.getCounter()) * 100000;

    myTree->deleteTree(myTree->getRoot());
    free(myTree);
    free(root);
  }
  cout << endl
       << "Average time of creating new bst instance: "
       << sumValue / howManyTestUnits << "ms /100000" << endl;
  sumValue = 0.0;

  for (int i = 0; i < howManyTestUnits; i++) {

    BST *myTree = new BST();
    NodeTree *root = myTree->getRoot();
    randomValue = 0.0;
    srand(time(NULL));
    for (int j = 0; j < howManyValuesToPrefill; j++) {
      randomValue = ((100.0 - 0.0) * ((float)rand() / RAND_MAX)) + 0.0;
      root = myTree->insertNodeTree(root, randomValue);
    }

    timer.startCounter();
    myTree->deleteTree(myTree->getRoot());
    free(myTree);
    free(root);

    sumValue += (timer.getCounter()) * 100000;
  }
  cout << endl
       << "Average time of deleting prefilled bst instance: "
       << sumValue / howManyTestUnits << "ms /100000" << endl;
  sumValue = 0.0;

  for (int i = 0; i < howManyTestUnits; i++) {
    BST *myTree = new BST();
    NodeTree *root = myTree->getRoot();
    srand(time(NULL));
    randomValue = ((100.0 - 0.0) * ((float)rand() / RAND_MAX)) + 0.0;
    timer.startCounter();
    root = myTree->insertNodeTree(root, randomValue);
    sumValue += (timer.getCounter()) * 100000;

    myTree->deleteTree(myTree->getRoot());
    free(myTree);
    free(root);
  }
  cout << endl
       << "Average time of adding random value to empty BST is: "
       << sumValue / howManyTestUnits << "ms /100000" << endl;
  sumValue = 0.0;

  for (int i = 0; i < howManyTestUnits; i++) {
    BST *myTree = new BST();
    NodeTree *root = myTree->getRoot();
    randomValue = 0.0;
    srand(time(NULL));
    for (int j = 0; j < howManyValuesToPrefill; j++) {
      randomValue = ((100.0 - 0.0) * ((float)rand() / RAND_MAX)) + 0.0;
      root = myTree->insertNodeTree(root, randomValue);
    }
    randomValue = ((100.0 - 0.0) * ((float)rand() / RAND_MAX)) + 0.0;
    timer.startCounter();
    root = myTree->insertNodeTree(root, randomValue);
    sumValue += (timer.getCounter()) * 100000;
    myTree->deleteTree(myTree->getRoot());
    free(myTree);
    free(root);
  }
  cout << endl
       << "Average time of adding random value to prefilled BST is: "
       << sumValue / howManyTestUnits << "ms /100000" << endl;
  sumValue = 0.0;
  for (int i = 0; i < howManyTestUnits; i++) {
    BST *myTree = new BST();
    NodeTree *root = myTree->getRoot();
    randomValue = 0.0;
    srand(time(NULL));
    for (int j = 0; j < howManyValuesToPrefill; j++) {
      randomValue = ((100.0 - 0.0) * ((float)rand() / RAND_MAX)) + 0.0;
      root = myTree->insertNodeTree(root, randomValue);
    }

    timer.startCounter();
    root = myTree->deleteNodeTree(root, root->data);
    sumValue += (timer.getCounter()) * 100000;

    myTree->deleteTree(myTree->getRoot());
    free(myTree);
    free(root);
  }
  cout << endl
       << "Average time of deleting root from prefilled BST is: "
       << sumValue / howManyTestUnits << "ms /100000" << endl;
  sumValue = 0.0;

  for (int i = 0; i < howManyTestUnits; i++) {
    BST *myTree = new BST();
    NodeTree *root = myTree->getRoot();
    randomValue = 0.0;
    srand(time(NULL));
    for (int j = 0; j < howManyValuesToPrefill; j++) {
      randomValue = ((100.0 - 0.0) * ((float)rand() / RAND_MAX)) + 0.0;
      root = myTree->insertNodeTree(root, randomValue);
    }
    randomValue = ((100.0 - 0.0) * ((float)rand() / RAND_MAX)) + 0.0;
    timer.startCounter();
    myTree->calculateAverage(root);
    sumValue += (timer.getCounter()) * 100000;
    myTree->deleteTree(myTree->getRoot());
    free(myTree);
    free(root);
  }
  cout << endl
       << "Average time of calculating average of random value to prefilled "
          "BST is: "
       << sumValue / howManyTestUnits << "ms /100000" << endl;
}

// conducts time tests for linkedlist
void linkedlist(int howManyTestUnits, int howManyValuesToPrefill) {
  Timer timer;
  double sumValue = 0.0;
  float randomValue;

  for (int i = 0; i < howManyTestUnits; i++) {

    timer.startCounter();
    LinkedList *myList = new LinkedList();
    sumValue += (timer.getCounter()) * 100000;

    myList->cleanList();
    free(myList);
  }
  cout << endl
       << "Average time of creating new list instance: "
       << sumValue / howManyTestUnits << "ms /100000" << endl;
  sumValue = 0.0;

  for (int i = 0; i < howManyTestUnits; i++) {

    LinkedList *myList = new LinkedList();
    randomValue = 0.0;
    srand(time(NULL));
    for (int j = 0; j < howManyValuesToPrefill; j++) {
      randomValue = ((100.0 - 0.0) * ((float)rand() / RAND_MAX)) + 0.0;
      myList->insertValue(myList->getTailPointer(), randomValue);
    }

    timer.startCounter();
    myList->cleanList();
    free(myList);

    sumValue += (timer.getCounter()) * 100000;
  }
  cout << endl
       << "Average time of deleting prefilled list instance: "
       << sumValue / howManyTestUnits << "ms /100000" << endl;
  sumValue = 0.0;

  for (int i = 0; i < howManyTestUnits; i++) {
    LinkedList *myList = new LinkedList();

    srand(time(NULL));
    randomValue = ((100.0 - 0.0) * ((float)rand() / RAND_MAX)) + 0.0;
    timer.startCounter();
    myList->insertValue(myList->getTailPointer(), randomValue);
    sumValue += (timer.getCounter()) * 100000;

    myList->cleanList();
    free(myList);
  }
  cout << endl
       << "Average time of adding random value to empty linkedlist is: "
       << sumValue / howManyTestUnits << "ms /100000" << endl;
  sumValue = 0.0;
  for (int i = 0; i < howManyTestUnits; i++) {
    LinkedList *myList = new LinkedList();
    randomValue = 0.0;
    srand(time(NULL));
    for (int j = 0; j < howManyValuesToPrefill; j++) {
      randomValue = ((100.0 - 0.0) * ((float)rand() / RAND_MAX)) + 0.0;
      myList->insertValue(myList->getTailPointer(), randomValue);
    }
    randomValue = ((100.0 - 0.0) * ((float)rand() / RAND_MAX)) + 0.0;
    timer.startCounter();
    myList->insertValue(myList->getTailPointer(), randomValue);
    sumValue += (timer.getCounter()) * 100000;

    myList->cleanList();
    free(myList);
  }
  cout << endl
       << "Average time of adding random value to prefilled linkedlist is: "
       << sumValue / howManyTestUnits << "ms /100000" << endl;
  sumValue = 0.0;
  for (int i = 0; i < howManyTestUnits; i++) {
    LinkedList *myList = new LinkedList();
    randomValue = 0.0;
    srand(time(NULL));
    for (int j = 0; j < howManyValuesToPrefill; j++) {
      randomValue = ((100.0 - 0.0) * ((float)rand() / RAND_MAX)) + 0.0;
      myList->insertValue(myList->getTailPointer(), randomValue);
    }

    timer.startCounter();
    myList->removeFromIndex(myList->getHeadPointer(), 0);
    sumValue += (timer.getCounter()) * 100000;

    myList->cleanList();
    free(myList);
  }
  cout << endl
       << "Average time of deleting first value from prefilled linkedlist is: "
       << sumValue / howManyTestUnits << "ms /100000" << endl;
  sumValue = 0.0;

  for (int i = 0; i < howManyTestUnits; i++) {
    LinkedList *myList = new LinkedList();
    randomValue = 0.0;
    srand(time(NULL));
    for (int j = 0; j < howManyValuesToPrefill; j++) {
      randomValue = ((100.0 - 0.0) * ((float)rand() / RAND_MAX)) + 0.0;
      myList->insertValue(myList->getTailPointer(), randomValue);
    }

    timer.startCounter();
    myList->calculateAverage();
    sumValue += (timer.getCounter()) * 100000;

    myList->cleanList();
    free(myList);
  }
  cout << endl
       << "Average time of calculating average of prefilled linkedlist is: "
       << sumValue / howManyTestUnits << "ms /100000" << endl;
}

// conducts time tests for bst
void heap(int howManyTestUnits, int howManyValuesToPrefill) {

  Timer timer;
  double sumValue = 0.0;
  float randomValue;

  for (int i = 0; i < howManyTestUnits; i++) {

    timer.startCounter();
    Heap *myHeap = new Heap();
    sumValue += (timer.getCounter()) * 100000;

    myHeap->deleteHeap();
    free(myHeap);
  }
  cout << endl
       << "Average time of creating new heap instance: "
       << sumValue / howManyTestUnits << "ms /100000" << endl;
  sumValue = 0.0;

  for (int i = 0; i < howManyTestUnits; i++) {

    Heap *myHeap = new Heap();
    randomValue = 0.0;
    srand(time(NULL));
    for (int j = 0; j < howManyValuesToPrefill; j++) {
      randomValue = ((100.0 - 0.0) * ((float)rand() / RAND_MAX)) + 0.0;
      myHeap->insertNodeMaxHeap(randomValue);
    }

    timer.startCounter();

    myHeap->deleteHeap();
    free(myHeap);

    sumValue += (timer.getCounter()) * 100000;
  }
  cout << endl
       << "Average time of deleting prefilled heap instance: "
       << sumValue / howManyTestUnits << "ms /100000" << endl;
  sumValue = 0.0;

  for (int i = 0; i < howManyTestUnits; i++) {
    Heap *myHeap = new Heap();

    srand(time(NULL));
    randomValue = ((100.0 - 0.0) * ((float)rand() / RAND_MAX)) + 0.0;
    timer.startCounter();
    myHeap->insertNodeMaxHeap(randomValue);
    sumValue += (timer.getCounter()) * 100000;

    myHeap->deleteHeap();
    free(myHeap);
  }
  cout << endl
       << "Average time of adding random value to empty heap is: "
       << sumValue / howManyTestUnits << "ms /100000" << endl;
  sumValue = 0.0;

  for (int i = 0; i < howManyTestUnits; i++) {
    Heap *myHeap = new Heap();
    randomValue = 0.0;
    srand(time(NULL));
    for (int j = 0; j < howManyValuesToPrefill; j++) {
      randomValue = ((100.0 - 0.0) * ((float)rand() / RAND_MAX)) + 0.0;
      myHeap->insertNodeMaxHeap(randomValue);
    }
    randomValue = ((100.0 - 0.0) * ((float)rand() / RAND_MAX)) + 0.0;
    timer.startCounter();
    myHeap->insertNodeMaxHeap(randomValue);
    sumValue += (timer.getCounter()) * 100000;

    myHeap->deleteHeap();
    free(myHeap);
  }
  cout << endl
       << "Average time of adding random value to prefilled heap is: "
       << sumValue / howManyTestUnits << "ms /100000" << endl;
  sumValue = 0.0;
  for (int i = 0; i < howManyTestUnits; i++) {
    Heap *myHeap = new Heap();
    randomValue = 0.0;
    srand(time(NULL));
    for (int j = 0; j < howManyValuesToPrefill; j++) {
      randomValue = ((100.0 - 0.0) * ((float)rand() / RAND_MAX)) + 0.0;
      myHeap->insertNodeMaxHeap(randomValue);
    }
    randomValue = ((100.0 - 0.0) * ((float)rand() / RAND_MAX)) + 0.0;
    timer.startCounter();
    myHeap->deleteNodeMaxHeap();
    sumValue += (timer.getCounter()) * 100000;

    myHeap->deleteHeap();
    free(myHeap);
  }
  cout << endl
       << "Average time of deleting root from prefilled heap is: "
       << sumValue / howManyTestUnits << "ms /100000" << endl;
  sumValue = 0.0;
  for (int i = 0; i < howManyTestUnits; i++) {
    Heap *myHeap = new Heap();
    randomValue = 0.0;
    srand(time(NULL));
    for (int j = 0; j < howManyValuesToPrefill; j++) {
      randomValue = ((100.0 - 0.0) * ((float)rand() / RAND_MAX)) + 0.0;
      myHeap->insertNodeMaxHeap(randomValue);
    }
    randomValue = ((100.0 - 0.0) * ((float)rand() / RAND_MAX)) + 0.0;
    timer.startCounter();
    myHeap->calculateAverage();
    sumValue += (timer.getCounter()) * 100000;

    myHeap->deleteHeap();
    free(myHeap);
  }
  cout << endl
       << "Average time of calculating average of prefilled heap is: "
       << sumValue / howManyTestUnits << "ms /100000" << endl;
}

// conducts time tests for queue
void queue(int howManyTestUnits, int howManyValuesToPrefill) {
  Timer timer;
  float randomValue;
  double sumValue = 0.0;

  for (int i = 0; i < howManyTestUnits; i++) {

    timer.startCounter();
    Queue *myQueue = myQueue->createQueue(24);
    sumValue += (timer.getCounter()) * 100000;

    myQueue->cleanQueue(myQueue);
    free(myQueue);
  }
  cout << endl
       << "Average time of creating new queue instance: "
       << sumValue / howManyTestUnits << "ms /100000" << endl;
  sumValue = 0.0;

  for (int i = 0; i < howManyTestUnits; i++) {

    Queue *myQueue = myQueue->createQueue(24);
    randomValue = 0.0;
    srand(time(NULL));
    for (int j = 0; j < howManyValuesToPrefill; j++) {
      randomValue = ((100.0 - 0.0) * ((float)rand() / RAND_MAX)) + 0.0;
      myQueue->enqueue(myQueue, randomValue);
    }

    timer.startCounter();
    myQueue->cleanQueue(myQueue);
    free(myQueue);

    sumValue += (timer.getCounter()) * 100000;
  }
  cout << endl
       << "Average time of deleting prefilled queue instance: "
       << sumValue / howManyTestUnits << "ms /100000" << endl;
  sumValue = 0.0;

  for (int i = 0; i < howManyTestUnits; i++) {
    Queue *myQueue = myQueue->createQueue(24);
    srand(time(NULL));
    randomValue = ((100.0 - 0.0) * ((float)rand() / RAND_MAX)) + 0.0;
    timer.startCounter();
    myQueue->enqueue(myQueue, randomValue);
    sumValue += (timer.getCounter()) * 100000;

    myQueue->cleanQueue(myQueue);
    free(myQueue);
  }
  cout << endl
       << "Average time of adding random value to empty queue is: "
       << sumValue / howManyTestUnits << "ms /100000" << endl;
  sumValue = 0.0;

  for (int i = 0; i < howManyTestUnits; i++) {
    Queue *myQueue = myQueue->createQueue(24);
    randomValue = 0.0;
    srand(time(NULL));
    for (int j = 0; j < howManyValuesToPrefill; j++) {
      randomValue = ((100.0 - 0.0) * ((float)rand() / RAND_MAX)) + 0.0;
      myQueue->enqueue(myQueue, randomValue);
    }
    randomValue = ((100.0 - 0.0) * ((float)rand() / RAND_MAX)) + 0.0;
    timer.startCounter();
    myQueue->enqueue(myQueue, randomValue);
    sumValue += (timer.getCounter()) * 100000;

    myQueue->cleanQueue(myQueue);
    free(myQueue);
  }
  cout << endl
       << "Average time of adding random value to prefilled queue is: "
       << sumValue / howManyTestUnits << "ms /100000" << endl;
  sumValue = 0.0;

  for (int i = 0; i < howManyTestUnits; i++) {
    Queue *myQueue = myQueue->createQueue(24);
    randomValue = 0.0;
    srand(time(NULL));
    for (int j = 0; j < howManyValuesToPrefill; j++) {
      randomValue = ((100.0 - 0.0) * ((float)rand() / RAND_MAX)) + 0.0;
      myQueue->enqueue(myQueue, randomValue);
    }

    timer.startCounter();
    myQueue->dequeue(myQueue);
    sumValue += (timer.getCounter()) * 100000;

    myQueue->cleanQueue(myQueue);
    free(myQueue);
  }
  cout << endl
       << "Average time of deleting  value from prefilled queue is: "
       << sumValue / howManyTestUnits << "ms /100000" << endl;
  sumValue = 0.0;
  for (int i = 0; i < howManyTestUnits; i++) {
    Queue *myQueue = myQueue->createQueue(24);
    randomValue = 0.0;
    srand(time(NULL));
    for (int j = 0; j < howManyValuesToPrefill; j++) {
      randomValue = ((100.0 - 0.0) * ((float)rand() / RAND_MAX)) + 0.0;
      myQueue->enqueue(myQueue, randomValue);
    }

    timer.startCounter();
    myQueue->calculateAverage(myQueue);
    sumValue += (timer.getCounter()) * 100000;

    myQueue->cleanQueue(myQueue);
    free(myQueue);
  }
  cout << endl
       << "Average time of calculating average of prefilled queue is: "
       << sumValue / howManyTestUnits << "ms /100000" << endl;
}

// conducts time tests for array
void array(int howManyTestUnits, int howManyValuesToPrefill) {
  Timer timer;
  double sumValue = 0.0;
  float randomValue;

  for (int i = 0; i < howManyTestUnits; i++) {

    timer.startCounter();
    Array *myTab = new Array();
    sumValue += (timer.getCounter()) * 100000;

    myTab->cleanArray();
    free(myTab);
  }
  cout << endl
       << "Average time of creating new array instance: "
       << sumValue / howManyTestUnits << "ms /100000" << endl;
  sumValue = 0.0;

  for (int i = 0; i < howManyTestUnits; i++) {

    Array *myTab = new Array();
    randomValue = 0.0;
    srand(time(NULL));
    for (int j = 0; j < howManyValuesToPrefill; j++) {
      randomValue = ((100.0 - 0.0) * ((float)rand() / RAND_MAX)) + 0.0;
      myTab->insertValue(randomValue);
    }

    timer.startCounter();

    myTab->cleanArray();
    free(myTab);

    sumValue += (timer.getCounter()) * 100000;
  }
  cout << endl
       << "Average time of deleting prefilled array instance: "
       << sumValue / howManyTestUnits << "ms /100000" << endl;
  sumValue = 0.0;

  for (int i = 0; i < howManyTestUnits; i++) {
    Array *myTab = new Array();

    srand(time(NULL));
    randomValue = ((100.0 - 0.0) * ((float)rand() / RAND_MAX)) + 0.0;
    timer.startCounter();
    myTab->insertValue(randomValue);
    sumValue += (timer.getCounter()) * 100000;

    myTab->cleanArray();
    free(myTab);
  }
  cout << endl
       << "Average time of adding random value to empty array is: "
       << sumValue / howManyTestUnits << "ms /100000" << endl;
  sumValue = 0.0;
  for (int i = 0; i < howManyTestUnits; i++) {
    Array *myTab = new Array();
    randomValue = 0.0;
    srand(time(NULL));
    for (int j = 0; j < howManyValuesToPrefill; j++) {
      randomValue = ((100.0 - 0.0) * ((float)rand() / RAND_MAX)) + 0.0;
      myTab->insertValue(randomValue);
    }

    randomValue = ((100.0 - 0.0) * ((float)rand() / RAND_MAX)) + 0.0;
    timer.startCounter();
    myTab->insertValue(randomValue);
    sumValue += (timer.getCounter()) * 100000;

    myTab->cleanArray();
    free(myTab);
  }
  cout << endl
       << "Average time of adding random value to prefilled array is: "
       << sumValue / howManyTestUnits << "ms /100000" << endl;
  sumValue = 0.0;
  int randomIndex;
  for (int i = 0; i < howManyTestUnits; i++) {
    Array *myTab = new Array();
    randomValue = 0.0;
    srand(time(NULL));
    for (int j = 0; j < howManyValuesToPrefill; j++) {
      randomValue = ((100.0 - 0.0) * ((float)rand() / RAND_MAX)) + 0.0;
      myTab->insertValue(randomValue);
    }

    randomIndex = rand() % myTab->getSize();
    timer.startCounter();
    myTab->removeFromIndex(randomValue);
    sumValue += (timer.getCounter()) * 100000;

    myTab->cleanArray();
    free(myTab);
  }
  cout << endl
       << "Average time of deleting random index from prefilled array is: "
       << sumValue / howManyTestUnits << "ms /100000" << endl;
  sumValue = 0.0;
  for (int i = 0; i < howManyTestUnits; i++) {
    Array *myTab = new Array();
    randomValue = 0.0;
    srand(time(NULL));
    for (int j = 0; j < howManyValuesToPrefill; j++) {
      randomValue = ((100.0 - 0.0) * ((float)rand() / RAND_MAX)) + 0.0;
      myTab->insertValue(randomValue);
    }

    randomValue = ((100.0 - 0.0) * ((float)rand() / RAND_MAX)) + 0.0;
    timer.startCounter();
    myTab->calculateAverage();
    sumValue += (timer.getCounter()) * 100000;

    myTab->cleanArray();
    free(myTab);
  }
  cout << endl
       << "Average time of calculating average of random value to prefilled "
          "array is: "
       << sumValue / howManyTestUnits << "ms /100000" << endl;
}

int main(int argc, char *argv[]) {

  cout << "===================================================================="
          "================="
       << endl;
  cout << "*** Measure times for Array ***" << endl;
  ::array(1000, 12);

  cout << "===================================================================="
          "================="
       << endl;
  cout << "*** Measure times for Stack ***" << endl;
  ::stack(1000, 12);

  cout << "===================================================================="
          "================="
       << endl;
  cout << "*** Measure times for Queue ***" << endl;
  ::queue(1000, 12);

  cout << "===================================================================="
          "================="
       << endl;
  cout << "*** Measure times for Binary Tree ***" << endl;
  bst(1000, 12);

  cout << "===================================================================="
          "================="
       << endl;
  cout << "*** Measure times for LinkedList ***" << endl;
  linkedlist(1000, 12);

  cout << "===================================================================="
          "================="
       << endl;
  cout << "*** Measure times for Heap ***" << endl;
  heap(1000, 12);
  cout << "===================================================================="
          "================="
       << endl;

  cout << "Press Enter to exit...";
  cin.ignore();
  cin.get();
  return 0;
  // compile with: g++ -o benchmark main.cpp structures/array.cpp
  // structures/linkedlist.cpp structures/queue.cpp structures/timer.cpp
  // structures/bintree.cpp structures/maxheap.cpp structures/stack.cpp
}
