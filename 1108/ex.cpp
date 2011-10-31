//costflow for binray graph
#include<iostream>
#define MAXN 1002
#define INF 1000000000
using namespace std;

int q[ MAXN * 3 ];
int w[ MAXN ][ MAXN] , pre[ MAXN] , mark[ MAXN ];
int c[ MAXN ][ MAXN ] , f[ MAXN ][ MAXN ] , w[ MAXN ][ MAXN ];
int n , m , maxflow , mincost ;
bool in[ MAXN ];

bool findflow()
{
  int i , p , rear , front;
  for( i = 1 ; i <= n ; ++ i )
    {
      in[ i ] = false; mark[ i ] = INF; pre[ i ] = 0 ;
    }
  rear = 1 , front = 0;
  q[ 1 ] = 1 ; mark[ 1 ] = 0;
  do{
    p = q[ ++ front ];
    in[ i ] = false;
    for( i = 1 ; i <= n ; ++ i )
      if( c[ p ][ i ] > 0 and w[ i ][ j ] not_eq INF and mark[ i ] > mark[ p ] + w[ p ][ j ] )
	{
	  mark[ i ] = mark[ p ] + w[ p ][ i ];
	  if( not in [ i ] )
	    { q[ ++ rear ] = true ; in[ i ] = true; }
	}
  }while( front < rear );
 x
  return mark[ i ] < INF ;
}

void aug()
{
  int p , cost , flow ;
  while( p not_eq 1 )
    {
      cost +=;
    }
  while( p not_eq 1 )
    {
      flow
    }
  return ;
}

void init()
{
  return ;
}

int main()
{
  init();
  while( findflow() )
    aug();
  return 0;
}
