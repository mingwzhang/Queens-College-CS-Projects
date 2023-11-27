#include <iostream>
using namespace std;

int add(int a, int b)
{
    return a + b;
}

int multiply(int a, int b)
{
    return a * b;
}

int compute(int a, int b, int(c)(int, int))
{
    return c(a, b);
}

int main()
{
    cout << compute(2, 5, add) << endl;
    cout << compute(2, 5, multiply) << endl;

    return 0;
}