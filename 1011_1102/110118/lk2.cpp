#include<iostream>
#define MAXC 4096
using namespace std;
/*
ifstream cin("lk.in");
ofstream cout("lk1.out");
*/
long long f[2][ MAXC ][52];
bool v[13];
long long c[ MAXC ],s[ MAXC ];
long long n,tot,m;
long long ans;

void dfs(long long step)
{
  long long i;
  if (step == n)
    {
      ++tot;
      for(int j = 1 ; j <= n ; ++ j) cout<<v[j];cout<<"\n";
      for(i = 1; i <= n ; ++ i)
	if ( v[i] == true)
	  {
	    ++c[ tot ];
	    s[tot] = s[tot] + (1 << (i-1));
	  }
      return ;
    }
  dfs( step + 1 );
  
  if ( not v[step] )
    {
      v[ step + 1 ] = true;
      dfs( step + 1 );
      v[ step + 1 ] = false;
    }
  return ;
}

int main()
{  
  long long i,j,k,p;

  cin>>n>>m;
  
  if (m > ((n+1)/2)*((n+1)/2) )
    {cout<<0<<"\n";return 0;}
  

  dfs(0);
  
  cout<<tot<<"\n";
  for(i = 1; i <= tot ; ++ i)
    cout<<c[ i ]<<" ";
  cout<<"\n";
  for(i = 1 ; i <= tot ; ++ i)
    cout<<s[ i ]<<" ";
  cout<<"\n";
  
  f[0][1][0] = 1;

  for (i = 1 ; i <= n ; ++ i)
    {
      for (j = 1; j <= tot ; ++ j)
	for (k = c[j] ; k <= m ; ++ k)
	  for (p = 1 ; p <= tot ; ++ p)
	    if (
		(s[p] & s[j]) == 0 and 
		((s[j] << 1) & s[p]) == 0 and 
		((s[j] >> 1) & s[p]) == 0 and 
		(k-c[j] >= c[p])
		)
	      f[i & 1][j][k] = f[i & 1][j][k] + f[1 - (i & 1) ][ p ][ k - c[ j ] ];
      for( j = 0 ; j <= tot ; ++ j)
	for(k = 0 ; k <= m ; ++ k)
	  f[1 - (i & 1 )][ j ][ k ] = 0;
    }

  for(i = 1 ; i <= tot ; ++ i)
    ans+=f[n & 1 ][ i ][ m ];
  cout<<ans<<"\n";
  /*
  cin.close();
  cout.close();
  */
  return 0;
}
