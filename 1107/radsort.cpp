#include<iostream>
#define MAXN 10001
using namespace std;

int a[ MAXN ] , b[ MAXN ] , r[ MAXN ];
int n,m;

int main()
{
  int i;
  cin>>n;
  for( i = 1 ; i <= n ; ++ i )
    {
      cin>>a[ i ];
      m = m > a[ i ] ? m : a[ i ];
    }
  //bucket sort
  for( i = 1 ; i <= n ; ++ i )
    ++ b[ a[ i ] ];
  for( i = 1 ; i <= m ; ++ i )
    b[ i ] += b[ i - 1 ];
  for( i = n ; i >= 1 ; -- i )
    r[ b[ a[ i ] ]-- ] = i;
  for( i = 1 ; i <= n ; ++ i )
    cout<<a[ r[ i ] ]<<" ";
  cout<<"\n";
  return 0;
}
