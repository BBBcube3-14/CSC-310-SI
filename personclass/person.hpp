#include <iostream>
using namespace std;
class Person {
    string firstName, lastName;
    public:
        Person(string, string);
        void printName();
        void setName(string, string);
        void getName(string&, string&);
};

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

