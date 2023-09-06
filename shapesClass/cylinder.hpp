#include <iostream>
using namespace std;
#include "circle.hpp"

class Cylinder:public Circle{
    double height;
    public:
    Cylinder(double, double);
    double volume();
    void printCylinder();
    void get(double&, double&);
};
Cylinder::Cylinder(double r, double h):Circle(r){
    height = h;
}
double Cylinder::volume(){
    return area() * height;
}
void Cylinder::printCylinder(){
    cout << "Cylinder volume: " << volume() << endl;
    printCircle();
    cout << "Height: " << height << endl; 
}
void Cylinder::get(double& r, double& h){
    h = height;
    Circle::get(r);
}