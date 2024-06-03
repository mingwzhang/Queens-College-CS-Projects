#include <iostream>
using namespace std;

int add(int x, int y)
{
    return x + y;
}

int main ()
{   
    int (*a)(int, int) = add;
    cout << a(123,65);




    return 0;
}