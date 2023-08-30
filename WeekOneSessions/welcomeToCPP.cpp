#include <iostream>
//      iostream is the CPP equivalent to stdio.h
using namespace std;
//      Not required but is convenient.

#include <cstdlib>
#include <ctime>

int main(){
    /*
    int number = 1;
    double decimal = 9.99;
    char letter = 'A';
    string sentence = "Yes this exists in CPP!";

    cout << "Hello World\n";

    for(int i = 0; i < 10; i++){
        cout << "Times Run: " << (i + 1) << endl;
    }
    cout.precision(4);
    cout << decimal << endl;
    while(decimal > 1){
        decimal /= 2;
        cout << decimal << endl;
    }
    */
    //Single line comment
    /*
        Multi
        Line
        Comment
    */


    
    srand(time(NULL));
    int randNumber;
    for(int i = 1; i <= 100; i++){
        randNumber = rand() % 100;
        if(randNumber < 10){
            cout << "0";
        }
        cout  << randNumber << " ";
        if (i % 5 == 0 && i != 0){
            cout << endl;
        }
    }
    return 0;
}   