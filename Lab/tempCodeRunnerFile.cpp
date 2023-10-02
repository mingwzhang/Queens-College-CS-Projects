#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int c)
{
    // Row Test
    for (int i = 0; i < c; i++)
    {
        if (q[i] == q[c])
        {
            return false;
        }
    }
    // Up Diagonal Test
    for (int i = 0; i < c; i++)
    {
        if ((c - i) == q[c] - q[i])
        {
            return false;
        }
    }
    // Down Diagonal Test
    for (int i = 0; i < c; i++)
    {
        if ((c - i) == q[i] - q[c])
        {
            return false;
        }
    }
    return true;
}
void print(int q[], int solCount) {
    cout << "Solution #" << solCount << endl;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (q[i] == j) {
                cout << "1 ";
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
    cout << endl;
}


int main()
{
    int board[8] = {0}, col = 0;
    int solutionCount = 0;
    // put the queen in the upper left square
    // board[0] = 0; //b[0][0] = 1 in 2D version

    while (col >= 0)     // if we backtrack beyond the first col, we are done
    { 
        // if we have moved beyond the last column
        if (col == 8)
        {
            // print the board
            // backtrack
            solutionCount++;
            print(board, solutionCount);
            col--;
        }
        // If we have moved beyond the last row
        else if (board[col] == 8)
        {
            // reset queen
            // backtrack            
            board[col] = 0;
            col--; 
            if (col >= 0)
            {
                board[col]++; 
            }
        }
        // Check if the placed queen is ok.
        else if (ok(board, col))
        {
            col++;
    //        cout << col;
            // move to next column if ok
        }
        else
        {
            board[col]++;
            // move to next row if not ok
        }
    }
    return 0;
}