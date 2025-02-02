/*TIMUS 1039 Anniversary Party */
#include<iostream>
#define MAXN 6002
using namespace std;

int n;
int f[ MAXN ][ 2 ];
int stack[ MAXN ];
int val[ MAXN ];
int child[ MAXN ] , p[ MAXN ];
int top[ 2 ];
int visited,root;

int max(int a , int b){ return a > b ? a : b ; }

int main()
{
  int i,u,v,x,tmp;

  //init
  cin>>n;

  for(i = 1 ; i <= n ; ++ i)
    cin>>val[ i ];

  while(cin>>u>>v and u not_eq 0)
    {
      p[ u ] = v;
      ++child[ v ];
    }

  for(i = 1 ; i <= n ; ++ i)
    if(child[ i ] == 0)
      stack[ ++top[ 1 ] ] = i;
    else if(p[ i ] == 0)
      root = i;

  //dynamic programming
  x = 1;
  while( visited < n )
    {
      x = x ^ 1;
      top[ x ] = 0;
      for(i = 1 ; i <= top[ x ^ 1] ; ++ i)
	{

	  tmp = stack[ i ];

	  f[ tmp ][ 1 ] += val[ tmp ];

	  f[ p[ tmp ] ][ 1 ] += f[ tmp ][ 0 ];
	  f[ p[ tmp ] ][ 0 ] += max(f[ tmp ][ 0 ] , f[ tmp ][ 1 ]);

	  --child[ p[ tmp ] ];

	  if(child[ p[ tmp ]] == 0)
	    stack[++top[x]] = p[ tmp ];
	}
      visited += top[ x ^ 1 ];
    }

  cout<<max( f[ root ][ 0 ] , f[ root ][ 1 ] )<<"\n";

  return 0;
}
