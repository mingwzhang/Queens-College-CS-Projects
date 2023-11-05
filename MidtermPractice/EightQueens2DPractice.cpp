#include <iostream>
using namespace std;

bool ok(int col, int row, int arr[8][8])
{

    for(int i = 0; i < col; i++)
    {
        if(arr[row][i] == 1)
        {
            return false;
        }
    }

    for(int i = 1; (row - i >= 0) & (col - i >= 0); i++)
    {
        if(arr[row-i][col-i] == 1)
        {
            return false;
        }
    }

    for(int i = 1; (row + i < 8) & (col - i >= 0); i++)
    {
        if(arr[row+i][col-i] == 1)
        {
            return false;
        }
    }
    return true;
}

void Print(int count, int arr[8][8])
{
    cout << "Solution #: " << count << endl;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int arr[8][8] = {0};

    int row = 0;
    int col = 0;
    int count = 0;
    while (col > -1)
    {
        if (col == 8)
        {
            count++;
            Print(count, arr);
            col--;   // Backtrack
            row = 0;
            while(arr[row][col] != 1)
            {
                row++;
            }
            arr[row][col] = 0; 
            row++;            
        }
        else if (row == 8)
        {
            col--;   // Backtrack
            row = 0;
            while(arr[row][col] != 1)
            {
                row++;
            }
            arr[row][col] = 0; 
            row++;
        }
        else if (ok(col, row, arr))
        {
            arr[row][col] = 1;
            row = 0;
            col++;
        }
        else
        {
            row++;
        }
    }

    return 0;
}