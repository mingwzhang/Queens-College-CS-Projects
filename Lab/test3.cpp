#include <iostream>
using namespace std;

int main()
{

//    1. Set up the board and associated data structures
//     also set up the helper variables 
   int board[8][8] = {};

   int r = 0;
   int c = 0;   
   board[c][r] = 1;

//    2. Find a way to set the values

increment_column:
    c++;
    if (c == 8) {
       // tells us we are done
       // prints out your code
    }
    
    // Once you've incremented the column, start to rest row values
    r = -1;

increment_row:
    r++;
    if(r == 8)
    {
        // backtrack
        goto backtrack;
    }

    // 3. Test your configuration via the constraints
    /*
        a. check if they're on the same row
        b. check if they're on the same diagonal
    
    */

//    if(/*either test fails*/)
  //  {
    //    goto increment_row;
  //  }

    board[c][r] = 1;
    goto increment_column;

   // 4. If it works, print it and try to find another solution


   // 5. Loop until you either find all the solutions or you tried every possibility

backtrack:
    // go back a column
    c--;
    // find the queen
    r = -1;
    while(board[c][r] == 0)
    {
        r++;
    }

    board[c][r] = 0;
    goto increment_row;
}