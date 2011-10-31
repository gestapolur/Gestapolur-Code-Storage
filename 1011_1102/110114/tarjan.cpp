#include<iostream>
#include<cstring>
#define MAXN 1001

using namespace std;

int DFN[MAXN],LOW[MAXN],Belong[MAXN];/*DFS时间戳,*/
bool instack[MAXN];/*点i是否在栈中*/
int Dindex,Bcnt,Stop;
int Stap[MAXN];
int N,M;

struct edge
{
  int t;
  edge *next;
};

edge *V[MAXN * MAXN] = {NULL};/*邻接链表*/

void tarjan(int i)
{
  int j;
  edge *e;
  DFN[ i ] = LOW[ i ] = ++Dindex;
  instack[ i ] = true;
  Stap[ ++Stop ] = i;
  e = V[ i ];
  while(e not_eq NULL)
    {
      j=e->t;
      if (!DFN[j])
	{
	  tarjan( j );
	  if (LOW[j] < LOW[i])/* !!! */
	    LOW[i] = LOW[j];
	}
      else if (instack[j] && DFN[j]<LOW[i])
	LOW[i] = DFN[j];
      e = e->next ;
    }
  /*发现强连通分量*/
  if (DFN[i] == LOW[i])
    {
      Bcnt++;
      do{
	j=Stap[Stop--];
	instack[j]=false;
	Belong[j]=Bcnt;
      }while (j != i);
    }
}

void solve()
{
  int i;
  Stop = Bcnt = Dindex = 0;
  memset(DFN,0,sizeof(DFN));
  for (i=1;i<=N;i++)
    if (!DFN[i])
      tarjan(i);
  cout<<Bcnt<<"\n";
  for(i = 1 ;i <= N ; ++ i)
    cout<<Belong[i]<<" ";
  cout<<"\n";
}

int main()
{
  int i,u,v;
  cin>>N>>M;
  /*
  for(i = 1 ; i <= M ; ++ i)
    {
      cin>>v;
      if(not V[i])
	{
	  V[i] = new edge;
	  V[i]->t = v;
	  V[i]->next = NULL;
	}
      else
	{
	  edge *tmp,*e;
	  tmp = V[i];
	  while(tmp->next not_eq NULL)
	    tmp = tmp->next;
	  e = new edge;
	  e->next = NULL;
	  e->t = v;
	  tmp->next = e;
	}
    }
  */

  for(i = 1 ; i <= M ; ++ i)
    {
      cin>>u>>v;
      if(not V[ u ])
	{
	  V[ u ] = new edge;
	  V[ u ]->t = v;
	  V[ u ]->next = NULL;
	}
      else
	{
	  edge *tmp,*e;
	  tmp = V[u];
	  while(tmp->next not_eq NULL)
	    tmp = tmp->next;
	  e = new edge;
	  e->next = NULL;
	  e->t = v;
	  tmp->next = e;
	}
    }
  solve();
  return 0;
}
