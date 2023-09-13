//#include "ArrayListDesign.hpp"
#include <cassert>
#include <iostream>
using namespace std;

template<class Type>
class ArrayList{
protected:
	int length, maxSize;
	Type* list;
public:
	ArrayList(int);//constructor
	bool isEmpty();
	bool isFull();
	int listSize();
	int maxListSize();
	const void print();
	bool isItemAtEqual(int, const Type&);
	void insertAt(int, const Type&);
	void insertEnd(const Type&);
	void removeAt(int);
	void retrieveAt(int, Type&);
	void replaceAt(int, const Type&);
	void clearList();
	int seqSearch(const Type&);
	void insert(const Type&);//without duplication
	void remove(const Type&);
	ArrayList(const ArrayList<Type>&);//copy constructor
	~ArrayList();
	const ArrayList<Type>& operator=(const ArrayList<Type>&);
};

template<class Type>
ArrayList<Type>::ArrayList(int size) {
	length = 0;
	if (size < 0) {
		cout << "The array size must be positive. Creating of an array of size 100.\n";
		maxSize = 100;
	} else {
		maxSize = size;
    }
	list = new Type[maxSize];
	assert(list != NULL); // capture programming error
}

template<class Type>
bool ArrayList<Type>::isEmpty(){
	return length == 0;
}

template<class Type>
bool ArrayList<Type>::isFull(){
	return length == maxSize;
}

template<class Type>
int ArrayList<Type>::listSize(){
	return length;
}

template<class Type>
int ArrayList<Type>::maxListSize(){
	return maxSize;
}

template<class Type>
const void ArrayList<Type>::print(){
	if (isEmpty()){
		cout << "Empty list\n";
    }else{
		for (int i = 0; i < length; i++){
			cout << list[i] << " ";
        }
		cout << "\n";
	}
}

template<class Type>
bool ArrayList<Type>::isItemAtEqual(int pos, const Type& x){
	if (pos < 0 || pos >= maxSize){
		cout << "Valid positions must be in " << 0 << "..." << length - 1 << "\n";
		return false;
	} else if (list[pos] == x) {
		return true;
    }else{
		return false;
    }
}

template<class Type>
void ArrayList<Type>::insertAt(int pos, const Type& x){
	if (isFull()){
		cout << "Cannot insert in a full list.\n";
    } else if (pos < 0 || pos > length){
		cout << "Valid positions for insertion are " << 0 << "..." << length << "\n";
	} else {
		for (int i = length; i > pos; i--){
			list[i] = list[i - 1];
        }
		list[pos] = x;
		length++;
	}
}

template<class Type>
void ArrayList<Type>::insertEnd(const Type& x) {
	if (isFull()){
		cout << "Cannot insert in a full list.\n";
    } else {
		list[length] = x;
		length++;
	}
}

template<class Type>
void ArrayList<Type>::removeAt(int pos){
	if (isEmpty()){
		cout << "Cannot remove from an empty list.\n";
    } else if (pos < 0 || pos >= length) {
		cout << "Valid positions for removal are " << 0 << "..." << length-1 << "\n";
    } else {
		for (int i = pos; i <length-1; i++) {
			list[i] = list[i + 1];
        }
		length--;
	}
}

template<class Type>
void ArrayList<Type>::retrieveAt(int pos, Type& x) {
	if (isEmpty()) {
		cout << "Cannot retrieve from an empty list.\n";
	} else if (pos < 0 || pos >= length) {
		cout << "Valid positions for retrieving are " << 0 << "..." << length - 1 << "\n";
	} else {
		x = list[pos];
    }
}

template<class Type>
void ArrayList<Type>::replaceAt(int pos, const Type& x) {
	if (isEmpty()) {
		cout << "Empty list.\n";
    } else if (pos < 0 || pos >= length) {
		cout << "Valid positions for replacement are " << 0 << "..." << length - 1 << "\n";
    } else {
		list[pos] = x;
    }
}

template<class Type>
void ArrayList<Type>::clearList() {
	length = 0;
}

template<class Type>
int ArrayList<Type>::seqSearch(const Type& x) {
	if (isEmpty()) {
		cout << "Cannot search in an empty list.\n";
		return -1;
	} else {
		for (int i = 0; i < length; i++) {
			if (list[i] == x) {
				return i;
            }
        }
		return -1;
	}
}

template<class Type>
void ArrayList<Type>::insert(const Type& x) { //without duplication
	if (length == maxSize) { //or if(isFull())
		cout << "Cannot insert in a full list.\n";
    } else if(length == 0) {// or if(isEmpty())
		list[length++] = x;
    } else {
		if (seqSearch(x) != -1) {
			cout << "Dupplication is not allowed\n";
        } else {
			list[length++] = x;
        }
	}
}

template<class Type>
void ArrayList<Type>::remove(const Type& x) {
	if (length == 0) { // or if(isEmpty())
		cout << "Cannot remove from empty list\n"; 
    } else {
		int i = seqSearch(x);
		if(i==-1) {
			cout << x << " does not exist in the list\n";
        } else {
			removeAt(i);
        }
	}
}

template<class Type>
ArrayList<Type>::ArrayList(const ArrayList<Type>& otherList) {
	maxSize = otherList.maxSize;
	length = otherList.length;
	list = new Type[maxSize];
	assert(list != NULL); // capture programming error
	for (int i = 0; i < length; i++) {
		list[i] = otherList.list[i];
    }
}

template<class Type>
ArrayList<Type>::~ArrayList() { // destructor
	delete[] list;
}

template<class Type>
const ArrayList<Type>& ArrayList<Type>::operator=(const ArrayList<Type>& otherList) {
	if (this != &otherList) {
		delete[] list;
		maxSize = otherList.maxSize;
		length = otherList.length;
		list = new Type[maxSize];
		assert(list != NULL);
		for (int i = 0; i < length; i++) {
			list[i] = otherList.list[i];
        }
	}
	return *this;
}