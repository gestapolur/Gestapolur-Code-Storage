//dijkstra
#include<fstream>
#define INF 2141483647
#define MAXN 1002
using namespace std;

ifstream cin("data.in");
ofstream cout("out1.out");

int n,m;
//n are verxs , m are edges
int w[MAXN][MAXN],mark[MAXN];
int pre[MAXN];
bool in[MAXN];

void dijkstra(int s)
{
  int i,j,k,min;
  for(i=1;i<=n;i++) {mark[i] = w[s][i];pre[i] = s;}
  mark[s] = 0;
  pre[s] = 0;
  in[s] = true;

  for(i=1;i<=n;i++)
    {
      min = INF ;k = 0;
      for(j=1;j<=n;j++)
	if(not in[j] and min > mark[j])
	  {k = j;min = mark[j];}

      in[k] = true;

      for(j=1;j<=n;j++)
	if(w[k][j] not_eq INF and mark[j] > mark[k] + w[k][j])
	  {
	    mark[j] = mark[k] + w[k][j];
	    pre[ j ] = k; 
	  }
    }
 
  //print stage to every point's shortest path ;
  for(i=1;i<=n;i++)
    cout<<mark[i]<<" ";
  cout<<"\n";
  /*
  for(i = 1 ; i <= n ; ++ i)
    cout<<pre[ i ]<<" ";
  cout<<"\n";
  */
  return ;
}

int main()
{
  int i,u,v,wi;
  cin>>n>>m;
  //init
  for(u=0;u<=n;u++)
    for(v=0;v<=n;v++)
      w[u][v] = INF;
  
  for(i=1;i<=m;i++)
    {
      cin>>u>>v>>wi;
      w[u][v] = w[u][v] < wi ? w[u][v] : wi; 
    }

  dijkstra(1);
  
  cin.close();
  cout.close();
  
  return 0;
}
