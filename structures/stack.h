#include <iostream>
using namespace std;
struct StackNode {
  float data;
  struct StackNode *next;
};
class Stack {
public:
  struct StackNode *newNode(float data);
  float isEmpty(struct StackNode *root);

  // Add node to stack
  void push(struct StackNode **root, float data);

  // Delete node from stack
  float pop(struct StackNode **root);

  // Get top node from stack
  float peek(struct StackNode *root);

  void displayStack(struct StackNode *root);

  // Calculate sum of value of all nodes in stack
  float Sum(struct StackNode *root);

  // count all nodes in stack
  float count(struct StackNode *root);

  // Calculate average of value of all nodes in stack
  float calculateAverage(struct StackNode *root);

  // Delete all the stack
  void deleteStack(struct StackNode *root);
  struct StackNode *getRoot();

  struct StackNode *root = NULL;

  // constructor 1
  Stack();

  // constructor 2
  Stack(StackNode *root);

  // destructor
  ~Stack();
};
