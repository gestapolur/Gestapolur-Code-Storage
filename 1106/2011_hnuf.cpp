/*
  2011 HNU F
*/
#include<iostream>
#define MAXN 300
#define INF 1 << 20 
using namespace std;

int n,m;
int f[ MAXN ][ MAXN ] , c[ MAXN ][ MAXN ];
int w[ MAXN ][ MAXN ] , a[ MAXN ];
int cost , sink ;

/*
  0 : source , 1 to m : ai->aj ;
  m + 1 to m + n : transform verx ;
  m + n + 1 to 2 * m + n : destinations ;
  2*m + n + 1  : sink
*/
int main()
{
  int i , j , k , u , v , tval ;
  while(cin>>n>>m)
    {
      //construct map
      sink = 2 * n + m + 1;
      //UFO numbers
      for( i = 1 ; i <= n ; ++ i )
	{
	  cin>>tval;
	  //transform to sink
	  f[ m + i ][ sink ] = tval;
	}

      //init
      for( i = 1 ; i <= n ; ++ i )
	for( j = i + 1 ; j <= n ; ++ j )
	  {
	    w[ i ][ j ] = INF;
	    w[ j ][ i ] = INF;
	  }

      //edge values
      for( i = 1 ; i <= n ; ++ i )
	for( j = 1 ; j <= n ; ++ j )
	  if(cin>>tval and tval not_eq -1 )
	    w[ i ][ j ] = tval;

      //floyd
      for( k = 1 ; k <= n ; ++ k )
	for( i = 1 ; i <= n ; ++ i )
	  for( j = 1 ; j <= n ; ++ j )
	    if( i not_eq j and j not_eq k and k not_eq i 
		and w[ i ][ j ] > w[ i ][ k ] + w[ k ][ j ])
	      w[ i ][ j ] = w[ i ][ k ] + w[ k ][ j ];
      cout<<"\n";
      for( i = 1 ; i <= n ; ++ i )
	{
	  for( j = 1 ; j <= n ; ++ j )
	    cout<<w[ i ][ j ]<<" ";
	  cout<<"\n";
	}
      cout<<"====\n";

      for( i = 1 ; i <= m ; ++ i )
	cin>>a[ i ];
      
      for( i = 1 ; i < m ; ++ i )
	{
	  //source to precedure
	  f[ 0 ][ i ] = 1;
	  //precedure to destination
	  f[ i ][ m + n + i ] = 5 * w[ a[ i + 1 ] ][ i ];
	  //precedure to transform 
	  for( j = 1 ; j <= n ; ++ j )
	    {
	      f[ i ][ m + j ] = 1;
	      c[ i ][ m + j ] =  w[ a[ i ] ][ j ];
	      c[ m + j ][ i ] =  -w[ a[ i ] ][ j ];
	    }
	  //destination to sink 
	  f[ m + n + i ][ sink ] = 1 ;
	}
      //minimum cost flow
      cout<<cost<<"\n";
      
      cout<<"--------\n"<<sink<<"\n";
      for( i = 0 ; i <= sink ; ++ i )
	{
	  for( j = 0 ; j <= sink ; ++ j )
	    cout<<f[ i ][ j ]<<" ";
	  cout<<"\n";
	}
      cout<<"--------+\n";
      for( i = 0 ; i <= sink ; ++ i )
	{
	  for( j = 0 ; j <= sink ; ++ j )
	    cout<<c[ i ][ j ]<<" ";
	  cout<<"\n";
	}
    }
  return 0;
}
