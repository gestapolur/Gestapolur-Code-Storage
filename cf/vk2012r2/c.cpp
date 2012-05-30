#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#define MAXN 5005
using namespace std;

string ss , st;
int sums[ MAXN ][ 27 ] , sumt[ MAXN ][ 27 ];
int n , m;

void init()
{
  cin>>ss>>st;
  n = ss.size();
  m = st.size();

  for( int i = 0 ; i < n ; ++ i )
    {
      for( int j = 0 ; j < 26 ; ++ j )
        sums[ i + 1 ][ j ] = sums[ i ][ j ];
      ++ sums[ i + 1 ][ ss[ i ] - 'a' ];
    }
  
  for( int i = 0 ; i < m ; ++ i )
    {
      for( int j = 0 ; j < 26 ; ++ j )
        sumt[ i + 1 ][ j ] = sumt[ i ][ j ];
      ++ sumt[ i + 1 ][ st[ i ] - 'a' ];
    }

  return ;
}

void work()
{
  int i , j , k , lim;
  lim = ( n ) < () ? () : ();

  for( i = 1 ; i <= n ; ++ i )
    for( j = 1 ; j <= m ; ++ j )
      {
        
        for( k = 1 ; k <= lim ; ++ k )
          {}
      }
  return ;
}

int main()
{
  init();
  
  work();

  return 0;
}
