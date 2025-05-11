#include <iostream>
using namespace std;

struct ListNode {
  float data;
  ListNode *next;
  ListNode *prev;
};

typedef ListNode *ListNodePtr;

class LinkedList {
private:
  ListNodePtr head = NULL;
  ListNodePtr tail = NULL;

public:
  // Constructor
  LinkedList();

  // Destructor
  ~LinkedList();

  // Prints values of items stored in structure
  void printList();

  // Returns pointer to tail(which is pointer to last item)
  ListNode **getTailPointer();

  // Returns pointer to head(which is pointer to first item)
  ListNode **getHeadPointer();

  // Adds new item of given value to the end of the structure(which's head's
  // pointer was provided)
  void insertValue(ListNodePtr *, float);

  // Removes Nth item(counting from start) from list(which's head's pointer was
  // provided)
  float removeFromIndex(ListNode **, int);

  // Removes First item from list(which's head's pointer was provided)
  float removeFirst(ListNode **);

  // Removes Last item from list(which's tail's pointer was provided)
  float removeLast(ListNode **);

  // Calculates AVG of all objects inside structure
  float calculateAverage();

  // Removes all items from list
  void cleanList();
};
