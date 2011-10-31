#include <iostream>
#include <fstream>
#define INF 32767
using namespace std;
int c[201][201],h[201],vh[201],flow=0,n,m,delta;
bool found;

void aug(int v)
{
     if (v==n)
        {
            flow+=delta;
            found=true;
            return;
        }
     int temp=delta,i,minh=n-1;
     
     for (i=1;i<=n;i++)
         if (c[v][i] > 0)
            {
                if (h[i]+1==h[v])
                    {
                        delta=min(delta,c[v][i]);
                        aug(i);
                        if (h[1]>=n) return;
                        if (found) break;
                        delta=temp;
                    }
                minh=min(minh,h[i]);
            }
     if (found)
        {
            c[v][i]-=delta;
            c[i][v]+=delta;
        }
     else
        {
          vh[h[v]]--;
          if (vh[h[v]]==0) h[1]=n;
          h[v]=minh+1;
          vh[h[v]]++;
        }
}
int main()
{
    //memset(c,0,sizeof(c));
    //memset(h,0,sizeof(h));
    //memset(vh,0,sizeof(vh));
    flow=0;
    //ifstream fin("ditch.in");
    //ofstream fout("ditch.out");
    cin>>m>>n;
    /*
    for(int i = 0 ;i <= n ; i ++)
        for(int j = 0 ; j <= n ; j ++)
            c[i][j] = INF;
    */
    for (int i=1;i<=m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        c[x][y]+=z;
    }
    vh[0]=n;
    while (h[1]<n)
    {
          delta=2147483647;
          found=false;
          aug(1);
    }
    cout<<flow<<"\n";
    system("pause");
    return 0;
}
