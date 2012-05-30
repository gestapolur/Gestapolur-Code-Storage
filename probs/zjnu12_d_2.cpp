#include<iostream>
#include<cstdlib>
#include<cstdio>
#define MAXN 200005
using namespace std;

struct treenode
{
  int l , int r , int sum , int chg;
} node[ 1 << 20 ];

int n , m , kk;
int val[ MAXN ] , tmax[ MAXN ];

void create( int l , int r , int s)
{
  node[ s ].sum = 0;
  node[ s ].s = 0;
  node[ s ].l = l;
  node[ s ].r = r;
  if( l not_eq r )
    {
      create( l , mid , s << 1 );
      create( mid + 1 , r , ( s << 1 ) + 1 )
    }
  return ;
}

void update( int l , int r , int s , int del )
{
  if( node[ s ].l == l and node[ s ].r == r and node[ s ].s not_eq 2 )
    {
      node[ s ].sum += del;
      node[ s ].s = 1;
    }
  else if( node[ s ].l == node[ s ].r )
    return ;
  else
    {
      int mid = node[ s ].l + node[ s ].r >> 1;
      if( mid < r )
        update( l , r , ( s << 1 ) + 1 , del );
      else if( mid >= l )
        update( l , r , s << 1 , del );
      else
        {
          update( l , mid , s << 1 , del );
          update( mid + 1 , r , ( s << 1 ) + 1 , del );
        }
    }
  return ;
}

int find( int l , int r , int s , int )
{
  if( node[ s ].l == l and node[ s ].r == r and node[ s ].s not_eq 2 )
      return node[ s ].sum;
  else if( node[ s ].l == node[ s ].r )
    return 0;
  else
    {
      int mid = node[ s ].l + node[ s ].r >> 1;
      if( mid < r )
        return find( l , r , s << 1 );
      else if( mid >= l )
        return find( l , r , ( s << 1 ) + 1 );
      else
        return ( find( l , mid , s << 1 ) + find( mid + 1 , r , ( s << 1 ) + 1 ));
    }
}

void init()
{
  int i;
  cin>>n>>m>>kk;
  for( i = 1; i <= n ; ++ i )
    cin>>val[ i ];
  for( i = 1 ; i <= kk ; ++ i )
    tsum[ i ] += val[ i ];
  for( i = kk + 1; i <= n; ++ i )
    tsum[ i - kk + 1 ] = tsum[ i - kk ] - tsum[ i - kk ] + tsum[ i ]; 

  create( 1 , n - kk );
  
  for( i = n - kk ; i ; -- i )
    update( i , i , 1 , tsum[ i ] );

  return ;
}

int max( int a , int b ){ return a > b ? a : b ; }

int min( int a , int b ){ return a < b ? a : b ; }

void work()
{
  int ins , sx , sy;

  for( int i = 1 ; i <= m ; ++ i )
    {
      cin>>ins>>sx>>sy;
      if( ins == 1 )
        {
          del = val[ sy ] - val[ sx ];
          tmp = val[ sx ];
          val[ sx ] = val[ sy ];
          update( max ( 1 , sx - kk + 1 ) , min ( n - kk + 1 , sx + kk - 1 ) , 1 , del );
          
          del = tmp - val[ sy ];
          val[ sy ] = tmp;
          update( max ( 1 , sy - kk + 1 ) , min ( n - kk + 1 , sy + kk - 1 ) , 1 , del );
        }
      else if( ins == 2 ) 
        cout<<find( sx , sy - kk + 1 )<<"\n";
      else
        {
          del = sy - val[ sx ];
          val[ sx ] = sy;
          update( sx - kk + 1 , sx + kk - 1 , 1 , del );
        }
    }
  return ;
}

int main()
{
  int t;
  cin>>t;

  while( t -- )
    {
      init();

      work();
    }

  return ;
}
