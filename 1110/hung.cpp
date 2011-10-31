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
  int i , j , u , v ;
  cin>>n>>m;
  for( i = 1 ; i <= n ; ++ i )
  	for( j = 1 ; j <= m ; ++ j )
    {
  	  cin>>v;
  	  if( v == 1 )
      	mat[ i ][ j ] = true;
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
	for( i = 1 ; i <= n ; ++ i )
		cout<<lnk[ i ]<<" ";
	cout<<"\n";
  return 0;
}
