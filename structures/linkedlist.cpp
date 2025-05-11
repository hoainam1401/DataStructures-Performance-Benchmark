#include "linkedlist.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList() {
  this->head = NULL;
  this->tail = NULL;
}

LinkedList::~LinkedList() {
  cleanList();
  delete head;
  delete tail;
}

void LinkedList::insertValue(ListNode **tail, float value) {

  ListNode *newElem = new ListNode;
  newElem->data = value;
  newElem->prev = *tail;
  newElem->next = NULL;

  if ((*tail) != NULL) {
    (*tail)->next = newElem;
  }

  if (this->head == NULL) {
    this->head = newElem;
    this->tail = newElem;
  }
  *tail = newElem;
}

float LinkedList::removeFromIndex(ListNode **head, int index) {

  if (*head == NULL || this->tail == NULL) {
    return -273.15;
  }
  ListNodePtr p = *head;
  for (int i = 0; i < index; i++) {
    if (p != NULL && p->next != NULL) {
      p = p->next;
    } else {
      return -273.15;
    }
  }

  if (p == this->tail) {
    return removeLast(getTailPointer());
  }

  if (p == this->head) {
    return removeFirst(getHeadPointer());
  }

  if (p->prev != NULL) {
    (p->prev)->next = p->next;
  } else {
    *head = p->next;
  }

  if (p->next != NULL) {
    (p->next)->prev = p->prev;
  }

  float ret = p->data;
  delete p;
  return ret;
}

float LinkedList::calculateAverage() {
  ListNodePtr p = this->head;
  float sum = 0;
  int amount = 0;
  while (p != this->tail) {
    // cout<<"DATA: "<<p->data<<endl;
    sum += p->data;
    // cout<<"SUM: "<<sum<<endl;
    amount++;
    p = p->next;
  }
  sum += p->data;
  amount++;

  return (sum / amount);
}

void LinkedList::cleanList() {
  while (this->head != this->tail) {
    removeFromIndex(getHeadPointer(), 0);
  }
  removeFromIndex(getHeadPointer(), 0);
}

void LinkedList::printList() {
  if (this->head == NULL || this->tail == NULL) {
    return;
  }
  ListNode *p = this->head;
  // cout<<"head: "<<head->data<<endl;
  // cout<<"tail: "<<tail->data<<endl;
  while (p != tail) {
    cout << p->data << " ";
    p = p->next;
  }
  cout << p->data << " ";
  cout << endl;
}

ListNode **LinkedList::getTailPointer() { return &tail; }

ListNode **LinkedList::getHeadPointer() { return &head; }

float LinkedList::removeFirst(ListNode **head) {
  ListNode *newHead;
  if (this->head == this->tail) {
    float ret = (*head)->data;
    this->head = NULL;
    this->tail = NULL;

    delete *head;
    return ret;
  }

  if (*head != NULL) {
    newHead = (*head)->next;
    if (newHead != NULL) {
      newHead->prev = NULL;
    }
    float ret = (*head)->data;
    delete *head;
    this->head = newHead;
    return ret;
  }
  return -273.15;
}

float LinkedList::removeLast(ListNode **tail) {
  ListNodePtr newTail;
  if (this->head == this->tail) {
    float ret = (*tail)->data;
    this->head = NULL;
    this->tail = NULL;

    delete *tail;
    return ret;
  }

  if (*tail != NULL) {
    newTail = (*tail)->prev;
    if (newTail != NULL) {
      newTail->next = NULL;
    }
    float ret = (*tail)->data;
    delete *tail;
    this->tail = newTail;
    return ret;
  }
  return -273.15;
}
