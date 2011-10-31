/*
  wuhan 09 IC chae
  line scan
  whether it TLE ? 
  write by gestpolur
  2011-08-27
*/
#include<iostream>
#include<cmath>
#define MAXN 203
#define MAXC 102
#define ACU 0.01
#define ZERO 1e-10
using namespace std;

const int w[ 8 ][ 8 ] = 
  {
    
  };

double pl[ MAXN ] , pr[ MAXN ] ;
int pc[ MAXN ] , cc[ MAXC ] ;
double cr[ MAXC ] , cx[ MAXC ] , cy[ MAXN ];
double minx , maxx , miny , maxy ;
int nr , ng , nb , n ;
int cnt;
double col[ 8 ];
// col : 1 red 2 green 3 blue 4 white 5 yello 6 mag 7 cyan 

void sort( int i , int j )
{
  if( i >= j ) return ;
  int m , n ;
  double t , k ;
  m = i ,  n = j , k = pl[ i + j >> 1 ];
  while( m <= n )
    {
      while( pl[ m ] < k ) ++ m ;
      while( pr[ m ] > k ) -- n ;
      if( m <= n )
	{
 	  t = pl[ m ] ; pl[ m ] = pl[ n ] ; pl[ n ] = t;
	  t = pr[ m ] ; pr[ m ] = pr[ n ] ; pr[ n ] = t;
	  ++ m , -- n;
	}
    }
  sort( i , n );
  sort( m , j );
  return ;
}

void scan( double py )
{
  int i;
  double delt ;
  for( i = 1 ; i <= nr ; ++ i )
    {
      delt = sqrt( pow( py - cy[ i ] , 2 ) - pow( cr[ i ] , 2 ) ) ;
      pl[ ++ cnt ] = cx[ i ] - delt ; pr[ cnt ] = cx[ i ] + delt ;
      pc[ cnt ] j= cc[ i ] ;
    }
  return ;
}

void work()
{
  double ty , tend , pret ;
  int i , j , pre = 0 ;
  sign = false;
  for( ty = miny ; i <= maxy ; i += ACU )
    {
      scan( ty );
      cnt = 0 ;
      sort( 1 , cnt );
      for( i = 1 ; i < cnt ; ++ i )
	if( pl[ i ] < maxx + 1 )
	  for( j = i + 1 ; j <= cnt ; ++ j )
	    if( pr[ i ] > pl[ j ] and pc[ i ] not_eq pc[ j ] )
	      {
		tend = pr[ i ] < pr[ j ] ? pr[ i ] : pr[ j ];
		col[ w[ pc[ i ] ][ pc[ j ] ] ] += ACU * ( tend - pl[ i ] );
		if( pre )
		  { 
		    if( pr[ j ] - pret > ZERO and pc[ j ] not_eq pc[ pre ] ) 
		      {
			col[ w[ pc[ i ] ][ pc[ pre ] ] ] -= ACU * ( pr[ j ]- pret );
			col[ 4 ] += ACU * ( pr[ j ] - pret );//white area
			pret = pl[ j ];  
		      }
		    else
		      {
			col[ w[ pc[ i ] ][ pc[ pre ] ] ] -= ACU * ( pr[ j ] - pl[ j ] );
			col[ 4 ] += AUC * ( pr[ j ] - pret );
			pret = pl[ j ];
		      }
		  }
		if( pr[ j ] > pr[ i ] ) pl[ j ] = pr[ i ];
		else pl[ j ] = maxx + 2 ;
		pre = j , pret = tend;
	      }
    }
  return ;
}

void output()
{
  cin.setf(ios::showpoint && ios::fixed );
  cin.precision( 2 );
  for( int i = 1 ; i <= 7 ; ++ i ) cout<<col[ i ]<<" ";
  cout<<"\n";
  return ;
}

void init()
{
  int i ;
  minx = INF , miny = INF , maxx = 0 , maxy = 0 ;
  cin>>nr>>ng>>nb;
  for( i = 1 ; i <= nr ; ++ i )
    {
      cin>>rx[ i ]>>ry[ i ]>>rr[ i ];
      minx = minx < rx[ i ] - rr[ i ] ? minx : rx[ i ] - rr[ i ];
      maxx = maxx > rx[ i ] + rr[ i ] ? maxx : rx[ i ] + rr[ i ];
      miny = miny < ry[ i ] - rr[ i ] ? miny : ry[ i ] - rr[ i ];
      maxy = maxy > ry[ i ] + rr[ i ] ? maxy : ry[ i ] + rr[ i ];
    }
  for( i = 1 ; i <= ng ; ++ i ) 
    {
      cin>>gx[ i ]>>gy[ i ]>>gr[ i ];
      minx = minx < gx[ i ] - gr[ i ] ? minx : gx[ i ] - gr[ i ];
      maxx = maxx > gx[ i ] + gr[ i ] ? maxx : gx[ i ] + gr[ i ];
      miny = miny < gy[ i ] - gr[ i ] ? miny : gy[ i ] - gr[ i ];
      maxy = maxy > gy[ i ] + gr[ i ] ? maxy : gy[ i ] + gr[ i ];
    }
  for( i = 1 ; i <= nb ; ++ i ) 
    {
      cin>>bx[ i ]>>by[ i ]>>br[ i ];
      minx = minx < bx[ i ] - br[ i ] ? minx : bx[ i ] - br[ i ];
      maxx = maxx > bx[ i ] + br[ i ] ? maxx : bx[ i ] + br[ i ];
      miny = miny < by[ i ] - br[ i ] ? miny : by[ i ] - br[ i ];
      maxy = maxy > by[ i ] + br[ i ] ? maxy : by[ i ] + br[ i ];
    }
  
  return ;
}


int main()
{

  init();

  scan();

  return 0;
}
