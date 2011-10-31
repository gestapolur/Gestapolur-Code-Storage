#include<iostream>
#define MAXN 4600
#define MAXW 1000
#define INF 60000
using namespace std;

unsigned short int w[ MAXN ][ MAXN ];
unsigned short int flow;
unsigned short int n,m;

bool flag;
unsigned short int h[MAXN];
unsigned short int pre[MAXN];
unsigned short int d[MAXN];
unsigned short int vh[MAXN];
unsigned short int di[MAXN];
unsigned short int mint,aug;

void dfs(int source,int sink)
{
  int i,j,tmp,rec=0;

  vh[0] = n;

  for(i=1;i<=n;i++)
    di[i] = 1;
  i = source;
  aug=INF;
  
  while(d[source] < n)
    {
      h[i] = aug;
      flag = false;

      for(j = di[i] ; j <= n ; j++)
	if( w[i][j] > 0 and d[ j ] + 1 == d[ i ] )
	  {
	    flag = true;
	    
	    di[ i ] = j;
	    if( w[i][j] < aug ) 
	      aug = w[i][j];

	    pre[j] = i;
	    i=j;

	    if(i == sink)
	      {
		flow += aug;
		while(i not_eq source)
		  {
		    tmp = i;
		    i = pre[i];
		    w[i][tmp]-=aug;
		    w[tmp][i]+=aug;
		  }
		aug = INF;
	      }
	    break;
	  }
      
      if(flag)  continue;
      
      mint = n-1;
      for(j=1;j<=n;j++)
	if(w[i][j] > 0 and d[j] < mint)
	  {rec = j; mint = d[j]; }

      di[i]=rec;
      vh[d[i]]--;
      if(vh[d[i]] == 0)
	break;
      d[i] = mint + 1;
      vh[d[i]]++;
      
      if(i not_eq source)
	{i = pre[i];aug = h[i];}
    }
  return ;
}

int main()
{
  int i , j , minw , maxw , wi ,source , sink;
  while(cin>>n)
    {
      cin>>m;
      
      for( i = 1 ; i <= n ; ++ i)
	{
	  cin>>minw>>maxw;
	  for(j = minw ; j <= maxw ; ++ j)
	    w[ i + 1 ][ n + 1 + j ] = 1;
	}

      sink = n + 2 + MAXW;
      for( i = 1 ; i <= m; ++ i)
	{
	  cin>>wi;
	  w[n + 1 + wi ][ sink ] ++;
	}

      source = 1 ;
      for(i = 1 ; i <= n; ++ i) w[ 1 ][ i + 1 ] = 1;
      n = n + MAXW + 2;
      /*
      for(i = 1 ;i <= n ; ++ i)
	{
	  for(j = 1 ; j <= n ; ++ j)
	    {
	      cout<<w[ i ][ j ]<<" ";
	    }
	  cout<<"\n";
	}
      */
      dfs( source , sink );
      for(i = 1 ; i <= n ; ++ i)
	for(j = 1 ; j <= n ; ++ j)
	  w[ i ][ j ] = 0 ;
      cout<<flow<<"\n";
      flow = 0 ;
    }
  return 0;
}
