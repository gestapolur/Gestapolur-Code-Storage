#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#define MAXN 102
using namespace std;

long long q;
int div[ MAXN ][ MAXN ];

void init()
{
  int p ;
  cin>>q;

  p = sqrt( q );

  for( int i = 1 ; i <= p ; ++ i )
    if( q % i == 0 )
      {
        div[ ++ div[ 0 ] ] = i ;
      }
  cout<<div[ 0 ]<<"\n";
  return ;
}

int main()
{
  
  init();

  return 0;
}
