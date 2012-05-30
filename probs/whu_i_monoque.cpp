/*
  2012 WHU I
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#define MAXN 1002
#define MAXL 100
using namespace std;

typedef int bigint[ MAXL ];
int h , n , hs;//hs = heapsize

struct queue
{
  bigint val , sum;
  int idx;
} q[ MAXN ];

inline void add( bigint a , bigint b )
{
  a[ 0 ] = a[ 0 ] > b[ 0 ] ? a[ 0 ] : b[ 0 ];
  for( int i = 1 ; i <= a[ 0 ] ; ++ i )
    {
      a[ i ] += b[ i ];
      if( a[ i ] >= 10 )
        {
          a[ i ] -= 10;
          ++ a[ i + 1 ];
        }
    }
  while( a[ a[ 0 ] + 1 ] ) ++ a[ 0 ];

  return ;
}

inline void add( bigint a , int b )
{
  int i = 1;
  a[ 1 ] += b;
  while( a[ i ] >= 10 )
    {
      a[ i + 1 ] += a[ i ] / 10;
      a[ i ] %= 10;
      ++ i;
    }
  while( a[ a[ 0 ] + 1 ] ) ++ a[ 0 ];
  
  return ;
}

inline bool cmp( bigint a , bigint b )
{
  if( a[ 0 ] > b[ 0 ] ) return true;
  else if( a[ 0 ] < b[ 0 ] ) return false;
  for( int i = a[ 0 ] ; i ; -- i )
    if( a[ i ] > b[ i ] ) return true;
    else if( a[ i ] < b[ i ] ) return false;
  return false;
}

inline void heapify( int i )
{
  int l , r , mx;
  l = i << 1;
  r = ( i << 1 ) + 1;
  if( l <= hs and cmp( q[ l ].sum , q[ mx ].sum ) )
    mx = l;
  else 
    mx = i;
  if( r <= hs and cmp( q[ r ].sum , q[ mx ].sum ) )
    mx = r;

  if( mx != i )
    {
      queue t = q[ mx ]; q[ mx ] = q[ i ]; q[ i ] = t;
      heapify( mx );
    }
  return ;
}

void qadd( bigint val , int idx )
{
  if( cmp( val , q[ 1 ].val ) or idx > q[ 1 ].idx )
    {
      int tmp;
      ++ hs;
      q[ hs ].val = val;
      q[ hs ].idx = idx;
      q[ hs ].sum[ 0 ] = 1;
      add( q[ hs ].sum , idx );

      tmp = hs;
      while( ( tmp >> 1 ) and cmp( q[ tmp ].sum , q[ tmp >> 1 ].sum ) )
        {
          heapify( tmp >> 1 );
          tmp >>= 1;
        }
    }
  return ;
}

void monoque()
{
  int i;

  for( i = 2 ; i <= hs ; ++ i )
    if( not cmp( q[ i ].val , q[ 1 ].val ) and q[ i ].idx <= q[ 1 ].idx )
      {
        q[ i ] = q[ hs ];
        -- hs;
        heapify( i );
      }

  for( i = 1 ; i <= hs ; ++ i )
    add( q[ i ].sum , q[ i ].val );
 
  for( i = ( hs >> 1 ) ; i ; -- i )
    heapify( i );
   
  return ;
}

void dp()
{
  int i , j;
 
  hs = 0;
  if( n > 1 )
    {
      bigint tmp;
      tmp[ 0 ] = 1; tmp[ 1 ] = h;

      qadd( tmp , 1 );
      monoque();

      for( i = 2 ;i < n ; ++ i )
        {
          qadd( q[ 1 ].sum , i );
          monoque();
        }

      for( i = q[ 1 ].sum[ 0 ] ; i ; -- i )
        cout<<q[ 1 ].sum[ i ];
      cout<<"\n";    
    }
  else
    cout<<h<<"\n";
  return ;
}

int main()
{
  while( cin>>h>>n )
      dp();
  
  return 0;
}
