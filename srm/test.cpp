#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#define MAXN 53
#define MOD 1000000007
using namespace std;

int c( int p , int q )
{
  if( p == q or p == 0 ) return 1 ;
  if( p == 1 ) return q ;
  int del , s , t , i ;
  del = q - p ; s = 1 ;
  for( i = 1 ; i <= del ; ++ i )
    s *= i ; 
  t = p + 1 ;
  for( i = p + 2 ; i <= q ; ++ i )
    t *= i ;
  return t / s ;
}

int main()
{
  int n , m ;
  cin>>n>>m;
  cout<<c( m , n )<<"\n";
  return 0;
}
