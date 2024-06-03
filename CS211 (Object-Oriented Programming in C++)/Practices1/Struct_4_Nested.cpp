#include <iostream>
using namespace std;

struct Address
{
    string street;
    string city;
    int zip;
};

struct Person
{
    string name;
    string age;
    Address address;
};

int main()
{
    Person p;
    
    p.name = "Steve";
    p.age = 53;
    p.address = {"321 Ave", "NJ", 12324};

    cout << p.name << endl;
    cout << p.age << endl;
    cout << p.address.street << ", " << p.address.city << ", " << p.address.zip << endl;

    return 0;
}