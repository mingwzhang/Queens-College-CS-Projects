#include <iostream>
using namespace std;

void binaryString(int n, string str)
{
    if (n == 0)
    {
        cout << str << endl;
        return;
    }
    binaryString(n - 1, str + "0");
    binaryString(n - 1, str + "1");
}
int main()
{
    int n;
    cout << "Enter length of binary strings: ";
    cin >> n;
    binaryString(n, "");
    return 0;
}