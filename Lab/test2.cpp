#include <iostream>
using namespace std;

/*
1. Structure to store all the values to output
2. Generate all the value
*/

void printArray(int arr[], int capacity)
{
    for(int i = 0; i < capacity; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
//

bool ok(int board[][8], int c)
{
    return true;
}

int main()
{
    int window[6] = {};

    for(int i0 = 0; i0 < 10; i0++)
    {
        for(int i1 = 0; i1 < 10; i1++)
        {
            window[0] = i0;
            window[1] = i1;
            printArray(window, 2);
        }   
    }

    int i = 3;
    goto PRINT;
    i = 200;
PRINT: cout << i << endl;

//=====================================================================

    int a = 0;
LOOP: a++;
    while(a < 5) goto LOOP;
    {
        a++;
    }
    cout << a << endl;

//=====================================================================

    //1. Initialize the strucctures and helper variables to repstesent out problem
    int board [8][8] = {};
    int row;
    int column;

    //3. Find a way to set the values of the structure
    // Example

    board[0][0] = 1;
    board[0][1] = 1;
    board[0][2] = 1;

    //3. Check whether or not it works

    if(ok(board, 8))
    {
        //4. printout the results
    }

    //5. Find a way to do this whole procedure again but with a new set values
    //keep doing this until you found all solutions or tried all possible values
}

