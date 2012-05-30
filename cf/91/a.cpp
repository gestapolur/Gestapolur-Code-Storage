#include<iostream>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<cstdio>
using namespace std;

bool check( int x )
{
  int y ;
  do{
    y = x % 10;
    if( y not_eq 4 and y not_eq 7 ) return false ;
    x /= 10;
  }while( x > 0 );
  return true ;
}

void init()
{
  int n;
  cin>>n;
  for( int i = 1 ; i <= n ; ++ i )
    if( check( i ) and n % i == 0 )
      {cout<<"YES\n"; return ;}
  cout<<"NO\n";
  return ;
}

int main()
{
  init();
  return 0;
}
