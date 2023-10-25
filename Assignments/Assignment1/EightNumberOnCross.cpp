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
        {3, 4, 5, 6, -1},
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

void print(int q[], int solutionCount)
{
    cout << "Solution # " << solutionCount << endl;
    cout << "  " << q[0] << " " << q[1] << endl;
    cout << q[2] << " " << q[3] << " " << q[4] << " " << q[5] << endl;
    cout << "  " << q[6] << " " << q[7] << endl;
    cout << endl;
}



int main()
{
    int q[8] = {0};
    int index = 0;
    int solutionCount = 0;
    q[0] = 1;

    while (index >= 0)
    {
        if (index == 8)
        {
            solutionCount++;
            print(q, solutionCount);
            index--;
            q[index]++;
        }
        else if (q[index] == 9)
        {
            q[index] = 1;
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