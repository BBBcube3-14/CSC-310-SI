#include <iostream>
using namespace std;

class Date{
    int month, day, year;
    public: 
        Date();
        Date(int, int, int);
		void printDate();
		void setDate(int, int, int);
		void getDate(int&, int&, int&);
};

Date::Date(){
    month = 1;
    day = 1;
    year = 2023;
}

Date::Date(int m, int d, int y){
    month = m;
    day = d;
    year = y;
}

void Date::printDate(){
    cout << "The date is : " << month << "/" << day << "/" << year << endl;
}

void Date::setDate(int m, int d, int y){
    month = m;
    day = d;
    year = y;
}

void Date::getDate(int& m, int& d, int& y){
    m = month;
    d = day;
    y = year;
}