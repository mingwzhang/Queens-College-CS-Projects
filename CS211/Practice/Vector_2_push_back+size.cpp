#include <iostream>
using namespace std;
#include <vector>

int main ()
{
    cout << "Input: " << endl;
    
    int i;
    vector <int> v;

    for(int x = 0; x < 5; x++)
    {
        cin >> i;
        v.push_back(i);
    }

    cout << "Size: " << v.size() << endl;

    for(int y: v)
    {
        cout << y << " ";
    }
    cout << endl;
}