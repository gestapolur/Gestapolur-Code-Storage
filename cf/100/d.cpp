#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<vector>
#define MAXN 1002
using namespace std;
/*
int n , m ;
int f[ MAXN ][ MAXN ][ 2 ];

int max( int a , int b )
{ return a > b ? a : b ;}

int main()
{
  int i , j , delt ;
  cin>>n>>m;
  f[ 1 ][ 1 ][ 1 ] = 1 ;
  f[ 1 ][ 1 ][ 0 ] = 0 ;
  for( i = 1 ; i <= n ; ++ i )
    for( j = 1 ; j <= m ; ++ j )
      {
        delt = max ( max( f[ i - 1 ][ j ][ 0 ] , f[ i - 1 ][ j ][ 1 ] ) , max( f[ i ][ j - 1 ][ 0 ] , f[ i ][ j - 1 ][ 1 ] ) ) ;
        if( j - 2 > 0 and i - 1 > 0 ) f[ i ][ j ][ 1 ] = f[ i - 1 ][ j - 2 ][ 0 ] + 1 + delt ;
        if( i - 2 > 0 and j - 1 > 0 and f[ i ][ j ][ 1 ] < f[ i - 2 ][ j - 1 ][ 0 ] + 1 + delt ) 
          f[ i ][ j ][ 1 ] = f[ i - 2 ][ j - 1 ][ 0 ] + 1 + delt ;
        //f[ i ][ j ][ 1 ] = max( f[ i - 1 ][ j - 2 ][ 0 ] , f[ i - 2 ][ j - 1 ][ 0 ]) + 1 ;

        if( j - 2 > 0 and i - 1 > 0 ) f[ i ][ j ][ 0 ] = f[ i - 1 ][ j - 2 ][ 1 ] + delt ;
        if( i - 2 > 0 and j - 1 > 0 and f[ i ][ j ][ 0 ] < f[ i - 2 ][ j - 1 ][ 1 ] + delt ) 
          f[ i ][ j ][ 0 ] = f[ i - 2 ][ j - 1 ][ 1 ] + delt;
        //f[ i ][ j ][ 0 ] = max( f[ i - 1 ][ j - 2 ][ 1 ] , f[ i - 2 ][ j - 1 ][ 1 ]);
      }
  cout<<( f[ n ][ m ][ 0 ] > f[ n ][ m ][ 1 ] ? f[ n ][ m ][ 0 ] : f[ n ][ m ][ 1 ] )<<"\n";
  return 0;
}
*/

int main( )
{
  int n , m , tmp ;
  cin>>n>>m;
  if( ( n == 2 or m == 2 ) and ( n not_eq 1 and m not_eq 1 ) )
    {
      if( n == 2 ) n = m ;
      tmp = 0 ;
      if( n >= 4 )
        tmp = n / 4 * 4 ;
      if( n % 4 == 3 or n % 4 == 2 )
        tmp += 4 ;
      else if( n % 4 == 1 )
        tmp += 2 ;
      cout<<tmp<<"\n";
    }
  else if( n not_eq 1 and m not_eq 1 )
    {
      if( ( n * m ) % 2 == 0 )
        cout<<n*m/2<<"\n";
      else
        cout<<n*m/2+1<<"\n";
    }
  else
    {
      if( n == 1 ) n = m;
      cout<<n<<"\n";
    }
  return 0;
}
