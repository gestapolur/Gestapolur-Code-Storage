#include<iostream>
#define MAXN 50004
using namespace std;

class treenode
{
public:
  int l , r , cnt ;
};

treenode node[ 1 << 20 ];
bool a[ MAXN ];
int n , m ;
int pos[ MAXN ];

void create( int l , int r , int s )
{
  node[ s ].l = l , node[ s ].r = r , node[ s ].cnt = 0 ;
  if( r - l > 2 )
    {
      if( a[ l ] == 0 and a[ l + 1 ] == 1 and a[ l + 2 ] == 0 ) ++node[ s ].cnt;
      if( a[ r ] == 0 and a[ r - 1 ] == 1 and a[ r - 2 ] == 0 ) ++node[ s ].cnt;
    }
  else if( r - l == 2 and a[ l ] == 0 and a[ r ] == 0 and a[ r - 1 ] == 1 )
    node[ s ].cnt = 1 ;
  if( l == r )
    pos[ l ] = s ;
  if( l < r )
    {
      int mid = l + r >> 1 ;
      create( l , mid , s << 1 );
      create( mid + 1 , r , ( s << 1 ) + 1 );
    }
  return ;
}

int find( int l , int r , int s )
{
  if( l == node[ s ].l and node[ s ].r == r )
    {
      if( r - l > 2 )
        return node[ s ].cnt + find( l + 1 , r - 1 , 1 );
      else if( r - l == 2 )
        return node[ s ].cnt;
      else
        return 0 ;
    }

  if( node[ s ].l == node[ s ].r ) return 0;
  else
    {
      int mid = node[ s ].l + node[ s ].r >> 1 ;
      if( mid > r )
        return find( l , r , ( s << 1 ) );
      else if( mid <= l )
        return find( l , r , ( s << 1 ) + 1 );
      else
        return find( l , mid , s << 1 ) + find( mid + 1 , r , ( s << 1 ) + 1 );
    }
}

void update( int s )
{
  node[ s ].cnt = 0 ;
  int l = node[ s ].l , r = node[ s ].r;
  if( r - l > 2 )
    {
      if( a[ l ] == 0 and a[ l + 1 ] == 1 and a[ l + 2 ] == 0 ) ++node[ s ].cnt;
      if( a[ r ] == 0 and a[ r - 1 ] == 1 and a[ r - 2 ] == 0 ) ++node[ s ].cnt;
    }
  else if( r - l == 2 and a[ l ] == 0 and a[ r ] == 0 and a[ r - 1 ] == 1 )
    node[ s ].cnt = 1 ;
  
  if( s > 1 )
    update( s >> 1 );
  return ; 
}

void init()
{
  char ch;
  cin>>n>>m;
  for(int i = 1 ; i <= n ; ++ i )
    {
      cin>>ch;
      if( ch == 'b' )
        a[ i ] = true;
      else
        a[ i ] = false;
    }
  create( 1 , n , 1 );
  return ;
}

void work()
{
  int l , r , type;
  char ch;
  for( int i = 1 ; i <= m ; ++ i )
    {
      cin>>type;
      if( type == 0 )
        {
          cin>>l>>r;
          cout<<find( l , r , 1 )<<"\n";
        }
      else
        {
          cin>>l>>ch;
          if( ch == 'b' )
            a[ l ] = true;
          else                                  
            a[ l ] = false;
          update( pos[ l ] );
        }
    }
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
  return 0;
}
