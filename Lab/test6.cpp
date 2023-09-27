#include <iostream>

using namespace std;

int secondLargest(int arr[], int size)
{
    int max = arr[0];
    int second_max = arr[0];

    for(int i = 0; i  <size; i++)
    {
        if(arr[i] > max) 
        {
            second_max = max;
            max = arr[i];
        }
        else if(arr[i] > second_max && arr[i] != max){
            second_max = arr[i];
        }
    }
    second_max = arr[0];

    return second_max;
}


bool isSorted(int arr[], int size)
{
    for(int i=1; i < size; i++)
    {
        if(arr[i] < arr[i-1]) return false;
    }
    return true;
}
int main()
{
    
    
}