/*
  CODEFORCES #120 DIV2 C
  gestapolur
  2012-05-30
*/
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#define MAXN 50002
using namespace std;

int n , ans;
string a[ MAXN ];
int f[ MAXN ][ 27 ][ 27 ];
bool sync_with_stdio( bool sync = false );

void init()
{
  cin>>n;
  for( int i = 1 ; i <= n ; ++ i )
    cin>>a[ i ];
  return ;
}

void dp()
{
  int i , j , k , cnt;

  //init
  ans = 0;
  for( i = 1 ; i <= n ; ++ i )
    if( f[ 1 ][ a[ i ][ 0 ] - 'a' ][ a[ i ][ a[ i ].size() - 1 ] - 'a' ] < a[ i ].size() )
      f[ 1 ][ a[ i ][ 0 ] - 'a' ][ a[ i ][ a[ i ].size() - 1 ] - 'a' ] = a[ i ].size();

  //dp
  for( cnt = 2 ; cnt <= n ; ++ cnt )
     {
       cout<<cnt<<"\n";
       for( i = 0 ; i < 26 ; ++ i )
         {
           f[ cnt ][ i ][ i ] = f[ cnt - 1 ][ i ][ i ];
           for( j = 0 ; j < 26 ; ++ j )
             for( k = 0 ; k < 26 ; ++ k )
               if( f[ cnt ][ i ][ i ] < f[ cnt - 1 ][ i ][ j ] + f[ cnt - 1 ][ j ][ k ] + f[ cnt - 2 ][ k ][ i ] and cnt > 1 and f[ cnt - 1 ][ i ][ j ] and cnt > 2 and f[ cnt - 2 ][ k ][ i ] )
                 {
                   f[ cnt ][ i ][ i ] = f[ cnt - 1 ][ i ][ j ] + f[ cnt - 1 ][ j ][ k ] + f[ cnt - 1 ][ k ][ i ];
                   cout<<char( 'a' + i )<<" "<<char( 'a' + j )<<" "<<char( 'a' + k )<<" "<<f[ cnt ][ i ][ i ]<<"\n";
                 }
         }
     }

  for( i = 0 ; i < 26 ; ++ i )
    ans = ans > f[ n - 1 ][ i ][ i ] ? ans : f[ n - 1 ][ i ][ i ];
  cout<<ans<<"\n";

  return ;
}

int main()
{
  init();
  
  dp();

  return 0;
}
