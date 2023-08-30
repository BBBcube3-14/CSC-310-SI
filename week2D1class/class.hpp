#include <iostream>
using namespace std;

//static can be used by multiple objects?

class BankAccount{
    int accountNumber;
    double balance;
    static int numberOfAccounts;

    public:
        BankAccount(int accountNumber, double balance);
        void printStatus();
        void deposit(double amount);
        void withdraw(double amount);
        static int getNumberOfAccounts();
};
int BankAccount::numberOfAccounts = 0;

BankAccount::BankAccount(int an, double b){
    accountNumber = an;
    balance = b;
    numberOfAccounts++;
}
void BankAccount::printStatus(){
    cout << "Customer Account# " << accountNumber << ", Balance: " << balance << endl;
}
void BankAccount::deposit(double amount){
    balance += amount;
}
void BankAccount::withdraw(double amount){
    balance-=amount;
}
int BankAccount::getNumberOfAccounts(){
    return numberOfAccounts;
}