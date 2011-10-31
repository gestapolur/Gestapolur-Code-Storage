//timus1163
#include<iostream>
#include<cmath>
#define PREC 0.01
#define MAXC 17
using namespace std;

int v[ MAXC ][ 2 ]; 
bool f[ MAXC ][ MAXC ][ 2 ];//

double dist( double x1 , double y1 , double x2 , double y2 )
{ return sqrt( ( x1 - x2 ) * ( x1 - x2 ) + ( y1 - y2 )*( y1 - y2 ) ); }

void init()
{
  int i;
  for( i = 1 ; i < MAXC ; ++ i )
    cin>>v[ i ][ 0 ]>>v[ i ][ 1 ];
  return ;
}

void cal()
{
  for( i = 1 ; i <= 8 ; ++ i )
    {
      
    }
 
  return ;
}

void dp()
{
  return ;
}

int main()
{

  init();
  cal();
  dp();

  return 0;
}
