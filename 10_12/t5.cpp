#include<iostream>
#include<cstdlib>
#include<cstdio>
#define MAXM 51
#define MAXC 201
#define INF 2141483647
using namespace std;

int m,c,s,a[MAXC],d[MAXC][MAXC],f[MAXM][MAXC];

void sort(int i,int j)
{
  if(i >= j)
    return ;
  int m,n,t,k;
  m = i,n = j,k=a[i+j>>1];
  while(m<=n)
    {
      while(a[m] < k)
	m++;
      while(a[n] > k)
	n--;
      if(m<=n)
	{
	  t=a[m];
	  a[m]=a[n];
	  a[n]=t;
	  m++;
	  n--;
	}
    }
  sort(i,n);
  sort(m,j);
  return ;
}

int abs(int a)
{return a>0?a:-a;}

int main()
{
  freopen ("barn1.in", "r",  stdin);
  freopen ("barn1.out", "w", stdout);
  int i,j,k;
  cin>>m>>s>>c;
  for(i=1;i<=c;i++)
    cin>>a[i];
  sort(1,c);
  //init
  for(i=1;i<=m;i++)
    for(j=1;j<=c;j++)
      f[i][j] = INF;
  
  for(i=1;i<=c;i++)
    for(j=1;j<=c;j++)
      {
	d[i][j] = abs(a[i] - a[j]) + 1;
	//cout<<i<<" "<<j<<" "<<d[i][j]<<"\n";
      }
  //cout<<"-------------\n";
  
  for(i=1;i<=c;i++)
    {
      f[0][i] = INF;
      f[1][i] = d[1][i];
    }

  for(i=1;i<=m;i++)
    f[i][0] = 0;

  //dynamic programming
  for(i = 1 ; i <= m ; i++)
    for(j = 1 ; j <= c ; j++)
      for(k = 1 ; k <= j ; k++)
	if(f[ i ][ j ] > f[ i - 1 ][ k - 1 ] + d[ k ][ j ])
	  {
	    f[ i ][ j ] = f[ i - 1 ][ k - 1 ] + d[ k ][ j ];
	    //cout<<i<<" "<<j<<" "<<f[i][j]<<" k "<<k<<" d[k,j] "<<d[k][j]<<" f[i-1,k-1]"<<f[i-1][k-1];
	    //getchar();
	  }

  cout<<f[m][c]<<"\n";
  /*
  for(i=1;i<=m;i++)
    for(j=1;j<=c;j++)
      cout<<i<<" "<<j<<" "<<f[i][j]<<"\n";
  */
  //system("pause");
  return 0;
}
