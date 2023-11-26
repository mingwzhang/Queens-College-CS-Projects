#include <iostream>
using namespace std;
#include <cmath>

struct Circle
{
    double radius;
};

double Circumference (Circle c)
{
    return 2 * 	3.1415926	 * c.radius;
}

int main()
{
    Circle c;
    c.radius = 5.0;


    cout << Circumference(c);
    return 0;
}