#include <iostream>
using namespace std;

int Problem1(int n)
{
    int arr[5] = {};
    int last = 1;
    for (int x = n; x >= 0; x--)
    {
        arr[x] = 1;
    }

    for (int x = n; x > 0; x--)
    {
        arr[x - 1] = last;

        for (int y = 0; y < x; y++)
        {
            cout << arr[y];
        }
        cout << endl;

        if (arr[x - 1] > 2)
        {
            if (x >= 2)
            {
                for (int y = 0; y < x - 2; y++)
                {
                    cout << arr[y];
                }
                cout << arr[x - 2] + 1 << arr[x - 1] - 1 << endl;
            }
        }
        last = last + arr[x - 2];
    }
}

int Problem2(int arr[5],int size)
{
    cout << "Original Array:" << endl;
    for(int x = 0; x < size; x++)
    {
        cout << arr[x] << " ";
    }

    cout << endl;

    cout << "Reverse Array:" << endl;
    for(int y = size-1; y >= 2; y--)
    {
        cout << arr[y] << " ";
    }

    cout<< endl;
}

int Problem3(int arr[5],int size)
{
    for(int x = 0; x < size-1; x++)
    {
        for(int y = 0; y < size-x-1; y++)
        {
            if(arr[y] > arr[y+1])
            {
                int temp = arr[y];
                arr[y] = arr[y+1];
                arr[y+1] = temp;
            }
        }
    }

    for(int x = 0; x < 5; x++){
        cout << arr[x];
    }

    cout << endl;

    int count = 0;
    for(int x = 0; x < size; x++)
    {
        for(int y = x; y < size; y++)
        {
            if(arr[x] == arr[y])
            {
                count++;
            }
        }
        if(arr[x]==arr[x+1])
        {
            
        }
        cout << arr[x++] << " occurs " << count << " times" << endl;
        count = 0;
        
    }
}


int main()
{
    int n = 5;
    int arr[5] = {1,2,3,4,5};
    int arr1[5] = {1,2,1,4,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    int size1 = sizeof(arr1)/sizeof(arr1[0]);

    Problem1(n);
    Problem2(arr,size);
    
    Problem3(arr1, size1);

}