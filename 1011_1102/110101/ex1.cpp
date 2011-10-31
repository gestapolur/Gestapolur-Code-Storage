/*
  USACO 2002 winter new year's party
  2011.1.1 by Gestapolur
  ACCEPTED
*/
#include<fstream>
#define MAXN 415
#define INF 2141483647
using namespace std;

ifstream cin("party.in");
ofstream cout("party.out");

int w[MAXN][MAXN],source,sink;
int cow,dish,k;

int n,flow,aug;
bool flag;
int d[MAXN],di[MAXN],pre[MAXN];
int vh[MAXN],h[MAXN];

void dfs()
{
  int i,j,mint,rec,tmp;

  vh[ 0 ] = n;

  for(i = 1 ;i <= n ; ++ i)
    di[ i ] = 1;

  i = source;
  aug = INF;

  while(d[ source ] < n)
    {
      h[i] = aug;
      flag = false;
      for(j = di[i] ; j <= n ; ++ j)
	if(w[i][j] > 0 and d[ j ] + 1 == d[ i ])
	  {
	    flag = true;
	    di[i] = j;
	    if(w[i][j] < aug)
	      aug = w[i][j];
	    pre[ j ] = i;
	    i = j;
	    if(i == sink)
	      {
		flow += aug;
		while(i not_eq source)
		  {
		    tmp = i;
		    i = pre[i];
		    w[tmp][i]+=aug;
		    w[i][tmp]-=aug;
		  }
		aug = INF;
	      }
	    break;
	  }
      if( flag )
	continue;
      mint = n - 1;
      for(j = 1 ; j <= n ; ++ j)
	if(d[j] < mint and w[i][j] > 0)
	  {mint = d[j] ; rec = j;}
      di[ i ] = rec ;
      vh[ d[i] ] --;
      if(vh[ d[i] ] == 0) break;
      d[ i ] = mint + 1;
      vh[ d[i] ] ++;
      if(i not_eq source )
	{
	  i = pre[i];
	  aug = h[i];
	}
    }
  return ;
}

int main()
{
  int i,j;
  int u,v;
  cin>>cow>>k>>dish;
  source = cow + dish + 1;
  sink = cow + dish + 2;
  n = cow + dish + 2;
  for(i = 1;i <= dish ; ++ i)
    cin>>w[ source ][ i ];

  for(i = 1 ;i <= cow ; ++ i)
    {
      cin>>u;
      for(j = 1 ;j <= u ; ++ j)
	{
	  cin>>v;
	  w[ v ][ dish + i ] = 1;
	}
    }

  for(i = 1 ;i <= cow ; ++ i)
    w[ dish + i ][ sink ] = k;
  /*
  for(i=1;i<=n;i++)
    {
      for(j=1;j<=n;j++)
	cout<<w[i][j]<<" ";
      cout<<"\n";
    }
  */
  dfs();
  cout<<flow<<"\n";
  cin.close();
  cout.close();
  return 0;
}
