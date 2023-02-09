
// Online C++ Compiler - Build, Compile and Run your C++ programs online in your favorite browser

#include<iostream>
#include "LinkedList.cpp"

using namespace std;

int main()
{
    LinkedList numList;
    numList.addAtRear(3);
    numList.addAtRear(5);
    numList.addAtHead(4);
    numList.addAtRear(9);
    numList.getItems();
    
}
