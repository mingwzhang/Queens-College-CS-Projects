#include <iostream>
using namespace std;

struct Rectangle
{
    double length;
    double width;
    double area()
    {
        return length * width;
    }
};

int main()
{
    Rectangle r;

    r.length = 2;
    r.width = 4;
    cout << r.length << endl;
    cout << r.width << endl;
    cout << r.area() << endl;

    return 0;
}