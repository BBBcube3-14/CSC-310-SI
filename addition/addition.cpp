#include <iostream>
using namespace std;

template<class T>
class math {
    T operatorOne;
    T operatorTwo;
    public:
        math();
        math(T, T);
        T add(T operatorOne, T operatorTwo);
        void printAddition();
};

template<class T>
math::math(){
    operatorOne = 0;
    operatorTwo = 0;
}

template<class T>
math::math(T one, T two){
    operatorOne = one;
    operatorTwo = two;
}

template<class T>
T math::add(){
    return operatorOne + operatorTwo;
}

template<class T>



int main(){


    return 0;
}