#include<stdio.h>
#include<cstring>
#define max(a,b) a>b?a:b
typedef struct wu
{
	double V;
	int T;
}wu;
wu wupin[10005];
double dp[100005];
int main()
{
	int n,i,vz,m;
	double MAX,mm,TT;
	int t;
	freopen("g2.in","r",stdin);
	freopen("ans2.out","w",stdout);
	scanf("%d",&t);
	while( t > 0 )
	  {
	    scanf("%d%lf",&n,&mm);
		MAX=0;
		m=mm*100+0.5;
		for(i=0;i<n;i++)
		{
			scanf("%lf%lf",&wupin[i].V,&TT);
			wupin[i].T=TT*100+0.5;
		}
		memset(dp,0,sizeof(dp));
		for(i=0;i<n;i++)
			for(vz=m;vz>=wupin[i].T;vz--)
				dp[vz]=max(dp[vz],dp[vz-wupin[i].T]+wupin[i].V);
		printf("%.2lf\n",dp[m]);
		--t;
	  }
	return 0;
}
