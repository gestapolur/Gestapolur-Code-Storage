#include<iostream>
#define INF 1000000000
#define MAXN 1002
using namespace std;

int n , m ;
int f[ MAXN ][ MAXN ] , c[ MAXN ][ MAXN ] , w[ MAXN ][ MAXN ];
int pre[ MAXN ] , mark[ MAXN ] , q[ MAXN * 3 ];
int mincost , maxflow;
short int in[ MAXN ];

//source is 1 and sink is n 

bool findflow()
{
  int i , p ;
  int rear , front;
  rear = 1 , front = 0;
  for( i = 1 ; i <= n ; ++ i ) 
    {
      in[ i ] = 0 ;
      mark[ i ] = INF;
    }
  q[ 1 ] = 1 ; mark[ 1 ] = 0 ;

  do{
    p = q[ ++ front ];
    in[ p ] ++ ;
    for( i = 1 ; i <= n ; ++ i )
      if( c[ p ][ i ] > 0 and  w[ p ][ i ] not_eq INF and mark[ i ] > mark[ p ] + w[ p ][ i ] )
	{ 
	  mark[ i ] = mark[ p ] + w[ p ][ i ] ; pre[ i ] = p ;
	  if( in[ i ] < 2 )
	    { q[ ++ rear ] = i; in[ i ] ++ ;} 
	}
    for( i = 1 ; i <= n ; ++ i ) cout<<mark[ i ]<<" ";cout<<"\n";cin.get();
  }while( front <= rear );

  for( i = 1 ; i <= n ; ++ i ) cout<<pre[ i ]<<" "; cout<<"\n";

  return mark[ n ] < INF ;
}

void addflow()
{
  int p , flow = 0 , cost = 0 ;
  p = n ; flow = INF;
  while( p not_eq 1 )
    {
      flow = flow < c[ pre[ p ] ][ p ] ? flow : c[ pre[ p ] ][ p ];
      cost += w[ pre[ p ] ][ p ];
      p = pre[ p ];
    }
  
  maxflow += flow;
  mincost += flow * cost;

  p = n;
  while( p not_eq 1 )
    {
      c[ pre[ p ] ][ p ] -= flow;
      c[ p ][ pre[ p ] ] += flow;
      p = pre[ p ]; 
    }
  
  return ;
}

int main()
{
  int i , u , v , wi , fi ;
  cin>>n>>m;

  for( i = 1 ; i <= m ; ++ i )
    {
      cin>>u>>v>>fi>>wi;
      /*
      f[ u ][ v ] = fi ; 
      w[ u ][ v ] = wi ;
      c[ u ][ v ] = f[ u ][ v ];
      w[ v ][ u ] = -w[ u ][ v ];
      */
    }
  
  while( findflow( ) and cout<<"!!!\n")
    addflow( );
  cout<<mincost<<" "<<maxflow<<"\n";
  return 0;
}
