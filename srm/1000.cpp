#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#define MAXN 53
#define MOD 1000000007
using namespace std;

class SRMSystemTestPhase
{
public:
  long long f[ MAXN ][ MAXN ][ MAXN ];
  int p[ MAXN ];
  int n , m ; 
  long long ans ; 
  int c( int p , int q )
  {
    if( p == q or p == 0 ) return 1 ;
    if( p == 1 ) return q ;
    int del , s , t , i ;
    del = q - p ; s = 1 ;
    for( i = 1 ; i <= del ; ++ i )
      s *= i ; 
    t = p + 1 ;
    for( i = p + 2 ; i <= q ; ++ i )
      t *= i ;
    return t / s ;
  }
  int countWays(vector <string> d)
  {
    ans = 0 ;
    int i , j , k , v , q ;
    n = d.size(); m = d[ 0 ].size();
    memset( p , 0 , sizeof( p ) );
    memset( f , 0 , sizeof( f ) );

    for( i = 0 ; i < n ; ++ i )
      for( j = 0 ; j < m ; ++ j )
        if( d[ i ][ j ] == 'Y' ) ++ p[ n - i - 1 ];
    for( i = 0 ; i <= p[ 0 ] ; ++ i )
      for( j = 0 ; j <= p[ 0 ] - i ; ++ j )
        f[ 0 ][ i ][ j ] = c( i , p[ 0 ] ) * c( j , p[ 0 ] - i );

    for( i = 1 ; i < n ; ++ i )
      for( j = 0 ; j <= p[ i ] ; ++ j )
        for( k = 0 ; k <= p[ i ] - j ; ++ k )
          {
            for( v = 0 ; v < j ; ++ v )
              for( q = 0 ; q <= p[ i - 1 ] - v ; ++ q )
                f[ i ][ j ][ k ] = ( f[ i ][ j ][ k ] + f[ i - 1 ][ v ][ q ] ) % MOD ;
            for( v = p[ i - 1 ] - j ; v >= k  ; -- v )
              f[ i ][ j ][ k ] = ( f[ i ][ j ][ k ] + f[ i - 1 ][ j ][ v ] ) % MOD ;
            f[ i ][ j ][ k ] = ( ( c( j , p[ i ] ) * c( k , p[ i ] - j ) % MOD ) * f[ i ][ j ][ k ] ) % MOD;
          }
    for( i = 0 ; i <= p[ n - 1 ] ; ++ i )
      for( j = 0 ; j <= p[ n - 1 ] - i ; ++ j )
        ans = ( ans + f[ n - 1 ][ i ][ j ] ) % MOD;
    return ans ;
  }
};

int main()
{
  return 0;
}
