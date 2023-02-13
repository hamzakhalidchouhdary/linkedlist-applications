#include "LinkedList.cpp"

class Queue: protected LinkedList {
  public:
    void enqueue(int value) {
      this->addAtRear(value);
    };
};