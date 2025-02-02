/*
  O(n^2) algorithm for convex hull
  write by gestapolur 
  2011-10-02
*/
#include<iostream>
#include<cmath>
#define MAXN 1002
#define ZERO 1.0e-12
#define INF 1.0e16
using namespace std;

int n;

class point
{
public:
  long double x , y ;
};

point p[ MAXN ];
int st[ MAXN ];
bool chs[ MAXN ];

int dlcmp( long double d )
{
  if( fabs( d ) < ZERO ) return 0 ;
  return d > 0 ? 1 : -1 ;
}

long double det( long double x1 , long double y1 , long double x2 , long double y2 )
{ return x1 * y2 - x2 * y1 ;}

long double cross( point a , point b , point c )
{ return det( b.x - a.x , b.y - a.y , c.x - a.x , c.y - a.y ); }

void convex()
{
  int i , k , nk ;
  point m;
  long double conv , mcon ;
  st[ 0 ] = 2;
  st[ 1 ] = 1;
  chs[ 1 ] = true ;
  nk = 2 ; 
  for( i = 3 ; i <= n ; ++ i )
    if( cross( p[ i ] , p[ 1 ] , p[ nk ] ) < ZERO )
      nk = i ;
  chs[ nk ] = true ;
  st[ 2 ] = nk; 
  k = nk ;
  cout<<" start p "<<p[ 1 ].x<<" "<<p[ 1 ].y<<"\n";
  do{
    mcon = INF ; nk = 0 ;
    cout<<p[ k ].x<<" "<<p[ k ].y<<" cur \n";
    for( i = 1 ; i <= n ; ++ i )
      {
        cout<<"pre "<<cross( p[ i ] , p[ st[ st[ 0 ] - 1 ] ] , p[ k ] )<<" "<<p[ i ].x<<" "<<p[ i ].y<<"\n";
        if( cross( p[ i ] , p[ st [ st[ 0 ] - 1 ] ] , p[ k ] ) > ZERO 
            and ( nk == 0 or cross( p[ i ] , p[ k ] , p[ nk ] ) < ZERO ) )
          {
            nk = i ;
            cout<<p[ nk ].x<<" "<<p[ nk ].y<<"--"<<"\n";
          }
      }
    if( nk > 0 and not chs[ nk ] )
      { chs[ nk ] = true ; st[ ++ st[ 0 ] ] = nk ; k = nk ; }
    else break ;
  }while( nk );
  
  //last point
  /*
  for( i = 2 ; i <= n ; ++ i )
    if( not chs[ i ] and ( nk == 0 or cross( p[ i ] , p[ nk ] , p[ k ] ) < ZERO ) )
      nk = i ;
  st[ ++ st[ 0 ] ] = nk ;
  */
  //output
  cout<<st[ 0 ]<<"\n";
  for( i = 1 ; i <= st[ 0 ] ; ++ i )
    cout<<p[ st[ i ] ].x<<" "<<p[ st[ i ] ].y<<"\n";
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
  sortleft( 1 , n );
  for( int i = 1 ; i <= n ; ++ i ) cout<<p[ i ].x<<" "<<p[ i ].y<<"\n";cout<<"======\n";
  convex();

  return 0;
}
