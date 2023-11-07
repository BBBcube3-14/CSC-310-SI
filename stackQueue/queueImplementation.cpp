#include<iostream>
using namespace std;
#include"Queue.hpp"

int main()
{
	Queue<int> q(20);
	cout << "Is empty queue: "  << q.isEmpty() << endl;
	cout << "Is full queue: " << q.isFull() << endl;
	cout << "Queue size = " << q.queueSize() << endl;
	q.enqueue(1); q.enqueue(2); q.enqueue(3); q.enqueue(4);
	q.print();
	/*cout << "Front of the queue: " << q.front() << endl;
	cout << "Back of the queue: " << q.back() << endl;
	q.dequeue();
	q.print();
	cout << "Front of the queue: " << q.front() << endl;
	cout << "Back of the queue: " << q.back() << endl;*/
	Queue<int>newQ(q);
	cout << "New queue: ";
	newQ.print();
	return 0;
}