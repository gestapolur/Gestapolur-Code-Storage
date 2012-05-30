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
int a[ MAXN ];
bool f[ MAXN ];
bool sync_with_stdio( bool sync = false );

void init()
{
  cin>>n;
  for( int i = 1 ; i <= n ; ++ i )
    cin>>a[ i ];
  return ;
}

void work()
{
  int cnt = 0;
  int i;
  
  do{
    for( i = 1 ; i <= n ; ++ i ) f[ i ] = false; 

    if( a[ 1 ] ) f[ 1 ] = true;
    if( a[ 2 ] and f[ 1 ] ) f[ 2 ] = true;

    for( i = 3 ; i <= n ; ++ i )
      if( a[ i ] and ( f[ i - 1 ] or f[ i - 2 ] ) )
        f[ i ] = true;
    for( i = 1 ; i <= n ; ++ i )
      if( a[ i ] ) -- a[ i ];
    ++ cnt;
  }while( f[ n ] );

  cout<<cnt-1<<"\n";
  return ;
}

int main()
{
  init();
  
  work();

  return 0;
}
