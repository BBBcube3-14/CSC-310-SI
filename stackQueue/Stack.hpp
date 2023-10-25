#include <cassert>
#include <iostream>
using namespace std;
#include "ArrayListImplementation.hpp"

template<class T>
class Stack : public ArrayList<T>{
    public:
        Stack(int);
        bool isEmptyStack();
        bool isFullStack();
        void printStack();
        void push(const T& x);
        T top();
        void pop();
};

template<class T>
Stack<T>::Stack(int ms) : ArrayList<T>(ms){}

template<class T>
bool Stack<T>::isEmptyStack(){
    return ArrayList<T>::isEmpty();
}

template<class T>
bool Stack<T>::isFullStack(){
    return ArrayList<T>::isFull();
}

template<class T>
void Stack<T>::printStack(){
    ArrayList<T>::print();
}

template<class T>
void Stack<T>::push(const T& x){
    ArrayList<T>::insertEnd(x);
}

template<class T>
T Stack<T>::top(){
    int n;
    T x;
    n = ArrayList<T>::listSize();
    ArrayList<T>::retrieveAt(n-1,x);
    return x;
}

template<class T>
void Stack<T>::pop(){
    int n;
    n = ArrayList<T>::listSize();
    ArrayList<T>::removeAt(n - 1);
}