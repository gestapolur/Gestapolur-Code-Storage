//#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#define MAXN 102
using namespace std;


ifstream cin("input.txt");
ofstream cout("output.txt");

int n , k , ans ;
int a[ MAXN ] , cnt[ MAXN ] ;

int main()
{
  int i , maxx , rec ;
  bool turn = true ;
  cin>>n>>k;
  for ( i = 1 ; i <= n ; ++i )
    {cin>>a[ i ];a[ 0 ] += a[ i ];}
  while( turn )
    {
      turn = false ;
      maxx = 0 , rec = 0 ;
      for( i = 1 ; i <= n ; ++ i )
        if( cnt[ i ] < 3 and a[ i ] >= k and maxx < a[ i ] )
          { maxx = a[ i ] ; rec = i ;}
      if( rec not_eq 0 )
        { ans += k ; a[ rec ] -= k ; ++ cnt[ rec ]; turn = true ; }
    }
  ans = a[ 0 ] - ans ;
  cout<<ans<<"\n";
  return 0;
}
