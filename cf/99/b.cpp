#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#define MAXN 5002 
using namespace std;

int n , ans ;
int a[ MAXN ] , cnt[ MAXN ];

void init()
{
  cin>>n;
  for( int i = 1 ; i <= n ; ++ i )
    {
      cin>>a[ i ];
      ++ cnt[ a[ i ] ];
      a[ 0 ] = a[ i ] > a[ 0 ] ? a[ i ] : a[ 0 ];
    }
  for( int i = 1 ; i <= a[ 0 ] ; ++ i )
    if( cnt[ i ] > 1 and i <= n )
      ans += cnt[ i ] - 1 ;
    else if( i > n )
      ans += cnt[ i ];
  cout<<ans<<"\n";
  return ;
}

int main()
{
  
  init();

  return 0;
}
