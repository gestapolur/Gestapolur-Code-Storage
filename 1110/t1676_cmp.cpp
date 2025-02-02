#include <cstdio>
const int maxx=1501,maxn=maxx<<1,maxm=maxx*maxx;
int n,m,tot,totcolor;
int match[maxx],color[maxn],Q[maxn];
int h[maxn],node[maxm],next[maxm];
int revh[maxn],revnode[maxm],revnext[maxm];
bool vis[maxn],map[maxx][maxx],answer[301][maxx];
void addedge(int a,int b)
{
    node[++tot]=b;
    next[tot]=h[a];
    h[a]=tot;
    revnode[tot]=a;
    revnext[tot]=revh[b];
    revh[b]=tot;
}
bool dfs(int x)
{
    int y;
    for (y=1;y<=m;++y)
        if (map[x][y] && !vis[y])
        {
            vis[y]=true;
            if (!match[y] || dfs(match[y]))
            {
                match[y]=x;
                return true;
            }
        }
    return false;
}
void dfs1(int x)
{
    int i,y;
    for (vis[x]=true,i=h[x];i;i=next[i])
    {
        y=node[i];
        if (!vis[y])  dfs1(y);
    }
    Q[++tot]=x;
}
void dfs2(int x)
{
    int i,y;
    for (color[x]=totcolor,i=revh[x];i;i=revnext[i])
    {
        y=revnode[i];
        if (!color[y])  dfs2(y);
    }
}
int main()
{
    int i,j,ans;
    char str[maxx+1];
    scanf("%d%d",&n,&m);
    for (i=1;i<=n;++i)
    {
        scanf("%s",&str[1]);
        for (j=1;j<=m;++j)
            if (str[j] == '1')  map[i][j]=true;
            else  map[i][j]=false;
    }
    for (i=n+1;i<=m;++i)
        for (j=1;j<=m;++j)
            map[i][j]=true;
    for (i=1;i<=m;++i)  vis[i]=false,match[i]=0;
    for (ans=0,i=1;i<=n;++i)
        if (dfs(i))
        {
            ++ans;
            for (j=1;j<=m;++j)  vis[j]=false;
        }
    if (ans < n)
    {
        for (i=1;i<=m;++i)  str[i]='1';
        for (str[m+1]='\0',i=1;i<=n;++i)  puts(&str[1]);
        return 0;
    }
    for (j=0,i=n+1;i<=m;++i)
    {
        for (++j;match[j];++j);
        match[j]=i;
    }
    for (tot=0,i=1;i<=m;++i)
        for (j=1;j<=m;++j)
            if (match[j] == i)  addedge(i,j+m);
            else if (map[i][j]) addedge(j+m,i);
    for (i=1;i<=m+m;++i)  vis[i]=false,color[i]=0;
    for (tot=0,i=1;i<=m+m;++i)  if (!vis[i])  dfs1(i);
    for (totcolor=0,i=m+m;i>=1;--i)
        if (!color[Q[i]])
        {
            ++totcolor;
            dfs2(Q[i]);
        }
    for( i = 1 ; i <= 2 * m ; ++ i ) printf( "%d " , color[ i ] ); printf("\n");
    for (i=1;i<=n;++i)
    {
        for (j=1;j<=m;++j)
            if (map[i][j] && (match[j] == i || color[i] == color[j+m]))  printf("0");
            else  printf("1");
        printf("\n");
    }
    return 0;
}
/
