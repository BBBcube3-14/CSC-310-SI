#include<iostream>
using namespace std;
#include"Queue.hpp"

//average queue
void queueAverage(Queue<float> &q, float &a){
    float sum = 0;
    Queue<float> temp(q);
    int n = temp.queueSize();
    temp.print();
    while(!temp.isEmpty()){
        sum += temp.front();
        temp.dequeue();
    }
    a = sum / n;
    return;
}

template<class T>
void splitQueue(Queue<T>& q1, Queue<T>& q2, Queue<T>& q3){
    Queue<float> temp(q1);
    while(!temp.isEmpty()){
        q2.enqueue(temp.front());
        temp.dequeue();
        if(!temp.isEmpty()){
            q3.enqueue(temp.front());
            temp.dequeue();
        }
    }
    return;
}

int main(){
	Queue<float> q(20);
	//cout << "Is empty queue: "  << q.isEmpty() << endl;
	//cout << "Is full queue: " << q.isFull() << endl;
	//cout << "Queue size = " << q.queueSize() << endl;
	q.enqueue(1); q.enqueue(2); q.enqueue(3); q.enqueue(4);
	q.print();

    float val = 0;
    queueAverage(q, val);
    cout << "Average: " << val << endl;
	return 0;
}