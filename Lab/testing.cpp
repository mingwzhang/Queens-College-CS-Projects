#include <iostream>
using namespace std;

struct laptop
{
    string name;
    int batteryLife;
    string creator;
};

struct ligtbulb
{
    int modelNumber;
    string brand;
    int wattage;
};

struct test {
    long long field1; // 8 bytes
    int i; // 4 bytes
};

int main()
{
    laptop l1 = 
    {   
        "macbook air",
        30,
        "apple"
    };
    cout << l1.name << endl;
    cout << l1.batteryLife << endl;

    test variable1;
    long long variable2;
    int variable3;

    cout << sizeof(variable1) << endl; // 16 bytes
    cout << sizeof(variable2) << endl; // 8
    cout << sizeof(variable3) << endl; // 4
    return 0;

    // byte size
    // int = 4
    // bool = 1
    // char = 1

    // & - give address and element of pointer
    

}
