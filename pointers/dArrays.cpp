#include <iostream>
using namespace std;

class List{
	int *p, n;
	public:
		List();
		void insertEnd(int);
		void print() const;
		void destroyList();
		const List& operator=(const List& otherList);
};

List::List(){
	n = 0;
	p = new int[5];
}

void List::insertEnd(int name){
	if(n<5){
		p[n++] = name;
	}
    return;
}

void List::print() const {
    for (int i = 0; i < 5; i++){
        cout << " " << p[i];
    }
    cout << endl;
    return;
}

void List::destroyList(){
	delete[] p;
	p = NULL;
	n = 0;

    return;
}

const List& List::operator =(const List& otherList){
	if (this != &otherList) { // avoid self-assignment
		if (p != NULL){
			destroyList();
		}
		n = otherList.n;
		p = new int[5];
		for (int i = 0; i < 5; i++){
			p[i] = otherList.p[i];
		}
	}
	return *this;
}

int main() {
	List l1, l2;
	for (int i = 0; i < 5; i++){
		l1.insertEnd(10*i);
	}
	l2 = l1; // l1 and l2 are both pointed by the same pointer
 	l1.print(); //0 10 20 30 40 
	l2.print(); //0 10 20 30 40 
	l2.destroyList(); //both l1 and l2 will be destroyed!
	return 0;
}