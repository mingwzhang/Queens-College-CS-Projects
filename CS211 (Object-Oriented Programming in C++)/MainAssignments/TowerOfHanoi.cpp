//Reference: classnote p.75-76
//https://venus.cs.qc.cuny.edu/~mfried/cs211_waxman/templates/template-hanoi.cpp
//https://raw.githubusercontent.com/akplearner/CS-211/master/Tower%20of%20Hanoi%20(Non-Recursive)
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> t[3]; //three towers A,B,C represented as an array of 3 vectors
    int n, candidate, to, from, near, far, move = 0; //move counts the move number

    cout << "Please enter the number of rings to move: ";
    cin >> n;
    
    //initialize the 3 towers (rings)    
    for (int i = n+1; i >= 1; i--)
    {
        t[0].push_back(i);
    }
    t[1].push_back(n+1);
    t[2].push_back(n+1);

    //initialize towers and candidate
    if (n%2 == 0) {
        near = 2;
        far = 1;
    }else 
    {
        near = 1;
        far = 2;
    }
    from = 0; to = near; candidate = 1;

    while(t[1].size() < n + 1) //there are still rings to transfer to tower B = t[1]
    { 
        move++;
        cout << "Step #" << move << ": Moves ring " << candidate << " from tower " << char('A' + from) << " to towers "  << char('A' + to); 
        cout << endl;

        t[to].push_back(t[from].back());
        t[from].pop_back();

        if(t[(to + near) % 3].back() < t[(to + far) % 3].back())
        {
            from = (to + near) % 3;
        }else{
            from = (to + far) % 3;
        }
        candidate = t[from].back();

        if(t[(from) % 3].back() < t[(from + near) % 3].back())
        {
            to = (from + near) % 3;
        }else{
            to = (from + far) % 3;
        }
    }
    return 0;
}