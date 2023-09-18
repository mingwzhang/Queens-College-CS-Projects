#include <iostream>
using namespace std;
bool IsLastTwoDigitsOdd(int x)
{
    return x % 2 == 1 && (x / 10) % 2 == 1; // Checks last two digits of a value
}
int main()
{
    string result;
    bool foundPerfectSqr = false;
    float i = 0;
    cout << "Finding the first perfect square whose last two digits are both odd..." << endl;
    while (!foundPerfectSqr)
    {
        if (IsLastTwoDigitsOdd(i * i))
        {
            cout << "The first perfect square whose last two digits are both odd: " << i * i << endl;
            foundPerfectSqr = true;
            break;
        }
        i++;
    }
    if (!foundPerfectSqr)
        cout << "Cannot find the expected value.";
    return 0;
}