#include <iostream>
#include <vector>
using namespace std;

struct test
{
    string name;
    int score;
    char letter;

};

int main()
{

    //vector
    vector <int> i[3];
    i[0].push_back(3);
    i[0].push_back(2);
    cout << i[0].back() << endl;



    // dynamic memory;
    int* d = new int[10]();
    d[0] = 5;

    cout << d[0] << endl;
    delete[] d;
    cout << d[0] << endl;

    
    //struct
    test t = {"Ray", 50, 'F'};

    cout << t.name << endl;
    cout << t.score << endl;
    cout << t.letter << endl;


    return 0;
}