#include <stdio.h>
#include <string.h>
 
const long MAXN=2800;
long long num[28][1005];
long long n1[MAXN+1],n2[MAXN+1];
 
int Compare()
{
  long i,p1,p2;
  for (p1=1;p1<=MAXN;p1++) if (n1[p1]) break;
  for (p2=1;p2<=MAXN;p2++) if (n2[p2]) break;
  if (p1>p2) return 1;
  if (p2<p2) return 0;
  for (i=p1;i<=MAXN;i++)
    {
      if (n1[i]<n2[i]) return 1;
      if (n1[i]>n2[i]) return 0;
    }
  return 1;
}
 
long Produc(long long tmp)
{
  long i;
  long long c=0;
  for (i=MAXN;i>=1;i--)
    {
      c=c*10000+n2[i]*tmp;
      n2[i]=c%10000;
      c=c/10000;
    }
}
 
int main()
{
  long n,m,i,j,k,ans;
  while (scanf("%d %d",&n,&m)!=EOF)
    {
      for (i=1;i<=m;i++)
        for (j=1;j<=n;j++) scanf("%d",&num[i][j]);
      memset(n1,0,sizeof(n1));
      for (i=1;i<=n;i++)
        {
          memset(n2,0,sizeof(n2));
          n2[MAXN]=1; ans = 1 ;
          for (j=1;j<=m;j++) Produc(num[i][j]);
          if ( not Compare())
            {
              memcpy(n1,n2,sizeof(n1));
              ans=i;
            }
        }
      printf("%d\n",ans);
    }
  return 0;
}
