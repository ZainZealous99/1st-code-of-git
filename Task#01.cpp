#include <iostream>
using namespace std;

class shape 
{
public:
    virtual double area() = 0;
};

class circle : public shape 
{
private:

    double radius;

public:
    circle(double r) 
    {
        radius = r;
    }

    double area()
    {
        return 3.1416 * radius * radius;
    }
};

class rectangle : public shape 
{
private:

    double length;
    double width;

public:
    rectangle(double l, double w) 
    {
        length = l;
        width = w;
    }

    double area() 
    {
        return length * width;
    }
};

int main() 
{
    circle c(5);
    rectangle r(4, 6);

    cout << "area of circle: " << c.area() << endl;
    cout << "area of rectangle: " << r.area() << endl;

    return 0;
}