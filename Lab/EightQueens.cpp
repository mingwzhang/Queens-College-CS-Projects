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
    int r = 0, c = 0;
    int solution = 0;

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
    r = -1;
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
        return 0;
    }
    r = 0;
    goto check_queen;
execution_complete:
    if(c == 0 & r > 7)
    {
        cout << "Execution Complete" << endl;
    }
} 
