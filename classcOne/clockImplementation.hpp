/*#include "clock.hpp"
#include <iostream>
using namespace std;
clockType::clockType(){
    hr = 0;
    min = 0;
    sec = 0;
}
clockType::clockType(int h, int m, int s){
    hr = h;
    min = m;
    sec = s;
}

clockType::~clockType(){
    cout << "Destructor called!\n";
}

void clockType::setTime(int h, int m, int s){
    hr = h;
    min = m;
    sec = s;
}

const void clockType::getTime(int*& h, int*& m, int*& s){
    h = hr;
    m = min;
    s = sec;
}

const void clockType::printTime(){
    if(hr < 10){
        cout << 0;
    }
    cout << hr << ":";
    if(min < 10){
        cout << 0;
    }
    cout << min << ":";
    if(sec < 10){
        cout << 0;
    }
    cout << sec;
}

void clockType::incrementSeconds(){
    sec++;
    if(sec == 60){
        min++;
        sec = 0;
    }
    if(min == 60){
        hr++;
        min = 0;
    }
}

void clockType::incrementMinutes(){
    min++;
    if(min == 60){
        hr++;
        min = 0;
    }
}

void clockType::incrementHours(){
    hr++;
}

bool clockType::operator == (const clockType& t){
    return hr == t.hr && min == t.min && sec == t.sec;
}



//private default
// . is member access
// = assignment
*/