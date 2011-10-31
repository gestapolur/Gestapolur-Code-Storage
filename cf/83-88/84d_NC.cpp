#include<iostream>
#define MAXN 10005
using namespace std;

int pr , pl , vr , vl , dist; 
int pmin , pmax , vmin , vmax ;
double ans;
const int dl[ 10 ][ 2 ] = { 4 , 7 , 44 ,4};

int dig( int x )
{
  int cnt = 0;
  while( x > 0 )
    { ++ cnt ; x /= 10 ;}
  return cnt;
}

int cur1( int x )
{
  if( )
  return ;
}

int cur2( int x )
{

  return ;
}

void cnt()
{
  pmin = dig( pl / 10 ) + cur1( dig( pl ) );
  vmin = dig( vl / 10 ) + cur1( dig( vl ) );
  pmax = dig( pr / 10 ) + cur2( dig( pr ) );
  vmax = dig( vr / 10 ) + cur2( dig( vr ) );
  return ;
}

void work()
{
  cout.setf(ios::showpoint || ios::fixed );
  cout.precision( 10 );
  ans = double( pmax - pmin ) / double ( pr - pl ) * double ( vr - vl ) * double( vmax - vmin );
  cout<<ans<<"\n";
  return ;
}

int main()
{
  cin>>pl>>pr>>vl>>vr>>dist;
  cnt();
  pro();
  return 0;
}
