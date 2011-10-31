//binary graph hungary test
#include<iostream>
#include<cstring>
#define MAXN 1001
using namespace std;
//left has m verx , right side has n verx , k is the number of edge 
int n , m , k , cnt ; 
int lnk[ MAXN ];
bool mat[ MAXN ][ MAXN ] , vis[ MAXN ];

bool find( int x )
{
  for( int i = 1 ; i <= n ; ++ i )
    if( mat[ x ][ i ] )
      {
	if( vis[ i ] )
	  continue ;
	int u = i ;
	vis[ u ] = true;
	if( lnk[ u ] == -1 or find( lnk[ u ] ) )
	  {
	    lnk[ u ] = x;
	    return true;
	}
      }
  return false ;
}

int main()
{
  int i , u , v , tmin ;
  cin>>m>>n>>k;
  memset( lnk , -1 , sizeof( lnk ) );

  for( i = 1 ; i <= k ; ++ i )
    {
      cin>>u>>v;
      mat[ u ][ v ] = true;  
    }

  cnt = m + n ;
  
  for( i = 1 ; i <= m ; ++ i )
    {
      memset( vis , 0 , sizeof( vis ));
      if( find( i ) )
	-- cnt;
    }

  cout<<cnt<<"\n";
  return 0;
}
