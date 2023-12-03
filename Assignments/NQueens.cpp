#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int c)
{
    // Up Diagonal, Down Diagonal, and Row Test
    for (int i = 0; i < c; i++)
    {
        if ((c - i) == q[c] - q[i] || (c - i) == q[i] - q[c]|| q[i] == q[c])
        {
            return false;
        }
    }
    return true;
}

int NQueens(int n)
{
    int *q = new int [n];
    int c = 0;          
    q[0] = 0;
    int solutionCount = 0;                

    while (c >= 0)                       
    { 
        if (c == n)                     
        {
            solutionCount++;
            c--;                         
            q[c]++;
        }
        else if (q[c] == n)          
        {     
            q[c] = 0;            
            c--;                        
            q[c]++; 
        }
        else if (ok(q, c))          
        {
            c++;
            if (c < n) q[c] = 0;     //Because next column is going to be empty, it needs to be initialized to 0                  
        }
        else
        {
            q[c]++;                  
        }
    }
    delete[] q;

    return solutionCount;
}

int main()
{
    int n = 8;
 //   cout << "Please enter the number of queens: " << endl;
 //   cin >> n; 

    for(int i = 1; i <= n; i++)
    {
        cout << "There are " << NQueens(i) << " solutions to " << i << " queens problem." << endl; 
    }
    return 0;
}
