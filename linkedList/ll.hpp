#include <iostream>
#include <assert.h>
using namespace std;


template <class T>
struct Node{
    T info;
    Node* next;
};

template<class T>
class LinkedList {
    protected:
        int length;
        Node<T>* first;
        Node<T>* last;
    public:
        LinkedList();
        LinkedList(const LinkedList<T>&);
        bool isEmpty();
        int listSize();
        const void print();
        T front();
        T back();
        void insertFirst(const T&);
        void insertLast(const T&);
        bool search(const T&);
        void deleteNode(const T&);
        void destroyList();
        ~LinkedList();
};

template<class T>
LinkedList<T>::LinkedList(){
    length = 0;
    first = NULL;
    last = NULL;
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList<T>& otherList){
    Node<T>* current;
    if(first != NULL){
        destroyList();
    }
    current = otherList.first;
    while(current != NULL){
        insertLast(current->info);
        current = current->next;
    }
    length = otherList.length;
}

template<class T>
bool LinkedList<T>::isEmpty(){
    return first == NULL;
}

template<class T>
int LinkedList<T>::listSize(){
    return length;
}

template<class T>
T LinkedList<T>::front(){
    assert(first!=NULL);
    return first->info;
}

template<class T>
T LinkedList<T>::back(){
    assert(first!=NULL);
    return last->info;
}

template<class T>
const void LinkedList<T>::print(){
    if(isEmpty()){
        cout << "The list is empty, nothing to print.\n";
    }else{
        Node<T>* tmp;
        tmp = first;
        while(tmp!=NULL){
            cout << tmp->info << " ";
            tmp = tmp->next;
        }
        cout << endl;
    }
    return;
}

template<class T>
void LinkedList<T>::insertFirst(const T& n){
    
        Node<T>* tmp;
        tmp = new Node<T>;
        assert(tmp != NULL);
        tmp->info = n;
        tmp->next = first;
        first = tmp;
        length++;
    if(last == NULL){
        last = tmp;
    }
}

template<class T>
void LinkedList<T>::insertLast(const T& n){

    /*
    Node<T>* tmp;
    tmp = new Node<T>;
    assert(tmp != NULL);
    tmp->info = n;
    
    if(isEmpty()){
        first = last = new Node<T>;
        first = tmp;
        last = tmp;
    }else{
        last->next = tmp;
        last = tmp;
    }*/

    Node<T>* newNode;
    newNode = new Node<T>;
    assert(newNode != NULL);
    newNode->info = n;
    newNode->next = NULL;
    if(first == NULL){
        first = last = newNode;
    }else{
        last->next = newNode;
        last = newNode;
    }
    length++;
}

template<class T>
bool LinkedList<T>::search(const T& n){
    Node<T>* walker = new Node<T>;
    assert(walker != NULL);
    walker = first;
    while(walker != NULL){
        //cout << walker->info << " == " << n << "?\n";
        if(walker->info == n){
            return true;
        }
        walker = walker->next;
    }
    return false;
}

template<class T>
void LinkedList<T>::deleteNode(const T& n){
    Node<T>* walker;
    walker = new Node<T>;
    assert(walker != NULL);

    Node<T>* follower;
    follower = new Node<T>;
    assert(follower != NULL);

    if(first == NULL){
        cout << "No nodes to delete.\n";

    }else if(first->next == NULL){
        if(first->info == n){
            delete first;
            first = last = NULL;
            length = 0;
        }else{
            cout << "Node not found.\n";
        }
    }else{
        follower = first;
        walker = follower->next;
        if(follower->info == n){
            first = walker;
            delete follower;
            length--;
        }else{

            while(walker != NULL){
                if(walker->info == n){
                    follower->next = walker->next;
                    if(walker == last){
                        last = follower;
                    }
                    delete walker;
                    length--;
                    break;
                }else{
                    follower = walker;
                    walker = walker->next;
                }
            }

        }
        
    }
    return;
}

template<class Type>
LinkedList<Type>::~LinkedList(){
	cout << "The list was destroyed\n";
	destroyList();
}
