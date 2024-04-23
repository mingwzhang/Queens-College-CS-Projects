using namespace std;
#include <iostream>
#include <vector>
#include <cstdlib> // For srand and rand
#include <ctime>   // For time

int main()
{
    srand(time(0));

    int arrTime = (rand() % 250) + 1;
    int cpuBurst = (rand() % 14) + 2;
    int priority = (rand() % 5) + 1;

    while(true)
    {
        arrTime = (rand() % 250) + 1;
        if(arrTime == 250) {
            cout <<  arrTime; break;
        }else{
            cout << arrTime << endl;
        }
        
    }
    return 0;
}