#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#define MAXN 1002
using namespace std;

string s , u ;
int n , m , ans ;

void init()
{
  cin>>s>>u;
  m = u.size();
  return ;
}

void work()
{
  int i , j , tans ;
  string blank = "";

  i = 1 ;
  while( i <= m )
    {
      blank.push_back( ' ' );
      ++ i;
    }

  s = blank + s ;
  n = s.size() ;
  s = s + blank ;
  ans = m;
  for( i = 1 ; i <= n ; ++ i )
    {
      tans = m ;
      for( j = 0 ; j < m ; ++ j )
        if( s[ i + j ] == u[ j ] )
          -- tans;
      ans = tans < ans ? tans : ans;
    }

  cout<<ans<<"\n";

  return ;
}

int main()
{
  init();

  work();
  
  return 0;
}
