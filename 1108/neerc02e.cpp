// NEERC 02' E 
#include<iostream>
#define MAXN 210
#define INF 1000000000
using namespace std;

int bn , sn , n ;
int c[ MAXN ][ MAXN ] , f[ MAXN ][ MAXN ] , srt[ MAXN ] , pre[ MAXN ];
int w[ MAXN ][ MAXN ] , rec[ MAXN ][ MAXN ];
int sx[ MAXN >> 1 ] , sy[ MAXN >> 1 ] , bx[ MAXN >> 1 ] , by[ MAXN >> 1 ];
int maxflow , maxcost , ccost;

void addflow()
{
  int flow , cost , i ;

  flow = INF , cost = 0;
  i = n ;

  while ( i not_eq 1 )
    {
      if( flow > c[ pre[ i ] ][ i ])
	flow = c[ pre[ i ]][ i ];
      cost += w[ pre[ i ] ][ i ];
      i = pre[ i ];
    }

  maxflow += flow;
  maxcost += flow*cost;

  i = n ;
  while( i not_eq 1 )
    {
      rec[ pre[ i ] ][ i ] += flow;
      c[ pre[ i ]][ i ] -= flow;
      c[ i ][ pre[ i ] ] += flow;
      i = pre[ i ];
    }

  return ;
}

bool findflow()
{
  int i , j ;
  bool flag;
  
  for( i = 1 ; i <= n ; ++ i )
    {
      srt[ i ] = INF;
      pre[ i ] = -1;
    }

  srt[ 1 ] = 0 , pre[ 1 ] = 0;
  flag = true;
  
  while( flag )
    {
      flag = false;
      for( i = n ; i >= 1 ; -- i )
	for( j = 1 ; j <= n ; ++ j )
	  if( c[ j ][ i ] > 0 and srt[ i ] > srt[ j ] + w[ j ][ i ])
	    { 
	      flag = true;
	      srt[ i ] = srt[ j ] + w[ j ][ i ];
	      pre[ i ] = j ;
	    }
    }
  return srt[ n ] < INF ? true : false;
}

int abs( int a ){ return a > 0 ? a : -a;}

void init()
{
  int i , j , tn ;
  cin>>bn>>sn;

  for( i = bn + sn + 1  ; i >= 1 ; -- i )
    for( j = bn + sn + 1  ; j >= 1 ; -- j )
      w[ i ][ j ] = INF;

  for( i = 1 ; i <= bn ; ++ i )
    w[ 1 ][ i + 1 ] = 0;

  for( i = 1 ; i <= sn ; ++ i )
    w[ bn + i + 1 ][ sn + bn + 1 ] = 0;

  for( i = 1 ; i <= bn ; ++ i )
    {
      cin>>bx[ i ]>>by[ i ]>>f[ 1 ][ i + 1 ];
      c[ 1 ][ i + 1 ] = f[ 1 ][ i + 1 ];
    }

  for( i = 1 ; i <= sn ; ++ i )
    {
      cin>>sx[ i ]>>sy[ i ]>>f[ bn + i + 1 ][ bn + sn + 1 ];
      c[ bn + i + 1 ][ bn + sn + 1 ] = f[ bn + i + 1 ][ bn + sn + 1 ];
    }

  //count the dist
  for( i = 1 ; i <= bn ; ++ i )
    for( j = 1 ; j <= sn ; ++ j )
      {
	w[ i + 1 ][ bn + j + 1 ] = abs( bx[ i ] - sx[ j ] ) + abs( by[ i ] - sy[ j ] ) + 1 ;
	//w[ bn + j + 1 ][ i + 1 ] = w[ i + 1 ][ bn + j + 1 ];
	f[ i + 1 ][ bn + j + 1 ] = f[ 1 ][ i + 1 ];
	c[ i + 1 ][ bn + j + 1 ] = c[ 1 ][ i + 1 ];
      }

  //source = 1 , sink = bn + sn + 1
  n = sn + bn + 1 ; 

  // cal the council cost
  for( i = 1 ; i <= bn ; ++ i )
    for( j = 1 ; j <= sn ; ++ j )
      {
	cin>>tn;
	ccost += w[ i + 1 ][ bn + j + 1 ] * tn;
      }
  return ;
}

void output()
{
  if( maxcost == ccost ) cout<<"OPTIMAL\n";
  else
    {
      cout<<"SUBOPTIMAL\n";
      for(int i = 1 ; i <= bn ; ++ i )
	{
	  for(int j = 1 ; j <= sn ; ++ j )
	    cout<<rec[ i + 1 ][ bn + j + 1 ]<<" ";
	  cout<<"\n";
	}
    }
  return ;
}

int main()
{
  init();
  while( findflow() )
      addflow();
  cout<<ccost<<" "<<maxcost<<" "<<maxflow<<"\n";
  output();
  
  return 0;
}
