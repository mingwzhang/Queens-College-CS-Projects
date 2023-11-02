#include <iostream>
using namespace std;

int main()
{
    int win[6] = {0};
    for (int i5 = 0; i5 < 10; i5++)
    {
        for (int i4 = 0; i4 < 10; i4++)
        {
            for (int i3 = 0; i3 < 10; i3++)
            {
                for (int i2 = 0; i2 < 10; i2++)
                {
                    for (int i1 = 0; i1 < 10; i1++)
                    {
                        for (int i0 = 0; i0 < 10; i0++)
                        {
                            win[5] = i0;
                            win[4] = i1;
                            win[3] = i2;
                            win[2] = i3;
                            win[1] = i4;
                            win[0] = i5;

                            cout << win[0]<< win[1]<< win[2]<< win[3]<< win[4]<< win[5];
                            cout << endl;
                        }
                    }
                }
            }
        }
    }

    return 0;
}