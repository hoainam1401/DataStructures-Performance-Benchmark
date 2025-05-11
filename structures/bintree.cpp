#include "bintree.h"
#include <fstream>
#include <iostream>
using namespace std;

BST::BST() {
  this->root = NULL;
  this->cnt = 0;
}

BST::~BST() { deleteTree(BST::getRoot()); }

struct NodeTree *BST::getRoot() { return this->root; }

struct NodeTree *BST::insertNodeTree(struct NodeTree *root, float data) {
  struct NodeTree *newNodeTree = new NodeTree;
  newNodeTree->data = data;
  newNodeTree->right = NULL;
  newNodeTree->left = NULL;

  if (!root) {
    return newNodeTree;
  }
  if (data > root->data) {
    root->right = insertNodeTree(root->right, data);
  } else {
    root->left = insertNodeTree(root->left, data);
  }
  return root;
}

struct NodeTree *BST::deleteNodeTree(struct NodeTree *root, float data) {
  if (root == NULL) {
    return root;
  }

  if (data > root->data) {
    root->right = deleteNodeTree(root->right, data);
  } else if (data < root->data) {
    root->left = deleteNodeTree(root->left, data);
  } else {
    if (root->left == NULL && root->right == NULL) {
      free(root);
      return NULL;
    } else if (root->left == NULL) {
      struct NodeTree *rightNodeTree = root->right;
      free(root);
      return rightNodeTree;
    } else if (root->right == NULL) {
      struct NodeTree *leftNodeTree = root->left;
      free(root);
      return leftNodeTree;
    } else {
      struct NodeTree *rightNodeTree = root->right;
      struct NodeTree *tmp = rightNodeTree;
      while (tmp && tmp->left != NULL) {
        tmp = tmp->left;
      }
      root->data = tmp->data;
      root->right = deleteNodeTree(root->right, tmp->data);
    }
  }
  return root;
}

float BST::Sum(struct NodeTree *root) {
  if (root == NULL) {
    return 0;
  }
  return root->data + Sum(root->right) + Sum(root->left);
}

float BST::count(struct NodeTree *root) {
  if (root == NULL) {
    return 0;
  }
  return count(root->right) + count(root->left) + 1;
}

float BST::calculateAverage(struct NodeTree *root) {
  return static_cast<double>(Sum(root)) / count(root);
}

void BST::displayTreeUtil(struct NodeTree *root, int space) {
  if (root == NULL)
    return;
  space += cnt;

  displayTreeUtil(root->right, space + 2);

  cout << endl;
  for (int i = cnt; i < space; i++)
    cout << " ";
  cout << root->data << "\n";

  displayTreeUtil(root->left, space + 2);
}

void BST::displayTree(struct NodeTree *root) { displayTreeUtil(root, 2); }

void BST::deleteTree(struct NodeTree *root) {
  if (root == NULL)
    return;
  deleteTree(root->left);
  deleteTree(root->right);
  delete root;
}
