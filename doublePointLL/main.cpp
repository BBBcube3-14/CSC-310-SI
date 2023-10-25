#include <iostream>
#include <assert.h>
using namespace std;
#include "dLL.hpp"

template<class Type>
void printCommon(DoubleLinkedList<Type>& list1, DoubleLinkedList<Type>& list2){
    int x;
    for(int i = 0; i < list1.listSize(); i++){
        list1.retrieveAt(i, x);
        if(list2.search(x))
            cout << x << " ";
    }
    cout << "\n";
}

template<class Type>
bool isSublist(DoubleLinkedList<Type>& list1, DoubleLinkedList<Type>& list2){
    int one, two;
    for(int y = 0; y < list1.listSize(); y++){
        list1.retrieveAt(y, one);
        if(!list2.search(one)){
            return false;
        }
    }
    return true;
}


int main(){

    DoubleLinkedList<double> list;//, otherList;
    list.insertLast(5.1);
    list.insertLast(10.2);
    list.insertLast(15.6);
    list.insertLast(12.3);
    list.insertLast(30.8);
    list.insertLast(35.1);
    list.insertLast(4.7);
    list.insertLast(50.9);
    list.insertLast(60.6);
    /*list.insertLast(17); list.insertLast(3); list.insertLast(20);
    list.insertLast(8); list.insertLast(21); list.insertLast(4);
    list.insertLast(6); list.insertLast(0); list.insertLast(15);
    list.insertLast(1);
    list.print();
    int x;
    list.retrieveAt(4, x);
    cout << x << endl;
    list.replaceAt(4, -1);
    cout << "Normal Print:  ";
    list.print();
    cout << "Reverse Print: ";
    list.printRev();

    list.reverseNodes();

    cout << "Normal Print:  ";
    list.print();
    cout << "Reverse Print: ";
    list.printRev();*/
    cout << "Big numbers: " << list.bigNodes() << endl;
    return 0;
}