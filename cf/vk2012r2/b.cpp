#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#define MAXN 1000002
using namespace std;

int n , m;
int a[ MAXN ] , s[ MAXN ] , stk[ 10 ];
string sa , ss;

void init()
{
  cin>>sa>>ss;

  n = sa.size();
  m = ss.size();

  for( int i = 0 ; i < n ; ++ i )
    a[ i + 1 ] = sa[ i ] - 48;

  for( int i = 0 ; i < m ; ++ i )
    {
      s[ i + 1 ] = ss[ i ] - 48;
      ++ stk[ s[ i + 1 ] ];
    }

  return ;
}

void work( )
{
  int cur = 9 ;
  while( stk[ cur ] == 0 and cur > 0 )
    -- cur;

  for( int i = 1 ; i <= n ; ++ i )
    if( a[ i ] < cur )
      {
        a[ i ] = cur;
        -- stk[ cur ];
        while( stk[ cur ] == 0 and cur > 0 )
          -- cur;      
      }

  for( int i = 1 ; i <= n ; ++ i )
    cout<<a[ i ];
  cout<<"\n";

  return ;
}

int main()
{
  init();
  
  work();

  return 0;
}
