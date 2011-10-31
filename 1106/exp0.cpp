#include<fstream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include <bitset>
using namespace std;

const int MAXN = (1 << 18);
int w[MAXN], f[MAXN], bcnt[MAXN], g_k, g_n;
void reader()
{
      int i, j, t, a[20];
      scanf("%d%d", &g_k, &g_n);
      for (i = 0; i < g_n; i++)
            scanf("%d", a + i);
      for (i = 0; i < g_n; i++)
      {
            for (j = 0; j < g_n; j++)
            {
                  scanf("%d", &t);
                  w[(1 << i) | (1 << j)] = 2 * t + a[i] + a[j];
            }
      }
}
int work()
{
      int i, s, res = 0;
      bool at[20] = {0};
      memset(f, 0, sizeof (f));
      for (i = 0; i <= g_k; i++)
            at[3 * i] = true;
      for (s = 1; s < (1 << g_n); s++)
      {
            if (at[bcnt[s]])
            {
                  int b0 = s&-s;
                  int s1 = s^b0;
                  while (s1)
                  {
                        int b1 = s1&-s1;
                        s1 ^= b1;
                        int s2 = s1;
                        while (s2)
                        {
                              int b2 = s2&-s2;
                              s2 ^= b2;
                              int t = w[b0 | b1] + w[b0 | b2] + w[b1 | b2] + f[s^b0^b1^b2];
                              if (f[s] < t)f[s] = t;
                        }
                  }
                  if (res < f[s])res = f[s];
            }
      }
      return res;
}
int main()
{
  //freopen("1.in","r",stdin);
  //freopen("2.out","w",stdout);
      int s, t;
      bcnt[0] = 0;
      for (s = 1; s < MAXN; s++)
	bcnt[s] = bcnt[s >> 1]+(s & 1);
      for ( s = 1 ; s < 100 ; ++ s )
	printf("%d ", bcnt[ s ] );
      printf("\n");
      scanf("%d", &t);
      while (t--)
      {
            reader();
            int res = work();
            printf("%d\n", res / 2);
      }
      return 0;
}
