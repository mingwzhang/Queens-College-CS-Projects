# include <iostream>
using namespace std;

bool Ok(int arr[], int col)
{
    for(int i = 0; i < col; i++)
    {
        if(arr[i] == arr[col] || col - i == abs(arr[i] - arr[col]))
        {
            return false;
        }
    }
    return true;
}

void Print(int arr[], int count)
{
    cout << "Solution #" << count << endl;

    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(arr[i] == j)
            {
                cout << "1 ";
            }else{
                cout << "0 ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    int arr[8] = {0};

    int col = 0;
    
    int count = 0;

    while(col > -1)
    {
        if(col == 8)
        {
            count++;
            Print(arr, count);
            col--;
            arr[col]++;
        }else if(arr[col] == 8)
        {
            arr[col] = 0;
            col--;
            arr[col]++;
        }else if(Ok(arr, col)){
            col++;
        }else{
            arr[col]++;
        }
    }
    return 0;
}