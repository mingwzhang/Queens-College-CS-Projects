#include <iostream>
using namespace std;

bool ok(int q[], int col)
{
  int mp[3][3] = {{0, 2, 1},      // Means man 0 preference = woman 0 (0 - most prefer), woman 1 (2 - less prefer), woman 2 (1)
                  {0, 2, 1},
                  {1, 2, 0}};

  int wp[3][3] = {{2, 1, 0},
                  {0, 1, 2},
                  {2, 0, 1}};

  for(int i = 0; i < col; i++)
  {
    int newMan = col;
    int newWoman = q[col];
    int currentMan = i;
    int currentWoman = q[i];

    if(q[col] == q[i])
    {
      return false;
    }
    if(mp[currentMan][newWoman] < mp[currentMan][currentWoman]  && wp[newWoman][currentMan] < wp[newWoman][newMan])
    {
      return false;
    }
    if(mp[newMan][currentWoman] < mp[newMan][newWoman]  && wp[currentWoman][newMan] < wp[currentWoman][currentMan])
    {
      return false;
    }
  }

  return true;
}

void print(int q[])
{
  cout << "Man \t Woman" << endl;
  for(int i = 0; i < 3; i++)
  {
    cout << i << "\t " << q[i]<< endl;
  }
}

int main()
{
  int col = 0; // men
  int q[3] = {0}; // women = value of the index in the array

  while (col >= 0)
  {
    if (col == 3)
    {
      print(q);
      col--;
      q[col]++;
    }
    else if (q[col] == 3)
    {
      q[col] = 0;
      col--;
      q[col]++;
    }
    else if(ok(q, col))
    {
      col++;
    }else{
      q[col]++;
    }
  }

  return 0;
}