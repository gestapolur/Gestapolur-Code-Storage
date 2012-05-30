#include<iostream>
#include<string>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<vector>
#define MAXN 102 
using namespace std;

int a[ MAXN ];

int main()
{
  int n ;
  cin>>n;
  for( int i = 1 ; i <= n ; ++ i )
    {
      cin>>a[ i ];
      a[ 0 ] += a[ i ];
    }
  int cnt = 0;
  for( int i = 1 ; i <= n ; ++ i )
    if( ( a[ 0 ] - a[ i ] ) % 2 == 0 )
      ++ cnt;
  cout<<cnt<<"\n";
  return 0;
}
