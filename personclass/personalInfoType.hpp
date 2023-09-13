#include <iostream>
using namespace  std;
#include "person.hpp"
#include "date.hpp"
//template<classType>

class personalInfoType{
    Person fullName;
    Date birthDate;
    int id;
    public:
    personalInfoType();
    personalInfoType(string, string, int, int, int, int);
    void printPersonalInfo();
    void setPersonalInfo(string, string, int, int, int, int);
    void getPersonalInfo(string&, string&, int&, int&, int&, int&);
};

personalInfoType::personalInfoType():fullName(" ", " "), birthDate(0,0,0){
    id = 0;
}

personalInfoType::personalInfoType(string fn, string ln, int m, int d, int y, int ID){
    fullName.setName(fn, ln);
    birthDate.setDate(m,d,y);
    id = ID;
}

void personalInfoType::printPersonalInfo(){
    cout << "ID: " << id << endl;
    fullName.printName();
    birthDate.printDate();
}

void personalInfoType::setPersonalInfo(string fn, string ln, int m, int d, int y, int ID){
    fullName.setName(fn, ln);
    birthDate.setDate(m,d,y);
    id = ID;
}

void personalInfoType::getPersonalInfo(string& fn, string& ln, int& m, int& d, int& y, int& ID){
    fullName.getName(fn, ln);
    birthDate.getDate(m, d, y);
    id = ID;
}