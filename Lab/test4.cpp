#include <iostream>
using namespace std;

main()
{
    int b[4][4] = {};
    int row = 0;
    int col = 0;

    b[col][row] = 0;

    b[1][0] = 1;
    col++;
    // User Input
    cout << "Enter the row number for column that you want to check: ";
    cin >> row;

    /* //Row test
        for (int x = 0; x < col; x++)
        {
            if(b[row][x] == 1)
            {
                cout << "Cannot place queen in that row: " << row << endl;
                return 0;
            }
        }
    */

    // Up diagional test
    for (int i = 1; (row - i) >= 0 && (col - i) >= 0; i++)
    {
        if (b[row - i][col - i] == 1)
        {
            cout << "Cannot work";
        }
    }

    // Down diagional test
    for (int i = 1; (row + i) <= 4 && (col - i) >= 0; i++)
    {
        if (b[row + i][col - i] == 1)
        {
            cout << "Cannot work";
        }
    }

    cout << "You can put the queen in that row";
}
