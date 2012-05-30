#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#define MAXN 1002
#define PIE 3.141592653589793
using namespace std;

int n;
double r[ MAXN ] ;

void init()
{
  cout.setf(ios::showpoint|ios::fixed);
  cout.precision(12);
  cin>>n;
  for( int i = 1 ; i <= n ; ++ i )
    cin>>r[ i ];
  for( int i = 1 ; i <= n ; ++ i )
    for( int j = 1 ; j < i ; ++ j )
      if( r[ i ] > r[ j ] )
        { double t = r[ i ] ; r[ i ] = r[ j ] ; r[ j ] = t ; }

  double ans = 0.0000000000000;
  for( int i = 1 ; i <= n ; ++ i )
    if( i % 2 == 0 )
      ans -= r[ i ] * r[ i ];
    else
      ans += r[ i ] * r[ i ];
  ans *= PIE;
  cout<<ans<<"\n";
  return ;
}

int main()
{
  init();
  
  return 0;
}
