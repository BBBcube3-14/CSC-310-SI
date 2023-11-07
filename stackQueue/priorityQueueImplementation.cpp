#include<iostream>
using namespace std;
#include"priorityQueue.hpp"

int main() 
{
	PriorityQueue<string> q(20);
	string s;
	int p;
	cout << "Is empty queue: "  << q.isEmpty() << endl;
	cout << "Is full queue: " << q.isFull() << endl;
	cout << "Queue size = " << q.queueSize() << endl;
	q.enqueue("John", 7); q.enqueue("Sarah", 6); q.enqueue("Jacob", 6); q.enqueue("Noah", 4); q.enqueue("Alyssa", 8);
	q.enqueue("Youssef", 5); q.enqueue("Jacob", 0);
	q.print();
	q.front(s, p);
	cout << "Front of the queue: " << s << " "<<p<<endl;
	q.back(s, p);
	cout << "Back of the queue: " << s << " " << p << endl;
	q.dequeue();
	q.print();
	PriorityQueue<string> newQ(q);
	newQ.print();

	return 0;
}