#include<iostream>
#include<string>
#define MAXN 10001
#define MAXM 101
using namespace std;

int n,m;
string d[ MAXN ],l[ MAXM ];
int ld[ MAXN ],p[ MAXN ];
bool hashd[ MAXN ][ 26 ];

int main()
{
  int i,j,k;
  int t,tt;
  cin>>tt;
  t = 1;
  while ( t <= tt )
    {
      cin>>n>>m;
      for(i = 1 ;i <= n ; ++ i)
	{
	  cin>>d[ i ];
	  ld[ i ] = d[ i ].size();
	  for( j = 0 ; j < 26 ; ++ j)
	    hashd[ i ][ j ] = false;
	  for( j = 0 ; j < ld[ i ]  ; ++ j)
	    hashd[ i ][ d[ j ] - 'a' ] = true; 
	}

      for(i = 1 ;i <= m ; ++ j)
	cin>>l[ i ];
      for(i = 1 ;i <= m; ++ i)
	{
	  maxs = 0 ; rec = 0; 
	  for(j = 1 ;j <= n ; ++ j)
	    {
	      for(k = 0 ; k < 26 ; ++ k)
		if()
		  {}
	    }
	  p[ i ] = rec;
	}
      cout<<"Case #"<<t<<": ";
      for(i = 1 ; i <= ans ; ++ i) cout<<d[ p[ i ] ]<<" ";
      cout<<"\n";
      ++ t;
    }

  return 0;
}
