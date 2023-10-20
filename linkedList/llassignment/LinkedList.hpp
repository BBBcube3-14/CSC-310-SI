#include<iostream>
using namespace std; 
#include<assert.h>

template<class Type>
struct Node {
	Type info;
	Node<Type>* next;
};

template<class Type>
class LinkedList {
protected:
	int length;
	Node<Type>* first;
	Node<Type>* last;
public:
	LinkedList();
	bool isEmpty();
	int listSize();
	const void print();
	Type front();
	Type back();
	void insertFirst(const Type&);
	void insertLast(const Type&);
	bool search(const Type&);
	void deleteNode(const Type&);
	LinkedList(const LinkedList<Type>&);
	void destroyList();
	~LinkedList();
	//Tutorial chapter 5: Exercise 1
	void retrieveAt(int position, Type&);
	//Tutorial chapter 5: Exercise 2
	void replaceAt(int position, const Type&);
};

template<class Type>
LinkedList<Type>::LinkedList() {
	length = 0;
	first = NULL;
	last = NULL;
}

template<class Type>
bool LinkedList<Type>::isEmpty() {
	return length == 0;
	// return first == NULL; or return last == NULL;
}

template<class Type>
int LinkedList<Type>::listSize() {
	return length;
}

template<class Type>
const void LinkedList<Type>::print() {
	if (isEmpty())
		cout << "The list is empty, nothing to print\n";
	else
	{
		Node<Type>* current = first;
		while (current != NULL)
		{
			cout << current->info << " ";
			current = current->next;
		}
		cout << "\n";
	}
}

template<class Type>
Type LinkedList<Type>::front()
{
	assert(first != NULL);
	return first->info;
}

template<class Type>
Type LinkedList<Type>::back()
{
	assert(first != NULL);
	return last->info;
}

template<class Type>
void LinkedList<Type>::insertFirst(const Type& x)
{
	Node<Type>* newNode;
	newNode = new Node<Type>;
	assert(newNode != NULL);
	newNode->info = x;
	newNode->next = first;
	first = newNode;
	length++;
	if (last == NULL)
		last = newNode;
}

template<class Type>
void LinkedList<Type>::insertLast(const Type& x)
{
	Node<Type>* newNode;
	newNode = new Node<Type>;
	assert(newNode != NULL);
	newNode->info = x;
	newNode->next = NULL;
	if (first == NULL)
	{
		first = newNode;
		last = newNode;
	}
	else
	{
		last->next = newNode;
		last = newNode;
	}
	length++;
}

template<class Type>
bool LinkedList<Type>::search(const Type& x)
{
	Node<Type>* current;
	bool found;
	current = first;
	found = false;
	while (current != NULL && !found)
		if (current->info == x)
			found = true;
		else
			current = current->next;
	return found;
}

template<class Type>
void LinkedList<Type>::deleteNode(const Type& x)
{
	if (isEmpty())
		cout << "Empty linked list. No node to be deleted\n";
	else
	{
		Node<Type>* current, * prevCurrent;
		current = first;
		prevCurrent = NULL;
		while (current != NULL && current->info != x)
		{
			prevCurrent = current;
			current = current->next;
		}
		if (current == NULL)
			cout << x << " was not found in the linked list\n";
		else // the linked list is not empty and x was found.
		{
			if (first == last)//Linked list with only one node with info = x
			{
				delete current;
				first = NULL;
				last = NULL;
			}
			else if (current == first) //A list with more than one node and the first node has info = x
			{
				first = first->next;
				delete current;
			}
			else if (current == last)//A list with more than one node and only the last node has info = x
			{
				last = prevCurrent;
				last->next = NULL;
				delete current;
			}
			else//The node to be deleted is after first and before last
			{
				prevCurrent->next = current->next;
				delete current;
			}
			length--;
		}
	}
}

template<class Type>
LinkedList<Type>::LinkedList(const LinkedList<Type>& otherList)
{
	Node<Type>* current;   //pointer to traverse the otherlist
	if (first != NULL)
		destroyList();
	current = otherList.first;  //current points to the first node of otherlist 
	while (current != NULL)
	{
		insertLast(current->info);
		current = current->next;
	}
	length = otherList.length;
}

template<class Type>
void LinkedList<Type>::destroyList()
{
	Node<Type>* current;
	while (first != NULL)
	{
		current = first;
		first = first->next;
		delete current;
	}
	last = NULL;
	length = 0;
}

template<class Type>
LinkedList<Type>::~LinkedList(){
	cout << "The list was destroyed\n";
	destroyList();
}

//Tutorial chapter 5: Exercise 1
template<class Type>
void LinkedList<Type>::retrieveAt(int position, Type& item){
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

//Tutorial chapter 5: Exercise 2
template<class Type>
void LinkedList<Type>::replaceAt(int position, const Type& newItem)
{
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