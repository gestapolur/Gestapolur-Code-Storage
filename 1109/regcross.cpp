/*
  CTG : regular cross
  write by gestapolur
  20110927
*/
#include<iostream>
#include<cmath>
#define ZERO 1e-10
using namespace std;

class point
{
public:
  double x , y;
};

point a , b , c , d ;

int dblcmp( double d )
{
  if( fabs( d ) < ZERO )
    return 0 ;
  return ( d > 0 ? 1 : -1 ) ;
}

//cross mul
double det( double x1 , double y1 , double x2 , double y2 )
{ return x1 * y2 - x2 * y1 ;}

//check the position that c is at the right or left side of ab;
double cross( point a , point b , point c )
{ return det( b.x - a.x , b.y - a.y , c.x - a.x , c.y - a.y ); }

int segcrosssimple( point a , point b , point c , point d )
{
  //a , b in cd 's different side , c , d in ab's different side
  //cout<<cross( a , c , d )<<" "<<cross( b , c , d )<<" "<<cross( c , a , b )<<" "<<cross( d , a , b )<<"\n";
  return ( ( dblcmp( cross( a , c , d ) ) ^ dblcmp( cross( b , c , d ) ) )== -2 
           and ( dblcmp( cross( c , a , b ) ) ^ dblcmp( cross( d , a , b ) ) == -2 ) );
}

int main()
{
  point a , b , c ,d ;
  cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y>>d.x>>d.y;
  cout<<segcrosssimple( a , b , c ,d )<<"\n";
  return 0;
}
