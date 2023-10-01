#include <iostream>
using namespace std;

bool ok (int q[8])
{
    int c = 0;

    // Row Test
    for(int i = 0; i < c; i++)
    {
        if(q[i] == q[c])
        {
            //next row
        }
    }

    //Up Diagonal Test
    for(int i = 0; i < c; i++)
    {
        if((c-i) == q[c] - q[i])
        {
            //next row
        }
    }

    //Down Diagonal Test
    for (int i = 0; i<c; i++) {
	    if ((c-i) == q[i] - q[c])
        {
            //next row
        }
    }

}

}

int PrintBoard(int q[8])
{
    int board[8][8] = {0};

    for(int i = 0; i < 8; i++)
    {
        board[q[i]][i] = 1;
    }

    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{

    int q[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    int c = 0;
    int r = 0;
    PrintBoard(q);
    for (int i0 = 0; i0 < 8; i0++)
        for (int i1 = 1; i1 < 8; i1++)
            for (int i2 = 2; i2 < 8; i2++)
                for (int i3 = 3; i3 < 8; i3++)
                    for (int i4 = 4; i4 < 8; i4++)
                        for (int i5 = 5; i5 < 8; i5++)
                            for (int i6 = 6; i6 < 8; i6++)
                                for (int i7 = 7; i7 < 8; i7++)
                                {
                                    q[0] = i0;
                                    q[1] = i1;
                                    q[2] = i2;
                                    q[3] = i3;
                                    q[4] = i4;
                                    q[5] = i5;
                                    q[6] = i6;
                                    q[7] = i7;

                                    if(ok(q))
                                    {
             //                           PrintBoard(q);
                                    }
                                }

    return 0;
}