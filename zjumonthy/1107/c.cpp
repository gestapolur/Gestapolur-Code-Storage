//c
#include<iostream>
#define MAXN 50002
using namespace std;

int u[ MAXN ] , v[ MAXN ] , w[ MAXN ];
int ind[ MAXN ];
int n , m ;

void work()
{
  return ;
}

int main()
{
  int i;
  while( cin>>n )
    {
      for( i = 1 ; i <= n ; ++ i )
	cin>>u[ i ]>>v[ i ]>>w[ i ];
      cin>>m;
      for( i = 1 ; i <= m ; ++ i )
	{
	  cin>>u[ n + 1 ]>>v[ n + 1 ]>>w[ n + 1 ];
	  work();
	}      
    }
  return 0 ;
}
