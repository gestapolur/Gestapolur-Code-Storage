#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<time.h>
#define MAXN 10000000
using namespace std;

bool in[ MAXN ];

int main()
{
  srand( time( 0 ) );
  int tmp ;
  cout<<100000<<"\n";
  tmp = rand()%MAXN;
  in[ tmp ] = true;
  cout<<-1<<" "<<tmp<<"\n";
  for( int i = 2 ; i <= 100000 ; ++ i )
    {
      tmp = rand()%MAXN;
      if( i % 2 == 0 ) cout<<i-1;
      else cout<<i-2;
      cout<<" "<<tmp<<"\n";
      in[ tmp ] = true;
    }
  cout<<100000<<"\n";
  for( int i = 1 ; i <= 100000 ; ++ i )
    {
      do{
        tmp = rand()%MAXN;
      }while( in[ tmp ] );
      cout<<tmp<<"\n";
    }
  return 0;
}
