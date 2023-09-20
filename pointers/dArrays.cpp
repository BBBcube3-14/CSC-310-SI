#include <iostream>
using namespace std;

class List{
	// int pointer p
	// int n 
	int *p;
	int n;

	public:
		List();
		void insertEnd(int);
		void print() const;
		void destroyList();
		const List& operator=(const List& otherList);
};

List::List(){
	//n is assigned to 0. N will be used to track the length of the list.
	n = 0;
	p = new int[5];
	//p  creates space for 5 integars effectively making an array.
}

void List::insertEnd(int name){
	//Because the length of the array was set to 5, the if statement prevents an overflow in memory.
	if(n<5){
		//The n th position of the p array is set to name, then n is incremented.
		p[n++] = name;
	}

	//E.g.
	/*
		The first time a number is inserted n = 0 and the p array has no numbers. 
		name = 1;
		p[n++] = name
		p[0] = 1
		n = 1
	*/
    return;
}

void List::print() const {
	//Pretty self explanatory.
	//Just prints out the p array.
    for (int i = 0; i < 5; i++){
        cout << " " << p[i];
    }
    cout << endl;
	//And adds a new line
    return;
}

void List::destroyList(){
	//Deletes all positions of the p array and sets p to null then n = 0 again.
	delete[] p;
	p = NULL;
	n = 0;

    return;
}

const List& List::operator =(const List& otherList){
	//This is to allow the ' = ' to allow another list to equal another.
	if (this != &otherList) { // this is to avoid duplicates and errors caused by setting a list equal to itself
		if (p != NULL){
			//If the array is already NULL, no need to destroy it.
			//We need to make room for the data in the otherList
			destroyList();
		}
		//Setting the length of this list to the length of the other list
		n = otherList.n;
		//Creating the p array again, guaranteeing the space for all five numbers.
		p = new int[5];
		for (int i = 0; i < 5; i++){
			//Setting each value in this list to the corresponding value in the other list
			p[i] = otherList.p[i];
		}
	}
	return *this;
	//Simply returning the list created back to main by reference as declared with the 'const List&' function return type at the start of the function.
}

int main() {
	//Creates two instances of lists.
	List l1, l2;

	//L1 has the first five positions in the l1 list values 0, 10, 20, 30, 40
	for (int i = 0; i < 5; i++){
		l1.insertEnd(10*i);
	}

	l2 = l1; // l1 and l2 are both pointed by the same pointer
 	l1.print(); //0 10 20 30 40 
	l2.print(); //0 10 20 30 40 
	l2.destroyList(); //both l1 and l2 will be destroyed!
	return 0;
}