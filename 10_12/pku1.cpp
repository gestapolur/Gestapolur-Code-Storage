/*problem C*/
#include<iostream>
#define MAXE 100005
using namespace std;

int n,m;
int u[MAXE],v[MAXE];
bool child[MAXE];
int ind[MAXN];

void work(int x)
{
  return ;
}

int main()
{
  int i;
  cin>>n>>m;
  for(i=1;i<=n;i++)
    cin>>u[i]>>v[i];
  for(i=1;i<=n;i++)
    if(ind[i] == 1)
      work(i);
  return 0;
}
