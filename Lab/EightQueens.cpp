#include <iostream>
using namespace std;

int main()
{

    int b[8][8] = {};
    int r = 0, c = 0;

//    b[r][c] = 1;
    goto check_queen;

check_queen:
    for (int i = 0; i <= c; i++)
    {
        if (b[r][i] == 1)
        {
            //         cout << "Cannot add Queen row" << endl;
            goto increment_row;
        }
    }
    for (int i = 1; (r - i >= 0) && (c - i >= 0); i++)
    {
        if (b[r - i][c - i] == 1)
        {
            //         cout << "Cannot add Queen upper diagonal" << endl;
            goto increment_row;
        }
    }
    for (int i = 1; (r + i < 8) && (c - i >= 0); i++)
    {
        if (b[r + i][c - i] == 1)
        {
            //           cout << "Cannot add Queen lower diagonal" << endl;
            goto increment_row;
        }
    }
    b[r][c] = 1;
    goto increment_column;

increment_row:
    if (r < 8)
    {
        r++;
        goto check_queen;
    }
    if (r == 8)
    {
        goto increment_column;
    } // backtrack

increment_column:
    if (c < 8)
    {
        r = 0;
        c++;
        goto increment_row;
    }
    if (c == 8)
    {
        cout << "Execution complete" << endl;
        for (int x = 0; x < 8; x++)
        {
            for (int y = 0; y < 8; y++)
            {
                cout << b[x][y] << " ";
            }
            cout << endl;
        }
        cout << r;
        cout << c;
        return 0;
    }
}
