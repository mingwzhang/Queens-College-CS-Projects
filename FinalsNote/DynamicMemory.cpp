#include <iostream>
#include <vector>
using namespace std;


int main()
{
    int *pia = new int [10];

    int *pia2 = new int [10](); // initialize all values to 10

    string *psa = new string[10];

    string *psa2 = new string[10](); // initialize 10 blocks of empty string

    
    
    pia2[0] = 8;
    pia2[1] = 2;
    pia2[2] = 4;
    pia2[3] = 5;

    pia[0] = 8;
    pia[1] = 2;
    pia[2] = 4;
    pia[3] = 5;

    delete[] pia;
    delete[] pia2;
    
    for(int x = 0; x < 10; x++)
    {
        cout << pia[x];
    }
    cout << endl;
    for(int x = 0; x < 10; x++)
    {
        cout << pia2[x];
    }
    return 0;
}