#include <iostream>
using namespace std;

int main()
{
    int arr[3][3];
    int largest = 0;
    cout << "Enter the element in matrix" << endl;

    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            cin >> arr[x][y];
        }
    }

    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            if (arr[x][y] > largest)
            {
                largest = arr[x][y];
            }
        }
    }

    cout << largest;

    return 0;
}