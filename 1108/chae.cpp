//Wuhan regional 09' chaeyeon
#include<iostream>
#include<cmath>
#define INF 2141483647
#define MAXN 102
#define LEN 0.01
#define AREA LEN * LEN
#define ZERO 1e-10
using namespace std;

int nr , ng , nb ;
double rx[ MAXN ] , ry[ MAXN ] , rr[ MAXN ] , gx[ MAXN ] , gy[ MAXN ] , gr[ MAXN ];
double bx[ MAXN ] , by[ MAXN ] , br[ MAXN ];
double minx , miny , maxx , maxy;
double red , blue , green , white , yellow , cyan , mag;

inline double dist( double sx , double sy , double rx , double ry )
{return sqrt( pow( fabs( sx - rx ) , 2 ) + pow( fabs( sy - ry ) , 2 ) );}

void work()
{
  double i , j ;
  int k;
  bool cr , cg , cb;
  red = ZERO , blue = ZERO , green = ZERO ;
  white = ZERO , yellow = ZERO, cyan = ZERO , mag = ZERO;
  for( i = minx ; i <= maxx ; i += LEN )
    for( j = miny ; j <= maxy ; j += LEN )
      {

	cr = false , cg = false , cb = false;

	for( k = 1 ; k <= nr ; ++ k )
	  if( rr[ k ] - dist( i , j , rx[ k ] , ry[ k ] ) > ZERO )
	    {cr = true;break;}
	
	for( k = 1 ; k <= ng ; ++ k )
	  if( gr[ k ] - dist( i , j , gx[ k ] , gy[ k ] ) > ZERO )
	    {cg = true;break;}
	
	for( k = 1 ; k <= nb ; ++ k )
	  if( br[ k ] - dist( i , j , bx[ k ] , by[ k ] ) > ZERO )
	    {cb = true;break;}

	if( cr & cg & cb ) white += AREA;
	else if( cr & cg ) yellow += AREA;
	else if( cg & cb ) cyan += AREA;
	else if( cr & cb ) mag += AREA;
	else if( cr ) red += AREA;
	else if( cb ) blue += AREA;
	else if( cg ) green += AREA;
      }

  cout.setf(ios::showpoint);
  cout.setf(ios::fixed);
  cout.precision( 2 );
  cout<<red<<" "<<green<<" "<<blue<<" "<<white<<" "<<yellow<<" "<<mag<<" "<<cyan<<"\n";

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
  int t ;
  cin>>t;
  while( t -- )
    {
      init();
      work();
    }
  return 0;
}
