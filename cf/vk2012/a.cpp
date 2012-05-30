/*VK CUP 2012 A*/
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#define MAXN 55
using namespace std;

int n , k ;
int a[ MAXN ];

void init()
{
  cin>>n>>k;
  for( int i = 1 ; i <= n ; ++ i )
    cin>>a[ i ];
  return ;
}

void work()
{
  int ans = 0 ;
  if( a[ k ] > 0 )
    {
      ans = k ;
      while( a[ k + 1 ] == a[ k ] and k < n )
        {
          ++ ans;
          ++ k;
        }
    }
  else
    for( int i = 1 ; i <= k ; ++ i )
      if( a[ i ] > 0 )
        ++ ans;
      else
        break;
  cout<<ans<<"\n";

  return ;
}

int main()
{
  init();

  work();
  
  return 0;
}
