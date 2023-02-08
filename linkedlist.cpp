#include<cstddef>
#include<iostream>

using namespace std;

class Node {
    int value;
    Node* next;
    void init(int value){
        this->value = value;
        this->next = NULL;
    };
    public:
        Node() {
            this->init(0);
        };
        Node(int value) {
            this->init(value);
        };
        void setValue(int value) {
            this->value = value;
        };
        void setNext(Node* next) {
            this->next = next;
        };
        Node* getNext() {
            return this->next;
        };
        int getValue(void) {
            return this->value;
        };
};

class LinkedList {
    Node *head, *rear;
    int length = 0;
    public:
        LinkedList() {
            this->head = this->rear = NULL;
        };
        LinkedList(int value) {
            
        };
        void addAtRear(int value) {
            if(this->head == NULL && this->rear == NULL) {
                this->head = this->rear = new Node(value);
            } else {
                Node *_new = new Node(value);
                this->rear->setNext(_new);
                this->rear = _new;
            }
            this->length++;
        };
        void addAtHead(int value) {
            if(this->head == NULL && this->rear == NULL) {
                this->head = this->rear = new Node(value);
            } else {
                Node *_new = new Node(value);
                _new->setNext(this->head);
                this->head = _new;
            }
            this->length++;
        };
        void getItems() {
            Node *temp = head;
            while(temp) {
                cout << temp->getValue() << ',';
                temp = temp->getNext();
            };
        };
        void removeFromHead() {
            Node *temp = head;
            head = head->getNext();
            delete temp;
            this->length--;
        };
        void removeFromRear() {
            Node *temp = head;
            while(temp->getNext() != rear) temp = temp->getNext();
            rear = temp;
            rear->setNext(NULL);
            delete temp->getNext();
            this->length--;
        };
        void removeFirstMatch(int value) {
            Node *temp = head, *prev = NULL;
            while(temp->getValue() != value && temp) {
                prev = temp;
                temp = temp->getNext();
            };
            if(temp == head) {
                this->removeFromHead();
            } else if(prev == rear) {
                this->removeFromRear();
            } else {
                prev->setNext(temp->getNext());
                delete temp;
                this->length--;
            }
        };
        void removeAllMatch(int value) {
            Node *temp = head, *prev = NULL;
            while(temp){
                if(temp->getValue() == value) {
                    if(temp == head) {
                        this->removeFromHead();
                        temp = head;
                    } else if(temp == rear) {
                        this->removeFromRear();
                    } else {
                        prev->setNext(temp->getNext());
                        delete temp;
                        temp = prev->getNext();
                        this->length--;
                    }
                }
                prev = temp;
                temp = temp->getNext();
            };
        };
        int getLength() {
            return this->length;
        };
};