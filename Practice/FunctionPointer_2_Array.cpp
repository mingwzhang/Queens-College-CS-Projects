#include <iostream>
using namespace std;

int add(int a, int b)
{
    return a +  b;
}   

int subtract(int a, int b)
{
    return a - b;
}

int multiply(int a, int b)
{
    return a * b;
}

int main ()
{
    int(*arr[3])(int, int) = {add, subtract, multiply};

    for(int x = 0; x < 3; x++)
    {
        cout << arr[x](10, 5);
        cout <<endl;
    }
    


    return 0;
}