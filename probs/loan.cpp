/*
  loan
  gestapolur
  2012-05-26
*/
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#define ZERO 0.0000001
using namespace std;

double p , c;
int m;
double mid , rst;

void cal( double rest , int mon )
{
  //cout<<rest<<" "<<mon<<"\n";
  if( mon == m )
    {
      //cout<<rest<<"\n";
      rst = rest;
      return ;
    }
  else
    cal( rest * ( 1 + mid ) - c , mon + 1 );
}

void init()
{
  cin>>p>>c>>m;
  return ;
}

void work()
{
  cout.setf(ios::showpoint|ios::fixed);
  cout.precision( 1 );
  double l , r;
  
  l = 0.0000; r = c * m / p;

  while( fabs( r - l ) > ZERO )
    {
      mid = ( l + r ) / 2;
      cal( p , 0 );
      if( rst > ZERO ) r = mid;
      else if(rst < ZERO ) l = mid + 0.00001;
      else break;
    }
  if( int( mid * 10000 ) - int ( int( mid * 1000 ) * 10 ) >= 5 )
    cout<<mid*100+0.1<<"\n";
  else
    cout<<mid*100<<"\n";

  return ;
}

int main()
{
  init();
  
  work();
  
  return 0;
}
