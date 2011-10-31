#include<iostream>
#define MAXN 1002 
using namespace std;

int st[ MAXN ] , con[ MAXN ] , pre[ MAXN ] , next[ MAXN ];
int n , m , h ;
long long tot , htot ;

void dfs()
{
  int p , num ;
  bool sign ;
  p = 1 ; num = 0 ;
  while( p )
    {
      if( p <= m and num < n and con[ p ] < st[ p ] )
	{
	  ++ con[ p ];
	  num += con[ p ];
	  p += next[ p ];
	  ++ next[ p ];
	}
      else
	{
	  if( num == n )
	    {
	      ++ tot;
	      if( sign ) ++ htot;
	    }
	  num -= con[ p ];
	  con[ p ] = 0 ;
	  next[ p ] = 1 ;
	  p = pre[ p ];
	}
    }
  return ;
}

int main()
{
  int i;
  cin>>n>>m>>h;
  for( i = 1 ; i <= m ; ++ i )
    cin>>st[ i ];
  -- n ; -- st[ h ];
  dfs();
  cout<<htot<<" "<<tot<<"\n";
  cout<<double( htot )/double( tot )<<"\n";
  return 0;
}
