//timus 1164
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#define MAXN 12
#define MAXW 102
using namespace std;

int n , m , p;
int len[ MAXW ] , cnt[ 27 ];
char wd[ MAXW ][ MAXW ];

void init()
{
  int i , j ;
  char k;
  cin>>n>>m>>p;
  for( i = 1 ; i <= n ; ++ i )
    for( j = 1 ; j <= m ; ++ j )
      {
        cin>>k;
        ++ cnt[ k - 'A' ];
      }
  /*
  for( i = 0 ; i < 26 ; ++ i )
    cout<<cnt[ i ]<<" ";cout<<"\n";
  */
  for( i = 1 ; i <= p ; ++ i )
    {
      cin>>wd[ i ];
      len[ i ] = strlen( wd[ i ] );
    }

  return ;
}

void work()
{
  int i , j; 
  for( i = 1 ; i <= p ; ++ i )
    for( j = 0 ; j < len[ i ] ; ++ j )
      -- cnt[ wd[ i ][ j ] - 'A' ];
  //for( i = 0 ; i < 26 ; ++ i ) cout<<cnt[ i ]<<" ";cout<<"\n";
  for( i = 0 ; i < 26 ; ++ i )
    while( cnt[ i ] not_eq 0 )
      {
        cout<<char( i + 'A');
        -- cnt[ i ];
      }
  cout<<"\n";
  return ;
}

int main()
{
  init();
 
  work();

  return 0;
}
