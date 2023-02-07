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
    public:
        LinkedList() {
            this->head = this->rear = NULL;
        };
        LinkedList(int value) {
            
        };
        void addRear(int value) {
            if(this->head == NULL && this->rear == NULL) {
                this->head = this->rear = new Node(value);
            } else {
                Node *_new = new Node(value);
                this->rear->setNext(_new);
                this->rear = _new;
            }
        };
        void addHead(int value) {
            if(this->head == NULL && this->rear == NULL) {
                this->head = this->rear = new Node(value);
            } else {
                Node *_new = new Node(value);
                _new->setNext(this->head);
                this->head = _new;
            }
        };
        void getItems() {
            Node *temp = head;
            while(temp) {
                cout << temp->getValue() << ',';
                temp = temp->getNext();
            };
        };
        void removeHead() {
            Node *temp = head;
            head = head->getNext();
            delete temp;
        };
        void removeRear() {
            Node *temp = head;
            while(temp->getNext() != rear) temp = temp->getNext();
            rear = temp;
            rear->setNext(NULL);
            delete temp->getNext();
        };
        void removeFirst(int value) {
            Node *temp = head, *prev = NULL;
            while(temp->getValue() != value && temp) {
                prev = temp;
                temp = temp->getNext();
            };
            if(temp == head) {
                this->removeHead();
            } else if(prev == rear) {
                this->removeRear();
            } else {
                prev->setNext(temp->getNext());
                delete temp;
            }
        };
        void removeAll(int value) {
            Node *temp = head, *prev = NULL;
            do {
                if(temp->getValue() == value) {
                    if(temp == head) {
                        this->removeHead();
                        temp = head;
                    } else if(temp == rear) {
                        this->removeRear();
                    } else {
                        prev->setNext(temp->getNext());
                        delete temp;
                        temp = prev->getNext();
                    }
                }
                prev = temp;
                temp = temp->getNext();
            }while(temp);
        };
};