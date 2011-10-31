#include<fstream>
#include<cstdio>
#define N 1000
using namespace std;

ifstream cin("choice.in");
ofstream cout("choice1.out");

struct node{
  int y,next;
} E[N*2];

int edg[N],ans,s[N],n,x,C,cnt;
int f[N][N];

void add_edge(int x,int y)
{
  ++cnt;
  E[ cnt ].next = edg[ x ];
  edg[ x ] = cnt;
  E[ cnt ].y = y;    
}

void dp(int u,int C)
{
     if (C<=0) return;
     int i,j,v;

     for (j = edg[u] ; j!=0 ; j=E[j].next)
     {
         v=E[j].y;
         for ( i = 0 ; i <= C ; ++i ) 
	   f[v][i]=f[u][i];
         dp(v,C-1);
         for (i = 0 ; i <= C-1 ; ++i )
	   if ( f[ u ][ i + 1] < f[v][i]+s[v] ) 
	     f[u][i+1]=f[v][i]+s[v];
     }
     return ;
}
int main()
{
  ///freopen("choice.in","r",stdin);
  //freopen("choice1.out","w",stdout);
  // scanf("%d%d",&n,&C);
  cin>>n>>C;
  for (int i=1;i<=n;++i)
    {
      //scanf("%d%d",&x,&s[i]);
      cin>>x>>s[i];
      add_edge(x,i);
    }
  dp(0,C+1);
  for (int i=0;i<=C;++i) if (f[0][i]>ans) ans=f[0][i];
  cout<<ans<<endl;
  return 0;
}
