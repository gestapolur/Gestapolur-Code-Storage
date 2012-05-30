/*
  LCS with record
 */
#include<iostream>
#define MAXN 1002
using namespace std;

int a[ MAXN ] , b[ MAXN ] , ans[ MAXN ];
int f[ MAXN ][ MAXN ];
int rec[ MAXN ][ MAXN ];
int n , m;

void init()
{
  cin>>n;
  for( int i = 1 ; i <= n ; ++ i )
    cin>>a[ i ];
  cin>>m;
  for( int i = 1 ; i <= m ; ++ i )
    cin>>b[ i ];
  return ;
}

void dp()
{
  int i , j;

  for( i = 1 ; i <= n ; ++ i )
    for( j = 1 ; j <= m ; ++ j )
      {
        f[ i ][ j ] = f[ i - 1 ][ j ] ; rec[ i ][ j ] = 1;
        
        if( f[ i ][ j ] < f[ i ][ j - 1 ] )
          { f[ i ][ j ] = f[ i ][ j - 1 ]; rec[ i ][ j ] = 2; }

        if( a[ i ] == b[ j ] and f[ i ][ j ] < f[ i - 1 ][ j - 1 ] + 1 )
          {
            f[ i ][ j ] = f[ i - 1 ][ j - 1 ] + 1;
            rec[ i ][ j ] = 2;
          }
      }
  return ;
}

void gen( int i , int j )
{
  if( i > 0 or j > 0 )
    {
      if( rec[ i ][ j ] == 2 )
        {
          ans[ ++ ans[ 0 ] ] = a[ i ];
          gen( i - 1 , j - 1 ); 
        }
      else if( rec[ i ][ j ] == 1 )
        gen( i - 1 , j );
      else
        gen( i , j - 1 );
    }
  return ;
}

void out()
{
  for( int i = ans[ 0 ] ; i > 0 ; -- i )
    cout<<ans[ i ]<<" ";
  cout<<"\n";
  return ;
}

int main()
{
  init();

  dp();

  gen( n , m );

  out();

  return 0;
}
