#include<iostream>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<vector>
#define MAXE 100000002
using namespace std;

int n , m , s;
int len;
int u[ MAXE ] , v[ MAXE ] , w[ MAXE ]

void init()
{
  cin>>n>>m>>s;
  for( int i = 1 ; i <= m ; ++ i )
    cin>>u[ i ]>>v[ i ]>>w[ i ];
  cin>>len;
  return ;
}

void bfd()
{
  int i , j , k;
  do{
    for( i = 1 ; i <= m ; ++ i )
      {
        if( mark[ u[ i ] ] > mark[ v[ i ] ] + w[ i ] )
          mark[ u[ i ] ] = mark[ v[ i ] ] + w[ i ];
  return ;
}

void work()
{
  return ;
}

int main()
{
  
  init();
  
  work();

  return 0;
}
