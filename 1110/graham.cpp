/*
  graham scan
  write by gestapolur
  2011-10-01
*/
#include<iostream>
#include<cmath>
#define MAXN 1002
#define ZER0 1.0e-12
using namespace std;

int n;

class point
{
public:
  long double x , y ;
};

point p[ MAXN ];
point st;

int pre[ MAXN ];
int st[ MAXN ];

int dlcmp( long double d )
{
  if( fabs( d ) < ZERO ) return 0 ;
  return d > 0 ? 1 : -1 ;
}

long double det( long double x1 , long double y1 , long double x2 , long double y2 )
{ return x1 * y2 - x2 * y1 ;}

long double cross( point a , point b , point c )
{ return det( b.x - a.x , b.y - a.x , c.x - a.x , c.y - a.y ); }

void dfs()
{
  int i ;
  point c ;
  for( i = 1 ; i <= n ; ++ i ) pre[ i ] = 0 ;
  st[ 0 ] = 0 ;
  do{
    
  }while( cur > 0 );
  
  return ;
}

void sortleft( int i , int j )
{
  if( i >= j ) return ;
  int m , n ;
  point t , k = p[ i + j >> 1 ];
  m = i , n = j ;
  while( m <= n )
    {
      while( p[ m ].x < k.x or ( fabs( p[ m ].x - k.x ) < ZERO and p[ m ].y > k.y ) ) ++ m;
      while( p[ n ].x > k.x or ( fabs( p[ n ].x - k.x ) < ZERO and p[ n ].y < k.y ) ) -- n;
      if( m <= n )
        {
          t = p[ m ] ; p[ m ] = p[ n ]; p[ n ] = t;
          ++ m ; -- n ;
        }
    }
  sortleft( i , n );
  sortleft( m , j );
  return ;
}

void init()
{
  cin>>n;
  for( int i = 1 ; i <= n ; ++ i )
    cin>>p[ i ].x>>p[ i ].y;
  return ; 
}

int main()
{
  init();
  findleft();
  dfs();
  return 0;
}
