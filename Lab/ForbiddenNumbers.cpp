#include <iostream>
using namespace std;


bool IsForbidden(int arr[14], int forbidNum[50])
{
 //   int size = sizeof(forbidNum) / sizeof(forbidNum[0]);

    for(int i = 0; i  < 14; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            if(arr[i] == forbidNum[j])
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int arr[14];
    int count = 0;
    int forbidNum[50] = { 7, 49, 73, 58, 30, 72, 44, 78, 23, 9, 40, 65, 92, 42, 87, 3, 27, 29, 40, 12, 3, 69, 9, 57, 60, 33, 99, 78, 16, 35, 97, 26, 12, 67, 10, 33, 79, 49, 79, 21, 67, 72, 93, 36, 85, 45, 28, 91, 94};


    while(count < 14)
    {
        arr[count] = count;

        if(IsForbidden(arr, forbidNum))
        {
            count--;
        }else{
            count++;
            cout << arr[count] << " " << endl;
        }
    }
}