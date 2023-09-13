#include <iostream>
using namespace std;

class clockType{
    int hr, min, sec;
    public:
        clockType();
        clockType(int, int, int);
        ~clockType();

        void setTime(int, int, int);
        const void getTime(int&, int&, int&);
        const void printTime();
        void incrementSeconds();
        void incrementMinutes();
        void incrementHours();
        bool operator == (const clockType&);
        bool operator <= (const clockType&);
};


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

const void clockType::getTime(int& h, int& m, int& s){
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
    if(hr == 24){
        hr = 0;
    }
}

bool clockType::operator == (const clockType& t ){
    return hr == t.hr && min == t.min && sec == t.sec;
}


/*
int main(){
    int num = 0;

    return 0;
}*/

/**
 * hr int
 * min int
 * sec int
 * 
 * clockType()
 * setTime(int,int,int): void
 * getTime(&int, &int, &int) const:void
 * printTime()const:void
 * incrementSeconds():int
 * incrementMinutes():int
 * incrementHours():int
 * equalTime(const clockType&)const:bool
 */