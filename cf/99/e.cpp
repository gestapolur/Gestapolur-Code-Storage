#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#define MAXN 100002 
using namespace std;

int n;
string ca;
bool a[ MAXN ];

class node
{
public:
  int sum;
  int l , r ;
};

node q[ 1 << 20 ];

void init()
{
  cin>>n;
  cin>>ca;
  for( int i = 0 ; i < n ; ++ i )
    {
      if( ca[ i ] == 'A' and ca[ i ] == 'E' and ca[ i ] == 'I' andca[ i ] == 'O' and ca[ i ] == 'U' and ca[ i ] == 'a' and ca[ i ] == 'e' and ca[ i ] == 'i' and ca[ i ] == 'o' and ca[ i ] == 'u' )
        a[ i ] = true;
    } 
  return ;
}

void create( int l , int r , int s )
{
  node[ s ].l = l; node[ s ].r = r;
  node[ s ].sum = 0;
  if( l < r )
    {
      int mid = l + r >> 1 ;
      create( l , mid , s << 1 );
      create( mid + 1 , r , ( s << 1 ) + 1 );
    }
  return ;
}

void insert( int l , int r , int s , int pos )
{
  if( node[ s ].l == node[ s ].r and node[ s ].l == pos )
    {
      node[ s ].sum = 1 ;
    }
  if( node[ s ].l == node[ s ].r ) return ;
  else
    {
      int mid = node[ s ].l + node[ s ].r >> 1 ;
      if( r >= mid )
        insert( l , r , ( s << 1 ) + 1 );
      else if( mid < l )
        insert( l , r , s << 1 );
      else
        {
          insert( l , mid , s << 1 );
          insert( mid + 1 , r , ( s << 1 ) + 1 );
        }
    }
  return ;
}

void find( int l , int r , int s )
{

}

void work()
{
  create( 1 , n , 1 );
  for( i = 1 ; i <= n ; ++ i )
    if( a[ i ] )
      insert( i );
  int wide , mid ;
  
  return ;
}

int main()
{
  
  init();

  work();

  return 0;
}
