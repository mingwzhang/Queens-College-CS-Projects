#include <iostream>
using namespace std;
#include <vector>

int main ()
{
    vector <string> v = {"ewr","213","sade","gthr"};

    while (!v.empty())
    {
        cout << v.back();
        v.pop_back();
        cout << endl;
    }

    cout << v.size();


    return 0;
}