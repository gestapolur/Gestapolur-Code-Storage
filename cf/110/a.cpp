#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#define MAXN 32
using namespace std;

int n;
int w[ MAXN ][ MAXN ];

void init()
{
  cin>>n;
  for( int i = 1 ; i <= n ; ++ i )
    for( int j = 1 ; j <= n ; ++ j )
      {
        cin>>w[ i ][ j ];
      }
  return ;
}

void work()
{
  int ans = 0 ;
  for( int i = 1 ; i <= n ; ++ i )
    for( int j = 1 ; j <= n ; ++ j )
      {
        int tma = 0 , tmb = 0 ;
        for( int k = 1 ; k <= n ; ++ k )
          tma += w[ i ][ k ];
        for( int k = 1 ; k <= n ; ++ k )
          tmb += w[ k ][ j ];
        if( tmb > tma ) ++ ans;
      }
  cout<<ans<<"\n";
  return ;

}

int main()
{
  init();

  work();
  
  return 0;
}
