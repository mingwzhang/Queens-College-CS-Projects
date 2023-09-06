#include <iostream>
#include <cmath>
using namespace std;


void changeThisValue(int x, int y)
{
    x = 10;
    return;
}


bool nameOfFunct (int x, int y, int z)
{
    if(x > y)
        if(y < z)
            return true;
    return false;
}

int main()
{
    int w;
    double x;
    bool y;
    char z;

    int a = 100;
    int b = 10;
    changeThisValue(100, b);
    cout << a;

    cout << "x " << sizeof(w)<<endl;
    cout << "x " << sizeof(x)<<endl;
    cout << "y " << sizeof(y)<<endl;
    cout << "z " << sizeof(z)<<endl;   //sizeof: the size in bytes of a data type or an object

    int a[] = {1,2,3,4};
    int b[20];

    bool arr[] = {true, false, true};
    if(true){

    }else if(true){

    }else{

    }

    int i = 0;

    while(i < 5)
    {
        cout << "In loop" << endl;
        i++;
    }

    for(int i = 0; i < 5; i++)
    {

    }

    for(bool i: arr)
    {

    }
}