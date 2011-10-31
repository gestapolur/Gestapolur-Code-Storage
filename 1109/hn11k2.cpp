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
  int l , r , minl , minr ;//minl , minr is the min verxs in it's lefttree and right
};

treenode node[ MAXNODE ];

int n , q ;
int qe[ MAXN ] , pos[ MAXN ] , base[ MAXN ] ;
//qe current shift or query value
//pos , position that l == r
//base original value 

//update the min value position , isleft = s update from it's leftchild or right
void update( int s , int minp , bool isleft )//minp = min value position
{
  
  if( node[ s ].l not_eq node[ s ].r )
    {
      if( isleft and base[ node[ s ].minl ] > base[ minp ] )
        node[ s ].minl = minp;
      else if( not isleft and base[ node[ s ].minr ] > base[ minp ] ) 
        node[ s ].minr = minp;
    }

  if( s > 1 )
    {
      //update min value of the whole tree to it's parent
      minp = base[ node[ s ].minl ] < base[ node[ s ].minr ] ? node[ s ].minl : node[ s ].minr;
      if( s & 1 == 1 )
        update( s >> 1 , minp , false );
      else
        update( s >> 1 , minp , true );
    }
  return ;
}

//create linear tree
void create( int l , int r , int s )
{
  node[ s ].l = l , node[ s ].r = r ;
  node[ s ].minl = n + 1 , node[ s ].minr = n + 1 ;
  
  if( l == r )
    {
      pos[ l ] = s ;//record the position that l == r
      node[ s ].minl = l ;
      node[ s ].minr = l ;
      if( s & 1 == 1 )
        update( ( s >> 1 ) , l , false );
      else
        update( ( s >> 1 ) , l , true );
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
    return base [ node[ s ].minl ] < base [ node[ s ].minr ] ? base [ node[ s ].minl ] : base [ node[ s ].minr ] ;
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
            if( pos[ qe[ j ] ] & 1 == 1 )
              update( pos[ qe[ j ] ] >> 1 , qe[ j ] , false );
            else
              update( pos[ qe[ j ] ] >> 1 , qe[ j ] , true );

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
