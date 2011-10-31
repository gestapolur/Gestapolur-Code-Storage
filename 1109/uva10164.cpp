//UVA 10164
#include<iostream>
#include<cstring>
#define MAXN 1 << 12
using namespace std;

int n , m , ans ;
bool chs[ MAXN ];
int a[ MAXN ] , b[ MAXN ] , cnt[ MAXN ][ MAXN ] , sv[ MAXN ] , tc[ MAXN ];

bool init()
{
  ans = 0 ;
  memset( chs , 0 , sizeof( chs ) );
  memset( tc , 0 , sizeof( tc ) );
  cin>>n;
  if( n == 0 ) return false;
  m = 2 * n - 1 ;
  for( int i = 1 ; i <= m ; ++ i )
    {
      cin>>a[ i ];
      cnt[ i ][ 0 ] = 0 ;
      b[ i ] = a[ i ];
    }
  return true;
}

void work( )
{
  int i , j ;
  int cur = 2 ;
  while( cur < n )
    {
      for( i = 1 ; i < m ; ++ i )
        {
          bool pair = false;
          for( j = i + 1 ; j <= m ; ++ j )
            {
              if( ( chs[ i ] | chs[ j ] ) == 0 and ( ( a[ i ] + a[ j ] ) & 1 ) == 0 )
                {
                  a[ i ] += a[ j ];
                  cnt[ i ][ ++ cnt[ i ][ 0 ] ] = j ;
                  chs[ j ] = true;
                  a[ i ] >>= 1 ;
                  pair = true;
                }
              if( pair ) break;
            }
        }
      cur <<= 1 ;
    }
  return ;
}

void out( int x )
{
  sv[ ++ ans ] = x;
  while( cnt[ x ][ 0 ] > 0 )
    out( cnt[ x ][ cnt[ x ][ 0 ] -- ] );
  return ;
}

void ct( int x , int y )
{
  tc[ x ] += cnt[ y ][ 0 ];
  for( int i = 1 ; i <= cnt[ y ][ 0 ] ; ++ i )
    ct( x , cnt[ y ][ i ] );
  return ;
}

void output()
{
  int i , j ;
  //for( i = 1 ; i <= m ; ++ i ) cout<<a[ i ]<<" ";cout<<"\n";
  //for( i = 1 ; i <= m ; ++ i ) cout<<chs[ i ]<<" ";cout<<"\n"; 
  //for( i = 1 ; i <= m ; ++ i ) cout<<cnt[ i ][ 0 ]<<" ";cout<<"\n";
  for( i = 1 ; i <= m ; ++ i ) ct( i , i );
  for( i = 1 ; i < m ; ++ i )
    for( j = i + 1 ; j <= m ; ++ j )
      if( ( chs[ i ] | chs[ j ] ) == 0 and ( a[ i ] + a[ j ] & 1 ) == 0 
          and ( tc[ i ] + tc[ j ] + 2 == n ) )
        {
          out( i ) ; out( j );
          cout<<"Yes\n";
          for( i = 1 ; i < ans ; ++ i ) cout<<b[ sv[ i ] ]<<" ";
          cout<<b[ sv[ ans ] ]<<"\n";
          return ;
        }
  cout<<"No\n";
  return ;
}

int main()
{
  while( init() )
    {
      work();
      output();
    }
  
  return 0 ;
}
