#include <iostream>
using namespace std;
#include <vector>



int main ()
{
    vector<double> v;
    double t;

    cout << "Enter 5 temperature values: " << endl;

    for(int x = 0; x < 5; x++)
    {
        cin >> t;
        v.push_back(t);
    }
    cout << endl;

    for(double& i: v)
    {
        i += 5.5;
        cout << i;
        cout << endl;
    }





    return 0;
}