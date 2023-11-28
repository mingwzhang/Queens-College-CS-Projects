#include <iostream>
using namespace std;

struct book
{
    string title = "The Axe";
    string author = "Cena";
    int page = 10;

};

struct rectangle
{
    double length = 2; 
    double width = 4;
    double getArea()
    {
        return length * width;
    }
};

struct student
{
    string name;
    int age;
    char grade;
};

struct Address
{
    string street;
    string city;
    int zipcode;
};

struct Person{
    string name;
    int age;
    Address address;
};

int add(int a, int b)
{
    return a + b;
}

int main()
{
    struct book bk;

    cout << bk.title << endl;
    cout << bk.author << endl;
    cout << bk.page << endl;
    cout << endl;

    struct rectangle rect;
    cout << rect.width << endl;
    cout << rect.length << endl;
    cout << rect.getArea() << endl;
    cout << endl;

    struct student std[3];
    std[0] = {"Bbb", 21, 'A'};
    std[1] = {"Cena", 12, 'B'};
    std[2] = {"Vip", 65, 'C'};

    for(int x = 0; x < 3; x++)
    {
        cout << std[x].name << " ";
        cout << std[x].age << " ";
        cout << std[x].grade << " ";
        cout << endl;
    }

    Person person;
    person.name = "John Doe";
    person.age = 11;
    Address a = {"123, Random St", "Ny", 10023};
    person.address =  {"11023, Jon St", "Nj", 13203};
    cout << person.address.city << endl;

    int(*functPtr)(int,int) = add;
    cout << (*functPtr)(3,4);

    
}