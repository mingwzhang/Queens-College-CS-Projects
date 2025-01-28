#include <iostream>
using namespace std;

    typedef double (*FUNC)(double);
    
    double line (double x) {return x;}

    double square (double x) {return x * x;}

    double cube (double x) {return x * x * x;}

    double integrate(FUNC f, double a, double b)
    {
        double sum = 0;
        double x = 0.0001;
        while(a < b)
        {
            a += x;
            sum += f(a) * x;
        }
        return sum;
    }


int main(){

    cout << "The integral of f(x)=x between 1 and 5 is: " << integrate(line, 1, 5)<<endl;
    cout << "The integral of f(x)=x^2 between 1 and 5 is: " << integrate(square, 1, 5)<<endl;
    cout << "The integral of f(x)=x^3 between 1 and 5 is: " << integrate(cube, 1, 5)<<endl;

    return 0;
}