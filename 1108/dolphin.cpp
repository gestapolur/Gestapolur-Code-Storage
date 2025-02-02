/*
  WHU 2009 IC DOLPHIN
  write a hash and check the distance in a food chose condition
  write by Gestapolur
  2011-08-29
*/
#include<iostream>
#include<cstring>
#define MAXN 102
#define INF 2141483647
using namespace std;

int w[ MAXN ][ MAXN ] , lnk[ MAXN ][ MAXN ];
int n , m , s , e , ans , toc ;//totaly color
int type[ MAXN ] , ty[ MAXN ] , pos[ MAXN ];
//int stack[ MAXN ] ;

class queue
{
public:
  int cnt , dist , cur;
  bool fd[ MAXN ];
  /*
  void clr()
    {
      for( int i = 1 ; i <= n ; ++ i )
	fd[ i ] = false;
      cnt = 0 , dist = 0 , cur = 0 ;
    }
  */
};

queue q[ MAXN * MAXN ];

void bfs()
{
  int rear ,front ;
  int i ;
  queue p ;
  q[ 1 ].cnt = 1 , q[ 1 ].dist = 0 , q[ 1 ].fd[ type[ s ] ] = true , q[ 1 ].cur = s; 
  rear = 1 , front = 0 ;
  
  do{
    p = q[ ++ front ];
    //cout<<p.cur<<" "<<p.dist<<" "<<p.cnt<<"\n";
    //for( i = 0 ; i < toc ; ++ i ) cout<<p.fd[ i ];cout<<"\n";
    if( p.cur not_eq e )
      {
	for( i = 1 ; i <= lnk[ p.cur ][ 0 ] ; ++ i )
	  if( not p.fd[ type[ lnk[ p.cur ][ i ] ] ] )
	    { 
	      q[ ++ rear ] = p; 
	      q[ rear ].cnt ++ ;
	      q[ rear ].dist += w[ p.cur ][ lnk[ p.cur ][ i ] ];
	      q[ rear ].cur = lnk[ p.cur ][ i ];
	      q[ rear ].fd[ type[ lnk[ p.cur ][ i ] ] ] = true;
	    }
      }
    else if( p.cnt == toc and p.dist < ans )
      ans = p.dist ;
  }while( front < rear );

  return ;
}

void init()
{
  int i , j , u , v , wi ;
  cin>>n>>m>>s>>e;
  ++ s , ++ e ;
  for( i = 1 ; i <= m ; ++ i )
    {
      cin>>u>>v>>wi;
      ++ v , ++ u;
      w[ u ][ v ] = wi;
      w[ v ][ u ] = wi;
      lnk[ u ][ ++ lnk[ u ][ 0 ] ] = v ;
      lnk[ v ][ ++ lnk[ v ][ 0 ] ] = u ;
    }

  
  //count the differ foods
  
  for( i = 1 ; i <= n ; ++ i )
    { cin>>ty[ i ]; pos[ i ] = i ;}
  //cout<<"end\n";
  for( i = 1 ; i < n ; ++ i )
    for( j = i + 1 ; j <= n ; ++ j )
      if( ty[ i ] >  ty[ j ] )
	{  
	  wi = ty[ i ] ; ty[ i ] = ty[ j ] ; ty[ j ] = wi ; 
	  wi = pos[ i ] ; pos[ i ] = pos[ j ] ; pos[ j ] = wi;  
	}

  toc = 1;

  for( i = 2 ; i <= n ; ++ i )
    if( ty[ i ] == ty[ i - 1 ] )
      type[ pos[ i ] ] = type[ pos[ i - 1 ] ];
    else
      type[ pos[ i ] ] = type[ pos[ i - 1 ] ] + 1 , ++ toc;
  //cout<<toc<<"\n";
  //for( i = 1 ; i <= n ; ++ i ) cout<<type[ i ]<<" "; cout<<"\n";
  
  ans = INF;

  //test
  /*
  for( i = 1 ; i <= n;  ++ i )
    {
      cout<<i<<" : ";
      for( j = 1 ; j <= lnk[ i ][ 0 ] ; ++ j )
	cout<<lnk[ i ][ j ]<<":"<<w[ i ][ lnk[ i ][ j ] ]<<" ";
      cout<<"\n";
    }
  */
  return ;
}

void output()
{
  if( ans not_eq INF ) cout<<ans<<"\n";
  else cout<<-1<<"\n";

  memset( q , 0 , sizeof( q ) );
  memset( lnk , 0 , sizeof( lnk ) );
  memset( w , 0 , sizeof( w ) );
  return ;
}

int main()
{
  int t;
  cin>>t;
  while( t -- )
    {
      init();
      //cout<<" end in \n";
      bfs();
      //cout<<" end b \n";
      output();
    }  

  return 0;
}
