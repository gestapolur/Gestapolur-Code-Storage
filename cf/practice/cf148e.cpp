/*
  CF148E
  2012-02-17
  ACCEPTED
*/
#include<iostream>
#include<cstring>
#define MAXN 102
#define MAXM 10002
using namespace std;

int n , m ;
int f[ MAXN ][ MAXM ];
int g[ MAXN ][ MAXN ] , gt[ MAXN ][ MAXN ][ MAXN ];
int w[ MAXN ][ MAXN ] , v[ MAXN ];

void init()
{
  cin>>n>>m;
  for( int i = 1 ; i <= n ; ++ i )
    {
      cin>>v[ i ];
      for( int j = 1 ; j <= v[ i ] ; ++ j )
        cin>>w[ i ][ j ];
    }
  return ;
}

int max( int a , int b ) { return a > b ? a : b ; }

void dp1()
{
  int i , j , k , t ;

  for( k = 1 ; k <= n ; ++ k )
    {
      for( t = 1 ; t <= v[ k ] ; ++ t )
        {
          for( i = 1 ; i <= v[ k ] ; ++ i )
            {
              gt[ i ][ i ][ t ] = w[ k ][ i ];
              for( j = 1 ; i + j <= v[ k ] ; ++ j )
                {
                  gt[ i ][ i + j ][ t ] = max( gt[ i + 1 ][ i + j ][ t - 1 ] + w[ k ][ i ] , gt[ i ][ i + j - 1 ][ t - 1 ] + w[ k ][ i + j ] );
                  //g[ k ][ t ] = g[ k ][ t ] > gt[ i ][ i + j ][ t - 1 ] ? g[ k ][ t ] : gt[ i ][ i + j ][ t ];
                }
            }
          g[ k ][ t ] = gt[ 1 ][ v[ k ] ][ t ];
        }
    }
  //test
  /*
  for( i = 1 ; i <= n ; ++ i )
    {
      for( j = 1 ; j <= v[ i ] ; ++ j )
        cout<<g[ i ][ j ]<<" ";
      cout<<"\n";
    }
  */
  return ;
}

void dp2()
{
  int i , j , k ;
  memset( f , 0 , sizeof( f ) );

  for( i = 1 ; i <= n ; ++ i )
    {
      for( j = 1 ; j <= m ; ++ j )
        for( k = 0 ; k <= v[ i ] ; ++ k )
          if( j - k >= 0 and f[ i ][ j ] < f[ i - 1 ][ j - k ] + g[ i ][ k ] )
            f[ i ][ j ] = f[ i - 1 ][ j - k ] + g[ i ][ k ];
    }
  cout<<f[ n ][ m ]<<"\n";
  return ;
}

int main()
{

  init();

  dp1();

  dp2();

  return 0;
}
