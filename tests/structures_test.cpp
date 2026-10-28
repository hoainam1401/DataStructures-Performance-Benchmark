#include "structures/array.h"
#include "structures/bintree.h"
#include "structures/linkedlist.h"
#include "structures/maxheap.h"
#include "structures/queue.h"
#include "structures/stack.h"

#include <cmath>
#include <iostream>
#include <optional>

namespace {
bool closeTo(std::optional<float> value, float expected) {
  return value && std::fabs(*value - expected) < 0.0001F;
}

bool check(bool condition, const char *expression, int line) {
  if (!condition) {
    std::cerr << "check failed at line " << line << ": " << expression << '\n';
  }
  return condition;
}
} // namespace

#define CHECK(expression)                                                       \
  do {                                                                          \
    if (!check(static_cast<bool>(expression), #expression, __LINE__)) {         \
      return 1;                                                                 \
    }                                                                           \
  } while (false)

int main() {
  Array array;
  CHECK(!array.calculateAverage());
  array.insertValue(1.0F);
  array.insertValue(3.0F);
  CHECK(closeTo(array.calculateAverage(), 2.0F));
  CHECK(closeTo(array.removeFromIndex(0), 1.0F));
  CHECK(!array.removeFromIndex(4));
  array.cleanArray();
  CHECK(array.getSize() == 0);

  Stack stack;
  stack.push(1.0F);
  stack.push(3.0F);
  CHECK(closeTo(stack.peek(), 3.0F));
  CHECK(closeTo(stack.calculateAverage(), 2.0F));
  CHECK(closeTo(stack.pop(), 3.0F));
  stack.clear();
  CHECK(stack.isEmpty());

  Queue queue(2);
  queue.enqueue(1.0F);
  queue.enqueue(2.0F);
  queue.enqueue(3.0F);
  CHECK(closeTo(queue.calculateAverage(), 2.5F));
  CHECK(closeTo(queue.dequeue(), 2.0F));
  queue.cleanQueue();
  CHECK(queue.isEmpty());

  BST tree;
  tree.insert(2.0F);
  tree.insert(1.0F);
  tree.insert(3.0F);
  CHECK(closeTo(tree.calculateAverage(), 2.0F));
  CHECK(tree.erase(2.0F));
  CHECK(!tree.erase(7.0F));
  CHECK(tree.size() == 2);
  tree.clear();
  CHECK(tree.size() == 0);

  LinkedList list;
  list.insertValue(1.0F);
  list.insertValue(2.0F);
  list.insertValue(3.0F);
  CHECK(closeTo(list.removeFromIndex(1), 2.0F));
  CHECK(closeTo(list.calculateAverage(), 2.0F));
  CHECK(closeTo(list.removeFirst(), 1.0F));
  CHECK(closeTo(list.removeLast(), 3.0F));
  CHECK(!list.removeFirst());

  Heap heap;
  heap.insertNodeMaxHeap(1.0F);
  heap.insertNodeMaxHeap(3.0F);
  heap.insertNodeMaxHeap(2.0F);
  CHECK(closeTo(heap.deleteNodeMaxHeap(), 3.0F));
  CHECK(closeTo(heap.calculateAverage(), 1.5F));
  heap.deleteHeap();
  CHECK(!heap.deleteNodeMaxHeap());
}
