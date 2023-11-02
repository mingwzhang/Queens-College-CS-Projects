#include <iostream>
using namespace std;

bool IsLastTwoOdd(int i)
{
    return ((i / 10) % 2 == 1) & (i %2 == 1);      // FInd Odds
}   

void PrintLastTwoDigits(int i )
{
    cout << ((i / 10) % 10)  <<  (i % 10);   //Print last two digits
}

int main()
{

    int input;
    cout << "Input: " << endl;
    cin >> input;

        if(input > 9 & IsLastTwoOdd(input))
        {
            cout << "Output of last two are odd: " << endl;
            PrintLastTwoDigits(input);
            return false;

        }else{
            cout << "Invalid Input ";
            cout << ((input / 10) % 2 ) << (input %2 );
            return false;
        }

    return 0;
}