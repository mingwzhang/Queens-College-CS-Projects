#include <iostream>
using namespace std;

struct pet {
    string animalType;
    string name;
    int age;
};


class Lightbulb{
    private:
    public: 
    protected:
};

struct car{
    int miles; // 4 bytes
    unsigned long long age; // 8 byte
    int numWheel; // 4 byte
};

int main()
{
    pet pet1 = {"Cat", "John", 6};
    car car1 ;

    cout << pet1.name << endl;
    cout << sizeof(car1) << endl;
    
    return 0;
}