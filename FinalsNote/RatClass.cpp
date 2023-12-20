#include <iostream>
#include <vector>
using namespace std;

class Rat
{
private:
    int n;
    int d;

public:
    // constructors
    Rat()
    {
        n = 0;
        d = 1;
    }
    Rat(int i, int j)
    {
        n = i;
        d = j;
    }
    Rat(int i)
    {
        n = i;
        d = 1;
    }

    int get() { return n; }
    int getD() { return d; }

    void setN(int i) { n = i; }
    void setD(int i) { d = i; }

    Rat operator+(Rat r)
    {
        Rat t;
        t.n = n * r.d + d * r.n;
        t.d = d * r.d;
        return t;
    }

    Rat operator-(Rat r)
    {
        Rat t;
        t.n = n * r.d - d * r.n;
        t.d = d * r.d;
        return t;
    }

    Rat operator*(Rat r)
    {
        Rat t;
        t.n = n * r.n;
        t.d = d * r.d;
        return t;
    }

    Rat operator/(Rat r)
    {
        Rat t;
        t.n = n * r.d;
        t.d = d * r.n;
        return t;
    }

    friend ostream &operator<<(ostream &os, Rat r);

    friend istream &operator>>(istream &is, Rat &r);
};

ostream &operator<<(ostream &os, Rat r)
{
    if (abs(r.n) >= r.d || r.n == 0)
        os << r.n / r.d << " ";
    if (r.d != 1)
        os << (r.n / r.d <= -1 ? abs(r.n % r.d) : r.n % r.d) << "/" << r.d;
    return os;
}

istream &operator>>(istream &is, Rat &r)
{
    is >> r.n >> r.d;
    return is;
}

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