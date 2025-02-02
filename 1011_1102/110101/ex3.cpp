//RMQ
#include<iostream>
#define MAXN 10001
using namespace std;

int a[MAXN];
int f[MAXN][14];
int n;

int max(int a , int b) { return a > b ? a : b;}

int main()
{
  int i,j,k;
  cin>>n;
  for(i = 1 ;i <= n ; ++ i)
    cin>>a[ i ];
  //init
  for(i = 1 ; i <= n ; ++ i)
    f[ i ][ 0 ] = a[ i ];

  //dp
  /*
  for(i = 1 ; i <= n ; ++ i)
    {
      j = 1;
      while(i + (1 << j) - 1 <= n )
	{
	  if(f[ i ][ j ] < max( f[ i ][ j - 1 ] , f[ i + ( 1 << j - 1 ) ][ j - 1 ]) )
	    f[ i ][ j ] = max( f[ i ][ j - 1] , f[ i + ( 1 << j - 1 )][ j - 1 ]);
	  ++j;
	}	
    }
  */

  for(j = 1 ; j <= n ; ++ j)
    for(i = 1 ; i <= n ; ++ i)
      if(i + (1 << j) - 1 <= n)
	{
	  //cout<<i<<" "<<j<<" "<<f[i][j]<<" after ";
	  if(f[ i ][ j ] < max( f[ i ][ j - 1 ] , f[ i + ( 1 << j - 1 ) ][ j - 1 ]))
	    f[ i ][ j ] = max( f[ i ][ j - 1 ] , f[ i + ( 1 << j - 1 ) ][ j - 1 ]);
	  //cout<<f[i][j]<<"\n";
	}
      else
	break;
  /*
  for(i = 1 ; i <= n ; ++ i)
    {
      for(j = 0 ; j <= 3 ; ++ j)
	cout<<f[i][j]<<" ";
      cout<<"\n";
    }
  */
  while(1)
    {
      cin>>i>>j;
      k = 0;
      int lim = j - i + 1 ;
      //cout<<"lim : "<<lim<<"\n";
      while( (1 << k) < lim )
	++k;
      if(k > 0)
	--k;
      cout<<" k : "<<k<<"\n";
      cout<<max( f[ i ][ k ] , f[ j - (1 << k) + 1][ k ])<<"\n";
    }
  return 0;
}
