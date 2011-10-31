//state compression test 0 
#include<iostream>
#define MAXC 21
using namespace std;

int f[MAXC];
int n;

int main()
{
  int i,j,finc;
  f[ 0 ] = 1;
  cin>>n;
  finc = 0;
  for(i = 1 ; i <= n ; ++ i)
    finc = finc | (1 << i);
  cout<<finc<<"\n";
  for(i = 1 ;i <= finc ; ++ i)
    for(j = 0 ; j <= n ; ++ j)
      f[ i ] += f[i ^ (1 << j)];
  cout<<f[ n ]<<"\n";
  /*
    1 << x
  */
  return 0;
}
