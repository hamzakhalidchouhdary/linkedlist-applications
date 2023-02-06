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
        void addItemAtRear(int value) {
            if(this->head == NULL && this->rear == NULL) {
                this->head = this->rear = new Node(value);
            } else {
                Node *_new = new Node(value);
                this->rear->setNext(_new);
                this->rear = _new;
            }
        };
        void addItemAtHead(int value) {
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
};