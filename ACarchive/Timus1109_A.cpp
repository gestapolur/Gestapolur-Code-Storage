/* binary graph exercise */
#include<iostream>
#define MAXN 1002
using namespace std;

int n , m , k , cnt ;
bool mat[ MAXN ][ MAXN ] , vis[ MAXN ];
int lnk[ MAXN ];

bool find( int x )
{
  for( int i = 1 ; i <= n ; ++ i )
    if( mat[ x ][ i ] )
      {
	if( vis[ i ] )
	  continue;
	vis[ i ] = true;
	if( lnk[ i ] == -1 or find( lnk[ i ] ) )
	  {
	    lnk[ i ] = x;
	    return true;
	  }
      }
  return false;
}

int main()
{
  int i , u , v ;
  cin>>m>>n>>k;
  for( i = 1 ; i <= k ; ++ i )
    {
      cin>>u>>v;
      mat[ u ][ v ] = true;
    }
  for( i = 1 ; i <= n ; ++ i )
    lnk[ i ] = -1;

  cnt = m + n ;
  for( i = 1 ; i <= m ; ++ i )
    {
      for( int u = 1 ; u <= n ; ++ u )
	vis[ u ] = false;
      if( find( i ) )
	-- cnt ;
    }

  cout<<cnt<<"\n";

  return 0;
}
