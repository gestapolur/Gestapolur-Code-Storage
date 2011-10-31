/*
  SPFA
  2011-01-11
  write by Gestapolur
  most case tested
*/
#include<fstream>
#define MAXN 1002
#define INF 2141483647
using namespace std;

ifstream cin("data.in");
ofstream cout("out2.out");

int n,m;//verx,edge
int rear,front;
int w[MAXN][MAXN],que[MAXN * 100],mark[MAXN]; // record the number of verx in queue ;
int pre[MAXN];
bool in[MAXN];
//array w is adj matrix

void SPFA(int s)
{
  int i;
  for(i=1;i<=n;i++) mark[i] = INF;
  front = 0,rear = 1;
  que[rear] = s,mark[s] = 0;

  do{
    ++front;
    in[ que[ front ] ] = false;//notice que[front] here
    
    for(i=1;i<=n;i++)
      {
	if( w[que[front]][i] > 0 and mark[i] > mark[que[front]] + w[que[front]][i] )
	  {
	    mark[i] = mark[que[front]] + w[que[front]][i];
	    pre[ i ] = que[ front ];
	    
	    if(not in [ i ])
	      {
		que[ ++rear ] = i;
		in [ i ] = true; 
	      }
	  }
      }
  }while(front<=rear);
  
  for(i=1;i<=n;i++)
    cout<<mark[i]<<" ";
  cout<<"\n";
  /*
  for(i=1;i<=n;++i)
    cout<<pre[ i ]<<" ";
  cout<<"\n";
  */
  return ;
}

int main()
{
  int i,u,v,wi;
  cin>>n>>m;
  for(i = 1 ; i <= m ; ++ i)
    {
      cin>>u>>v>>wi;
      if(w[u][v] not_eq 0)
	w[u][v] = w[u][v] < wi ? w[u][v] : wi ;
      else
	w[u][v] = wi;
    }

  SPFA(1);
  
  return 0;
}
