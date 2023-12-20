#include <iostream>
#include <vector>
using namespace std;


int Fib(int i)
{
    vector<int> fib(i+2);
    fib[0] = 0;
    fib[1] = 1;

    for (int x = 2; x <= i; x++) {
        fib[x] = fib[x - 1] + fib[x - 2];
        cout << endl;
        cout << fib[x] << "?"<< endl;
    }

    return fib[i];

}

int main()
{
    int i;

    cout << "Input: ";
    cin >> i;

    for(int x = 0; x <= i; x++)
    {
        cout << Fib(x) << ", ";
    }
}