#include <iostream>
using namespace std;
#include <vector>

int main ()
{
    vector <int> v = {123, 321 ,34, 123, 000};

    for(int i : v)
    {
        cout << i << endl;
    }
    return 0;
}