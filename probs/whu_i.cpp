#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#define MAXN 1002
using namespace std;

struct queue
{
  int val , idx , sum;
};

int h , n , hs;//hs = heapsize
queue q[ MAXN ];

inline void heapify( int i )
{
  int l , r , mx;
  l = i << 1;
  r = ( i << 1 ) + 1;
  if( l <= hs and q[ l ].sum > q[ i ].sum )
    mx = l;
  else 
    mx = i;
  if( r <= hs and q[ r ].sum > q[ mx ].sum )
    mx = r;

  if( mx != i )
    {
      queue t = q[ mx ]; q[ mx ] = q[ i ]; q[ i ] = t;
      heapify( mx );
    }
  return ;
}

void add( int val , int idx )
{
  if( val > q[ 1 ].val or idx > q[ 1 ].idx )
    {
      int tmp;
      ++ hs;
      q[ hs ].val = val;
      q[ hs ].idx = idx;
      q[ hs ].sum = idx;

      tmp = hs;
      while( ( tmp >> 1 ) and q[ tmp ].sum > q[ tmp >> 1 ].sum )
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
    if( q[ i ].val <= q[ 1 ].val and q[ i ].idx <= q[ 1 ].idx )
      {
        q[ i ] = q[ hs ];
        -- hs;
        heapify( i );
      }

  for( i = 1 ; i <= hs ; ++ i )
    q[ i ].sum += q[ i ].val;
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
      add( h , 1 );
      monoque();

      for( i = 2 ;i < n ; ++ i )
        {
          add( q[ 1 ].sum , i );
          monoque();
          for( int j = 1 ; j <= hs ; ++ j ) 
            cout<<q[ j ].sum<<":"<<q[ j ].idx<<":"<<q[ j ].val<<" "; cout<<"\n";
        }

      cout<<q[ 1 ].sum<<"\n";
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
