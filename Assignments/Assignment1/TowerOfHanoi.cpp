//Reference: classnote p.75-76
//https://venus.cs.qc.cuny.edu/~mfried/cs211_waxman/templates/template-hanoi.cpp
//https://raw.githubusercontent.com/akplearner/CS-211/master/Tower%20of%20Hanoi%20(Non-Recursive)
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> t[3]; //three towers A,B,C represented as an array of 3 vectors
    int n, candidate, to, from, near, far, move=0; //move counts the move number

    cout << "Please enter the number of rings to move: ";
    cin >> n;
    cout << endl;

    //initialize the 3 towers
    for (int i = n+1; i >= 1; i--) t[0].push_back(i);
    t[1].push_back(n+1);
    t[2].push_back(n+1);

    //initialize towers and candidate
    if (n%2 == 0) {
        // Fill in code here
    }
    else {
        // Fill in code here

    }
    from = 0; to = near; candidate = 1;

    while(t[1].size() < n+1) {//there are still rings to transfer to tower B = t[1]
      
    }
    return 0;
}