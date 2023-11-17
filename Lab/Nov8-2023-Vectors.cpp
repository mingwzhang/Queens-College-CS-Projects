#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v1;
    vector<bool> v2;
    vector<char> v3;

    /*
        3 operators
        fill the vectors with values
    */
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);

    /*
        Getting something from the vector
    */

    int i;
    i = v1.back();

    cout << v1[0] << endl;
    cout << v1[1] << endl;
    cout << v1.back() << endl;

    //Remove something
    cout << "Before: " << v1.back() << endl; // pushback and pop back are void. They dont return anything back with cout << . TO call them you use .back()
    v1.pop_back();
    cout << "After: " << v1.back() << endl;

    v1.size();   // To find out how big the vector is


//////////////////////////////////////////////////////////////////////////////////
    int q[] = {1,2,3,4,5};

    vector<int> v4;

    for(int i = 0; i < 5; i++)
    {
        v4.push_back(q[i]);
    }
    for(int i = 0; i < 5; i++)
    {
        q[i]  = v4.back();
        v4.pop_back();
    }

    for(int i =0;i < 5;i++)
    {
        cout << q[i] << endl;
    }
    


    return 0;
}