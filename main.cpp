
// Online C++ Compiler - Build, Compile and Run your C++ programs online in your favorite browser

#include<iostream>
#include "LinkedList.cpp"

using namespace std;

int main()
{
    LinkedList numList;
    numList.addItemAtRear(3);
    numList.addItemAtRear(5);
    numList.addItemAtHead(4);
    numList.addItemAtRear(9);
    numList.getItems();
    
}
