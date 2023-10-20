#include <iostream>
#include <assert.h>
using namespace std;
#include "ll.hpp"



int main(){

    LinkedList<int> myList;
    cout << "Is the list empty: " << myList.isEmpty() << endl;
    cout << "How many are in the list: " << myList.listSize() << endl;
    myList.print();
    myList.insertFirst(10); //10
    myList.print();
    myList.insertFirst(5);  //05 10
    myList.print();
    myList.insertFirst(2);  //02 05 10
    myList.print();
    myList.insertLast(1);   //02 05 10 01
    myList.print();
    myList.deleteNode(2);   //05 10 01
    myList.print();
    myList.insertFirst(7);  //07 05 10 01
    myList.print();
    myList.insertLast(20);  //07 05 10 01 20
    myList.print();
    myList.deleteNode(5);   //07 10 01 20
    myList.print();
    myList.deleteNode(20);  //07 10 01
    myList.print();
    cout << "Is 7 in the list: " << myList.search(7) << endl;
    cout << "Is 20 in the list: " << myList.search(20) << endl;
    cout << "Front: " << myList.front() << endl;
    //cout << "Back: " << myList.back() << endl;
    return 0;
}