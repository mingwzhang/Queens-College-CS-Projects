#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[]){
  for (int c = 0; c < 4; c++){ 

    for (int i = 0; i < c; i++)
      if (q[i]%2 != q[i+1]%2 || q[i] == q[i+1]) 
        return false; 

  }
  return true;
}
void print(int q[], int count){
  cout << "Configuration # " << count << ": " << endl;
  for (int i=0; i<4; i++)
    cout << q[i];
  cout << endl; 
}

int main( )
{
  int q[4]={0};
  int count = 0;
  for(int i0 =0; i0 <4; i0 ++)
    for(int i1 =0; i1 <4; i1 ++)
      for(int i2 =0; i2 <4; i2 ++)
        for(int i3 =0; i3 <4; i3 ++) { 

                  q[0] = i0;
                  q[1] = i1;
                  q[2] = i2;
                  q[3] = i3;

                  if (ok(q)) print(q, ++count);

                }
  return 0;
}