#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#define ZERO 1.0e-12
#define pi acos(-1.0)
using namespace std;

long double n , ax , ay , bx , by , ab , len , tri , cir , del ,s ;

bool init()
{
  scanf("%Lf%Lf%Lf%Lf%Lf" , &ax , &ay , &bx , &by , &n );
  //cin>>ax>>ay>>bx>>by>>n;
  if( fabs( ax ) < ZERO and fabs( ay ) < ZERO and fabs( bx ) < ZERO and fabs( by ) < ZERO and fabs( n ) < ZERO )
    return false;
  return true;
}

void work()
{
  ab = sqrt ( pow( ax - bx , 2 ) + pow( ay - by , 2 ) ) ;
  
  if( int( n ) & 1 == 0 )
    tri = sin( 2 * pi / n ) * pow( ab / 2 , 2 ) * 0.50000000;
  else
    {
      len = ab * 0.50000000 / sin( pi * int ( n / 2 ) / n );
      tri = sin( 2 * pi / n ) * pow( len , 2 ) * 0.50000000;
    }
  s = n * tri ; 
  printf("%.6Lf\n" , s );
  return ;
}

int main()
{
  while( init() )
    {
      work();
    }
}
