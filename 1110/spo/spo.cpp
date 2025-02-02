#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXN 16010
#define MAXM 40010
int n, m, N, Gfirst[MAXN], Gnext[MAXM], Gv[MAXM], Ge;
int col , afirst[MAXN], anext[MAXN], av[MAXN], ae, color[MAXN];
int gfirst[MAXN], gnext[MAXM], gv[MAXM], ge;
int s[MAXN], top, dfn[MAXN], low[MAXN], cnt, ins[MAXN];
int topo[MAXN], t, del[MAXN], vis[MAXN];
int ans[MAXN], res;
int cmp(const void *_p,const void *_q)
{
	int *p=(int *)_p;
	int *q=(int *)_q;
	return *p-*q;
}
int init()
{
	int i, j, k, n1, n2;
	char b1,b2;
	if(scanf("%d%d", &n, &m)==EOF)
		return 0;
	N = 2 * n;
	memset(Gfirst, -1, sizeof(Gfirst));
	Ge = 0;
	for(i = 0; i < m; i ++)
	{
		scanf("%d%d", &n1, &n2);
		n1 --;
		n2 --;
		Gv[Ge] = n2 ^ 1;
		Gnext[Ge] = Gfirst[n1];
		Gfirst[n1] = Ge;
		Ge ++;
		Gv[Ge] = n1 ^ 1;
		Gnext[Ge] = Gfirst[n2];
		Gfirst[n2] = Ge;
		Ge ++;
	}
	return 1;
}
void tarjan(int u)
{
	int i, j, e;
	dfn[u] = low[u] = ++cnt;
	for(e = Gfirst[u]; e != -1; e = Gnext[e])
	{
		if(!dfn[Gv[e]])
		{
			s[top ++] = Gv[e];
			ins[Gv[e]] = 1;
			tarjan(Gv[e]);
			if(low[Gv[e]] < low[u])
				low[u] = low[Gv[e]];
		}
		else if(ins[Gv[e]] && dfn[Gv[e]] < low[u])
			low[u] = dfn[Gv[e]];
	}
	if(low[u] == dfn[u])
	{
		for(i = 0, s[top] = -1; s[top] != u; i++)
		{
			top --;
			av[ae] = s[top];
			anext[ae] = afirst[col];
			afirst[col] = ae;
			ae ++;
			color[s[top]] = col;
			ins[s[top]] = 0;
		}
		col ++;
	}
}
int judge()
{
	int i;
	for(i = 0;i < N; i ++)
		if(color[i] == color[i ^ 1])
			return 0;
	return 1;
}
int dfs(int u)
{
	int e;
	vis[u] = -1;
	for(e = gfirst[u]; e != -1; e = gnext[e])
	{
		if(vis[gv[e]] == -1)
			return 0;
		if(!vis[gv[e]] && !dfs(gv[e]))
			return 0;
	}
	vis[u] = 1;
	topo[-- t] = u;
	return 1;
}
int toposort()
{
	int i;
	t = col;
	memset(vis, 0, sizeof(vis));
	for(i = 0; i < col; i ++)
		if(!vis[i] && !dfs(i))
			return 0;
	return 1;
}
void dfsdel(int u)
{
	int e;
	del[u] = 1;
	for(e = gfirst[u]; e != -1; e = gnext[e])
		if(!del[gv[e]])
			dfsdel(gv[e]);
}
void search(int i)
{
	int j, p;
	del[i] = 1;
	for(j = afirst[i]; j != -1; j = anext[j])
	{
		p = av[j];
		ans[res ++] = p;
		if(!del[color[p ^ 1]])
			dfsdel(color[p ^ 1]);
	}
}
int com()
{
	int i, j, k, p, ok;
	top = cnt = col = 0;
	memset(ins, 0, sizeof(ins));
	memset(dfn, 0, sizeof(dfn));
	memset(afirst, -1, sizeof(afirst));
	ae = 0;
	for(i = 0; i < N; i ++)
		if(! dfn[i])
		{
			s[top ++] = i;
			ins[i] = 1;
			tarjan(i);
		}
	if(!judge())
		return 0;
	memset(gfirst, -1, sizeof(gfirst));
	ge = 0;
	for(i = 0; i < N; i ++)
		for(j = Gfirst[i]; j != -1; j = Gnext[j])
			if(color[i] != color[Gv[j]])
			{
				gv[ge] = color[i];
				gnext[ge] = gfirst[color[Gv[j]]];
				gfirst[color[Gv[j]]] = ge;
				ge ++;
			}
	if(!toposort())
		return 0;
	memset(del , 0, sizeof(del));
	res = 0;
	for(i = 0; i < col; i ++)
		if(!del[i])
			search(i);
	if(res != n)
		return 0;
	return 1;
}
void printpath()
{
	int i, j, tt;
	tt = 0;
	qsort(ans, res, sizeof(ans[0]), cmp);
	for(i = 0; i < res; i ++)
		printf("%d\n",ans[i]+1);
}
int main()
{
	while(init())
	{
		if(com())
			printpath();
		else
			printf("NIE\n");
	}
	return 0;	
}

