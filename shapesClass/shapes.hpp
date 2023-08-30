#include <iostream>
using namespace std;


/*
    - private
    + public
    # protected
*/
const double PI = 3.141592653589793238463;
class Circle{
    double radius;

    public:
    Circle(double);
    double circumference(); //2piR
    double area(); //pi r ^2
    void printCircle();
    void get(double&)
};
Circle::Circle(double r){
    radius = r;
}
double Circle::circumference(){
    return radius * 2 * PI;
}
double Circle::area(){
    return PI * radius * radius;
}
void Circle::printCircle(){
    cout << "Circle circumference: " << circumference() << endl;
    cout << "Circle area: " << area() << endl;
    cout << "Circle radius: " << radius << endl;
}

void Circle::get(double& r){
    r = radius;
}

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