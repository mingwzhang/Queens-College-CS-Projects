#include <iostream>
using namespace std;
#include <vector>

struct Point{
    int x;
    int y;

};

int main ()
{
    vector <Point> v = {{1,2}, {3,4}, {10,0}};

    for(const Point& p: v)
    {
        cout << p.x << ", " << p.y;
        cout << endl;
    }


    return 0;
}