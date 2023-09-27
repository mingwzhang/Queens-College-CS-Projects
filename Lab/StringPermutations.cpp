#include <iostream>
#include <string>
using namespace std;

void swap(char &a, char &b)
{
    char temp = a;
    a = b;
    b = temp;
}
void permute(string &str, int l, int r)
{
    if (l == r)
    {
        cout << str << endl;
        return;
    }
    else
    {
        for (int i = l; i <= r; i++)
        {
            swap(str[l], str[i]);
            permute(str, l + 1, r);
            swap(str[l], str[i]); // backtrack
        }
    }
}
int main()
{
    string str;
    cout << "Enter a string: ";
    cin >> str;
    cout << "All permutations of the string are: \n";
    permute(str, 0, str.length() - 1);
    return 0;
}