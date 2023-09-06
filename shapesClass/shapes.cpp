#include <iostream>
using namespace std;
//#include "circle.hpp"
#include "cylinder.hpp"
int main(){
    Circle c(3.7);
    c.printCircle();
    cout << endl;
    Cylinder cylinder(3, 5);
    cylinder.printCylinder();
    return 0;
}