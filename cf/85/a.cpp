#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#define MAXN 102
using namespace std;

int n;
char a[ MAXN ][ MAXN ];

void work()
{
  int i , j , col ;
  cin>>n;
  
      col = 0 ;
      for( i = 2 ; i <= n ; i += 2 )
        {
          a[ 1 ][ i ] = char( 97 + col );
          a[ 1 ][ i - 1 ] = char( 97 + col );
          col = ( col + 1 ) % 26;
          a[ 2 ][ i ] = char( 97 + col );
          a[ 2 ][ i - 1 ] = char( 97 + col );
          col = ( col + 1 ) % 26;
        }
      if( i == n + 1 )
        {
          a[ 1 ][ n ] = char( 97 + col );
          a[ 2 ][ n ] = char( 97 + col );
          col = ( col + 1 ) % 26 ;
        }      
      while( a[ 2 ][ 1 ] == char( 97 + col ) )
        col = ( col + 1 ) % 26;
      a[ 3 ][ 1 ] = char( 97 + col );
      a[ 4 ][ 1 ] = char( 97 + col );
      col = ( col + 1 ) % 26;
      for( i = 3 ; i <= n ; i += 2 )
        {
          while( char( 97 + col ) == a[ 2 ][ i ] or char( 97 + col ) == a[ 2 ][ i - 1 ] )
            col = ( col + 1 ) % 26; 
          a[ 3 ][ i ] = char( 97 + col );
          a[ 3 ][ i - 1 ] = char( 97 + col );
          col = ( col + 1 ) % 26;
          a[ 4 ][ i ] = char( 97 + col );
          a[ 4 ][ i - 1 ] = char( 97 + col );
          col = ( col + 1 ) % 26;          
        }
      if( i == n + 1 )
        {
          while( char( 97 + col ) == a[ 2 ][ n ] )
            col = ( col + 1 ) % 26;
          a[ 3 ][ n ] = char( 97 + col );
          a[ 4 ][ n ] = char( 97 + col );
          col = ( col + 1 ) % 26 ;
        }
      
  
  for( i = 1 ; i <= 4 ; ++ i )
    {
      for( j = 1 ; j <= n ; ++ j )
        cout<<a[ i ][ j ];
      cout<<"\n";
    }
  return ;
}

int main()
{

  work();

  return 0;
}
