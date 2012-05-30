#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#define MAXN 
using namespace std;

int n;
string a;

void init()
{
  int cnt = 1 ;
  int ans = 1 ;
  cin>>a;
  n = a.size();
  for( int i = 1 ; i < n ; ++ i )
    {
      if( a[ i ] == a[ i - 1 ] and cnt < 5 )
        {
          ++ cnt ;
        }
      else
        { ++ ans ; cnt = 1 ; }
    }
  cout<<ans<<"\n";
  return ;
}

int main()
{
  
  init();

  return 0;
}
