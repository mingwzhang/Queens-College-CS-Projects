#include <iostream>
using namespace std;

int main()
{
    int i,j,k,l;
    char c = ' ';

    //Print board
    for(int i = 0; i < 8; i++)
        for(int k = 0; k < 5; k++)
        {
            for(int j = 0; j < 8; j++)
            {
                if((i + j) % 2 == 0)
                    c = char(179);
                else
                    c = ' ';
                for(l = 0; l < 7; l++)
                    cout << c;
            }
            cout << char(179); cout << endl;
        }
    for(int i = 0; i < 7*8 + 1; i++)
        cout << char(196);
    cout << endl;

    return 0;
}
