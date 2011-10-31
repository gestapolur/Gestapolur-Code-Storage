//SAP 迭代 非递归形式
/*
  SAP非递归代码
  gestapolur
  2009.6.11
 */
#include<iostream>
#define MAXN 1006
#define INF 2141483647
using std::cin;
using std::cout;
/*
ifstream cin("ditch.in");
ofstream cout("ditch.out");
*/
bool flag;
int h[MAXN];//height mark 
int pre[MAXN];
int d[MAXN];
int vh[MAXN];//gap
int di[MAXN];
int map[MAXN][MAXN];
int mint,flow,aug,m,n;

void dfs()
{
  int i,j,tmp,rec=0;

  vh[0] = n;

  for(i=1;i<=n;i++)
    di[i] = 1;

  i=1;
  aug=INF;

  while(d[1] < n)//is this the source point ? 
    {
      h[i] = aug;
      flag = false;
      cout<<"flow "<<flow<<" "<<i<<" "<<di[i]<<"\n";

      for(j=di[i];j<=n;j++)
	{
	  cout<<"scanning : "<<i<<" "<<j<<" "<<map[i][j]<<" "<<d[ j ]<<" "<<d[i]<<"\n";
	  if(map[i][j]>0 and d[j]+1==d[i])
	  {
	    flag = true;
	    di[i]=j;
	    cout<<"verx : "<<j<<"\n";
	    if(map[i][j] < aug) aug=map[i][j];
	    pre[j] = i;
	    i=j;
	    if(i == n)
	      {
		flow += aug;
		while(i not_eq 1)
		  {
		    tmp = i;
		    i = pre[i];
		    map[i][tmp]-=aug;
		    map[tmp][i]+=aug;
		  }
		aug = INF;
	      }
	    break;
	  }
	}

      if(flag)  continue;
      mint = n-1;
      for(j=1;j<=n;j++)
	if(map[i][j]>0 and d[j] < mint)
	  {rec=j;mint=d[j];}
      cout<<"nopath con"<<i<<" "<<mint<<" "<<rec<<"\n";
      di[i]=rec;
      vh[d[i]]--;
      if(vh[d[i]] == 0) break;
      d[i]=mint + 1;
      vh[d[i]]++;
      if(i not_eq 1){i=pre[i];aug=h[i];}
    }
  return ;
}

int main()
{
  int i,x,y,w;
  cin>>m>>n;
  for(i=1;i<=m;i++)
    {
      cin>>x>>y>>w;
      map[x][y]+=w;
    }
  dfs();
  cout<<flow<<"\n";
  /*
  cin.close();
  cout.close();
  */
  return 0;
}
