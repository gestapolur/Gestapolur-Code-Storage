#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#define MAXN 1002
using namespace std;
int n;
int a[ MAXN ] , b[ MAXN ];

void init()
{
  cin>>n;
  for( int i = 1 ; i <= n ; ++ i )
    cin>>a[ i ]>>b[ i ];
  for( int i = 2 ; i <= n ; ++ i )
    for( int j = 1 ; j < i ; ++ j )
      if( b[ i ] > b[ j ] )
        { int t = a[ i ] ; a[ i ] = a[ j ] ; a[ j ] = t ; 
          t = b[ i ] ; b[ i ] = b[ j ] ; b[ j ] = t;
        }
      else if( b[ i ] == b[ j ] and a[ i ] > a[ j ] )
        { int t = a[ i ] ; a[ i ] = a[ j ] ; a[ j ] = t ; }
  return ;
}

void work()
{
  int p = 0 , i = 1 , rest = 1 ;
  do{
    -- rest;
    p += a[ i ];
    rest += b[ i ];
    ++ i;
  }while( rest > 0 and i <= n );

  cout<<p<<"\n";

  return ;

}

int main()
{
  init();

  work();
  
  return 0;
}
