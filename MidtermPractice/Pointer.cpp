# include <iostream>
using namespace std;


void change(int &a)
{
    a = 3;
    a++;
}

int main()
{
    int* i;
    int j = 2;

    i = &j;
    cout << *i  << endl;
    
    int a = 1;
    change(a);
    cout << a << endl;

    int nums[3] = {1,2,3};
    *(nums+1) = 12;
    cout << nums[1] << endl;
    unsigned long long addr1_int = (unsigned long long) (nums + 0); 
    unsigned long long addr2_int = (unsigned long long) (nums + 1); 
    cout << *(nums + 1) << endl; 
    cout << addr2_int-addr1_int << endl; 

    int b;
    int* ptr;
    ptr = &b;
    *ptr = 10;

    cout << b << endl; 

    return 0;
}