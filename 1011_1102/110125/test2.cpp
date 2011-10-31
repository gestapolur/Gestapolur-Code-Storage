#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long lld;
const int N=50005;
const int E=150005;
const lld INF=(lld)(1)<<60;
struct gtp{int x,y,w,next;}g[E];
int n,m,L,e;
int ls[N],du[N],list[N];
lld F[N][11];

void input(){
  scanf("%d %d %d",&n,&m,&L);
  for (int i=1,x,y,w;i<=m;i++)
    {
      scanf("%d%d%d",&x,&y,&w);
      g[++e].x=x; g[e].y=y; g[e].w=w; g[e].next=ls[x]; ls[x]=e;
      du[y]++;
    }
}

void bfs()
{
  int head=0,tail=0,i,t;
  for (i=1;i<=n;i++) 
    if (!du[i]) list[++tail]=i;

  while (head<tail)
    {
      head++;
      for (t=ls[list[head]];t;t=g[t].next)
	{
	  du[g[t].y]--;
	  if (!du[g[t].y]) 
	    list[++tail]=g[t].y;
	}
    }
}

void dp()
{
     memset(F,200,sizeof(F));
     F[n][0]=0;
     int i,j,k,t;
     lld Min,Max;
     for (k=n;k>=1;k--)
       {
         i=list[k];
	 cout<<i<<"\n";
         for (j=0;j<=L;j++)
	   {

	     Min=INF;
	     
             if ( j )
	       for (t=ls[i];t;t=g[t].next)
		 if (F[ g[t].y ][ j - 1 ] >= 0 && F[ g[t].y ][ j - 1 ] + g[ t ].w < Min )
		   Min = F[ g[t].y ][ j - 1 ] + g[t].w;
	     
             Max=0;

             for ( t = ls[i] ; t ; t = g[ t ].next)
               Max = max( Max , F[g[t].y][j] + g[t].w );
	     
             F[i][j]=min( Max , Min );
	     
	     cout<<i<<","<<j<<" "<<F[ i ][ j ]<<"\n";
	   }
       }
     cout << F[1][L] << '\n';
}

int main()
{
  //freopen("slide.in","r",stdin);
  //freopen("slide.out","w",stdout);
  input();
  bfs();
  dp();
  return 0;
}
