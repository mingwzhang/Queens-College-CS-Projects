#include <iostream>
#include <vector>
using namespace std;

class Rat
{
private:
    int n;
    int d;

public:
    Rat() {}
    Rat(int i)
    {
        n = i;
        d = i;
    }
    Rat(int i, int j)
    {
        n = i;
        d = j;
    }

    int getN() { return n; }
    int getD() { return d; }

    void setN(int i) { n = i; }
    void setD(int i) { d = i; }

    int gcd(int n, int d)
    {
        return d == 0 ? n : gcd(d, n % d);
    }

    void reduce()
    {
        int _gcd = gcd(n, d);
        n /= _gcd;
        d /= _gcd;
        if(d < 0)
        {
            n = -n;
            d = -d;
        }
    }

    Rat operator+(Rat r)
    {
        Rat t;
        t.n = n * r.d + d * r.n;
        t.d = d * r.d;
        t.reduce();
        return t;
    }

    Rat operator-(Rat r)
    {
        Rat t;
        t.n = n * r.d - d * r.n;
        t.d = d * r.d;
        t.reduce();
        return t;
    }

        Rat operator*(Rat r)
    {
        Rat t;
        t.n = n * r.n;
        t.d = d * r.d;
        t.reduce();
        return t;
    }
        Rat operator/(Rat r)
    {
        Rat t;
        t.n = n * r.d;
        t.d = d * r.n;
        t.reduce();
        return t;
    }
    friend ostream &operator << (ostream &os, Rat r);
    friend istream &operator >> (istream &is, Rat &r);
};




int main()
{
    Rat x(5, 2), y(3, 2), z;
    z = x + y;
    cout << z << endl;

    z = x - y;
    cout << z << endl;

    z = x * y;
    cout << z << endl;

    z = x / y;
    cout << z << endl;
}