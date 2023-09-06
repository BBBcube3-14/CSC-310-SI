#include <iostream>
using namespace  std;
#include "person.hpp"
#include "date.hpp"

class personalInfoType{
    Person fullName;
    Date birthDate;
    int id;
    public:
    personalInfoType();
    personalInfoType(string, string, int, int, int, int);
    void printPersonalInfo();
    void setPersonalInfo(string, string, int, int, int, int);

};

personalInfoType::personalInfoType(){

}

personalInfoType::personalInfoType(string fn, string ln, int m, int d, int y, int id){
    fullName.setName(fn, ln);

}

void personalInfoType::printPersonalInfo(){
    cout << "ID: " << id << endl;
    fullName.printName();
    birthDate.printDate();
}

void personalInfoType::setPersonalInfo(string fn, string ln, int m, int d, int y, int id){

}

