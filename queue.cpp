#include "LinkedList.cpp"

class Queue: protected LinkedList {
  public:
    void enqueue(int value) {
      this->addAtRear(value);
    };

    void dequeue() {
      this->removeFromHead();
    };

    void getItems() {
      LinkedList::getItems();
    };
};