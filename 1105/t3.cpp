/*
  state compression test #0
*/
#include<iostream>
#define MAXN 2000000
using namespace std;

int n;
int f[MAXN];
int state;

int main()
{
  int i,j;

  cin>>n;
  /*
  for(i = 0 ; i <= n ; ++ i)
    state = state | ( 1 << i );

  f[ 1 << n ] = 1;

  for(i = (1 << n) + 1 ; i <= state ; ++ i)
    for(j = 1 ; j <= n ; ++ j)
      if( i >> (j - 1) & 1 == 1)//if j-th digit is 1
	f[ i ] = f[ i ] + f[ i ^ (1 << (j - 1) )];
  
  cout<<f[ state ]<<"\n";
  */

  for(i = 0 ; i < n ; ++ i)
    state = state | ( 1 << i);
  f[ 0 ] = 1;
  for(i = 1 ; i <= state ; ++ i)
    for(j = 1 ; j <= n ; ++ j)
      if( i >> (j - 1) & 1 == 1 ) // if j-th digit is 1
	f[ i ] = f[ i ] + f[ i ^ (1 << (j - 1))];
  cout<<f[ state ]<<"\n";

  return 0;
}
