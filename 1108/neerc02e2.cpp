// NEERC 02' E 
#include<iostream>
#include<cstdlib>
#define MAXN 210
#define INF 1000000000
using namespace std;

int bn , sn , ccost ;
int sx[ MAXN ] , sy[ MAXN ] , bx[ MAXN ] , by[ MAXN ];

int n ;
int f[ MAXN ][ MAXN ] , c[ MAXN ][ MAXN ] , w[ MAXN ][ MAXN ] ;
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
  q[ 1 ] = 1 ; mark[ 1 ] = 0 ;// in[ 1 ] = true;
  
  do{
    p = q[ ++ front ];
    in[ p ] ++  ;
    for( i = 1 ; i <= n ; ++ i )
      if( c[ p ][ i ] > 0 and  w[ p ][ i ] not_eq INF and mark[ i ] > mark[ p ] + w[ p ][ i ] )
	{ 
	  mark[ i ] = mark[ p ] + w[ p ][ i ] ; pre[ i ] = p ;
	  if( in[ i ] == 0 )
	    { q[ ++ rear ] = i; in[ i ] ++ ;} 
	}
    //for( i = 1 ; i <= n ; ++ i ) cout<<mark[ i ]<<" ";cout<<"\n";cin.get();
  }while( front <= rear );

  //for( i = 1 ; i <= n ; ++ i ) cout<<pre[ i ]<<" "; cout<<"\n";
  //cin.get();
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
       cout<<p<<"\n";
    }
  cout<<"trace cp \n";
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

//int abs( int a ){ return a > 0 ? a : -a;}

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
  /*
  for( i = 1 ; i <= bn ; ++ i )
    {
      for( j = 1 ; j <= sn ; ++ j )
	cout<<w[ i + 1 ][ bn + j + 1 ]<<" ";
      cout<<"\n";
    }
  */
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
  //cout<<"!!!\n";
  while( findflow() and cout<<"!!!!\n" )
      addflow();

  //cout<<ccost<<" "<<mincost<<" "<<maxflow<<"\n";

  output();
  
  return 0;
}
