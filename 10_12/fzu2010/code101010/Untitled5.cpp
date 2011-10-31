#include<iostream>
#define MAXN 1001
using namespace std;

int g[MAXN][MAXN],c[MAXN][MAXN],f[MAXN][MAXN];
int d[MAXN],vd[MAXN];
int m,n,flow,ans;

int min(int a,int b)
{return a > b ? b : a;}
 
int dfs(int u ,int flow)
{    
    int v,tmp,aug;
    
    if ( u == n )
        return flow;
        
    aug = 0;  		 
    for (v = 1;v <= n ; v ++ )
        if ( ( g[u][v]>0 ) and (d[u] == d[v] + 1) )
            {
                tmp = dfs( v, min( flow - aug,g[u][v]) );	
                g[u][v]-=tmp;
                g[v][u]+=tmp;
                if(c[u][v]>0) 
                    f[u][v]-=tmp; 
                else 
                    f[v][u]-=tmp;
                aug+=tmp;
                if (aug == flow)
                    return flow;
            }
    
    if ( d[1] >= n )
        return 0;
    --vd[d[u]];
    
    if ( vd[d[u]] == 0 ) 
        d[1]=n;
    d[u] = d[u] + 1;
    ++vd[d[u]];
    return 0;
}

int main()
{
    int i,x,y,z;
	cin>>n>>m;
	for (i=1;i<=m;i++)
	 {
	    cin>>x>>y>>z;
	    g[x][y]+=z;
	    c[x][y]+=z;
	 }
	
	vd[0] = n;
	while (d[1]<n)
	  {
	    flow = dfs(1,32767);
	    ans+=flow;
	  }
	  
	cout<<ans<<"\n";
	
	system("pause");

    return 0;
}
