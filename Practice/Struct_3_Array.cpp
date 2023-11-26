#include <iostream>
using namespace std;

struct Student
{
    string name;
    int age;
    char grade;
};

int main()
{
    Student s[3] = 
    {
        {"Bob", 21, 'A'},
        {"Gaya", 12, 'C'},
        {"Abe", 34, 'B'},
    };

    for(int x = 0; x < 3; x++)
    {
        cout << s[x].name << endl;
        cout << s[x].age << endl;
        cout << s[x].grade << endl;
        cout << endl;
    }

    return 0;
}