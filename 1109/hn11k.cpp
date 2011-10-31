#include<iostream>
#include<string>
#define MAXNODE 1 << 24
#define MAXN 100005
#define INF 1000000009
using namespace std;

class treenode
{
public:
  int l , r , minl , minr , cntl , cntr ;
};

treenode node[ MAXNODE ];

int n , q ;
int qe[ MAXN ] , pos[ MAXN ] , base[ MAXN ] ;

void update( int s , int org , int chg , bool isleft )
{
  //test
  //if( org == 0 ) cout<<s<<" "<<chg<<" "<<base[ chg ]<<" "<<node[ s ].mint<<"----\n";
  if( node[ s ].l == node[ s ].r )
    {
      node[ s ].minr = base[ chg ] , node[ s ].cntr = 1 ;
      node[ s ].minl = base[ chg ] , node[ s ].cntl = 1 ;
    }
  else
    {
      if( isleft )
        {
          if( node[ s ].minl == base[ org ] ) 
            -- node[ s ].cntl;
          else if( node[ s ].minl == base[ chg ] )
            ++ node[ s ].cntl;
          if( node[ s ].minl > base[ chg ] or node[ s ].cntl <= 0 )
            { node[ s ].minl = base[ chg ] ; node[ s ].cntl = 1 ;}      
        }     
      else 
        {
          if( node[ s ].minr == base[ org ] ) 
            -- node[ s ].cntr;
          else if( node[ s ].minr == base[ chg ] )
            ++ node[ s ].cntr;
          if( node[ s ].minr > base[ chg ] or node[ s ].cntr <= 0 )
            { node[ s ].minr = base[ chg ] ; node[ s ].cntr = 1 ;}      
      
        }
    }
  if( s > 1 )
    {
      if( s & 1 == 1 )
        update( s >> 1 , org , chg , false );
      else
        update( s >> 1 , org , chg , true );
    }
  return ; 
}

void create( int l , int r , int s )
{
  node[ s ].l = l , node[ s ].r = r ;
  node[ s ].minl = INF , node[ s ].cntr = 0 , node[ s ].minr = INF , node[ s ].cntr = 0 ;
  //cout<<"order : "<<l<<" "<<r<<" "<<s<<"\n";
  if( l == r )
    {
      //cout<<"!\n";
      pos[ l ] = s ;
      node[ s ].minl = base[ l ] , node[ s ].cntl = 1 ;
      node[ s ].minr = base[ l ] , node[ s ].cntr = 1 ;
      if( s & 1 == 1 )
        update( ( pos[ l ] >> 1 ) , 0 , l , false );
      else
        update( ( pos[ l ] >> 1 ) , 0 , l , true );
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
  if( node[ s ].l == l and node[ s ].r == r )
    return node[ s ].minl < node[ s ].minr ? node[ s ].minl : node[ s ].minr ;
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
/*
void disp( int s )
{
  cout<<s<<" "<<node[ s ].l<<" "<<node[ s ].r<<" "<<s<<" "<<node[ s ].minl<<" "<<node[ s ].minr<<" "<<node[ s ].cntl<<" "<<node[ s ].cntr<<"\n";
  if( node[ s ].l < node[ s ].r  )
    {
      disp( s << 1 );
      disp( ( s << 1 ) + 1 );
    }
  return ;
}
*/
bool init()
{
  cin>>n>>q;
  for(int i = 1 ; i <= n ; ++ i )
    cin>>base[ i ];
  //base[ 0 ] = INF;
  create( 1 , n , 1 );
  //disp( 1 );cout<<"------\n";
  //for( int i = 1 ; i <= n ; ++ i ) cout<<pos[ i ]<<" "; cout<<"\n";
  return true;
}

void transfind( string ch )
{
  int i , len = ch.size() , x = 0 ;
  bool trans ;
  trans = false;
  qe[ 0 ] = 0;
  for( i = 0  ; i < len ; ++ i )
    if( ch[ i ] <= '9' and ch[ i ] >= '0' and not trans )
      { qe[ ++ qe[ 0 ] ] = ch[ i ] - 48 ;trans = true ;}
    else if( ch[ i ] <= '9' and ch[ i ] >= '0' )
      { qe[ qe[ 0 ] ] = qe[ qe[ 0 ] ] * 10 + ( ch[ i ] - 48 ) ;}
    else trans = false;
  //cout<<" order : ";for( i = 1 ; i <= qe[ 0 ] ; ++ i ) cout<<qe[ i ]<<" ";cout<<"\n";
  return ;
}

void work( )
{
  string ch;
  for( int i = 1 ; i <= q ; ++ i )
    {
      cin>>ch;
      transfind( ch );
      
      if( ch[ 0 ] == 's' )//shift
        {
          //int tmp = base[ qe[ 1 ] ];
          base[ 0 ] = base[ qe[ 1 ] ];

          for( int j = 1 ; j < qe[ 0 ] ; ++ j )
            if( base[ qe[ j ] ] not_eq base[ qe[ j + 1 ] ] )
              {
                if( pos[ qe[ j ] ] & 1 == 1 )
                  update( pos[ qe[ j ] ] , qe[ j ] , qe[ j + 1 ] , false );
                else
                  update( pos[ qe[ j ] ] , qe[ j ] , qe[ j + 1 ] , true );
                //change two value and their mark
                base[ qe[ j ] ] = base[ qe[ j + 1 ] ];
              }
          
          if( base[ 0 ] not_eq base[ qe[ qe[ 0 ] ] ] )
            {
              if( pos[ qe[ qe[ 0 ] ] ] & 1 == 1 )
                update( pos[ qe[ qe[ 0 ] ] ] , qe[ qe[ 0 ] ] , 0 , false );
              else
                update( pos[ qe[ qe[ 0 ] ] ] , qe[ qe[ 0 ] ] , 0 , true );
            }
          base[ qe[ qe[ 0 ] ] ] = base[ 0 ];
            
        }
      else//query
        cout<<find( qe[ 1 ] , qe[ 2 ] , 1 )<<"\n";
      /*
      cout<<"========\n";
      cout<<"base : ";
      for( int j = 1 ; j <= n ; ++ j ) cout<<base[ j ]<<" ";cout<<"\n";
      disp( 1 );
      */
    }
  return ;
}

int main()
{

  init();

  work();

  return 0;
}
