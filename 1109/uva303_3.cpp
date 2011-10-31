#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#define ZERO 1.00000e-12
#define MAXN 22
using namespace std;

int n ;
long double ans;
bool crs;

class point
{
public:
  long double x , y ;
};

point up[ MAXN ] , down[ MAXN ] , cp ;

void out()
{
  if( crs ) printf("%.2Lf\n" , ans );
  else printf("Through all the pipe.\n");
  return ;
}

bool init()
{
  scanf("%d" , &n );
  ans = ZERO;
  if( n == 0 ) return false;
  for( int i = 1 ; i <= n ; ++ i )
    {
      //cin>>up[ i ].x>>up[ i ].y;
      scanf("%Lf%Lf",&up[ i ].x,&up[ i ].y );
      down[ i ].x = up[ i ].x;
      down[ i ].y = up[ i ].y - 1.0000000 ;
    }
  return true;
}

long double dot( point a , point b , point c )
{ 
  long double re = ( ( b.x - a.x ) * ( c.x - a.x ) + ( b.y - a.y ) * ( c.y - a.y ) );
  return re;
}

long double cross( point a , point b , point c )
{ 
  long double re = ( (b.x - a.x) * ( c.y - a.y ) - ( b.y - a.y )* ( c.x - a.x ) ) ;
  return re;
}

int dblcmp( long double d )
{ 
  if( fabs( d ) < ZERO )
    return 0;
  return ( d > 0 ? 1 : -1 ) ;
}

int betweencmp( point a , point b , point c )
{ return dblcmp( dot( a , b , c ) ) ;}

bool segcross( point a , point b , point c ,point d , bool isup )
{
  point p;
  int d1 , d2 , d3 , d4 ;
  long double s1 , s2 , s3 , s4 ;

  d1 = dblcmp( s1 = cross( c , a , b ) );
  d2 = dblcmp( s2 = cross( d , a , b ) );
  d3 = dblcmp( s3 = cross( a , c , d ) );
  d4 = dblcmp( s4 = cross( b , c , d ) );
  
  //regular cross
  if( ( d1 ^ d2 ) == -2 and ( d3 ^ d4 ) == -2 )
    {
      //cp.x = ( c.x * s2 - d.x * s1 ) / ( s2 - s1 );
      //cp.y = ( c.y * s2 - d.y * s1 ) / ( s2 - s1 );
      long double k1 , k2 ;
      k1 = ( b.y - a.y ) / ( b.x - a.x );
      k2 = ( d.y - c.y ) / ( d.x - c.x );
      cp.x = ( a.x * k1 - c.x * k2 - a.y + c.y ) / ( k1 - k2 );
      cp.y = k1 * ( cp.x - a.x ) + a.y ;
      return true ;
    }
  
  if( d1 == 0 and betweencmp( c , a , b ) not_eq 1 )
    {
 
      if( isup and dblcmp( cross( d , a , b ) ) == -1 )
        { cp = c ; return true;}
      else if( not isup and dblcmp( cross( d , a , b )) == 1  )
        { cp = c ; return true;}
    }

  return false;
}


void work()
{
  int i , j , k ;
  long double ki;
  point p1 , p2 ;
  // i is up j is down
  for( i = 1 ; i < n ; ++ i )
    for( j = i + 1 ; j <= n ; ++ j )
      {
        p1.x = up[ 1 ].x ; 
        p1.y = ( p1.x - up[ i ].x ) * ( up[ i ].y - down[ j ].y ) / ( up[ i ].x - down[ j ].x )  + up[ i ].y;
        p2.x = up[ n ].x ;
        p2.y = ( p2.x - up[ i ].x ) * ( up[ i ].y - down[ j ].y ) / ( up[ i ].x - down[ j ].x )  + up[ i ].y;       

        if( p1.y >= down[ 1 ].y and p1.y <= up[ 1 ].y )
          {
            crs = false;
            for( k = 1 ; k < n ; ++ k )
              if( segcross( p1 , p2 , up[ k ] , up[ k + 1 ] , true ) 
                  or segcross( p1 , p2 , down[ k ] , down[ k + 1 ] , false ))
                {
                  ans = cp.x > ans ? cp.x : ans; 
                  crs = true;
                  break;
                }

            if( not crs and ( up[ n ].y >= p2.y and p2.y >= down[ n ].y ) )
              return ;
            else crs = true;
          }

        p1.x = down[ 1 ].x ; 
        p1.y = ( p1.x - down[ i ].x ) * ( down[ i ].y - up[ j ].y ) / ( down[ i ].x - up[ j ].x ) + down[ i ].y;
        p2.x = down[ n ].x ;
        p2.y = ( p2.x - down[ i ].x ) * ( down[ i ].y - up[ j ].y ) / ( down[ i ].x - up[ j ].x )  + down[ i ].y;
        

        if( p1.y >= down[ 1 ].y and p1.y <= up[ 1 ].y )
          {
            crs = false;
            for( k = 1 ; k < n ; ++ k )
              if( segcross( p1 , p2 , up[ k ] , up[ k + 1 ] , true ) 
                  or segcross( p1 , p2 , down[ k ] , down[ k + 1 ] , false ) )
                {
                  ans = cp.x > ans ? cp.x : ans; 
                  crs = true;
                  break;
                }
            if( not crs and ( up[ n ].y >= p2.y and p2.y >= down[ n ].y ) )
              return ; 
            else crs = true; 
          }

      }
 
  return ;
}

int main()
{
  while( init() )
    {
      work();
      out();
    }
  return 0;
}
