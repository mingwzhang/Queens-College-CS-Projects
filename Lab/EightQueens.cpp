#include <iostream>
using namespace std;

void PrintSolution(int b[8][8], int solution)
{
    cout << "Solution #" << solution << endl;
    for (int x = 0; x < 8; x++)
    {
        for (int y = 0; y < 8; y++)
        {
            cout << b[x][y] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int b[8][8] = {};
    int r = 0, c = 7;
    int solution = 0;

/**/
    b[0][0] = 1;
    b[4][1] = 1;
    b[7][2] = 1;
    b[5][3] = 1;
    b[2][4] = 1;
    b[6][5] = 1;
    b[1][6] = 1;
    b[3][7] = 1;

    goto increment_column;

check_queen:
    for (int i = 0; i <= c; i++)
    {
        if (b[r][i] == 1)
        {
            goto increment_row;
        }
    }
    for (int i = 1; (r - i >= 0) && (c - i >= 0); i++)
    {
        if (b[r - i][c - i] == 1)
        {
            goto increment_row;
        }
    }
    for (int i = 1; (r + i < 8) && (c - i >= 0); i++)
    {
        if (b[r + i][c - i] == 1)
        {
            goto increment_row;
        }
    }
    b[r][c] = 1;
    goto increment_column;
    
backtrack:
    c--;
    if(c == -1)
    {
        goto execution_complete;
    }
    r = 0;

    while (b[r][c] != 1)
    {
        r++;
    }
    b[r][c] = 0;
    goto increment_row;
    
increment_row:
    r++;
    if (r == 8)
    {
        goto backtrack;
    }
    goto check_queen;
increment_column:
    c++;
    if (c == 8)
    {
        solution++;
        PrintSolution(b, solution);
        goto backtrack;
    }
    r = 0;
    goto check_queen;
execution_complete:
        cout << "Execution Complete" << endl;
        return 0;
} 
