#include<assert.h>

template<class Type>
struct Node
{
	Type info;
	int priority;
	Node<Type>* next;
};

template<class Type>
class PriorityQueue
{
	int length, maxSize;
	Node<Type>* first;
	Node<Type>* last;
public:
	PriorityQueue(int);
	bool isEmpty();
	bool isFull();
	int queueSize();
	const void print();
	void front(Type&, int&);
	void back(Type&, int&);
	void enqueue(const Type&, const int&);
	void dequeue();
	void destroyQueue();
	PriorityQueue(const PriorityQueue<Type>&);
	~PriorityQueue();
};

template<class Type>
PriorityQueue<Type>::PriorityQueue(int ms)
{
	length = 0;
	maxSize = ms;
	first = NULL;
	last = NULL;
}

template<class Type>
bool PriorityQueue<Type>::isEmpty()
{
	return length == 0;
}

template<class Type>
bool PriorityQueue<Type>::isFull()
{
	return length == maxSize;
}

template<class Type>
int PriorityQueue<Type>::queueSize()
{
	return length;
}

template<class Type>
const void PriorityQueue<Type>::print()
{
	if (first == NULL)
		cout << "The queue is empty, nothing to print\n";
	else
	{
		Node<Type>* current = first;
		while (current != NULL)
		{
			cout << current->info << ", "<<current->priority<<endl;
			current = current->next;
		}
	}
}

template<class Type>
void PriorityQueue<Type>::front(Type &x, int &p)
{
	assert(first != NULL);
	x = first->info;
	p = first->priority; 
}

template<class Type>
void PriorityQueue<Type>:: back(Type& x, int& p)
{
	assert(first != NULL);
	x = last->info;
	p = last->priority; 
}

template<class Type>
void PriorityQueue<Type>::enqueue(const Type& x, const int &p)
{
	if (isFull())
		cout << "Cannot insert in a full queue." << endl;
	else
	{
		Node<Type> *newNode, *current, *prevCurrent;
		newNode = new Node<Type>;
		assert(newNode != NULL);
		newNode->info = x;
		newNode->priority = p;
		newNode->next = NULL;
		if (first == NULL)//empty queue
			first = last = newNode;
		else
		{
			prevCurrent = NULL;
			current = first;
			while (current != NULL && current->priority >= p)
			{
				prevCurrent = current;
				current = current->next;
			}
			if (current == first)//The node has the highest priority and will be inserted at the beginning
			{
				newNode->next = first;
				first = newNode;
			}
			else if (current == NULL)//The node has the least priority and will be inserted at the end
			{
				last->next = newNode;
				last = newNode;
			}
			else
			{
				newNode->next = prevCurrent->next;
				prevCurrent->next = newNode;
			}	
		}
		length++;
	}
}

template<class Type>
void PriorityQueue<Type>::dequeue()
{
	if (isEmpty())
		cout << "Empty queue. No node to be deleted\n";
	else 
	{
		Node<Type>* current = first;
		if (first == last)//only one node in the queue
		{
			delete current;
			first = last = NULL;
		}
		else //more than one node in the queue
		{
			first = first->next;
			delete current;
		}
		length--;
	}
}

template<class Type>
PriorityQueue<Type>::PriorityQueue(const PriorityQueue<Type>& otherQueue)
{
	Node<Type>* current;   //pointer to traverse otherQueue
	if (first != NULL)
		destroyQueue();
	maxSize = otherQueue.maxSize;
	current = otherQueue.first;  //current points to the first node of otherQueue 
	while (current != NULL)
	{
		enqueue(current->info, current->priority);
		current = current->next;
	}
}

template<class Type>
void PriorityQueue<Type>::destroyQueue()
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
PriorityQueue<Type>::~PriorityQueue()
{
	cout << "The queue was destroyed\n";
	destroyQueue();
}



//split queue - every other node