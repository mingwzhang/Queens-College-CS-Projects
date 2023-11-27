#include <iostream>
using namespace std;
#include <vector>

int square (int a)
{
    return a * a;
}

void processData(int *arr, int size, int (*square)(int))
{
    for(int x = 0; x < size; x++)
    {
        cout << square(arr[x]) << " ";
    }
    cout << endl;
}

int main ()
{
    int arr[] = {2, 4, 5};

    processData(arr, 3, square);
    return 0;
}