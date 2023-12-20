#include <iostream>

using namespace std;
 
void f(int i, int a, int b) {
	if (a < i) {
		cout << a << endl;
		f(i, b, b+b);
		/*
		b+b is not a mistake, notice the following:
		
		a = b; //a gets the value of b
		b = a + b; //Since (a = b), b = (a + b) = (b + b)
		*/
	}
}
 
int main(){ 
    for	(int i = 1; i < 50; ++i) { 
    	cout << "i = " << i << endl; 
    	f(i, 0, 1); 
        cout << endl; 
	} 
	
	return 0; 
} 