#include <iostream>
using namespace std;

bool ok(int q[], int c)
{
    int adj[8][5] = {
        {-1},
        {0, -1},
        {0, -1},
        {0, 1, 2, -1},
        {0, 1, 3, -1},
        {1, 4, -1},
        {2, 3, 4, -1},
        {3, 4, 6, -1},
    };

    for (int i = 0; adj[c][i] != -1; i++)
    {
        if (abs(q[c] - q[adj[c][i]]) == 1)
        {
            return false;
        }
    }

    for (int i = 0; i < c; i++)
    {
        if (q[c] == q[i])
        {
            return false;
        }
    }

    return true;
}

void print(int q[])
{
    cout << "\t " << q[0] << "\t " << q[1] << endl;
    cout << q[2] << "\t " << q[3] << "\t " << q[4] << "\t " << q[5] << endl;
    cout << "\t " << q[6] << "\t " << q[7] << endl;
}

int main()
{
    int q[8] = {0};
    int index = 0;

    while (index >= 0)
    {
        if (index == 8)
        {
            print(q);
            index--;
            q[index]++;
        }
        else if (q[index] == 7)
        {
            q[index] == 0;
            index--;
            q[index]++;
        }
        else if (ok(q, index))
        {
            index++;
        }
        else
        {
            q[index]++;
        }
    }
    return 0;
}