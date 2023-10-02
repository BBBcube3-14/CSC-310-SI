#include <iostream>
using namespace std;

template <class T>
struct Node{
    T info;
    Node *next;
};

template<class T>
class LinkedList {
    protected:
        int length;
        Node<T>* first;
        Node<T>* last;
    public:
        LinkedList();
        bool isEmpty();
        int listSize();
        const void print();
        T front();
        T back();
        void insertFirst(const T&);
        void insertLast(const T&);
        bool serach(const T&);
        void deleteNode(const T&);
        LinkedList(const LinkedList<T>&);
        void destroyList();
        //~LinkedList();
};

template<class T>
LinkedList<T>::LinkedList(){
    length = 0;
    first = NULL;
    last = NULL;
}

template<class T>
bool LinkedList<T>::isEmpty(){
    return first == NULL;
}