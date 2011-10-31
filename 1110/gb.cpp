//UVA CG CONTEST
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#define ZERO 1.0e-12
#define DEG 180.0000
using namespace std;

long double acb , cae , eab , cbd , dba;

bool init()
{
  scanf("%Lf%Lf%Lf%Lf%Lf" , &acb , &cae , &eab , &cbd , &dba );
  if( fabs( acb ) < ZERO and fabs( cae ) < ZERO and fabs( eab ) < ZERO and fabs( cbd ) < ZERO and fabs( dba ) < ZERO) return false;
  return true;
}

void work()
{
  if(  acb + cae + eab + cbd + dba - DEG < -ZERO or acb + cae + eab + cbd + dba - DEG > ZERO ) { printf("Impossible\n"); return ; }
  long double e1 , e2 , aeb ;
  aeb = DEG - ( dba + cbd + eab );
  e1 = eab + dba ;// x + y 
  e2 = DEG - ( acb + cae );// x + a
  e3 = DEG - aeb;//180 - aeb -> x + a
  e2 = ( e2 - e3 ) / 2 ; //2x - a 
  printf("%.2Lf\n" , e2 );
  return ;
}

int main()
{
  while( init() )
    work();
  return 0;
}
