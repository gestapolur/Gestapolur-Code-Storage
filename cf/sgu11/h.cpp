#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#define MAXN 201
#define MAXM 500000
using namespace std;

/*
ifstream cin("input.txt");
ofstream cout("output.txt");
*/

int n , m ; 
short int w[ MAXM ][ MAXN ];
bool vis[ MAXN ] ;
int lnk[ MAXN ];

bool find( int x )
{
  for( int i = 1 ; i <= w[ x ][ 0 ] ; ++ i )
    if( not vis[ w[ x ][ i ] ] )
      {
        vis[ w[ x ][ i ] ] = true ;
        if( lnk[ w[ x ][ i ] ] == 0 or find( lnk[ w[ x ][ i ] ] ) )
          {
            lnk[ w[ x ][ i ] ] = x ;
            return true ;
          }
      }
  return false ;
}

void output( int x )
{
  while( x > 0 ){
    cout<<char( x % 27 + 'a' - 1 );
    x /= 27;
  }
  cout<<"\n";
  return ;
}

void hungary()
{
  int i , cnt = 0 ;
  for( i = 0 ; i <= m ; ++ i )
    if( w[ i ][ 0 ] > 0 )
      {
        memset( vis , 0 , sizeof( vis ) );
        if( find( i ) ) ++ cnt ;
        if( cnt == n ) break;
      }
  
  //cout<<cnt<<"\n"; for( i = 1 ; i <= n ; ++ i ) cout<<lnk[ i ]<<" "; cout<<"\n";
  if( cnt not_eq n ){ cout<<"-1\n"; }
  else
    for( i = 1 ; i <= n ; ++ i )
      output( lnk[ i ] );
  return ;
}

void add( int a , int b , int c , int d , int idx )
{
  int cnt = 0 , hashs = 0 ;
  if( a > 0 ) { hashs += a ; ++ cnt ; }
  if( b > 0 ) { hashs += b * pow( 26 , cnt ); ++ cnt ; }
  if( c > 0 ) { hashs += c * pow( 26 , cnt ); ++ cnt ; }
  if( d > 0 ) { hashs += d * pow( 26 , cnt ); }
  w[ hashs ][ ++ w[ hashs ][ 0 ] ] = idx ;
  //w[ idx ][ ++ w[ idx ][ 0 ] ] = hashs ;
  //cout<<hashs<<" "<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
  m = hashs > m ? hashs : m ;
  return ;
}

int main()
{
  string w ;
  int i , j , k , v , vv , tn ;
  cin>>n;
  for( i = 1 ; i <= n ; ++ i )
    {
      cin>>w;
      tn = w.size();
      for( j = 0 ; j < tn ; ++ j )
        add( w[ j ] - 'a' + 1 , 0 , 0 , 0 , i );

      for( j = 0 ; j < tn ; ++ j )
        for( k = j + 1 ; k < tn ; ++ k )
          add( w[ j ] - 'a' + 1 , w[ k ] - 'a' + 1 , 0 , 0 , i );

      for( j = 0 ; j < tn ; ++ j )
        for( k = j + 1 ; k < tn ; ++ k )
          for( v = k + 1 ; v < tn ; ++ v )
            add( w[ j ] - 'a' + 1 , w[ k ] - 'a' + 1 , w[ v ] - 'a' + 1 , 0 , i );

      for( j = 0 ; j < tn ; ++ j )
        for( k = j + 1 ; k < tn ; ++ k )
          for( v = k + 1 ; v < tn ; ++ v )
            for( vv = v + 1 ; vv < tn ; ++ vv )
              add( w[ j ] - 'a' + 1 , w[ k ] - 'a' + 1 , w[ v ] - 'a' + 1 , w[ vv] - 'a' + 1 , i );

    }

  hungary();

  return 0;
}
