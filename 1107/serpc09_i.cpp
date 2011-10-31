//SERPC09 I
#include<iostream>
#define MAXS 32769
#define MAXN 16
using namespace std;

int f[ MAXS ] , c[ MAXN ] , w[ MAXN ];

int main()
{
  int i , j , t , tot , di ;
  cin>>t;
  while( t -- )
    {
      cin>>n>>m;
      for( i = 1 ; i <= n ; ++ i ) cin>>w[ i ];
      for( i = 1 ; i <= n ; ++ i ) cin>>c[ i ];
      //con
      tot = (1 << n + 1) - 1 ;
      for( i = 1 ; i <= tot ; += i )
	{
	  s = i ;
	  while( s )
	    {
	      di = s & -s;
	      
	      s -= di;
	    }
	}
    }
  return 0;
}
