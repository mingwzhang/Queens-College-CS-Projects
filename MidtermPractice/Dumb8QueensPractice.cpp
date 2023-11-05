#include <iostream>
using namespace std;

bool Okay(int arr[])
{
    for(int c = 7; c > 0; c--)
    {
        for(int i = 0; i < c; i++)
        {
            if(arr[i] == arr[c] || (c - i) == abs(arr[i] - arr[c]))
            {
                return false;
            }
        }
    }
    return true;

}
void Print(int count, int arr[])
{
    cout << "Solution #: " << count << endl;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if(arr[i] == j)
            {
                cout << "1 ";
            }else{
                cout << "0 ";
            }
        }
        cout << endl;
    }
}


int main()
{
    int arr[8] = {0};
    int row = 0;
    int col = 0;
    int count = 0;
    for (int i0 = 0; i0 < 8; i0++)
    {
        for (int i1 = 0; i1 < 8; i1++)
        {
            for (int i2 = 0; i2 < 8; i2++)
            {
                for (int i3 = 0; i3 < 8; i3++)
                {
                    for (int i4 = 0; i4 < 8; i4++)
                    {
                        for (int i5 = 0; i5 < 8; i5++)
                        {
                            for (int i6 = 0; i6 < 8; i6++)
                            {
                                for (int i7 = 0; i7 < 8; i7++)
                                {   
                                    arr[0] = i0;
                                    arr[1] = i1;
                                    arr[2] = i2;
                                    arr[3] = i3;
                                    arr[4] = i4;
                                    arr[5] = i5;
                                    arr[6] = i6;
                                    arr[7] = i7;

                                    if(Okay(arr))
                                    {
                                        count++;
                                        Print(count, arr);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}