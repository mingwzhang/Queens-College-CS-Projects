#include <iostream>
using namespace std;

struct example
{
    int id;
};

typedef int *pr;
int main()
{
    typedef char box[3][7];

    struct example ex;    
    ex.id = 111;

    cout << ex.id << endl;

    pr pvar;


    return 0;
}