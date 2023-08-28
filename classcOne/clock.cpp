#include <iostream>
using namespace std;
#include "clock.hpp"

void printEquality(clockType t1, clockType t2){
    if ((t1 == t2) == 0){
        t1.printTime();
        cout << " == ";
        t2.printTime();
        cout << ": ";
        cout << "Not Equal";
    } else {
        t1.printTime();
        cout << " == ";
        t2.printTime();
        cout << ": ";
        cout << "Equal";
    }
    cout << endl;
}

int main(){
    clockType t1, t2(7, 59, 18);
    t1.printTime();
    cout << endl;
    t2.printTime();
    cout << endl;
    t1.setTime(2,8,59);
    t1.printTime();
    cout << endl;
    t1.incrementSeconds();
    t1.printTime();
    cout << endl;
    int hour = 0;
    int min = 0;
    int sec = 0;
    t2.getTime(hour, min, sec);
    cout << "Get Time Results: " << hour << ":" << min << ":" << sec << endl;
    printEquality(t1, t2);
    t1.setTime(hour, min, sec);
    cout << endl;
    t1.printTime();
    cout << endl;
    printEquality(t1, t2);
    
}