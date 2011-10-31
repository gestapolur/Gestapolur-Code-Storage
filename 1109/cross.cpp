#include<iostream>
#include<cmath>
#define ZERO 1e-6
using namespace std;

class point
{
public:
  double x , y ;
};

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
      cout<<p.x<<" "<<p.y<<"\n";
      return 1 ;
    }
  //irregular cross
  if( ( d1 == 0 and betweencmp( c , a , b ) ) or
      ( d2 == 0 and betweencmp( d , a , b ) ) or
      ( d3 == 0 and betweencmp( a , c , d ) ) or
      ( d4 == 0 and betweencmp( b , c , d ) ))
    return 2;
  return 0;
}

int main()
{
  point a , b , c , d ;
  cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y>>d.x>>d.y;
  cout<<segcross( a , b , c , d )<<"\n";
  return 0; 
}
