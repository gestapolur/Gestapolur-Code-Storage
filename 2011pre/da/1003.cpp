//1003
#include<iostream>
#define MAXN 10003
#define MAXK 10003
using namespace std;

int n , s , k ;

int f[ MAXN ][ MAXK ] , u[ MAXN ] , v[ MAXN ];

class link
{
public:
  int x ;
  link *next;
};

link *head[ MAXN ];

void add( int x , int e )
{
  if( head[ x ] == NULL )
    {
      head[ x ]->x = e;
    }
  else
    {
      link *p = NULL;
      p->x = e;
      p->next = head[ x ];
    }
  head[ x ]->next = NULL;
  return ;
}

void dp( int x , int rk )
{
  int i , mint = INF ;
  link *p;
  p = head[ x ];
 
  while( p not_eq NULL )
    {
      for( i = 1 ; i <= rk ; ++ i )
	dp( p->x , i );
      g[ p->x ][ i ];
      p = p->next;
    }
  p = head[ x ];
  while( p not_eq NULL )
    {
      for( i = 1 ; i <= rk ; ++ i )
	if( f[ p->x ][ i ] > f[][])
      p = p->next;
    }
  return ;
}

int main()
{
  while( cin>>n>>s>>k )
    {
      init();
    
      dfs();
  
      dp( s , k );
      
      cout<<f[ s ][ k ]<<"\n";
    }
  return 0;
}
