/*PKU100509 PROB G*/
#include<iostream>
#define MAXN 605
using namespace std;

int n,m;
int w[MAXN][MAXN];
bool col[MAXN];


int main()
{
  int i,u,v;
  cin>>n>>m;
  for(i=1;i<=m;i++)
    {
      cin>>u>>v;
      cin>>w[u][v];
      w[v][u] = w[u][v];
    }

  for(i=1;i<=n;i++)
    {
      cin>>v;
      if(v == 1)
	col[i] = true;
      else
	col[i] = false;
    } 
  return 0;
}
