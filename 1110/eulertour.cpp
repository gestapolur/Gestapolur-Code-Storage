#include<iostream>
#define MAXN 1002
using namespace std;

int n , m ;
int st[ MAXN ] , w[ MAXN ][ MAXN ];

void euler( int pos )
{
  for( int i = 1 ; i <= w[ pos ][ 0 ] ; ++ i )
    if( not mark[ w[ pos ][ i ] ] )
      {
        mark[ w[ pos ][ i ] ] = true;
        u
        euler( w[ pos ][ i ] );
        break;
      }
  return ;
}

void init()
{
  cin>>n>>m;
  for()
  return ;
}

int main()
{
  init();
  euler();
  return 0;
}
