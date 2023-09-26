#include<iostream>
using namespace std;
#include"ArrayListImplementation.hpp"

int countEven(ArrayList<int> list){
	int count = 0, n, i, x;
	n = list.listSize();
	for(i = 0; i < n; i++){
		list.retrieveAt(i, x);
		if(x % 2 == 0){
			count++;
		}
	}
	return count;
}

int countVowel(ArrayList<char> list){
	int count = 0, n, i;
	char x;
	n = list.listSize();
	for(i = 0; i < n; i++){
		list.retrieveAt(i, x);
		if(x == 'a' || x == 'A' || x == 'e' || x == 'E' || x == 'i' || x == 'I' || x == 'o' || x == 'O' || x == 'u' || x == 'U'){
			count++;
		}
	}
	return count;
}

void replaceVowels(ArrayList<char> &list, char letter){
	int n = list.listSize();
	char x;
	for(int i = 0; i < n; i++){
		list.retrieveAt(i, x);
		if(x == 'a' || x == 'A' || x == 'e' || x == 'E' || x == 'i' || x == 'I' || x == 'o' || x == 'O' || x == 'u' || x == 'U'){
			list.replaceAt(i, letter);
		}
	}
	return;
}

template <class T>
void bubbleSort(ArrayList<T> &list){
	int i, j, n;
	T one;
	T two;
	n = list.listSize();
	bool swapped;
	for (i = 0; i < n - 1; i++){
		swapped = false;
		for(j = 0; j < n - i - 1; j++){
			list.retrieveAt(j, one);
			list.retrieveAt(j + 1, two);
			if(one > two){
				list.replaceAt(j, two);
				list.replaceAt(j + 1, one);
				swapped = true;
				list.print();
			}
		}
		if (swapped == false){
			break;
		}
	}
}

bool deleteValues(ArrayList<int>& list, int item){
	/*int n = list.listSize();
	bool found = false;
	int val;
	for(int i = 0; i < n; i++){
		list.retrieveAt(i,val);
		if(found == false){
			if(val == item){
				found = true;
			}
		}
		if(found == true){
			if(val <= item){
				list.removeAt(i);
				i--;
				n--;
			}
		}
	}*/
	int val;
	int n = list.listSize();
	int p = list.seqSearch(item);
	if(p == -1){
		return false;
	}else{
		for(int i = p; i < list.listSize(); i++){
			list.retrieveAt(i,val);
			if(val <= item){
				list.removeAt(i);
				i--;
			}
		}
		return true;
	}


	//return found;
}

int main() {
	ArrayList<int> number(10);
	ArrayList<char> letters(10);
	//14 9 3 6 5
	//B a T i E
	number.insertEnd(3);
	number.insertEnd(10);
	number.insertEnd(4);
	number.insertEnd(5);
	number.insertEnd(3);
	number.insertEnd(2);
	number.insertEnd(8);
	number.insertEnd(4);
	number.insertEnd(6);
	number.insertEnd(1);

	letters.insertEnd('B');
	letters.insertEnd('a');
	letters.insertEnd('T');
	letters.insertEnd('i');
	letters.insertEnd('E');

	number.print();
	letters.print();

	//cout << countEven(number) << " even numbers in the number list." << endl;
	//cout << countVowel(letters) << " vowels in the letter list." << endl;

	bubbleSort(letters);
	
	//Replace letter code
	/*
	cout << "Enter a letter to replace vowels with: ";
	char letter;
	cin >> letter;
	letters.print();
	replaceVowels(letters, letter);
	letters.print();
	cout << countVowel(letters) << " vowels in the letter list." << endl;
	*/

	number.print();
	//bubbleSort(number);
	//number.print();
	
	int input;
	cout << "Enter a value: ";
	cin >> input;
	deleteValues(number, input);
	number.print();	
	return 0;
}