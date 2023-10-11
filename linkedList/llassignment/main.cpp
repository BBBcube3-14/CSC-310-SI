#include<iostream>
using namespace std;
#include"LinkedList.hpp"

//Tutorial chapter 5: Exercise 3
template<class Type>
void printCommon(LinkedList<Type>& list1, LinkedList<Type>& list2){
    int x;
    for(int i = 0; i < list1.listSize(); i++){
        list1.retrieveAt(i, x);
        if(list2.search(x))
            cout << x << " ";
    }
    cout << "\n";
}

//Tutorial chapter 5: Exercise 4
template<class Type>
bool isSublist(LinkedList<Type>& list1, LinkedList<Type>& list2){
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
	LinkedList<int> list; LinkedList<int> otherList;
    list.insertLast(17); list.insertLast(3); list.insertLast(20);
    list.insertLast(8); list.insertLast(21); list.insertLast(4);
    list.insertLast(6); list.insertLast(0); list.insertLast(15);
    list.insertLast(1);
    list.print();
    int x;
    list.retrieveAt(4, x);
    cout << x << endl;
    list.replaceAt(4, -1);
    list.print();
    otherList.insertLast(6); otherList.insertLast(0); otherList.insertLast(15);
    printCommon(list, otherList);
    cout << isSublist(otherList, list) << endl;
    cout << isSublist(list, otherList) << endl;
	return 0;
}