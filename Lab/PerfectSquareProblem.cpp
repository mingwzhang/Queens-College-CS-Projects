#include <iostream>
#include <cmath>
using namespace std;

bool IsLastTwoDigitsOdd(int x)
{
    return x % 2 == 1 && (x / 10) % 2 == 1;   // Checks first and second digits
}

/*Test whether value is even or odd
If it has at least 2 digits -> you need a way of chopping it off
*/


int main()
{
    int i;
    cout << "Enter a value: ";
    cin >> i;

    int perfectSqr = pow(i,2);
    cout << "The perfect square of " << i << " is " << perfectSqr << endl;

    if(IsLastTwoDigitsOdd(perfectSqr%100) == true)
    {
        cout << "The last two digit of " << perfectSqr << " are both odd";
    }else{
        cout << "Both of the last two digit of " << perfectSqr << " are not odd";
    }
    return 0;
}
