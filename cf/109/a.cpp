#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#define MAXN 1002
using namespace std;

int n;
int a[ MAXN ];

void init()
{
  cin>>n;
  for( int i = 1 ; i <= n ; ++ i )
    cin>>a[ i ];
  int cnt = 0 ;
  bool s1 , s2;
  for( int i = 2 ; i <= n ; ++ i )
    {
      s1 = true ; s2 = true;
      for( int j = 1 ; j < i ; ++ j )
        {
          if( a[ j ] >= a[ i ] ) s1 = false;
          if( a[ j ] <= a[ i ] ) s2 = false;
          if( ( s1 or s2 ) == false ) break;
        }
      if( s1 or s2 ) ++ cnt;
    }
  cout<<cnt<<"\n";
  return ;
}

int main()
{
  init();
  
  return 0;
}
