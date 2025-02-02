/*
  minium expense flow
  2011-04-19
  write by gestapolur
*/
#include<iostream>
#define INF 2141483647
#define MAXN 1005
using namespace std;

int n,m;
int srt[ MAXN ] , b[ MAXN ];
int f[ MAXN ][ MAXN ] , c[ MAXN ][ MAXN ];
int w[ MAXN ][ MAXN ];
int maxflow , mincost;
int sink;

bool findflow()
{
  int i,j;
  bool flag ;

  for(i = 1 ; i <= n ; ++ i)
    {
      srt[ i ] = INF ;
      b[ i ] = -1;
    }

  srt[ 1 ] = 0 ; b[ 1 ] = 0;
  flag = true;
     
  while( flag )
    {
      flag = false;
      for (i = 1 ; i <= n ; ++ i)   // 修改srt[i]的值及前驱
	for(j = 1 ; j <= n ; ++ j)
	  if ( c[ j ][ i ] > 0 and srt[ i ] > srt[ j ] + w[ j ][ i ] )
	    {
	      flag = true;
	      srt[ i ] = srt[ j ] + w[ j ][ i ];
	      b[ i ] = j;
	    }
    }

  //test
  /*
  for( i = 1 ; i <= n ; ++ i)
    cout<<srt[ i ]<<" ";
  cout<<"\n";
  */
  if ( srt[ n ] < INF )
    return true;

  return false;

}

void addflow( )//沿增广路增广流量,同时改变费用
{
  int flow,cost,i ;
  
  flow = INF ; cost = 0;
  //i = n;//i = sink
  i = sink ; 
  while ( i not_eq 1 )  //计算增加的流量flow,增加路径的单位费用 cost
    {
      if ( flow > c[ b[ i ] ][ i ] ) flow = c[ b[ i ] ][ i ];
      cost+=w[ b[ i ] ][ i ];    // cost=srt[n]
      i = b[i];
    }

  maxflow+=flow; // 流量增加
  mincost+=flow*cost;//费用增加,增广路径费用

  //i = n;
  i = sink;
  while ( i not_eq 1 )
    {
      c[ b[ i ] ][ i ]-=flow; //正向弧减少残留量
      c[ i ][ b[ i ] ]+=flow; //逆向弧增加残留量
      i = b[ i ];
    }
  return ;
}

void input()
{
  int i , j ;
  int u , v , cap , wi;
  cin>>n>>m>>sink;
  for(i = 1 ; i <= m ; ++ i)
    {
      cin>>u>>v>>cap>>wi;
      c[ u ][ v ] = f[ u ][ v ] = cap ;
      w[ u ][ v ] = wi ;
    }
  return ;
}

int main()
{
  input();
  while( findflow( ) )
    addflow();
  cout<<maxflow<<" "<<mincost<<"\n";
  return 0;
}
