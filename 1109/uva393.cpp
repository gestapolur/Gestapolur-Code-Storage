/*
  UVA 393 AC 
  write by gestapolur
  compute geometry
  2011-09-30
*/ 
#include<iostream>
#include<cmath>
#define MAXN 302
#define ZERO 1e-6 
#define INF 20000000
using namespace std;

int n , m ;
double w[ MAXN ][ MAXN ];

class point
{
public:
  double x , y;
};

point p[ MAXN ];

double dotdet( double x1 , double y1 , double x2 , double y2 )
{ return ( x1 * y1 + x2 * y2 );}

//whether a is in the range of b , c 
double dot( point a , point b , point c )
{ return dotdet( b.x - a.x , b.y - a.y , c.x - a.x , c.y - a.y ) ;}

double det( double x1 , double y1 , double x2 , double y2 )
{ return ( x1 * y2 - x2 * y1 );}

double cross( point a , point b , point c )
{ return det( b.x - a.x , b.y - a.y , c.x - a.x , c.y - a.y );}

double dblcmp( double d )
{ 
  if( fabs( d ) < ZERO )
    return 0;
  return d > 0 ? 1 : -1;
}

//cmpare whether 
int betweencmp( point a , point b , point c )
{
  return dblcmp( dot( a , b , c ) );
}

int segcross( point a , point b , point c ,point d )
{
  point p;
  int d1 , d2 , d3 , d4 ;
  double s1 , s2 , s3 , s4 ;
  d1 = dblcmp( s1 = cross( a , b , c ) );
  d2 = dblcmp( s2 = cross( a , b , d ) );
  d3 = dblcmp( s3 = cross( c , d , a ) );
  d4 = dblcmp( s4 = cross( c , d , b ) );
  
  //regular cross
  if( ( d1 ^ d2 ) == -2 and ( d3 ^ d4 ) == -2 )
    {
      p.x = ( c.x * s2 - d.x * s1 ) / ( s2 - s1 );
      p.y = ( c.y * s2 - d.y * s1 ) / ( s2 - s1 );
      return 1 ;
    }
  return 0;
}

bool init()
{
  cin>>n;
  if( n == -1 ) return false;
  p[ 1 ].x = 0 ; p[ 1 ].y = 5 ;
  double tx ;
  m = 1 ;
  for( int i = 1 ; i <= n ; ++ i )
    {
      cin>>tx;
      p[ ++ m ].x = tx ; p[ m ].y = 0 ;
      p[ ++ m ].x = tx ; cin>>p[ m ].y;
      p[ ++ m ].x = tx ; cin>>p[ m ].y;
      p[ ++ m ].x = tx ; cin>>p[ m ].y;
      p[ ++ m ].x = tx ; cin>>p[ m ].y;
      p[ ++ m ].x = tx ; p[ m ].y = 10;
    }
  p[ ++ m ].x = 10 ; p[ m ].y = 5 ;
  return true;
}

double min( double a , double b ){ return a < b ? a : b ;}

double dist( point a , point b )
{ return sqrt( ( a.x - b.x ) * ( a.x - b.x ) + ( a.y - b.y ) * ( a.y - b.y ) ) ;}
//{ return sqrt( pow( a.x - b.x , 2 ) + pow( a.y - b.y , 2 ) );}

void graph()
{
  int i , j , k ;

  for( i = 1 ; i <= m ; ++ i )
    for( j = 1 ; j <= m ; ++ j )
      w[ i ][ j ] = INF; 

  for( k = 1 ; k <= m ; ++ k )
    for( i = 1 ; i <= m ; ++ i )
      if( i not_eq k )
        {
          w[ k ][ i ] = w[ i ][ k ] = dist( p[ k ] , p[ i ] );
          for( j = 2 ; j < m ; j += 2 )
            if( i not_eq j and segcross( p[ k ] , p[ i ] , p[ j ] , p[ j + 1 ] ))
              {w[ k ][ i ] = w[ i ][ k ] = INF ; break;}
        }
  
  return ;
}

void floyd()
{
  cout.setf(ios::showpoint|ios::fixed);
  cout.precision( 2 );
  /*
  for( int i = 1 ; i <= m ; ++ i )
    {
      for( int j = 1 ; j <= m ; ++ j )
        cout<<w[ i ][ j ]<<" ";
      cout<<"\n";
    }
  */
  for( int k = 1 ; k <= m ; ++ k )
    for( int i = 1 ; i <= m ; ++ i )
      for( int j = 1 ; j <= m ; ++ j )
        if( k not_eq i and k not_eq j and i not_eq j and 
            w[ i ][ j ] > w[ i ][ k ] + w[ k ][ j ] )
          w[ i ][ j ] = w[ i ][ k ] + w[ k ][ j ];
  cout<<w[ 1 ][ m ]<<"\n";
  return ;
}

int main()
{
  while( init() )
    {
      graph();
      floyd();
    }
  return 0 ;
}
