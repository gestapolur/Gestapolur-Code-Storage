/*
ID: dd.ener1
PROG: ditch
LANG: C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory>
using namespace std;

const int maxn=1024*1024;
int n,m,ans=0,o,c,len=0,num,tot=0;
int e[maxn][2];
int limit[maxn];
int flow[maxn];
int st[maxn],stc[maxn];
int st2[maxn],stc2[maxn];
int next[maxn],nextc[maxn];
bool v[maxn];
int q[maxn];
int qe[maxn];
int h[maxn];

const int inf=2141483647;

void insert_e(int a,int b,int c)// (u,v) = c
{
  len++;
  e[ len ][ 0 ] = a ; 
  e[ len ][ 1 ] = b ;
  limit[ len ] = c ;
  next[ len ] = st[ a ];
  st[ a ] = len;
  nextc[ len ] = stc[ b ];
  stc[ b ] = len;
  
  return ;
}


void init()
{
  int i,j,a,b,c;
  scanf("%d %d",&m,&n);
  
  memset(limit,0,sizeof limit);
  memset(e,0,sizeof e);
  memset(st,0,sizeof st);
  memset(stc,0,sizeof stc);
  memset(next,0,sizeof next);
  memset(nextc,0,sizeof nextc);
  
  for (i=1;i<=m;i++)
    {
      scanf("%d%d%d",&a,&b,&c);
      insert_e(a,b,c);
    }

  insert_e(3,2,inf);

  return ;
}

int min(int a,int b)
{if (a>b) return b;else return a;}

void make_h()
{
    memset(v,0,sizeof v);
    memset(h,0,sizeof h);
    
    v[0] = true;
    
    o = 1;c = 0;q[1] = 0;h[0] = 0;
    int i,j;
    
    while (c < o)
      {
	c++;
	j = st[ q[ c ] ];
	while ( j > 0 )
	  {
	    if (limit[j]>flow[j] && !v[e[j][1]])
	      {
		v[e[j][1]]=true;
		h[e[j][1]]=h[q[c]]+1;
		q[++o]=e[j][1];
	      }
	    j=next[ j ];
	  }
	j = stc[ q[ c ] ];

	while (j>0)
	  {
	    if (flow[j]>0 && !v[e[j][0]])
	      {
		v[e[j][0]] = true;
		h[e[j][0]] = h[q[c]] + 1;
		q[++o]=e[j][0];
	      }
	    j = nextc[j];
	  }
      }
    return ;
}

bool change_flow(int k,int w)
{
  if (k>0)
    {
        flow[k]+=w;
        return flow[k] == limit[k];
      }
    else
      {
        flow[-k]-=w;
        return flow[-k] == 0;
      }
}


int make_flow()
{
  int ans=0;
  int i,j,delta;
  memset(flow,0,sizeof flow);
  
  while (1)
    {
      make_h();
      if (h[n] == 0) break;
      
      memcpy(st2,st,sizeof st);
      memcpy(stc2,stc,sizeof stc);
      
      q[1] = 0 ; num = 1;

      memset(v,0,sizeof v);
      while (!v[0])
        {
	  if (q[num]==n)
            {
	      delta = inf;
	      for (i=2;i<=num;i++) 
		if (qe[i]>0) 
		  delta = min(delta,limit[qe[i]]-flow[qe[i]]);
                else 
		  delta = min(delta,flow[-qe[i]]);
	      for (i = num ; i >= 2 ; i --) 
		if ( change_flow(qe[i],delta) ) j = i;
	      num=j-1;
	      ans+=delta; 
            }
	  else
            {
	      j=st2[q[num]];
	      while(j>0)
                {
		  if (!v[e[j][1]] && h[e[j][1]]==h[q[num]]+1 && limit[j]>flow[j])
                    {
		      q[++num]=e[j][1];
		      qe[num]=j;
		      break;
                    }
		  j = next[j] ; st2[q[num]] = j ;
                }
	      if (j==0)
                {
		  j=stc2[q[num]];
		  
		  while (j>0)
                    {
		      if (!v[e[j][0]] && h[e[j][0]]==h[q[num]]+1 && flow[j]>0)
                        {
			  q[++num]=e[j][0];
			  qe[num]=-j;
			  break;
                        }
		      j=nextc[j];stc2[q[num]]=j;
                    }
                }
	      if ( j == 0 ) v[ q[num--] ] = true;
            }
        }
    }
  return ans;
}



int main()
{
  //freopen("ditch.in","r",stdin);
  //freopen("ditch.out","w",stdout);
  init();
  ans = make_flow();
  
  printf("%d\n",ans);
  //  system("pause");

}
