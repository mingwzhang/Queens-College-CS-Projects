#include <iostream>
#include <vector>
using namespace std;

int main() {
   vector<int> t[3];
   int arr[3] = {};
   for (int i = 0; i <= 3; i++)
    {
        t[0].push_back(i);
    }

   for (int i = 0; i < 3; i++)
    {
        cout<< t[0].back() << endl;
        t[0].pop_back();
       cout << "   " << arr[0] << "   " << arr[1] << "   "  << arr[2] << endl;
    }
   return 0;
}