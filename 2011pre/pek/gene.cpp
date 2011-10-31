#include<iostream>
#include<cstdlib>
#include<cstdio>
#define MAXN 1000
#define MAXM 200
using namespace std;

int n , m ;
bool w[ MAXN ][ MAXN ];
int main()
{
  int u , v ;
  srand( time( 0 ) );
  n = 1000 , m = 200;
  for( int i = 1 ; i < n ; ++ i )
    {
      do{
        u = rand() % n + 1 ;
        v = rand() % n + 1 ;
      }while( v == u or w[ u ][ v ] == true );
      w[ u ][ v ] = w[ v ][ u ] = true;
      cout<<u<<" "<<v<<"\n";
    }
  cout<<m<<"\n";
  for( int i = 1 ; i <= n ; ++ i )
    {
      cout<<50<<" ";
      for( int j = 1 ; j <= 50 ; ++ j )
        {
          u = rand( )%MAXM + 1 ;
          v = rand( )%MAXM + 1 ;
          cout<<u<<" "<<v<<" ";
        }
      cout<<"\n";
    }
}
