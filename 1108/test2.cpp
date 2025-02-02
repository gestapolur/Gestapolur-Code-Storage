#include<stdio.h>
#include<string.h>
#define INF 1000000000
int min(int a, int b)
{return a < b ? a : b;}
int line[20][20];
int site[20][2];
int dp[140000];
int n, need;
bool visi[140000];
bool isline(int i, int j, int k)
{
	return (site[i][0] - site[j][0]) * (site[i][1] - site[k][1]) == (site[i][1] - site[j][1]) * (site[i][0] - site[k][0]);
}
int dps(int s, int num, int can)
{
	int &ans = dp[s], i, j, lin, nexnum;
	if(visi[s])
		return ans;
	visi[s] = true;
	if(num >= need)
		return ans = 0;
	ans = INF;
	for(i = can;i < n;i ++)
	{
		for(j = i;j < n;j ++)
		{
			if(lin = (s & line[i][j]))
			{
				nexnum = 0;
				while(lin)
				{
					nexnum += (lin & 1);
					lin >>= 1;
				}
				ans = min(ans, dps(s & (~line[i][j]), num + nexnum, i + 1) + 1);
			}
		}
	}
	return ans;
}
int main()
{
	int i, j, k, T, cou = 0;
	//freopen("test.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	scanf("%d", &T);
	while(T --)
	{
		memset(line, 0, sizeof(line));
		memset(visi, 0, sizeof(visi));
		scanf("%d%d", &n, &need);
		for(i = 0;i < n;i ++)
		{
			scanf("%d%d", &site[i][0], &site[i][1]);
			line[i][i] |= 1 << i;
			for(j = i - 1;j >= 0;j --)
			{
				line[j][i] |= 1 << j;
				line[j][i] |= 1 << i;
				line[i][j] |= line[j][i];
				for(k = j - 1;k >= 0;k --)
				{
					if(isline(i, j, k))
					{
						line[j][i] |= 1 << k;
						line[k][i] |= line[j][i];
						line[k][j] |= line[j][i];
					}
				}
			}
		}
		printf("Case #%d:\n%d\n", ++ cou, dps((1 << n) - 1, 0, 0));
		if(T)
			printf("\n");
	}
	return 0;
}
						
						
