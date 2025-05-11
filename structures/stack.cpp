#include "stack.h"
#include <iostream>
using namespace std;

Stack::Stack() { this->root = NULL; }

Stack::Stack(StackNode *root) { this->root = root; }

Stack::~Stack() { deleteStack(Stack::getRoot()); }

struct StackNode *Stack::getRoot() { return this->root; }

struct StackNode *Stack::newNode(float data) {
  struct StackNode *stackNode = new StackNode;
  stackNode->data = data;
  stackNode->next = NULL;
  return stackNode;
}
float Stack::isEmpty(struct StackNode *root) { return !root; }

void Stack::push(struct StackNode **root, float data) {
  struct StackNode *stackNode = newNode(data);
  stackNode->next = *root;
  *root = stackNode;
  // cout << data;
}

float Stack::pop(struct StackNode **root) {
  if (isEmpty(*root))
    return INT_MIN;
  struct StackNode *temp = *root;
  *root = (*root)->next;
  int popped = temp->data;
  free(temp);

  return popped;
}

float Stack::peek(struct StackNode *root) {
  if (isEmpty(root))
    return INT_MIN;
  return root->data;
}

float Stack::Sum(struct StackNode *root) {
  if (root == NULL) {
    return 0;
  }
  return root->data + Sum(root->next);
}

float Stack::count(struct StackNode *root) {
  if (root == NULL) {
    return 0;
  }
  return count(root->next) + 1;
}

float Stack::calculateAverage(struct StackNode *root) {
  return static_cast<double>(Sum(root)) / count(root);
}

void Stack::deleteStack(struct StackNode *root) {
  if (root == NULL)
    return;
  deleteStack(root->next);
  delete root;
}

void Stack::displayStack(struct StackNode *root) {
  // cout << pop(&root) << endl;
  // cout << peek(root) << endl;
  while (!isEmpty(root)) {
    // print top element in stack
    cout << peek(root) << " ";
    // remove top element in stack
    pop(&root);
  }
}
