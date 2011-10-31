//#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#define MAXN 100001
#define MAXP 2002 
//using namespace std;

const double ZERO = 1e-12;

int n , minr ,  minc , dr , dc ;
double r ;

class point
{
public:
  double x , y ;
};

point p[ MAXP ] ;

bool init()
{
  //cin>>n>>r;
  scanf("%d%lf" , &n , &r );
  if( n == 0 and r < ZERO ) return false ;
  minr = minc = 1 << 20 ; dr = dc = - ( 1 << 20 ) ;
  for( int i = 1 ; i <= n ; ++ i )
    scanf("%lf%lf" , &p[ i ].x , &p[ i ].y );
  return true ;
}

inline double dist( double x1 , double y1 , double x2 , double y2 )
{ return ( sqrt( ( x1 - x2 )*( x1 - x2 ) + ( y1 - y2 )*( y1 - y2 ) ) ); }

void work()
{
  int ans = 0 ;
  double tx , ty , tl , r2 , del ;
  int i , j , tmp ;
  r2 = r * r;
  for( i = 1 ; i <= n ; ++ i )
    {
      tl = p[ i ].x + r ;
      for( tx = p[ i ].x - r ; tx <= tl ; tx = tx + 1 )
        {
          /*
          if( tx < 0.1 and tx > - 0.1 )
            {
              //cout<<tx<<" "<<ty<<"\n";cin.get();
            }
          */
          del = sqrt( r2 - pow( tx - p[ i ].x , 2 ) ) ;
          ty = del - p[ i ].y;
          tmp = 0 ; 
          for( j = 1 ; j <= n ; ++ j )
            if(  r - dist( p[ j ].x , p[ j ].y , tx , ty ) > - ZERO )
              ++ tmp;
          ans = tmp > ans ? tmp : ans;

          ty = del + p[ i ].y;
          tmp = 0 ; 
          for( j = 1 ; j <= n ; ++ j )
            if( r - dist( p[ j ].x , p[ j ].y , tx , ty ) > - ZERO )
              ++ tmp;
          ans = tmp > ans ? tmp : ans;

        }
    }

  printf("It is possible to cover %d points.\n" , ans );
  return ;
}

int main()
{
  while( init() )
    work();
  return 0;
}
