#include<iostream>
using namespace std;
#include "Stack.hpp"
#include<string>
#include<iomanip>

template<class Type>
void postfix(Stack<Type> s)
{
	string e;
	float num, num1, num2;
	cin >> e;
	while (e != "=") 
	{
		if (e == "+")
		{
			num1 = s.top();
			s.pop();
			num2 = s.top();
			s.pop();
			s.push(num1 + num2);
		}
		else if(e == "-")
		{
			num1 = s.top();
			s.pop();
			num2 = s.top();
			s.pop();
			s.push(num2 - num1);
		}
		else if (e == "*")
		{	
			num1 = s.top();
			s.pop();
			num2 = s.top();
			s.pop();
			s.push(num1* num2);
		}
		else if (e == "/")
		{	
			num1 = s.top();
			s.pop();
			num2 = s.top();
			s.pop();
			s.push(num2 / num1);
		}
		else
		{
			num = stof(e);
			s.push(num);
		}
		cin >> e;
	}
	cout << setprecision(2) << fixed << s.top() << endl;
}

void rearrangeStacks(Stack<int>&s1, Stack<int>&s2){
    int n1 = s1.listSize();
    int n2 = s2.listSize();
    int t;
    Stack<int> s3(n1+n2);

    while(!s1.isEmptyStack()){
        s3.push(s1.top());
        s1.pop();
    }

    while(!s2.isEmptyStack()){
        s3.push(s2.top());
        s2.pop();
    }

    while(!s3.isEmptyStack()){
        t = s3.top();
        if(t > 0){
            s1.push(t);
        }else if(t < 0){
            s2.push(t);
        }
        s3.pop();
    }
}

int main(){
	/*Stack<int> s(10);
	cout<<"Is empty stack? "<<s.isEmptyStack() << endl;
	s.push(10); s.push(2); s.push(25);
	cout << "Top = "<<s.top() << endl;
	s.printStack();
	s.pop();
	cout << "Top = " << s.top() << endl;
	s.printStack();
	cout << "Is full stack? " << s.isFullStack() << endl;*/

	//code for postfix evaluation
	Stack<int> s1(5);
    Stack<int> s2(10);
    int x;
    s1.push(10);
    s1.push(-2);
    s1.push(25);
    s2.push(-5);
    s2.push(15);
    s2.push(-9);
    s2.push(-4);
    s1.printStack();
    s2.printStack();
    rearrangeStacks(s1, s2);
    s1.printStack();
    s2.printStack();
    /*
    s1.printStack();
    s1.pop();
    s1.pop(x);
    cout <<"The last popped element is: " << x << endl;
    s1.printStack();
	postfix(s);*/
	return 0;
}