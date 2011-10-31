//tarjan test
#include<iostream>
#define MAXN 1006
using namespace std;

int dfn[ MAXN ] , low[ MAXN ] , st[ MAXN ];
int w[ MAXN ][ MAXN ];
bool vis[ MAXN ] , ins[ MAXN ];
int n , m , pos ;

int min( int a , int b ){ return a < b ? a : b ; }

void tarjan( int u )
{
  int v ;
  dfn[ u ] = low[ u ] = ++ pos ;//current mark 
  st[ ++ st[ 0 ] ] = u;
  ins[ u ] = true ;
  vis[ u ] = true ;
  //cout<<u<<"\n";
  for( v = 1 ; v <= w[ u ][ 0 ] ; ++ v )
    {
      if( not vis[ w[ u ][ v ] ] )//dfs process 
        {
          tarjan( w[ u ][ v ] );
          low[ u ] = min( low[ w[ u ][ v ] ] , low[ u ] );//update the lowest mark 
        }
      else if( ins[ w[ u ][ v ] ] )
        low[ u ] = min( low[ u ] , dfn[ w[ u ][ v ] ] );
      //low[ w[ u , v ] ] may updated by the following node which was added by other scc
      //if a node aready in the stack , the low must be ???
    }
  //because it recursion structure 
  if( dfn[ u ] == low[ u ] )// no lower mark ancestor than u so u must be the end of a scc
    {
      //pop stack
      //cout<<u<<" "<<dfn[ u ]<<" "<<low[ u ]<<"\n";
      do{
        v = st[ st[ 0 ] -- ];
        ins[ v ] = false ;
      }while( v not_eq u and st[ 0 ] > 0 );
    }
  return ;
}

void init()
{
  int i , u , v ;
  cin>>n>>m;
  for( i = 1 ; i <= m ; ++ i )
    {
      cin>>u>>v;
      w[ u ][ ++ w[ u ][ 0 ] ] = v ;
    }
  pos = 1 ;
  return ;
}

void output( )
{
  int i ;
  for( i = 1 ; i <= n ; ++ i )
    cout<<low[ i ]<<" ";
  cout<<"\n";
  return ;
}

int main()
{
  init();
 
  tarjan( 1 );
  output();
  return 0;
}
