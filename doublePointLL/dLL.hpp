#include <iostream>
using namespace std;

template <class T>
struct Node{
    Node* prev;
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

template <class T>
LinkedList<T>::LinkedList(){
    length = 0;
    first = NULL;
    last = NULL;
}

template <class T>
LinkedList<T>::LinkedList( const LinkedList<T>& otherList){
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
    return first = NULL;
}

template<class T>
int LinkedList<T>::listSize(){
    return length;
}

template<class T>
T LinkedList<T>::front(){
    if (first != NULL){
        return first->info;
    }else{
        cout << "Empty list.\n";
        Node<T>* tmp = new Node<T>;
        tmp->info = 0;
        return tmp->info;
    }
}

template<class T>
T LinkedList<T>::back(){
    if (first != NULL){
        return last->info;
    }else{
        cout << "Empty list.\n";
        Node<T>* tmp = new Node<T>;
        tmp->info = 0;
        return tmp->info;
    }
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
    Node<T>* tmp = new Node<T>;
    if(first != NULL){
        tmp->info = n;
        first->prev = tmp;
        tmp->next = first;
        tmp->prev = NULL;
        first = tmp;
        length++;
    }else{
        tmp->info = n;
        tmp->prev = NULL;
        tmp->next = NULL;
        length++;
        first = last = tmp;
    }
}

template<class T>
void LinkedList<T>::insertLast(const T& n){
    Node<T>* newNode =  new Node<T>;
    newNode->info = n;
    newNode->next = NULL;
    if(first == NULL){
        first = last = newNode;
    }else{
        last->next = newNode;
        newNode->prev = last;
        last = newNode;
    }
    length++;
}

template<class T>
bool LinkedList<T>::search(const T& n){
    Node<T>* walker = new Node<T>;
    walker = first;
    while(walker != NULL){
        if(walker->info == n){
            return true;
        }
    }
    return false;
}

template<class T>
void LinkedList<T>::deleteNode(const T& n){
    Node<T>* walker = new Node<T>;
    Node<T>* follower = new Node<T>;
    
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

template<class T>
void LinkedList<T>::destroyList(){
    Node<T>* tmp;
    while(first != NULL){
        tmp = first;
        first = first->next;
        delete tmp;
    }

    return;
    
}

template<class T>
LinkedList<T>::~LinkedList(){
    cout << "Destructor called.\n";
    destroyList();
}