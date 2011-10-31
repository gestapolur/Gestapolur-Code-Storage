#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<cstdio>
//using namespace std;

long long n , k , sum ;
const long long MOD = 1000000007;
/*
inline long long mod( long long x , long long y , long long m )
{
  if( y == 1 )
    return ( x % m );
  else if( y == 2 )
    return ( x * x % m );
  else
    {
      int mid = y >> 1 ;
      return ( ( mod( x , mid , m ) * mod( x , y - mid , m ) ) % m );
    }
}
*/

long long mod( long long x , long long y )
{
  long long ans = 1;
  x %= MOD ;
  while( y > 0 )
    {
      if( ( y & 1 ) == 1 ) ans = ( ans * x ) % MOD ;
      y >>= 1 ;
      x = ( x * x ) % MOD;
    }
  return ans;
}

int main()
{
  //scanf( "%lld%lld" , &n , &k );
  //printf( "%lld\n" , mod( n , k , 7 ) );
  
  while( scanf( "%lld%lld" , &n , &k ) not_eq EOF )
    {
      sum = mod( 2 , k ) - 1 ;
      sum = mod( sum , n );
      printf( "%lld\n" , sum );
    }
 
  return 0;
}
