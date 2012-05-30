/**/
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#define MAXN 1002
using namespace std;

long long n;

bool sync_with_stdio( bool sync = false );

void init()
{
  cin>>n;
  return ;
}

bool work()
{
  long long tans;
  long long l1 , l2 , r1 , r2 , k1 , k2;
  
  l1 = 0 , r1 = sqrt( 2 * n ) + 1;
  k1 = 1;
  while( k1 <= r1 )
    {
      l2 = 1; r2 = k1;
      while( l2 <= r2 )
        {
          k2 = l2 + r2 >> 1;
          tans = k1 * ( k1 + 1 ) + k2 * ( k2 + 1 );
          
          if( tans == 2 * n )  
            return true;
          else if( l2 == r2 )
            break;
          else if( tans < 2 * n )
            l2 = k2 + 1;
          else
            r2 = k2;
        }
      ++ k1;
    }
  return false;
}

int main()
{
  init();
  if ( work() ) cout<<"YES\n";
  else cout<<"NO\n";

  return 0;
}
