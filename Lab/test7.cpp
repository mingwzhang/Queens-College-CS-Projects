#include <iostream>
using namespace std;

int main()
{
    int b[8] = {};
    int col = 0;
    int config = 0;

    b[0] = 0;

nc: col++;
    if(col == 8) goto print;
    b[col] = -1;
nr: b[col]++;
    if(b[col] == 8) goto backtrack;
    for(int i = 0; i < col; i++)
    {
        if(b[i] == b[col] || (col - i) == abs(b[i] - b[col]))
            goto nr;
    }
    goto nc;

backtrack:
    b[col] = 0;
    col--;
    if(col == -1) return 0;
    goto nr;

print:
    config++;
    cout << 0;
}