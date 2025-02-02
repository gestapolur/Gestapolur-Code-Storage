#include<cstdlib>
#include<cstdio>
#include<cmath>
#define ZERO 1.00000e-12
#define MAXN 22

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
  //cout.setf(ios::fixed|ios::showpoint);
  //cout.precision( 2 );
  if( crs )
    {
      //if ( int( ans * 1000 ) / 10 - int( ans * 100 ) >= 5 )
        printf("%.2Lf\n" , ans );
        //else printf("%.2Lf\n" , ans );
    }
    //cout<<ans<<"\n";
  else
    printf("Through all the pipe.\n");
  return ;
}

bool init()
{
  scanf("%d" , &n );
  ans = ZERO;
  if( n == 0 ) return false;
  for( int i = 1 ; i <= n ; ++ i )
    {
      scanf("%Lf%Lf",&up[ i ].x,&up[ i ].y );
      //cin>>up[ i ].x>>up[ i ].y;
      down[ i ].x = up[ i ].x;
      down[ i ].y = up[ i ].y - 1.0000000 ;
    }
  return true;
}

long double det( long double x1 , long double y1 , long double x2 , long double y2 )
{ return ( x1 * y2 - x2 * y1 );}

long double dotdet( long double x1 , long double y1 , long double x2 , long double y2 )
{ return ( x1 * x2 + y1 * y2 );}

long double dot( point a , point b , point c )
{ return dotdet( b.x - a.x , b.y - a.y , c.x - a.x , c.y - a.y );}

long double cross( point a , point b , point c )
{ return det( b.x - a.x , b.y - a.y , c.x - a.x , c.y - a.y );}

int dblcmp( long double d )
{ 
  if( fabs( d ) < ZERO )
    return 0;
  return d > 0 ? 1 : -1;
}

int betweencmp( point a , point b , point c )
{ return dblcmp( dot( a , b , c ) ) ;}

bool segcross( point a , point b , point c ,point d , bool isup )
{
  point p;
  int d1 , d2 , d3 , d4 ;
  long double s1 , s2 , s3 , s4 ;
  /*
  d1 = dblcmp( s1 = cross( a , b , c ) );
  d2 = dblcmp( s2 = cross( a , b , d ) );
  d3 = dblcmp( s3 = cross( c , d , a ) );
  d4 = dblcmp( s4 = cross( c , d , b ) );
  */
  d1 = dblcmp( s1 = cross( c , a , b ) );
  d2 = dblcmp( s2 = cross( d , a , b ) );
  d3 = dblcmp( s3 = cross( a , c , d ) );
  d4 = dblcmp( s4 = cross( b , c , d ) );
  
  //regular cross
  if( ( d1 ^ d2 ) == -2 and ( d3 ^ d4 ) == -2 )
    {
      cp.x = ( c.x * s2 - d.x * s1 ) / ( s2 - s1 );
      cp.y = ( c.y * s2 - d.y * s1 ) / ( s2 - s1 );
      return true ;
    }
  
  //cout<<"not reg "<<a.x<<" "<<a.y<<" "<<b.x<<" "<<b.y<<" ";
  //cout<<c.x<<" "<<c.y<<" "<<d.x<<" "<<d.y<<" "<<idx<<" "<<d1<<"\n";
  if( d1 == 0 and betweencmp( c , a , b ) not_eq 1 )
    {
      //if( a.x == 0 and a.y == 0 and b.x == 3 and c.x == 2 and c.y == 0 )
      //cout<<c.x<<" "<<c.y<<" "<<d.x<<" "<<d.y<<" "<<a.x<<" "<<a.y<<" "<<b.x<<" "<<b.y<<" "<<isup<<" "<<cross( d , a , b )<<"!\n";
      if( isup and dblcmp( cross( d , a , b ) ) == -1 )
        { cp = c ; return true;}
      else if( not isup and dblcmp( cross( d , a , b )) == 1  )
        { cp = c ; return true;}
      //cout<<"!\n";
    }

  return false;
}


void work()
{
  //cout.setf(ios::fixed|ios::showpoint);
  //cout.precision( 3 );

  int i , j , k ;
  long double ki;
  point p1 , p2 ;
  // i is up j is down
  for( i = 1 ; i < n ; ++ i )
    for( j = i + 1 ; j <= n ; ++ j )
      {
        /*
        ki = ( up[ i ].y - down[ j ].y ) / ( up[ i ].x - down[ j ].x ) ;
        p1.x = up[ 1 ].x ; 
        p1.y = ( p1.x - up[ i ].x ) * ki + up[ i ].y;
        p2.x = up[ n ].x ;
        p2.y = ( p2.x - up[ i ].x ) * ki + up[ i ].y;
        */
        p1.x = up[ 1 ].x ; 
        p1.y = ( p1.x - up[ i ].x ) * ( up[ i ].y - down[ j ].y ) / ( up[ i ].x - down[ j ].x ) + up[ i ].y;
        p2.x = up[ n ].x ;
        p2.y = ( p2.x - up[ i ].x ) * ( up[ i ].y - down[ j ].y ) / ( up[ i ].x - down[ j ].x ) + up[ i ].y;
       

        //cout<<i<<" "<<j<<" "<<p1.x<<" "<<p1.y<<" ";
        //cout<<p2.x<<" "<<p2.y<<"\n";
        if( p1.y >= down[ 1 ].y and p1.y <= up[ 1 ].y )
          {
            crs = false;
            for( k = 1 ; k < n ; ++ k )
              if( segcross( p1 , p2 , up[ k ] , up[ k + 1 ] , true ) 
                  or segcross( p1 , p2 , down[ k ] , down[ k + 1 ] , false ))
                {
                  //cout<<i<<" "<<j<<" "<<p1.x<<" "<<p1.y<<" ";
                  //cout<<p2.x<<" "<<p2.y<<" "<<cp.x<<" "<<cp.y<<" "<<k<<"\n";
                  ans = cp.x > ans ? cp.x : ans; 
                  crs = true;
                  break;
                }
            //if( i == 1 and j == 2 ) cout<<crs<<" "<<p2.x<<" "<<p2.y<<" "<<up[ n ].y<<" "<<down[ n ].y<<"\n";
            if( not crs and ( up[ n ].y >= p2.y and p2.y >= down[ n ].y ) )
              return ;//{ cout<<i<<" "<<j<<"\n";return ;}
            else crs = true;
          }
        /*
        ki = ( down[ i ].y - up[ j ].y ) / ( down[ i ].x - up[ j ].x ) ;
        p1.x = down[ 1 ].x ; 
        p1.y = ( p1.x - down[ i ].x ) * ki + down[ i ].y;
        p2.x = down[ n ].x ;
        p2.y = ( p2.x - down[ i ].x ) * ki + down[ i ].y;
        */
        p1.x = down[ 1 ].x ; 
        p1.y = ( p1.x - down[ i ].x ) * ( down[ i ].y - up[ j ].y ) / ( down[ i ].x - up[ j ].x ) + down[ i ].y;
        p2.x = down[ n ].x ;
        p2.y = ( p2.x - down[ i ].x ) * ( down[ i ].y - up[ j ].y ) / ( down[ i ].x - up[ j ].x ) + down[ i ].y;
        

        if( p1.y >= down[ 1 ].y and p1.y <= up[ 1 ].y )
          {
            crs = false;
            for( k = 1 ; k < n ; ++ k )
              if( segcross( p1 , p2 , up[ k ] , up[ k + 1 ] , true ) 
                  or segcross( p1 , p2 , down[ k ] , down[ k + 1 ] , false ) )
                {
                  //tans = dist( p1.x , p1.y , cp.x , cp.y );
                  //cout<<i<<" "<<j<<" "<<p1.x<<" "<<p1.y<<" ";
                  //cout<<p2.x<<" "<<p2.y<<" "<<cp.x<<" "<<cp.y<<" "<<k<<" d\n";  
                  ans = cp.x > ans ? cp.x : ans; 
                  crs = true;
                  break;
                }
            if( not crs and ( up[ n ].y >= p2.y and p2.y >= down[ n ].y ) )
              return ; //{ cout<<i<<" "<<j<<"!\n";return ;}
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
