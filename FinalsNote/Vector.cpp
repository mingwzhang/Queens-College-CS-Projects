#include <iostream>
using namespace std;
#include <vector>


int main()
{
    vector<int> v = {1,2,3,4};

    v.push_back(5);
 
    for(int x: v)
    {
        cout << v.back();
        v.pop_back();
    }

}