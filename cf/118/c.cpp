#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#define MAXN 1002
#define MOD 1000000007
using namespace std;

unsigned long long n , ans;
//bool sync_with_stdio( bool sync = false );

unsigned long long resolve( unsigned long long b )
{
  if( b == 2 )
    return 4;
  else if( b == 1 )
    return 2;
  else if( b == 0 )
    return 1;
  else if( b & 1 )
    return resolve( b - 1 ) * 2 % MOD;
  else
    {
      unsigned long long t = resolve( b >> 1 );
      return t * t % MOD;
    }
}

void init()
{
  cin>>n;
  //resolve( 2 * n - 1 );
  if( n )
    ans = ( resolve( 2 * n - 1 ) + resolve( n - 1 ) ) % MOD;
  else
    ans = 1;
  cout<<ans<<"\n";
  return ;
}

int main()
{
  init();
  
  return 0;
}
