#include <iostream>
using namespace std;
#include<assert.h>

template <class T>
struct Node{
    Node* prev;
    T info;
    Node* next;
};

template<class T>
class DoubleLinkedList {
    protected:
        int length;
        Node<T>* first;
        Node<T>* last;
    public:
        DoubleLinkedList();
        DoubleLinkedList(const DoubleLinkedList<T>&);
        bool isEmpty();
        int listSize();
        const void print();
        const void printRev();
        T front();
        T back();
        void insertFirst(const T&);
        void insertLast(const T&);
        bool search(const T&);
        void deleteNode(const T&);
        void destroyList();
        ~DoubleLinkedList();
        void retrieveAt(int position, T&);
        void replaceAt(int position, const T&);
        bool isSortedList();
        void reverseNodes();
        bool Palindrome();
        int bigNodes();
        //reverseNodes
};

template <class T>
int DoubleLinkedList<T>::bigNodes(){
    if(length < 2){
        return 0;
    }

    int count = 0;
    Node<T> *current = first->next;
    if(first->info  > first->next->info){
       count++; 
    }
    if(last->info  > last->prev->info){
       count++; 
    }

    while(current != last){
        if(current->info > current->prev->info && current->info > current->next->info){
            count++;
        }
        current = current->next;
    }
    

    return count;
}

template <class T>
bool DoubleLinkedList<T>::Palindrome(){
    Node<T>* currentFirst = first;
    Node<T>* currentLast = last;
    for(int i = 0; i < length/2; i++){
        if(currentFirst->info == currentLast->info){
            return false;
        }
        currentFirst = currentFirst->next;
        currentLast = currentLast->prev;
    }
    return true;
}

template <class T>
bool DoubleLinkedList<T>::isSortedList(){
    if(first == NULL){
        cout << "Empty List. Technically in order.\n";
        return true;
    }if(length == 1){
        cout << "In order.\n";
        return true;
    }else{
        bool inOrder = true;
        Node<T>* current = first;
        while(current->next != NULL && inOrder == true){
            if(current->info > current->next->info){
                inOrder = false;
            }
        }
        return inOrder;
    } 
}

template <class T>
void DoubleLinkedList<T>::reverseNodes(){
    //int n = length;
    Node<T>* currentFirst = first;
    Node<T>* currentLast = last;
    T tmp;
    for(int i = 0; i < length/2; i++){
        tmp = currentFirst->info;
        currentFirst->info = currentLast->info;
        currentLast->info = tmp;
        currentFirst = currentFirst->next;
        currentLast = currentLast->prev;
    }
}

template <class T>
DoubleLinkedList<T>::DoubleLinkedList(){
    length = 0;
    first = NULL;
    last = NULL;
}

template <class T>
DoubleLinkedList<T>::DoubleLinkedList( const DoubleLinkedList<T>& otherList){
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
bool DoubleLinkedList<T>::isEmpty(){
    return length == 0;
}

template<class T>
int DoubleLinkedList<T>::listSize(){
    return length;
}

template<class T>
T DoubleLinkedList<T>::front(){
    assert(first != NULL);
	return first->info;
}

template<class T>
T DoubleLinkedList<T>::back(){
    assert(first != NULL);
	return last->info;
}

template<class T>
const void DoubleLinkedList<T>::print(){
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
const void DoubleLinkedList<T>::printRev(){
    if(isEmpty()){
        cout << "The list is empty, nothing to print.\n";
    }else{
        Node<T>* tmp;
        tmp = last;
        while(tmp!=NULL){
            cout << tmp->info << " ";
            tmp = tmp->prev;
        }
        cout << endl;
    }
    return;
}

template<class T>
void DoubleLinkedList<T>::insertFirst(const T& n){
    Node<T>* tmp;
    tmp = new Node<T>;
    assert(tmp != NULL);
    tmp->info = n;
    tmp->prev = NULL;
    tmp->next = first;
    first->prev = tmp;
    first = tmp;
    length++;
    if(last == NULL){
        last = tmp;
    }
}

template<class T>
void DoubleLinkedList<T>::insertLast(const T& n){
    Node<T>* newNode;
    newNode = new Node<T>;
    assert(newNode!= NULL);
    newNode->info = n;
    newNode->next = NULL;
    if(first == NULL){
        first =  newNode;
        last = newNode;
    }else{
        last->next = newNode;
        newNode->prev = last;
        last = newNode;
    }
    length++;
}

template<class T>
bool DoubleLinkedList<T>::search(const T& n){
    Node<T>* walker;
    bool found;
    walker = first;
    found = false;
    while(walker != NULL && !found){
        if(walker->info == n){
            return true;
        }else{
            walker = walker->next;
        }
    }
    return found;
}

template<class T>
void DoubleLinkedList<T>::deleteNode(const T& n){
    if(isEmpty()){
        cout << "Empty linked list. No node to be deleted\n";
    }else{
        Node<T> *current, *prevCurrent;
        current = first;
        prevCurrent = NULL;
        while(current != NULL && current->info != n){
            prevCurrent = current;
            current = current->next;
        }
        if(current == NULL){
            cout << n << " was not found in the linked list\n";
        }else{
            if(first == last){
                delete current;
                first = NULL;
                last = NULL;
            }else if(current == first){
                first = first->next;
                delete current;
            }else if(current == last){
                last = prevCurrent;
                last->next = NULL;
                delete current;
            }else{
                prevCurrent->next = current->next;
                delete current;
            }
            length--;
        }
    }
    return;
}

template<class T>
void DoubleLinkedList<T>::destroyList(){
    Node<T>* tmp;
    while(first != NULL){
        tmp = first;
        first = first->next;
        delete tmp;
    }
    last = NULL;
    length = 0;
    return;
}

template<class T>
DoubleLinkedList<T>::~DoubleLinkedList(){
    cout << "Destructor called.\n";
    destroyList();
}

template<class Type>
void DoubleLinkedList<Type>::retrieveAt(int position, Type& item){
	Node<Type>* start;
	if(isEmpty())
		cout << "List is empty. Cannot recieve\n";
	else if(position < 0 || position >= length)
		cout << "Invalid position\n";
	else{
		start = first;
		for(int i = 0; i < position; i++)
			start = start->next;
		item = start->info;
	}

}

template<class Type>
void DoubleLinkedList<Type>::replaceAt(int position, const Type& newItem){
	Node<Type>* start;
	if(isEmpty())
		cout << "List is empty. Cannot recieve\n";
	else if(position < 0 || position >= length)
		cout << "Invalid position\n";
	else{
		start = first;
		for(int i = 0; i < position; i++)
			start = start->next;
		start->info = newItem;
	}
}