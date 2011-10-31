#include<iostream>
#define MAXN 701
using namespace std;

int f,n,m,h;
int w[MAXN][MAXN];
int mark[MAXN];
bool in[MAXN];

void SPFA(int s)
{
    int q[MAXN << 1];
    int i,u,front,rear;
    front = 0;
    rear = 1;
    q[front] = s;
    
    for(i = 1 ; i <= n ; i ++)
        mark[i] = INF;
    
    do{
        u  = q[front ++];
        in[u] = false;
        for(i = 1 ; i <= n ; i ++)
            if(w[u][i] not_eq INF and mark[i] > mark[u] + w[u][i])
                {
                    mark[i] = mark[u] + w[u][i];
                    if(not in[i])
                        {
                            in[i] = true;
                            q[++rear] = i;
                        }    
                    
                }
    }while(front <= rear);
    
     return 0;     
}

int main()
{
    int i,j,k;
    cin>>f;
    for(j=1;j<=f;j++)
        {
           cin>>n>>m>>h;
           
           for(i = 1 ; i <= m ; i ++)
            for( k = 1 ; k <= m ; k ++)
                w[i][k] = INF;
                
           for(i = 1 ;i <= m ;i++)
            {
                cin>>u>>v;
                cin>>w[u][v];    
            }
            
           for(i = 1;i <= h ;i++)
            {
                cin>>u>>v;
                cin>>w[u][v];    
            }
            
           for(i = 1 ;i <= m ;i ++)
              if(w[1][i] not_eq INF)
                {
                    k = w[1][i];
                    w[1][i] = INF;
                    SPFA(i);
                    w[1][i] = INF;
                }
        }
    return 0;    
}
