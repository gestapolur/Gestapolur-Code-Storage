#include<iostream>
#define MAXN 6002
using namespace std;

struct node
{
  int c;
  node *next;
}*child[MAXN] = {NULL};

int n;
int val[ MAXN ];

//int child[ MAXN ][ MAXN ];
int p[ MAXN ];

long long  max(long long  a, long long b) {return a > b ? a : b;}

long long dfs(int x , bool chose)
{ 
  if(child[ x ] == NULL and chose )
    return val[ x ]; 
  else if(child[ x ] == NULL and not chose )
    return 0;

  long long res = 0;
  node *p;

  if(not chose)
    {
      p = child[ x ];
      do{
	res = res + max( dfs( p->c , true ) , dfs( p->c , false ) );
	p = p->next;
      }while(p not_eq NULL);
    }
  else 
    {
      res = val[ x ];
      p = child[ x ];  
      do{
	res = res + dfs( p->c , false );
	p = p->next;
      }while(p not_eq NULL);
    }
  return res;
}

int main()
{
  int i,u,v;
  int root = 0;

  cin>>n;
  for( i = 1 ; i <= n ; ++ i)
    cin>>val[ i ];

  while(cin>>u>>v and u not_eq 0)
    {
      if( child[ v ] == NULL)
	{
	  child[ v ] = new node ;
	  child[ v ]->c = u;
	  child[ v ]->next = NULL;
	}
      else
	{
	  node *p ;
	  p = new node ;
	  p->c = u;
	  p->next = child[ v ];
	  child[ v ] = p;
	}
      //child[ v ][ ++child[ v ][ 0 ] ] = u;
      p[ u ] = v;
    }


  for(i = 1 ; i <= n ; ++ i)
    if(p[i] == 0)
      {root = i ; break;}

  long long ans;
  ans = max( dfs( root , true ) , dfs( root , false ) );
  cout<<ans<<"\n";

  return 0;
}
