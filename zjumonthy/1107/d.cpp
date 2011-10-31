#include<iostream>
#include<cstring>
#include<string>
#define MAXN 55
using namespace std;

string a[ MAXN ] ;
int ans , n , m ;
int f[ MAXN ];

int main()
{
  int i , j , k ;
  while( cin >> n >> m )
    {
      ans = 0 ;
      getline( cin , a[ 0 ] );
      
      for( i = 1 ; i <= n ; ++ i )
	{
	  for( j = 1 ; j <= m ; ++ j )
	    { getline( cin , a[ j ] ) ; f[ j ] = 1 ; }
	
	  f[ 0 ] = 0 ;
	  
	  for( j = 1 ; j <= m ; ++ j )
	    {
	      for( k = 1 ; k < j ; ++ k )
		if( f[ j ] < f[ k ] + 1 and a[ k ] <= a[ j ] )
		  f[ j ] = f[ k ] + 1 ;
	      f[ 0 ] = f[ 0 ] > f[ j ] ? f[ 0 ] : f[ j ];
	    }
	  ans += m - f[ 0 ];
	  
	}
      cout<<ans<<"\n";
    }
  return 0;
}
