#include <iostream>
using namespace std;
#include "shapes.hpp"
int main(){
    Circle c(3.7);
    c.printCircle();
    cout << endl;
    Cylinder cylinder(3, 5);
    cylinder.printCylinder();


    return 0;
}