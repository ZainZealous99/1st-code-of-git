#include <iostream>
using namespace std;

class employee 
{
public:

    virtual double calculatesalary() = 0;
};

class fulltimeemployee : public employee 
{
private:

    double salary;

public:
    fulltimeemployee(double s) 
    {
        salary = s;
    }

    double calculatesalary()
    {
        return salary;
    }
};

class parttimeemployee : public employee 
{
private:

    double hours;
    double rate;

public:
    parttimeemployee(double h, double r) 
    {
        hours = h;
        rate = r;
    }

    double calculatesalary() 
    {
        return hours * rate;
    }
};
int main() 
{
    fulltimeemployee f(50000);
    parttimeemployee p(20, 500);

    cout << "Full time salary of employee is this:" << f.calculatesalary() << endl;
    cout << "Part time salary of employee is this:" << p.calculatesalary() << endl;

    return 0;
}
