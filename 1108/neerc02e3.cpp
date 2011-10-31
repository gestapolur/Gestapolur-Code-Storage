// NEERC 02' E 
#include<iostream>
#include<cstdlib>
#define MAXN 216
#define INF 1000000000
using namespace std;

int bn , sn , ccost ;
int sx[ MAXN ] , sy[ MAXN ] , bx[ MAXN ] , by[ MAXN ];

int n ;
int f[ MAXN ][ MAXN ] , c[ MAXN ][ MAXN ] , w[ MAXN ][ MAXN ] , tw[ MAXN ][ MAXN ];
int pre[ MAXN ] , mark[ MAXN ] , q[ MAXN * 3 ];
int mincost , maxflow;
bool in[ MAXN ];

//source is 1 and sink is n 

bool findflow()
{
  int i , p , tmin , rec ;
  int rear , front;
  rear = 1 , front = 0;
  //cout<<"ff st \n";

  for( i = 1 ; i <= n ; ++ i ) 
    { in[ i ] = false ; mark[ i ] = INF; pre[ i ] = 0 ; }

  q[ 1 ] = 1 ; mark[ 1 ] = 0 ; in[ 1 ] = true;

  //first time find shortest path 
  do{
    p = q[ ++ front ];
    for( i = 1 ; i <= n ; ++ i )
      if( c[ p ][ i ] > 0 and  w[ p ][ i ] not_eq INF 
	  and mark[ i ] > mark[ p ] + w[ p ][ i ] )
	{ 
	  mark[ i ] = mark[ p ] + w[ p ][ i ] ; pre[ i ] = p; 
	  if( not in[ i ] )
	    { q[ ++ rear ] = i; in[ i ] = true  ; } 
	}
  }while( front < rear );
  
  //cout<<"fd cp \n";
  return mark[ n ] < INF ;
}

void addflow()
{
  int p , flow , cost = 0 ;
  bool hash[ MAXN ];
  for( p = 1 ; p <= n ; ++ p ) hash[ p ] = false;
  p = n ; flow = INF;
  cout<<"------\n";
  while( p not_eq 0 )
    { 
      if( not hash[ p ] )
	{
	  -- c[ pre[ p ] ][ p ]; 
	  ++ c[ p ][ pre[ p ] ];
	  cost += w[ pre[ p ] ][ p ];
	  hash[ p ] = true;
	  p = pre[ p ];
	}
      else
	{
	  int i = p;
	  int tmin = INF , rec = 0 ;
	  while( i not_eq p)
	    do{
	      -- c[ pre[ i ] ][ i ] ;
	      ++ c[ i ][ pre[ i ] ] ;
	      cost += w[ pre[ i ] ][ i ];
	    }while( i not_eq p );
	  for( i = 1 ; i <= n ; ++ i )
	    if( not hash[ i ] and c[ i ][ p ] > 0 and w[ i ][ p ] not_eq INF and i not_eq pre[ p ] and tmin > mark[ i ] + w[ i ][ p ] and pre[ i ] not_eq p )
	      { rec = i ; tmin = mark[ i ] + w[ i ][ p ] ; }
	  pre[ p ] = rec ;hash[ p ] = false;
	  cout<<"x "<<pre[ p ]<<" "<<p<<"\n";//cin.get();cin.get();
	}
      cout<<p<<":"<<pre[ p ]<<":"<<w[ pre[ p ] ][ p ]<<":"<<c[ pre[ p ]][ p ]<<" ";
    }
  cout<<"\n";
  cout<<"trace cp "<<mincost<<"\n";
  maxflow ++ ;
  mincost += cost ;

  return ;
}

void init()
{
  int i , j , tn ;
  cin>>bn>>sn;
  
  for( i = bn + sn + 2  ; i >= 1 ; -- i )
    for( j = bn + sn + 2  ; j >= 1 ; -- j )
      w[ i ][ j ] = INF;
  
  for( i = 1 ; i <= bn ; ++ i )
    {
      cin>>bx[ i ]>>by[ i ]>>f[ 1 ][ i + 1 ];
      c[ 1 ][ i + 1 ] = f[ 1 ][ i + 1 ];
      w[ 1 ][ i + 1 ] = w[ i + 1 ][ 1 ] = 0;
    }

  for( i = 1 ; i <= sn ; ++ i )
    {
      cin>>sx[ i ]>>sy[ i ]>>f[ bn + i + 1 ][ bn + sn + 2 ];
      c[ bn + i + 1 ][ bn + sn + 2 ] = f[ bn + i + 1 ][ bn + sn + 2 ];
      w[ bn + i + 1 ][ sn + bn + 2 ] = w[ sn + bn + 2 ][ bn + i + 1 ] = 0;
    }

  //count the dist
  for( i = 1 ; i <= bn ; ++ i )
    for( j = 1 ; j <= sn ; ++ j )
      {
	w[ i + 1 ][ bn + j + 1 ] = abs( bx[ i ] - sx[ j ] ) + abs( by[ i ] - sy[ j ] ) + 1 ;
	w[ bn + j + 1 ][ i + 1 ] = -w[ i + 1 ][ bn + j + 1 ];
	f[ i + 1 ][ bn + j + 1 ] = f[ 1 ][ i + 1 ];
	c[ i + 1 ][ bn + j + 1 ] = c[ 1 ][ i + 1 ];
      }

  //source = 1 , sink = bn + sn + 2
  n = sn + bn + 2 ; 

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

  if( mincost == ccost ) cout<<"OPTIMAL\n";
  else
    {
      cout<<"SUBOPTIMAL\n";
      for(int i = 1 ; i <= bn ; ++ i )
	{
	  for(int j = 1 ; j <= sn ; ++ j )
	    {
	      cout<<f[ i + 1 ][ bn + j + 1 ] - c[ i + 1 ][ bn + j + 1 ];
	      cout<<( j < sn  ? " " : "\n");
	    }
	}
    }

  return ;
}

int main()
{
  init();

  while( findflow() )
      addflow();

  output();
  
  return 0;
}
