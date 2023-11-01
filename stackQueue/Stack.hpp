#include "ArrayListImplementation.hpp"

template<class Type>
class Stack : public ArrayList<Type>
{
public:
	Stack(int);
	bool isEmptyStack();
	bool isFullStack();
	void printStack();
	void push(const Type& x);
	Type top();
	void pop();
    bool pop(Type&);
//    int stackSize();
};



template<class Type>
Stack<Type>::Stack(int ms) : ArrayList<Type>(ms)
{
}

template<class Type>
bool Stack<Type>::isEmptyStack()
{
	return ArrayList<Type>::isEmpty();
}

template<class Type>
bool Stack<Type>::isFullStack()
{
	return ArrayList<Type>::isFull();
}

template<class Type>
void Stack<Type>::printStack()
{
	ArrayList<Type>::print();
}

template<class Type>
void Stack<Type>::push(const Type& x)
{
	ArrayList<Type>::insertEnd(x);
}

template<class Type>
Type Stack<Type>::top()
{
	int n;
	Type x;
	n = ArrayList<Type>::listSize();
	ArrayList<Type>::retrieveAt(n-1, x);
	return x;
}

template <class Type>
bool Stack<Type>::pop(Type& x){
    int n;
    n = ArrayList<Type>::listSize();
    if(n == 0){
        return false;
    }else{
        ArrayList<Type>::retrieveAt(n-1, x);
        ArrayList<Type>::removeAt(n-1);
        return true;
    }
}

template<class Type>
void Stack<Type>::pop(){
	int n;
	n = ArrayList<Type>::listSize();
	ArrayList<Type>::removeAt(n - 1);
}