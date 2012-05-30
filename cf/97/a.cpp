//97
#include<iostream>
#define MAXN 1002
using namespace std;

int a[ MAXN ] , b[ MAXN ];
int n; 

void init()
{
  cin>>n;
  for( int i = 1 ; i <= n ; ++ i )
    cin>>a[ i ];
  for( int i = 1 ; i <= n ; ++ i )
    b[ a[ i ] ] = i ;
  for( int i =  1 ; i < n ; ++ i )
    cout<<b[ i ]<<" ";
  cout<<b[ n ]<<"\n";
  return ;
}

int main()
{

  init();

  return 0;
}
