#include <iostream>
using namespace std;

int main()
{

    int arr[8][8] = {0};

    int row = 0;
    int col = 0;
    int count = 0;

IsOkay:
    for (int i = 0; i < col; i++)
    {
        if (arr[row][i] == 1)
        {
            goto AddRow;
        }
    }
    for (int i = 1; (row - i >= 0) & (col - i >= 0); i++)
    {
        if (arr[row - i][col - i] == 1)
        {
            goto AddRow;
        }
    }
    for (int i = 1; (row + i < 8) & (col - i >= 0); i++)
    {
        if (arr[row + i][col - i] == 1)
        {
            goto AddRow;
        }
    }
    arr[row][col] = 1;
    goto AddCol;

AddRow:
    row++;
    if (row == 8)
    {
        goto Backtrack;
    }
    goto IsOkay;

AddCol:
    col++;
    row = 0;
    if (col == 8)
    {
        goto GetSolution;
    }
    goto IsOkay;

Backtrack:
    col--;
    row = 0;
    if(col == -1)
    {
        goto Done;
    }
    while (arr[row][col] != 1)
    {
        row++;
    }
    arr[row][col] = 0;
    goto AddRow;

GetSolution:
    count++;
    cout << "Solution #: " << count << endl;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    goto Backtrack;
Done:
    return 0;
}