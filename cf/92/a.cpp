#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<vector>
#define MAXN 
using namespace std;

int n , a , b ;

int main()
{
  cin>>n>>a>>b;
  int cnt = 0 ;
  for( int i = 0 ; i <= b ; ++ i )
    if( n - a > i ) ++ cnt ;
  cout<<cnt<<"\n";
  return 0;
}
