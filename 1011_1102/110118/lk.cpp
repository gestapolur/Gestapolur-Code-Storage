/* little Kings */
#include<iostream>
#define MAXN 11
#define MAXC 4096 
using namespace std;

int f[ MAXN ][MAXC][ MAXN * MAXN ];
int c[MAXC],s[MAXC];
int n,k,con;

void create()
{
  int m,i,j;
  m = n < k ? n : k;
  con = ( 1 << n ) - 1;
  
  for( i = 0 ; i <= con ; ++ i)
    {
      s[ i ] = i;
      for(j = 1 ; j <= n ; ++ j)
	if( i >> (j - 1) & 1 == 1)
	  c[ i ] ++ ;
    }
    
  return ;
}

int main()
{
  
  int i,j,v,p;
  cin>>n>>k;
  //init & create
  create();
  cout<<con<<"\n";
  for(i = 0 ; i <= con ; ++ i)
    cout<<c[ i ]<<" ";
  cout<<"\n";
  //dp
  f[ 0 ][ 1 ][ 0 ] = 1;
  for(i = 1 ;i <= n ; ++ i)
    {
      for(j = 0 ; j <= con ; ++ j)
	for(v = c[ j ] ; v <= k ; ++ v)
	  for(p = 0 ; p <= con ; ++ p)
	    if((j & p) == 0 and ((j<<1) & p) == 0 and ((j>>1) & p) == 0)
	      {
		cout<<"v:"<<v<<" j:"<<j<<" p:"<<p<<" i:"<<i<<" f[i]:"<<f[i][j][v]<<" f[i-1]:"<<f[i-1][p][v-c[j]]<<"\n";
		f[ i ][ j ][ v ] += f[ i - 1][ p ][ v - c[ j ]];
	      }
    }
  for(i = 0 ; i <= con ; ++ i)
    cout<<f[ n ][ i ][ k ]<<" ";
  cout<<"\n";
  /*
  k = 0;
  for(int i = 0 ; i <= 11 ; ++ i)
    k = k | (1 << i);
  cout<<k<<"\n";
  */

  return 0;
}
