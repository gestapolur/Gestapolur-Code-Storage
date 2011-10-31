//prob j
#include<iostream>
#define MAXN 20004
#define INF 2141483647
using namespace std;

int f[MAXN][MAXN];
int aug,maxc,n,m;
bool flag;

int vh[MAXN],di[MAXN],d[MAXN];
int pre[MAXN],h[MAXN];
int mint,flow;

void dfs()
{
  int i,j,tmp,rec = 0;

  vh[0] = n;

  for(i=1;i<=n;i++)
    di[i] = 1;

  i = 1;
  aug = INF;

  while(di[1] < n)
    {
      h[i] = aug;
      flag = false;

      for(j=di[i];j<=n;j++)
	if(f[i][j] > 0 and d[j] + 1 == d[i])
	  {
	    flag = true;
	    di[i] = j;
	    if(f[i][j] < aug) aug = f[i][j];
	    pre[j] = i;
	    i = j;
	    if(i == n)
	      {
		flow+=aug;
		while(i not_eq 1)
		  {
		    tmp = i;
		    i = pre[i];
		    f[i][tmp] -= aug;
		    f[tmp][i] += aug;
		  }
		aug = INF;
	      }
	    break;
	  }

      if(flag) continue;
      mint = n-1;
      for(j=1;j<=n;j++)
	if(f[i][j] > 0 and d[j] < mint)
	  {rec = j;mint = d[j];}
      di[i] = rec;
      vh[d[i]]--;
      if(vh[d[i]] == 0) break;
      d[i] = mint + 1;
      vh[d[i]]++;
      if(i not_eq 1){i = pre[i];aug = h[i];}
    }

  return ;
}

int main()
{
  int t,i,j,k,l,tn,tm;
  /*
  cin>>n>>m;
  for(i=1;i<=m;i++)
    {
      cin>>k>>l>>t;
      f[k][l]+=t;
    }
  dfs();
  cout<<flow<<"\n";
  return 0;
  */

  cin>>t;
  while(t > 0 )
    {
      cin>>tn>>tm;//n is girls ,m is stone
      n = tn + tm + 2;
      /* 1 is source , tn + tm + 2 is sink , [2,tn] is stone & [tn+1,tn+tm+1] is girl */
      //init
      maxc = 0;flow = 0;mint = 0;
      for(i=0;i<=n;i++)
	for(j=0;j<=n;j++)
	  f[i][j] = 0;
      for(i=0;i<MAXN;i++)
	{
	  di[i] = 0;
	  vh[i] = 0;
	  d[i] = 0;
	  pre[i] = 0;
	  h[i] = 0;
	}

      for(i=1;i<=tn;i++)
	{
	  cin>>k;
	  for(j=1;j<=k;j++)
	    {
	      cin>>l;
	      f[l + 1][tm + 1 + i] = INF;//stone l to girl i has a infinative flow 
	    }
	  /*the value of girl i*/
	  cin>>f[tm + 1 + i ][n];
	}
      
      for(i=1;i<=tm;i++)//source to stone i 's flow
	cin>>f[1][i + 1];

      for(i=tm+1;i<n;i++)
	maxc+=f[i][n];
      /*
      for(i=1;i<=n;i++)
	{
	  for(j=1;j<=n;j++)
	    cout<<f[i][j]<<" ";
	  cout<<"\n";
	}
      */
      dfs();
      //cout<<flow<<"\n";
      cout<<maxc-flow<<"\n";
      --t;
    }

  return 0;
}
