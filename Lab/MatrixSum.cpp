#include <iostream>
using namespace std;

int main()
{
    int a[3][3], b[3][3], c[3][3];

    cout << "Enter first matrix: " << endl;

    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            cin >> a[x][y];
        }
    }
    cout << "Enter second matrix: " << endl;

    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            cin >> b[x][y];
        }
    }
    cout << "Sum of matrices are: " << endl;
    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            c[x][y] = a[x][y] + b[x][y];
            cout << c[x][y] << " ";
        }
        cout << endl;
    }

    return 0;
}