#include<assert.h>

template<class Type>
struct Node
{
	Type info;
	Node<Type>* next;
};

template<class Type>
class Queue
{
	int length, maxSize;
	Node<Type>* first;
	Node<Type>* last;
public:
	Queue(int);
	bool isEmpty();
	bool isFull();
	int queueSize();
	const void print();
	Type front();
	Type back();
	void enqueue(const Type&);
	void dequeue();
	void destroyQueue();
	Queue(const Queue<Type>&);
	~Queue();
};

template<class Type>
Queue<Type>::Queue(int ms)
{
	length = 0;
	maxSize = ms;
	first = NULL;
	last = NULL;
}

template<class Type>
bool Queue<Type>::isEmpty()
{
	return length == 0;
}

template<class Type>
bool Queue<Type>::isFull()
{
	return length == maxSize;
}

template<class Type>
int Queue<Type>::queueSize()
{
	return length;
}

template<class Type>
const void Queue<Type>::print()
{
	if (isEmpty())
		cout << "The queue is empty, nothing to print\n";
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
Type Queue<Type>::front()
{
	assert(first != NULL);
	return first->info;
}

template<class Type>
Type Queue<Type>::back()
{
	assert(first != NULL);
	return last->info;
}

template<class Type>
void Queue<Type>::enqueue(const Type& x)
{
	if (isFull())
		cout << "Cannot insert in a full queue." << endl;
	else
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
}

template<class Type>
void Queue<Type>::dequeue()
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
Queue<Type>::Queue(const Queue<Type>& otherQueue)
{
	Node<Type>* current;   //pointer to traverse otherQueue
	if (first != NULL)
		destroyQueue();
	maxSize = otherQueue.maxSize;
	current = otherQueue.first;  //current points to the first node of otherQueue 
	while (current != NULL)
	{
		enqueue(current->info);
		current = current->next;
	}
}

template<class Type>
void Queue<Type>::destroyQueue()
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
Queue<Type>::~Queue()
{
	cout << "The queue was destroyed\n";
	destroyQueue();
}