#include <iostream>
#include <vector>
using namespace std;



int main()
{   
    vector<int> v1;
    v1.push_back(3);
    cout << v1.back() << endl;  // 3
    v1.push_back(2);
    cout << "size after adding 2: " << v1.size() << endl;
    cout << v1.back(); // 2
    v1.pop_back();
    cout << v1.back(); //3
    cout << v1.size() << endl;
    cout << endl;

    /*Mod Usage*/

    int arr[3] = {0};
    int n = 0;
    for(int i = 0; i < 100; i++)
    {
        arr[n] += 5;
        n++;
        n = n % 3;
    }
    n++;
    n % 3;

    for(int i = 0; i < 3; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}