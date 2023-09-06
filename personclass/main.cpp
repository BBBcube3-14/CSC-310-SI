#include "personalInfoType.hpp"
#include <iostream>
using namespace std;

int main(){
    int month, day, year;
    string firstName, lastName;
    firstName = "Benjamin";
    lastName = "Batie";
    month = 9;
    day = 1;
    year = 2023;

    Person me(firstName, lastName);
    me.printName();
    Date today(month, day, year);
    today.printDate();

    return 0;
}