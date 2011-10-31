/*
  2009 Wuhan Regional Internet Contest Dolphin
  write by Gestapolur
  2011-08-31
*/
#include<iostream>
#include<cstring>
#define MAXN 102 
#define INF 2141483647
using namespace std;

int n , m , s , e , ans , toc ;
int lnk[ MAXN ][ MAXN ] , w[ MAXN ][ MAXN ];
int mark[ MAXN ];
int type[ MAXN ] , pos[ MAXN ] , ty[ MAXN ];
bool psd[ MAXN ];
int pre[ MAXN ];

bool dfs( )
{
  int p , i ;
  int st[ MAXN ];

  for( i = 1 ; i <= n ; ++ i )
    {pre[ i ] = 0; st[ i ] = 1 ; }
  
  for( i = 1 ; i <= toc ; ++ i )
    psd[ i ] = false;
  
  p = s; psd[ type[ s ] ] = true;mark[ s ] = 0;
 
  do{
    for( i = st[ p ] ; i <= lnk[ p ][ 0 ] ; ++ i )
      {
	if( not psd[ type[ lnk[ p ][ i ] ] ]
	    and mark[ lnk[ p ][ i ] ] > mark[ p ] + w[ lnk[ p ][ i ] ][ p ] )
	  {
	    mark[ lnk[ p ][ i ] ] = mark[ p ] + w[ lnk[ p ][ i ] ][ p ];
	    pre[ lnk[ p ][ i ] ] = p ;
	    psd[ type[ lnk[ p ][ i ] ] ] = true;
	    st[ p ] = i + 1 ;
	    p = lnk[ p ][ i ];
	    break;
	  }
      }
    if( i == lnk[ p ][ 0 ] + 1 )
      {
	st[ p ] = 1 ;
	psd[ type[ p ] ] = false;
	p = pre[ p ];
      }
    
  }while( p > 0 );
  //for( i = 1 ; i <= n ; ++ i ) cout<<mark[ i ]<<" ";cout<<"\n";
  return true;
}

void clr()
{
  if( mark[ e ] ==  INF ) cout<<"-1\n";
  else cout<<mark[ e ]<<"\n";
  
  memset( mark , 0 , sizeof( mark ));
  memset( type , 0 , sizeof( type ));
  memset( ty , 0 , sizeof( ty ));
  memset( pos , 0 , sizeof( pos ));
  memset( lnk , 0 , sizeof( lnk ));
  memset( w , 0 , sizeof( w ) );
  return ;
}

void init()
{
  int i , j , u , v , wi ;
  cin>>n>>m>>s>>e;
  ++ s , ++ e ;
  for( i = 1 ; i <= n ; ++ i )
    for( j = 1 ; j <= n ; ++ j )
      w[ i ][ j ] = INF;

  for( i = 1 ; i <= m ; ++ i )
    {
      cin>>u>>v>>wi;
      ++ v , ++ u;
      if( w[ u ][ v ] == INF and u not_eq v )
	{
	  lnk[ u ][ ++ lnk[ u ][ 0 ] ] = v ;
	  lnk[ v ][ ++ lnk[ v ][ 0 ] ] = u ;
	}
      w[ u ][ v ] = w[ u ][ v ] < wi ? w[ u ][ v ] : wi; 
      w[ v ][ u ] = w[ v ][ u ] < wi ? w[ v ][ u ] : wi;
    }

  //count the differ foods  
  for( i = 1 ; i <= n ; ++ i )
    { cin>>ty[ i ]; pos[ i ] = i ; mark[ i ] = INF ;}
  
  //sort by color
  for( i = 1 ; i < n ; ++ i )
    for( j = i + 1 ; j <= n ; ++ j )
      if( ty[ i ] >  ty[ j ] )
	{  
	  wi = ty[ i ] ; ty[ i ] = ty[ j ] ; ty[ j ] = wi ; 
	  wi = pos[ i ] ; pos[ i ] = pos[ j ] ; pos[ j ] = wi;  
	}

  toc = 1;
  type[ pos[ 1 ] ] = 1;
  // mark the color
  for( i = 2 ; i <= n ; ++ i )
    if( ty[ i ] == ty[ i - 1 ] )
      type[ pos[ i ] ] = type[ pos[ i - 1 ] ];
    else
      type[ pos[ i ] ] = type[ pos[ i - 1 ] ] + 1 , ++ toc;
  
  ans = INF;

  return ;
}

int main()
{
  int t;
  cin>>t;
  while( t -- )
    {
      init();

      dfs();

      clr();
    }  

  return 0;
}
