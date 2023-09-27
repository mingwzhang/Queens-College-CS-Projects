#include <iostream>
using namespace std;
#include<algorithm>

int* SortedArray (int arr[10], int size)
{
    for(int x = 0; x < size-1; x++)
    {
        for(int y = 0; y < size-x-1; y++)
        if(arr[y] > arr[y+1])
        {
            int temp = arr[y];
            arr[y] = arr[y+1];
            arr[y+1] = temp;
        }
    }

    return arr;
}

int SecondLargest(int arr[10], int size)
{
    return SortedArray(arr, size)[size-2];
}



bool IsNonDecreasingOrder(int arr[10], int size)
{
    for(int x = 0; x < size-1; x++)
    {
        if(arr[x] > arr[x+1])
        {
            return false;
        }
    }
    return true;
}

bool ok(int arr[10], int size)
{
    for(int x = 0; x < size; x++)
    {
        if(arr[x] % 2 == 1)
        {
            return false;
        }
    }
        return true;

}

int main()
{
    int arr[10] = {7,2,3,1,4,0,6,2,10,0};

    int output = 0;
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << IsNonDecreasingOrder(arr, size) << " "<< endl;   
    cout << SecondLargest(arr, size) << " " << endl;
    cout << ok(arr, size) << " " << endl;
    for(int x = 0; x < size; x++)
    {
        cout << SortedArray(arr, size)[x] << " ";
    }
    return 0;


}