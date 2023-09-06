#include <iostream>
using namespace std;
class Person {
    string firstName, lastName;
    public:
        Person();
        Person(string, string);
        void printName();
        void setName(string, string);
        void getName(string&, string&);
        string getFirstName();
};

Person::Person () {
    firstName = "John";
    lastName = "Doe";
}

Person::Person(string fn, string ln){
    firstName = fn;
    lastName = ln;
}

void Person::printName(){
    cout << "Name: " << lastName << ", " << firstName << endl;
}

void Person::setName(string fn, string ln){
     firstName = fn;
     lastName = ln;
}

void Person::getName(string& fn, string& ln){
    fn = firstName;
    ln = lastName;
}

string Person::getFirstName(){
    return firstName;
}