//bellman_ford
#include<fstream>
#define MAXN 1002
#define INF 2141483647
using std::ifstream;
using std::ofstream;

ifstream cin("data1.in");
ofstream cout("out3.out");

//adj list
int n,e;//e is the num of edge 
int mark[MAXN],u[MAXN * MAXN],v[MAXN * MAXN],w[MAXN * MAXN];

bool bellman_ford(int s)
{
  int i,j;
  bool sign ;
  //init
  for(i=1;i<=n;i++) mark[i] = INF;
  mark[s] = 0; 

  for(i=1;i<n;i++)
    {
      sign = false;
      for(j=1;j<=e;j++)
	if(mark[u[j]] not_eq INF and mark[v[j]] > mark[u[j]] + w[j])
	  {mark[v[j]] = mark[u[j]] + w[j];sign = true;}
      if(not sign)
	break;
    }
  //验证是否存在负权回路
  for(i=1;i<=e;i++)
    if(mark[v[i]] > mark[u[i]] + w[i]) 
      return false;

  return true;
}

int main()
{
  int i;
  cin>>n>>e;
  for(i=1;i<=e;i++)
    cin>>u[i]>>v[i]>>w[i];

  if(bellman_ford(1))
    for(i=1;i<=n;i++)
      cout<<mark[i]<<" ";
  cout<<"\n";

  cin.close();
  cout.close();

  return 0;
}
