#include <iostream>
#include <cassert>
using namespace std;
#include "Stack.hpp"

int main(){
    Stack<float> equationStack(10);
    string equa;
    cout << "Enter a postfix expression: ";
    cin >> equa;
    float one, two;
    while(equa != "="){
        if(equa == "+"){

        }else if(equa == "-"){

        }else if(equa == "*"){

        }else if(equa == "/"){

        }else{

        }
    }
}

/*
a+b                     ab+
a+b*c                   abc*+
a*b+c                   ab*c+
(a+b)*c                 ab+c*
(a-b)*(c+d)             ab-cd+*
(a+b)*(c-d/e)+f         ab+cde/-*f+
*/