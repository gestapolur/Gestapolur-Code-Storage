//Wuhan Region 09 WHU
#include<iostream>
#include<cstring>
#define MAXN 11
using namespace std;

int f[ 1002 ][ 1002 ] , tx[ MAXN ] , ty[ MAXN ] , w[ MAXN ];
int cx , cy , n ;

int max( int a , int b ){ return a > b ? a : b ; }

int main()
{
  int t , i , j , k ;
  cin>>t;
  while( t -- )
    {

      cin>>n>>cx>>cy;
      for( i = 1 ; i <= n ; ++ i )
	{
	  cin>>tx[ i ]>>ty[ i ]>>w[ i ];
	  f[ tx[ i ] ][ ty[ i ] ] = max( f[ tx[ i ] ][ ty[ i ] ] , w[ i ]);
	}
      
      for( k = 1 ; k <= n ; ++ k )
	for( i = tx[ k ] ; i <= cx ; ++ i )
	  for( j = ty[ k ] ; j <= cy ; ++ j )
	    {
	      f[ i ][ j ] = max( f[ i ][ j ] , f[ i - tx[ k ] ][ ty[ k ] ] + f[ i ][ j - ty[ k ] ] + w[ k ]);
	      f[ i ][ j ] = max( f[ i ][ j ] , f[ i - tx[ k ] ][ j ] + f[ tx[ k ] ][ j - ty[ k ] ] + w[ k ]);
	    }
      cout<<f[ cx ][ cy ]<<"\n";
      memset( f , 0 , sizeof( f ) );
    }
  return 0;
}
