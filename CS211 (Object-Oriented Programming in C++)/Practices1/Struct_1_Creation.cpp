#include <iostream>
using namespace std;

struct Book
{
    string title = "Boi";
    string author = "Kratos";
    int page = 21;
};

int main()
{
    Book b;

    b.title = "Deep"; 
    b.author = "Van";
    b.page = 20;
    cout << b.title << endl;
    cout << b.author << endl;
    cout << b.page << endl;

    return 0;
}