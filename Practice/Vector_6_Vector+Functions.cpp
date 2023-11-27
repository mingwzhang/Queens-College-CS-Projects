#include <iostream>
using namespace std;
#include <vector>

void sum(const vector<int>& v)
{
    int sum = 0;
    for(int x: v)
    {
        sum += x;
    }
    cout << sum;
}

int main ()
{
    vector<int> v = {1, 2, 3, 4, 5, 6};

    sum(v);


    return 0;
}