#include <iostream>
using namespace std;
#include <cassert>
class bankBalance{
    double *balance;
    int capacity;
    int length;

    public: 
    bankBalance(int);

    bool isEmpty();
    bool isFull();

    int arrSize();
    int maxArrSize();

    bool isItemAtEqual(int, const double&);

    const void print();

    void insertStart(const double&);
    void insertAt(int, const double&);
    void insertEnd(const double&);

    void removeAt(int);
    void retrieveAt(int, double&);
    void replaceAt(int, const double&);

    void clearList();

    int seqSearch(const double&);

    void insert(const double&);
    void remove(const double&);

    bankBalance(const bankBalance&);
    ~bankBalance();
    const bankBalance& operator=(const bankBalance&);
};

bankBalance::bankBalance(int size){
    length = 0;
    if (size < 0){
        cout << "Aray must have a positive value. Creating an array that stores 10 doubles.";
        capacity = 100;
    } else {
        capacity = size;
    }
    balance = new double[capacity];
    assert(balance != NULL);
}

bool bankBalance::isEmpty(){
    return length == 0;
}

bool bankBalance::isFull(){
    return length == capacity;
}

int bankBalance::arrSize(){
    return length;
}

int bankBalance::maxArrSize(){
    return capacity;
}

bool bankBalance::isItemAtEqual(int pos, const double& x){
    if(pos < 0 || pos >= capacity){
        cout << "Valid positions: 0 - " << length - 1 << endl;
        return false;
    }else if(balance[pos] == x){
        return true;
    }else{
        return false;
    }
}

const void bankBalance::print(){
    if(isEmpty()){
        cout << "Empty list" << endl;
    }else{
        for(int i = 0; i < length; i++){
            cout << balance[i] << " ";
        }
        cout << endl;
    }
}

void bankBalance::insertStart(const double& x) {
    insertAt(0, x);
}
void bankBalance::insertAt(int pos, const double& x){
    if (isFull()){
		cout << "Full list.\n";
    } else if (pos < 0 || pos > length){
		cout << "Valid positions: 0 - " << length << endl;
	} else {
		for (int i = length; i > pos; i--){
			balance[i] = balance[i - 1];
        }
	    balance[pos] = x;
		length++;
	}
}
void bankBalance::insertEnd(const double& x){
    if (isFull()){
		cout << "Full list.\n";
    } else {
        balance[length] = x;
        length++;
    }
}

void bankBalance::removeAt(int pos){
    if (isEmpty()){
		cout << "The list is already empty. Aborted \n";
    } else if(pos < 0 || pos >= length) {
        cout << "Valid positions: 0 - " << length - 1 << endl;
    }else{
        for(int i = pos; i < length - 1; i++){
            balance[i] = balance[i+1];
        }
        length--;
    }
}

void bankBalance::retrieveAt(int pos, double& x){
    if (isEmpty()){
		cout << "The list is empty. Aborted \n";
    } else if(pos < 0 || pos >= length) {
        cout << "Valid positions: 0 - " << length - 1 << endl;
    } else {
        x = balance[pos];
    }
}

void bankBalance::replaceAt(int pos, const double& x){
    if (isEmpty()) {
		cout << "Empty list.\n";
    } else if (pos < 0 || pos >= length) {
		cout << "Valid positions: 0 - " << length - 1 << endl;
    } else {
		balance[pos] = x;
    }
}

void bankBalance::clearList(){
    length = 0;
}

int bankBalance::seqSearch(const double& x){
    if(isEmpty()){
        cout << "Cannot search in an empty list.\n";
        return -1;
    } else {
        for (int i = 0; i < length; i++){
            if(balance[i] == x){
                return i;
            }
        }
        return -1;
    }
}

void bankBalance::insert(const double& x){
    if (length == capacity) { //or if(isFull())
		cout << "Cannot insert in a full list.\n";
    } else if(length == 0) {// or if(isEmpty())
		balance[length++] = x;
    } else {
		if (seqSearch(x) != -1) {
			cout << "Dupplication is not allowed\n";
        } else {
			balance[length++] = x;
        }
	}
}

void bankBalance::remove(const double& x){
    if (length == 0) { // or if(isEmpty())
		cout << "Cannot remove from empty list\n"; 
    } else {
		int i = seqSearch(x);
		if(i==-1) {
			cout << x << " does not exist in the list\n";
        } else {
			removeAt(i);
        }
	}
}

bankBalance::bankBalance(const bankBalance& otherBalance){
    capacity = otherBalance.capacity;
	length = otherBalance.length;
	balance = new double[capacity];
	assert(balance != NULL); // capture programming error
	for (int i = 0; i < length; i++) {
		balance[i] = otherBalance.balance[i];
    }
}

bankBalance::~bankBalance(){
    delete[] balance;
}

const bankBalance& bankBalance::operator=( const bankBalance& otherBalance) {
    if(this != &otherBalance){
        delete[] balance;
        capacity = otherBalance.capacity;
        length = otherBalance.length;
        balance = new double[capacity];
        assert(balance != NULL);
        for(int i = 0; i < length; i++){
            balance[i] = otherBalance.balance[i];
        }
    }
    return *this;
}

int main(){
    bankBalance bOne(10);
    double num;
    bOne.print();
    cout << bOne.isEmpty() << endl;
    bOne.insert(1.1);
    bOne.insert(2.2);
    bOne.insert(4.4);
    bOne.print();
    cout << bOne.isEmpty() << endl;
    bOne.insertAt(2, 3.3);
    bOne.print();
    bOne.insertEnd(5.5);
    bOne.print();
    bOne.insertAt(7, 8.8);
    bOne.print();
    bOne.insert(2.2);
    cout << bOne.isFull() << endl;
    cout << bOne.isItemAtEqual(2, 'C') << endl;
    bOne.remove(2.2);
    bOne.print();
    bOne.removeAt(0);
    bOne.print();
    bOne.replaceAt(1, 0);
    bOne.print();
    cout << bOne.seqSearch(8.8) << endl;
    bOne.retrieveAt(0, num);
    cout << "Num: " << num << endl;
    bankBalance newBankBalance(bOne);
    cout << "New balance is: ";
    newBankBalance.print();
    bankBalance bTwo(10);
    bTwo = newBankBalance;
    cout << "Balance two begins: ";
    bTwo.print();


    return 0;
}