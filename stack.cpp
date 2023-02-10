#include "LinkedList.cpp"

class Stack: private LinkedList {
  public:
    void push(int value) {
      this->addAtHead(value);
    };
    void getItems() {
      LinkedList::getItems();
    };
    void pop() {
      this->removeFromHead();
    };
};