#include <iostream>
#include <cstdlib>
using namespace std;


int main(){
    int x = 5;
    int *p = &x;

    cout << "Size of int    " << sizeof(int) << endl;
    cout << "Size of float  " << sizeof(float) << endl;
    cout << "Size of double " << sizeof(double) << endl;
    cout << "Size of char   " << sizeof(char) << endl;
    cout << "Size of string " << sizeof(string) << endl;

    cout << endl << endl;

    cout << "Size of int*    " << sizeof(int*) << endl;
    cout << "Size of float*  " << sizeof(float*) << endl;
    cout << "Size of double* " << sizeof(double*) << endl;
    cout << "Size of char*   " << sizeof(char*) << endl;
    cout << "Size of string* " << sizeof(string*) << endl;



    int x = 4;
    cout << "X\'s value is: " << x  << " and is stored at: " << &x << endl;
    int* y = &x;
    cout << "Y is a pointer stored at: " << &y << " it stores: " << y << " the value where Y points to is: " << *y << endl;
    //p is a pointer.
    //If you print p it will print the location it is pointing to.
    //If you print p* it will print the value at the location it points to.
    //If you print out &p it will print the location p is stored at.
    // Run the program for future reference.

    /*
    cout << "X: " << x << " &x: " << &x << " *x " << endl << " P: " << p << " *p: " << *p << " &p: " << &p  <<endl;
    x = 6;
    cout << "X: " << x << " &x: " << &x << " *x " << endl << " P: " << p << " *p: " << *p << " &p: " << &p  <<endl;

    //A is being set to the value at p ( 6 );
    int a = *p;

    cout << "X: " << x << " A: " << a << endl;

    x = 10;
    //Note this does not mean when we change x we also change a as it was only set to the value that was at x.
    cout << "X: " << x << " A: " << a << endl;
    */
    return 0;
}