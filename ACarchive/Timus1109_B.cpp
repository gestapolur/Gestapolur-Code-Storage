/* binary graph in edge */
#include<iostream>
#define MAXN 1002
using namespace std;

int e[ MAXN ];
int lnk[ MAXN ];
int g[ MAXN ][ MAXN ];
int n , m , k , cnt ;
bool vis[ MAXN ];

bool find( int x )
{
  for(int i = 1 ; i <= e[ x ] ; ++ i )
    {
      if( vis[ g[ x ][ i ] ] )
	continue ;
      int u = g[ x ][ i ];
      vis[ u ] = true;
      if( lnk[ u ] == -1 or find( lnk[ u ] ) )
	{
	  lnk[ u ] = x ;
	  return true;
	}
    }
  return false ;
}

int main()
{
  int u , v ;
  cin>>m>>n>>k;

  for( int i = 1 ; i <= k ; ++ i )
    {
      cin>>u>>v;
      g[ u ][ ++e[ u ] ] = v ;
    }

  for( int i = 1 ; i <= n ; ++ i )
    lnk[ i ] = -1;

  cnt = m + n ;
  for( int i = 1 ; i <= m ; ++ i )
    {
      for( u = 1 ; u <= n ; ++ u )
	vis[ u ] = false;
      if( find( i ) )
	-- cnt;
    }

  cout<<cnt<<"\n";

  return 0;
}
