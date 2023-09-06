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

    personalInfoType Ben("Ben", "Batie", 4, 20, 2002, 1);
    Ben.printPersonalInfo();
    personalInfoType Cheyloh("Cheyloh", "Brockel", 2, 26, 2002, 2);
    Cheyloh.printPersonalInfo();
    personalInfoType voidEmpty; //.personalInfoType();
    voidEmpty.printPersonalInfo();

    me.setName("Ben-Juh-min", "Bay-TEE");
    me.printName();

    cout << "Previous  values: " << lastName << ", " << firstName << endl;
    me.getName(firstName, lastName);
    cout << "Retrieved Values: "  << lastName << ", " << firstName << endl;

    string name = me.getFirstName();
    cout << "Test getFirstName: " << name << endl;
    return 0;
}