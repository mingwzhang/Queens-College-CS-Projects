#include <iostream>
using namespace std;

typedef float (*Operation) (float, float);
float divide (float a, float b) { return a / b;};


int main ()
{
    Operation op = divide;

    cout << op(21.0, 3.0);

    return 0;
}