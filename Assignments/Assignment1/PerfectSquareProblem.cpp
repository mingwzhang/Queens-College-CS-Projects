#include <iostream>
using namespace std;

bool IsLastTwoDigitsOdd(int x)
{
    return x % 2 == 1 && (x / 10) % 2 == 1; // Checks last two digits of a value
}

int main()
{
    string result;
    bool twoDigitsOdd = false;
    float i = 0;

    cout << "Finding the first perfect square whose last two digits are both odd..."  << endl;

    while (!twoDigitsOdd)
    {
        if(IsLastTwoDigitsOdd(i * i))
        {
            cout << "The first perfect square whose last two digits are both odd: " << i * i << endl;
            twoDigitsOdd = true;
            break;
        }
        i++;
    }

    if (!twoDigitsOdd) cout << "Cannot find the expected value.";

    return 0;
}
