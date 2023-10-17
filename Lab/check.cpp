#include <iostream>
using namespace std;

int main()
{
   int x = 42;
   int* y = &x;

   cout << *y << endl;
   cout << y << endl;

   return 0;
}