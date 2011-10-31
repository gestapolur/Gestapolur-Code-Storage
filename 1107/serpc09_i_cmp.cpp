//SERPC09 I
#include<iostream>
#define MAXN 107
using namespace std;

class node
{
public:
  int ind , wi , vi;
};


int f[ MAXN * MAXN ] , w[ MAXN ] , c[ MAXN ];
int n,m;

int f( int x )
{
  return val;
}

void ref( int fi , int gi , int vi )
{
  return ;
}

int main()
{
  int i , j , t , tmp , cnt ;
  cin>>t;
  while( t -- )
    {
      cin>>n>>m;
      cnt = 0 ;
      for( i = 1 ; i <= n ; ++ i )
	{
	  cin>>w[tmp = ++ cnt ];
	  for( j = 1 ; j < i ; ++ j )
	    w[ ++ cnt ] = w[ tmp ];
	}
      cnt = 0 ;
      for( i = 1 ; i <= n ; ++ i )
	{
	  cin>>c[tmp = ++ cnt ];
	  for( j = 1 ; j < i ; ++ j )
	    c[ ++ cnt ] = c[ tmp ];
	}
      //test
      cout<<cnt<<"\n";
      for( i = 1 ; i <= cnt ; ++ i ) cout<<w[ i ]<<" "<<c[ i ]<<"\n";

      for( i = 1 ; i <= cnt ; ++ i )
	for( j = m ; j >= w[ i ] ; -- j )
	  ref( j , j - w[ i ] , i );
	 
      cout<<f( m )<<"\n";
      for( i = 0 ; i <= m ; ++ i )
	f[ i ] = 0;
    }
  return 0;
}
