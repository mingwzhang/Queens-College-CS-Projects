#include <iostream>;
using namespace std;

int main()
{
    /*
    int i  = 23;
    int j = 20;
    int* ptr;
    ptr = &i;
    *ptr = 30;   //dereference
cout << ptr << endl;
cout << *ptr << endl;
*/

    bool c  = false;
    int i = 30;
    int* ptr1 = &i;
    bool* ptr2 = &c;
    cout << "i's address: " << ptr1 << endl;
    cout << "i's address + 1: " << ptr1 + 1 << endl;
    cout << "c's address: " << ptr2 << endl;
    cout << "c's address+ 1: " << ptr2 + 1 << endl;
}