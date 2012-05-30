#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#include<list>
#include<time.h>
using namespace std;

int n;

void work()
{
  srand( time( 0 ) );
  cout<<400<<"\n";
  for( int i = 1 ; i <= 400 ; ++ i )
    if( rand() % 2 == 0 ) cout<<rand()%1000<<" ";
    else cout<<"-"<<rand()%1000<<" ";
  cout<<"\n";
  return ;
}

int main()
{
  work();
  
  return 0;
}
