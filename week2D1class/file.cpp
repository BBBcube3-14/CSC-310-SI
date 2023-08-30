
#include <iostream>
using namespace std;
#include "class.hpp"

int main(){
    BankAccount b1(1000, 250.6);
    BankAccount b2(1001, 1345.9);

    b1.deposit(316.2);
    b2.withdraw(45.0);

    b1.printStatus();
    b2.printStatus();

    cout << "Number of accounts = " << BankAccount::getNumberOfAccounts();
    return 0;
}