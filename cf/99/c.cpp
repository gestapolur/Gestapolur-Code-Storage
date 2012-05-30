#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
#define MAXN 100003 
using namespace std;

int n , cnt ;
int a[ MAXN ] , b[ MAXN ] ;
int mark[ MAXN ] , fa[ MAXN ] , fb[ MAXN ];
bool in[ MAXN ];

void init()
{
  cin>>n;
  for( int i = 1 ; i <= n ; ++ i )
    cin>>a[ i ]>>b[ i ];
  //cout<<"!!\n";
  return ;
}

void fsort( int i , int j )
{
  if( i >= j ) return ;
  int n , m , t , k;
  m = i , n = j , k = fb[ i + j >> 1 ];
  while( m <= n )
    {
      while( fb[ m ] < k )
        ++ m ;
      while( fb[ n ] > k )
        -- n ;
      if( m <= n )
        { 
          t = fa[ m ] ; fa[ m ] = fa[ n ] ; fa[ n ] = t; 
          t = fb[ m ] ; fb[ m ] = fb[ n ] ; fb[ n ] = t;
          t = mark[ m ] ; mark[ m ] = mark[ n ] ; mark[ n ] = t; 
          ++ m ; -- n;
        }
    }
  fsort( i , n );
  fsort( m , j );
  return ;
}

void sort( int i , int j )
{
  if( i >= j ) return ;
  int n , m , t , k;
  m = i , n = j , k = a[ i + j >> 1 ];
  while( m <= n )
    {
      while( a[ m ] < k )
        ++ m ;
      while( a[ n ] > k )
        -- n ;
      if( m <= n )
        { 
          t = a[ m ] ; a[ m ] = a[ n ] ; a[ n ] = t; 
          t = b[ m ] ; b[ m ] = b[ n ] ; b[ n ] = t;
          ++ m ; -- n;
        }
    }
  sort( i , n );
  sort( m , j );
  return ;
}

void work()
{
  sort( 1 , n );
  //cout<<"!!!\n";
  for( int i = 1 ; i <= n ; ++ i )
    { fa[ i ] = a[ i ] ; fb[ i ] = b[ i ] ; mark[ i ] = i ; }
  fsort( 1 , n );

  for( int i = 1 ; i <= n ; ++ i )
    {
      for( int j = mark[ i ] ; j <= n ; ++ j )
        if( not in[ mark[ j ] ] and a[ mark[ j ] ] < a[ i ] )
          { ++ cnt ; in[ mark[ j ] ] = true; }
    }
  cout<<cnt<<"\n";
  return ;
}

int main()
{
  
  init();
  
  work();

  return 0;
}
