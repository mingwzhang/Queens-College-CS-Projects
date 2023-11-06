#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

int main()
{
    string a(8, '\xdb');
    string b(8, ' ');

    string line1 = a + b + a + b + a + b + a + b;
    string line2 = b + a + b + a + b + a + b + a;


    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << line1 << endl;
        }
        for (int j = 0; j < 4; j++)
        {
            cout << line2 << endl;
        }
    }

    return 0;
}
