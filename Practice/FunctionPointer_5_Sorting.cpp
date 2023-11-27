#include <iostream>
#include <algorithm>
using namespace std;

bool ascending(int a, int b)
{
    return a < b;
}

bool descending(int a,  int b)
{
    return a > b;
}

void sorting(int* arr, int size, bool (*compare)(int, int))
{
    sort(arr, arr + size, compare);
}

int main ()
{
    int arr[] = {2,3,41,54,0};

    sorting(arr, 5, ascending);

    for(int x: arr)
    {
        cout << x << " ";
    }
    cout << endl;

    sorting(arr, 5, descending);

    for(int y: arr)
    {
        cout << y << " ";
    }
    cout << endl;

    return 0;
}