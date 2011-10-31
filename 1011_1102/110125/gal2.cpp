#include<cstdlib>
#include<cstdio>
#include<iostream>

int h[30001],f[30001],at[30001];

int find(int x)
{
  int t;
  if (f[x] == x) return (x);
  t = f[ x ];//记录父亲节点
  f[ x ] = find( f[ x ] );//路径压缩
  h[ x ] = h[ x ] + h[ t ];//与新父亲节点之间的距离更新
  return f[x];
}

int main()
{
  int n,x,y,i,t;
  char ch1,ch2;
  freopen("galaxy.in","r",stdin);
  freopen("galaxy.out","w",stdout);
  scanf("%d\n",&n);
  for (i=1;i<=30000;++i)
    {
      f[i]=i;
      at[i]=0;
      h[i]=0;
    }

  for (i=1;i<=n;++i)
    {
      scanf("%c%c%d%d\n",&ch1,&ch2,&x,&y);
      if (ch1=='M')
	{
	  x=find(x); y=find(y);
	  f[ x ] = y ;//合并
	  h[x]=at[y]+1;//更新第x艘船到第y艘船的距离
	  at[y]=at[x]+at[y]+1;//更新第y艘船后面的船的数目
	}
      else
	{
	  if (find(x)==find(y)) 
	    printf("%d\n",abs(h[x]-h[y])-1);//如果在同一列输出距离
	  else
	    printf("-1\n");
	}
    }
  return 0;
}
