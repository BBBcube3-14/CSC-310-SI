#include <iostream>
using namespace std;

int main(){

    int *p, x;
    p = &x;
    p = new int;

    char *name;
    name = new char[5];

    strcpy(name,"John");
    delete[] name;
    
    return 0;
}