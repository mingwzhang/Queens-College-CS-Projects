#include <iostream>
using namespace std;

bool Ok(int arr[], int col)
{
    int adj[8][5] = {
        {-1},
        {0,-1},
        {0,-1},
        {0,1,2,-1},
        {0,1,3,-1},
        {1,4,-1},
        {2,3,4,-1},
        {3,4,5,6,-1},
    }; 



    for(int x = 0; x < col; x++)
    {
        if(arr[x] == arr[col])
        {
            return false;
        }
    }
    for(int x = 0; adj[col][x] != -1; x++)
    {
        if(abs(arr[col]-arr[adj[col][x]]) == 1)
        {
            return false;
        }
    }
    return true;
}

void Print(int q[], int solutionCount)
{
    cout << "Solution # " << solutionCount << endl;
    cout << "  " << q[0] << " " << q[1] << endl;
    cout << q[2] << " " << q[3] << " " << q[4] << " " << q[5] << endl;
    cout << "  " << q[6] << " " << q[7] << endl;
    cout << endl;
}


int main()
{

    int arr[8] = {1};

    int col = 0, count = 0;
    
    while(col > -1)
    {
        if(col == 8)
        {
            count++;
            Print(arr, count);
            col--;
            arr[col]++;
        }else if(arr[col] == 9){

            arr[col] = 1;
            col--;
            arr[col]++;
        }else if(Ok(arr, col))
        {
            col++;
        }else{
            arr[col]++;
        }
    }
}