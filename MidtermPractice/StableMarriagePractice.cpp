#include <iostream>
using namespace std;

bool ok(int arr[], int col)
{
    int mp[3][3] = {0, 2, 1,
                    0, 2, 1,
                    1, 2, 0};
    int wp[3][3] = {2, 1, 0,
                    0, 1, 2,
                    2, 0, 1};

    for (int i = 0; i < col; i++)
    {
        int cm = arr[i];
        int cw = i;
        int nm = arr[col];
        int nw = col;

        if(arr[col] == arr[i])
        {
            return false;
        }

        if(mp[cm][nw] < mp[cm][cw] && wp[nw][cm] < wp[nw][nm])
        {
            return false;
        }
        if(mp[nm][cw] < mp[nm][nm] && wp[cw][nm] < wp[cw][cm])
        {
            return false;
        }
    }


    return true;
}

void print(int arr[])
{
    cout << "Man  "
         << "Woman" << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << i << "    " << arr[i] << endl;
    }
}

int main()
{
    int arr[3] = {0};
    int col = 0;

    while (col > -1)
    {
        if (col == 3)
        {
            print(arr);
            col--;
            arr[col]++;
        }
        else if (arr[col] == 3)
        {
            arr[col] = 0;
            col--;
            arr[col]++;
        }
        else if (ok(arr, col))
        {
            col++;
        }
        else
        {
            arr[col]++;
        }
    }
}