//2011 hunan college programming contest
#include<cstdlib>
#include<cstdio>
#include<cstring>
#define MAXNODE 1 << 24
#define MAXN 100005
#define INF 1000000009

class treenode
{
public:
  int l , r , minv ;
};

treenode node[ MAXNODE ];

int n , q ;
int qe[ MAXN ] , pos[ MAXN ] , base[ MAXN ] ;
//qe current shift or query value
//pos , position that l == r
//base original value 

//update the min value position , isleft = s update from it's leftchild or right
void update( int s , int minp )//minp = min value position
{
  if( base[ node[ s ].minv ] > base[ minp ] )
    node[ s ].minv = minp;
  if( s > 1 )
    update( s >> 1 , minp );
  return ;
}

//create linear tree
void create( int l , int r , int s )
{
  node[ s ].l = l , node[ s ].r = r ;
  node[ s ].minv = n + 1 ;
  
  if( l == r )
    {
      pos[ l ] = s ;//record the position that l == r
      node[ s ].minv = l ;
      update( ( s >> 1 ) , l );
    }
  else if( l < r )
    {
      int mid = l + r >> 1 ;
      create( l , mid , s << 1 );
      create( mid + 1 , r , ( s << 1 ) + 1 );
    }
  return ;
}

int find( int l , int r , int s )
{
  //return the min value
  if( node[ s ].l == l and node[ s ].r == r )
    return base[ node[ s ].minv ];
  if( node[ s ].l == node[ s ].r )
    return INF;
  else
    {
      int mid = node[ s ].l + node[ s ].r >> 1 ;
      if( mid >= r )
        return find( l , r , ( s << 1 ) );
      else if( mid < l )
        return find( l , r , ( s << 1 ) + 1 );
      else
        {
          int tx = find( l , mid , s << 1 );
          int ty = find( mid + 1 , r , ( s << 1 ) + 1 );
          return tx < ty ? tx : ty; 
        }
    }
}

void init()
{
  scanf("%d%d" , &n , &q );
  for(int i = 1 ; i <= n ; ++ i )
    scanf( "%d" , &base[ i ] ) ;
 
  base[ n + 1 ] = INF ;
 
  create( 1 , n , 1 );
  
  return ;
}

//trans string to integers
void transfind( char ch [] )
{
  int i , len = strlen( ch ) ;
  bool trans ;
  trans = false;
  qe[ 0 ] = 0;
  for( i = 0  ; i < len ; ++ i )
    if( ch[ i ] <= '9' and ch[ i ] >= '0' and not trans )
      { qe[ ++ qe[ 0 ] ] = ch[ i ] - 48 ;trans = true ;}
    else if( ch[ i ] <= '9' and ch[ i ] >= '0' )
      { qe[ qe[ 0 ] ] = qe[ qe[ 0 ] ] * 10 + ( ch[ i ] - 48 ) ;}
    else trans = false;
  
  return ;
}

void work( )
{
  char ch[ 255 ];
  gets( ch );
 
  for( int i = 1 ; i <= q ; ++ i )
    {
   
      gets( ch );
      
      transfind( ch );
      
      if( ch[ 0 ] == 's' )//shift
        {
          //shift the original value
          base[ 0 ] = base[ qe[ 1 ] ];
          for( int j = 1 ; j < qe[ 0 ] ; ++ j )
            base[ qe[ j ] ] = base[ qe[ j + 1 ] ]; 
          base[ qe[ qe[ 0 ] ] ] = base[ 0 ];
          //update the min value
          for( int j = 1 ; j <= qe[ 0 ] ; ++ j )
              update( pos[ qe[ j ] ] >> 1 , qe[ j ] );
        }
      else//query
        printf( "%d\n" , find( qe[ 1 ] , qe[ 2 ] , 1 ) );
  
    }
  return ;
}

int main()
{

  init();

  work();

  return 0;
}
