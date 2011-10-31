#include<iostream>
#define MAXN 1001
using std::cin;
using std::cout;

int n,e;
int f[MAXN][MAXN],c[MAXN][MAXN];
int w[MAXN][MAXN];//w[u][i] is the i-th verx that u linked
int v[MAXN];//v[i] is the number of verx that verx i linked
int e[MAXN],h[MAXN];
int mark[MAXN];//whether verx i were visited

int min(int a,int b)
{return a>b?b:a;}

void relabel(int u,int v)
{
  h[u] = min(h[v],c[][]) + 1;
  return ;
}

void push(int u)
{
  int aug,i;
  for(i=1;i<=v[0];i++)
    aug = min( e[ u ] , c[ u ][ w[ u ][ v[i] ] ]);
  
  return ;
}

void dfs(int u)
{
  int i;
  bool flag = false;//check whether u were overflow;
  for(i=1;i<=n;i++)
  return ;
}

void init(int s)
{
  int i;
  h[s] = n;//the height of source is n 
  //flow the source point
  for(i=1;i<=n;i++)
    {
      f[s][i] = c[s][i];
      f[i][s] = c[s][i];
      e[i] = c[s][i];
      e[s]-=c[s][i];
    }
  return ;
}

int main()
{
  int i,a,b,c;
  cin>>n>>e;
  for(i=1;i<=n;i++)
    {
      cin>>a>>b>>c;
      c[a][b]+=c;
      c[b][a]-=c;
      w[a][++v[a]] = b;
    }

  init(1);

  dfs(1);

  cout<<flow<<"\n";

  return 0;
}
