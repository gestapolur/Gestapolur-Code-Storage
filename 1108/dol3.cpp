/**/
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

bool dfs( int dist )
{
  int p , i ;
  int st[ MAXN ];

  for( i = 1 ; i <= n ; ++ i )
    {pre[ i ] = 0;st[ i ] = 1 ;}

  for( i = 1 ; i <= toc ; ++ i )
    psd[ i ] = false;

  p = s; psd[ type[ s ] ] = true;
  
  do{
    for( i = st[ p ] ; i <= lnk[ p ][ 0 ] ; ++ i )
      {
      if( not psd[ type[ lnk[ p ][ i ] ] ]
	  and mark[ lnk[ p ][ i ] ] + w[ lnk[ p ][ i ] ][ p ] <= dist
	  and mark[ p ] > mark[ lnk[ p ][ i ] ] + w[ lnk[ p ][ i ] ][ p ] )
 	    {
	      mark[ p ] = mark[ lnk[ p ][ i ] ] + w[ lnk[ p ][ i ] ][ p ];
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
  
  return mark[ e ] <= dist ;
}

//find the resible shortest path
void predfs()
{
  int i , j , p , top = 1;
  int st[ MAXN ];
  bool ref;
 
  for( i = 1 ; i <= n; ++ i )
    {mark[ i ] = INF;st[ i ] = 1 ;}
  for( i = 1 ; i <= toc ; ++ i )
    {psd[ i ] = false; pre[ i ] = 0 ;}
  mark[ s ] = 0 , psd[ type[ s ] ] = true;
  p = s;
  do{
    ref = false;
    for( i = st[ p ] ; i <= lnk[ p ][ 0 ] ; ++ i )
      if( not psd[ type[ lnk[ p ][ i ] ] ] and  mark[ lnk[ p ][ i ] ] > mark[ p ] + w[ p ][ lnk[ p ][ i ] ])
	{
	  ref = true;
	  mark[ lnk[ p ][ i ] ] = mark[ p ] + w[ p ][ lnk[ p ][ i ] ];
	  psd[ type[ lnk[ p ][ i ] ] ] = true;
	  st[ p ] = i + 1 ;
	  pre[ lnk[ p ][ i ] ] = p;
	  p = lnk[ p ][ i ];
	  break;
	}
    if( not ref )
      {
	psd[ type[ p ] ] = false;
	st[ p ] = 1 ;
	p = pre[ p ];
      }
  }while( p > 0 );
  
  return ;
}

void clr()
{
  if( ans ==  INF ) cout<<"-1\n";
  else cout<<ans<<"\n";
  
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
    { cin>>ty[ i ]; pos[ i ] = i ;}

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
  int l , r , mid;
  cin>>t;
  while( t -- )
    {
      init();
      
      predfs();

      ans = mark[ e ];
      if( ans < INF )
	{
	  l = 0 , r = mark[ e ] , mid = l + r >> 1 ;
	  while( l < r )
	    {
	      if (not dfs( mid ) ) 
		l = mid + 1 ;
	      else
		{r = mid ; ans = mid;}
	      mid = l + r >> 1 ;
	    }
	}
      
      clr();
    }  

  return 0;
}
