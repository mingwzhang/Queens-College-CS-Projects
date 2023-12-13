#include <iostream>
using namespace std;

int main()
{
    //Dynamic array = use it if you don't know the size of array
    // int *p = new int [i];       i = some value
    // delete [] p;

    // fib(n) = fib(n-1) + fib(n-2)

    
    /*
    static int memo[300] = {0};

    int fib(int n)
    {
        if(n == 0 || n == 1)
            return 1;
        if(memo[n] == 0)
            memo[n] = fib[n-1] + fib[n-2];
        return memo[n];
    }
    
    */

   /*
    class Rat {
        private:
            int n;
            int d;
        public:
            Rate(int numerator, int denominator)
            {
                n = numerator;
                d = demoninator;
            };   

            Rat()
            {
                n = 0;
                d = 1;
            }

            // overload + function
            Rat operator+(Rat x)
            {
                int num = n + x.n;
                int den = d + x.d;
                return Rat(num, den);
            }
    }
   */

}