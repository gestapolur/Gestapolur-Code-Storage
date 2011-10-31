#include<iostream>
#define MAXN 1004
#define MAXK 52 
using namespace std;

int n , m ;
int chs[ MAXN ] , pow[ MAXN ][ MAXK ] , pr[ MAXN ][ MAXK ];
int child[ MAXN ][ MAXN ];

void dfs( int x )
{
  do{

  }while();
}

void dp( int rt , int mon )
{
  for( int i = 1 ; i <= child[ rt ][ 0 ] ; ++ i )
    {
      `
    }
}

void init()
{
  int i , j ;
  cin>>n;
  for( i = 1 ; i < n ; ++ i )
    {}
  cin>>m;
  for( i = 1 ; i <= n ; ++ i )
    {
      cin>>chs[ i ];
      for( j = 1 ; j <= chs[ i ] ; ++ j )
        cin>>pr[ i ][ j ]>>pow[ i ][ j ];
    }
  return ;
}

int main()
{
  cin>>t;
  while( t -- )
    {
      init();
      cout<<dp( 1 , m )
    }
  return 0;
}
