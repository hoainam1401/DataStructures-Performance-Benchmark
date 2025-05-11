#include <iostream>
using namespace std;

struct NodeTree {
  float data;
  struct NodeTree *left;
  struct NodeTree *right;
};

class BST {
private:
  int cnt = 0;

public:
  struct NodeTree *root = NULL;

  // constructor 1
  BST();

  // destructor
  ~BST();

  // Calculate Sum of all value of Node
  float Sum(struct NodeTree *root);

  // Count all the node of tree
  float count(struct NodeTree *root);

  // Calculate average of the value of node
  float calculateAverage(struct NodeTree *root);

  // Find root of the binary tree
  struct NodeTree *getRoot();

  // Add new node to the tree
  struct NodeTree *insertNodeTree(struct NodeTree *root, float data);

  // Delete node from the tree
  struct NodeTree *deleteNodeTree(struct NodeTree *root, float data);

  // Display the tree
  void displayTreeUtil(struct NodeTree *root, int space);
  void displayTree(struct NodeTree *root);

  // Delete the tree
  void deleteTree(struct NodeTree *root);
};
