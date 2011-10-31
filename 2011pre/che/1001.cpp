#include<iostream>
#define MAXN 200005
using namespace std;

class treenode
{
public:
  int pret , l , r , ack , part ;//only 1 time type is 1 , none is 0 , >= 2 is 2
};

treenode node[ MAXN ];
int mark[ MAXN ] ;
int n , m , qt , tn ;

void create( int l , int r , int s )
{
  node[ s ].l = l , node[ s ].r = r ;
  node[ s ].pret = 0 , node[ s ].ack = 0 ;
  if( l == r ) 
    mark[ l ] = s;
  if( l not_eq r )
    {
      int mid = l + r >> 1;
      create( l , mid , s << 1 );
      create( mid + 1 , r , ( s << 1 ) + 1 );
    }
  return ;
}

void insert( int l , int r , int s , int ct )
{
  if( node[ s ].l == l and node[ s ].r == r )
    {
      if( node[ s ].part == 0 )
        {
          node[ s ].p;
          if( ct - node[ s ].pret < qt and node[ s ].pret not_eq 0 )
            node[ s ].ack ++ ;
          node[ s ].pret = ct ;
          
        }
      else if( node[ s ].part == 1 )
    }

  if ( node[ s ].l == node[ s ].r ) 
    return ;
   
  int mid = node[ s ].l + node[ s ].r >> 1; 
  
  if ( mid >= r )
    insert( l , r , s << 1 , ct ); 
  else if ( mid < l ) 
    insert( l , r , ( s << 1 ) + 1 , ct ); 
  else 
    {
      insert( l , mid , s << 1 , ct ); 
      insert( mid + 1 , r , ( s << 1 ) + 1 , ct ); 
    } 
  
  if ( node[ s >> 1 ].part == node[ ( s >> 1 ) + 1 ].part )
    node[ s ].part = node[ s >> 1 ].part;

  return ;
}

int find( int x )
{
  int cnt = 0 ;
  if( x > 0 )
    {
      cnt += node[ x ].ack;
      x = x >> 1 ;
    }
  return cnt ;
}

void work()
{
  int i , s , t , ct = 0 ;
  char cmd[ 10 ];

  cin>>n>>m>>qt;

  tn = 0 ;

  create( 1 , n , 1 );
  
  for( i = 1 ; i <= m ; ++ i )
    {
      cin>>cmd;
      if( cmd[ 0 ] == 'A' )
        {
          ++ ct;
          cin>>s>>t;
          insert( s , t , 1 , ct );
        }
      else
        {
          cin>>s;
          cout<<find( mark[ s ] )<<"\n";
        }
    }

  return ;
}

int main()
{
  int t , tt ;

  cin>>t;
  tt = 0 ;

  while( t -- )
    {
      ++ tt;

      cout<<"Case "<<tt<<":\n";
      
      work();

    }
  return 0;
}
