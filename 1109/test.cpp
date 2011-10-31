#include<iostream>
#include<cmath>
#define pi 3.1415926
using namespace std;

class point
{
public:
  double x , y ;
};

//deg(ba,bc)
double deg( point a , point b , point c )
{
  double k1 , k2 , degr , t ;
  k1 = ( a.y - b.y ) / ( a.x - b.x );
  k2 = ( c.y - b.y ) / ( c.x - b.x );
  degr = atan( t = ( k2 - k1 ) / ( 1 + k1 * k2 ) ) ;
  //return degr > 0 ? degr : degr + pi ;
  cout<<degr<<" "<<t<<"\n";
  return degr;
}

void dlcmp( int d )
{}

void dotdet( point a , point b , point c )
{
  return dot( b.x - a.x , b.y - a.y , c.x - a.x , c.y - a.y );
}

int betweencmp( point a , point b , point c  )
{
  return dlcmp( dotdet( a , b , c ) ) ;
}

int main()
{
  point a , b , c ;
  cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y;
  cout<<deg( a , b , c )*180/pi<<"\n";
  return 0;
}
