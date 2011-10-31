//#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#define MAXN 1002
#define ZERO 1.0e-12
#define INF 1.0e16
//using namespace std;

int n;

class point
{
public:
  long double x , y ;
};

point p[ MAXN ];
int st[ MAXN ];//points on converx hull 
bool chs[ MAXN ];

long double ans ;

int dlcmp( long double d )
{
  if( fabs( d ) < ZERO ) return 0 ;
  return d > 0 ? 1 : -1 ;
}

long double det( long double x1 , long double y1 , long double x2 , long double y2 )
{ return x1 * y2 - x2 * y1 ;}

long double cross( point a , point b , point c )
{ return det( b.x - a.x , b.y - a.y , c.x - a.x , c.y - a.y ); }

long double dist( long double x1 ,  long double y1 , long double x2 , long double y2 )
{ return sqrt( pow( x2 - x1 , 2 ) + pow( y2 - y1 , 2 ) );}

//trans points degree in convex hull 
void trans()
{
  int i , j , k ;
  point tmp[ MAXN ] , p1 , p2 ;
  long double ki , deg , r , si , co , maxh , maxw , mins = INF ;
  long double trec;
  for( int i = 1 ; i <= st[ 0 ] ; ++ i )
    {
      p1 = p[ st[ i ] ] , p2 = st[ i ] + 1 <= st[ 0 ] ? p[ st[ i ] + 1  ] : p[ st[ 1 ] ];
      r = dist( p1.x , p1.y , p2.x , p2.y );
      si = fabs( p1.y - p2.y ) / r ;
      co = sqrt ( 1 - pow( si , 2 ) ) ;
      maxh = ZERO , maxw = ZERO ;
      for( j = 1 ; j <= st[ 0 ] ; ++ j )
        {
          tmp[ j ].x = p[ st[ j ] ].x * co + p[ st[ j ] ].y * si ;
          tmp[ j ].y = p[ st[ j ] ].x * si + p[ st[ j ] ].y * co ;
        }
      //find current max value 
      for( j = 1 ; j <= st[ 0 ] ; ++ j )
        for( k = j + 1 ; k <= st[ 0 ] ; ++ k )
          {
            maxh = fabs ( tmp[ j ].y - tmp[ k ].y ) > maxh ? fabs ( tmp[ j ].y - tmp[ k ].y ) : maxh;
            maxw = fabs ( tmp[ j ].x - tmp[ k ].x ) > maxw ? fabs ( tmp[ j ].x - tmp[ k ].x ) : maxw;
          }
      if( mins < ( maxw * maxh ))
        trec = co;
      mins = ( maxw * maxh ) < mins ? ( maxw * maxh ) : mins;
    }
  printf("%.4Lfc\n" , acos(trec) );
  printf( "%.4Lf\n" , mins );
  //cout<<mins<<"\n";
  return ;
}

void convex()
{
  int i , j , k , nk ;
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
  
  do{
    mcon = INF ; nk = 0 ;  
    for( i = 1 ; i <= n ; ++ i )
      if( cross( p[ i ] , p[ st [ st[ 0 ] - 1 ] ] , p[ k ] ) > ZERO 
          and ( nk == 0 or cross( p[ i ] , p[ k ] , p[ nk ] ) < ZERO ) )
        nk = i ;
    if( nk > 0 and not chs[ nk ] )
      { chs[ nk ] = true ; st[ ++ st[ 0 ] ] = nk ; k = nk ; }
    else break ;
  }while( nk );//find the 
  
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

bool init()
{
  //cin>>n;
  scanf( "%d" , &n );
  if( n == 0 ) return false; 
  ans = ZERO;
  memset( chs , 0 , sizeof( chs ) );
  for( int i = 1 ; i <= n ; ++ i )
    scanf( "%Lf%Lf" , &p[ i ].x , &p[ i ].y );
  return true; 
}

bool sameline()
{
  double ki;
  bool only;
  long double miny = INF , maxy = ZERO ;
  for( int i = 1 ; i < n ; ++ i )
    for( int j = i + 1 ; j <= n ; ++ j )
      if( fabs( p[ i ].x - p[ j ].x ) > ZERO )
        { ki = fabs( ( p[ i ].y - p[ j ].y ) / ( p[ i ].x - p[ j ].x ) ) ; goto nor ;}
  for( int i = 1 ; i <= n ; ++ i )
    {
      miny = p[ i ].y < miny ? p[ i ].y : miny;
      maxy = p[ i ].y > maxy ? p[ i ].y : maxy;
    }
  printf("%.4Lf\n" , ( maxy - miny ) * ( maxy - miny )  );
  return true;
 nor :
  for( int i = 1 ; i < n ; ++ i )
    for( int j = i + 1 ; j <= n ; ++ j )
        if( fabs( p[ i ].x - p[ j ].x ) < ZERO 
            or fabs(ki - fabs( ( p[ i ].y - p[ j ].y ) / ( p[ i ].x - p[ j ].x ) ) ) > ZERO )
          return false;
  //printf("!!!\n" );
  long double tmpd , mlen = ZERO ;
  for( int i = 1 ; i <= n ; ++ i )
    for( int j = i + 1 ; j <= n ; ++ j )
      {
        //printf("%Lf %Lf %Lf %Lf\n" , p[ i ].x , p[ i ].y , p[ j ].x , p[ j ].y );
        tmpd = dist( p[ i ].x , p[ i ].y , p[ j ].x , p[ j ].y );
        mlen = tmpd > mlen ? tmpd : mlen;
      }
  //printf("%Lf\n" , mlen );
  mlen = mlen * mlen ;
  printf( "%.4Lf\n" , mlen );
  return true;
}

void twocase()
{
  printf( "%.4lf\n" , fabs( p[ 1 ].x - p[ 2 ].x ) * fabs( p[ 1 ].y - p[ 2 ].y ) );
  return ;
}

int main()
{
  while ( init() ) 
    {
      if( n == 1 ) printf("0.0000\n");
      else if( n == 2 ) twocase();
      else if( not sameline() )
        {
          sortleft( 1 , n );
          convex();
          trans();
        }
    }
  return 0;
}
