//check how SPFA check a neg circle 
#include<iostream>
#define MAXN 1000
#define INF 1000000000
using namespace std;

int n , m ;
int q[ MAXN * 2 ] , w[ MAXN ][ MAXN ] ;
int mark[ MAXN ] , pre[ MAXN ];
char in[ MAXN ];

void spfa()
{
  int i ;
  int front , rear , p ;
  for( i = 1 ; i <= n ; ++ i )
    { mark[ i ] = INF; in[ i ] = 0 ;}
  front = 0 , rear = 1 ;
  mark[ 1 ] = 0 ;pre[ 1 ] = 0 ;
  q[ 1 ] = 1 ; in[ 1 ] = 1 ;

  do{
    p = q[ ++ front ];
    for( i = 1 ;i <= n ; ++ i )
      if( w[ p ][ i ] not_eq INF and mark[ i ] > mark[ p ] + w[ p ][ i ])
	{
	  // if( p == 3 ) cout<<mark[ p ]<<" "<<w[ p ][ i ]<<" "<<p<<" "<<i<<"-\n";
	  mark[ i ] = mark[ p ] + w[ p ][ i ];
	  if( mark[ p ] + w[ p ][ i ] > 0 or in[ i ] == 0 )
	    pre[ i ] = p ;
	  if( in[ i ] < 1 or ( in[ i ] == 1 and mark[ p ] + w[ p ][ i ] < 0 ) )
	    { q[ ++ rear ] = i ; ++ in[ i ];}
	}
    for( i = front ; i <= rear ; ++ i ) cout<<int( in[ i ] ) <<" ";cout<<"\n";
  }while( front < rear );
  cout<<"--------\n";
  for( i = 1 ; i <= n ; ++ i ) cout<<mark[ i ]<<" ";cout<<"\n";
  for( i = 1 ; i <= n ; ++ i ) cout<<pre[ i ]<<" ";cout<<"\n";

  for( i = 1 ; i <= n ; ++ i )
    {
      p = i;
      while( p not_eq 0 )
	{
	  cout<<p<<"-";
	  p = pre[ p ];
	}
      cout<<"\n";
    }

  return ;
}

int main()
{
  int i , u , v , wi;
  cin>>n>>m;
  for( u = 1 ; u <= n ; ++ u )
    for( v = 1 ; v <= n ;  ++ v )
      w[ u ][ v ] = INF;

  for( i = 1 ; i <= m; ++ i )
    {
      cin>>u>>v>>wi;
      w[ u ][ v ] = wi;
    }

  spfa();
   
  return 0;
}
