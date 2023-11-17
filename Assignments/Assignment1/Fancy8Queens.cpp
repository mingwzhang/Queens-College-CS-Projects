#include <iostream>
using namespace std;

void Print(int q[], int solCount)
{
    cout << "Solution #" << solCount << endl;

    int i,j,k,l;

    typedef char box[5][7];

    box bb, wb, *board[8][8];

    // white and black queens set up
    box bq = {{char(219),char(219),char(219),char(219),char(219),char(219),char(219)},      
              {char(219),' '      ,char(219),' '      ,char(219),' '      ,char(219)},
              {char(219),' '      ,' '      ,' '      ,' '      ,' '      ,char(219)},
              {char(219),' '      ,' '      ,' '      ,' '      ,' '      ,char(219)},
              {char(219),char(219),char(219),char(219),char(219),char(219),char(219)}};

    box wq = {{' '      ,' '      ,' '      ,' '      ,' '      ,' '      ,' '      ,},
              {' '      ,char(219),' '      ,char(219),' '      ,char(219),' '      ,},
              {' '      ,char(219),char(219),char(219),char(219),char(219),' '      ,},
              {' '      ,char(219),char(219),char(219),char(219),char(219),' '      ,},
              {' '      ,' '      ,' '      ,' '      ,' '      ,' '      ,' '      ,}};

    // fill in bb = black box and wb = white box
    for(i = 0; i < 5; i++)
        for(j = 0; j < 7; j++)
        {
            wb[i][j] = ' ';
            bb[i][j] = char(219);
        }

    // fill board with pointers to bb and wb in alternate positions (bq and wq as well)
    for(i = 0; i < 8; i++)
    {
        for(j = 0; j < 8; j++)
            if((i + j) % 2 == 0)
                if (q[i] == j) 
                    board[i][j] = &wq;
                else 
                    board[i][j] = &wb;
            else
                if (q[i] == j) 
                    board[i][j] = &bq;
                else
                    board[i][j] = &bb;
    }

    //print the board via the pointers in array board
    //first print upper border
    cout << "  ";
    for(i = 0; i < 7*8; i++)
        cout << '_';
    cout << endl;

    //print board
    for(i = 0; i < 8; i++)
        for(k = 0; k < 5; k++)
        {
        cout << " " << char(179);    //print left border
        for(j = 0; j < 8; j++)
            for(l = 0; l < 7; l++)
                cout << (*board[i][j])[k][l];
        cout << char(179) << endl;  //at end of line print bar and then new line
        }
    
    //before exiting print lower border
    cout << "  ";    
    for(i = 0; i < 7*8; i++)
        cout << char(196);
    cout << endl;
}

bool ok(int q[], int c)
{
    // Up Diagonal, Down Diagonal, and Row Test
    for (int i = 0; i < c; i++)
    {
        if ((c - i) == q[c] - q[i] || (c - i) == q[i] - q[c]|| q[i] == q[c])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int board[8] = {0}, col = 0;           

    int solutionCount = 0;                 

    while (col >= 0)                        
    { 
        if (col == 8)                       
        {
            solutionCount++;
            Print(board, solutionCount);    
            col--;                        
            board[col]++;
        }
        else if (board[col] == 8)          
        {     
            board[col] = 0;              
            col--;                             
            board[col]++; 
        }
        else if (ok(board, col))         
        {
            col++;                        
        }
        else
        {
            board[col]++;             
        }
    }
    return 0;
}
