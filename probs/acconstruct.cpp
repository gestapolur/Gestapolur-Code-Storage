#include<iostream>
#include<string>
#define MAXN 1002
using namespace std;

string text , pat;
int n , m;
int pi[ MAXN ] , fail[ MAXN ][ 27 ];

void prefix()
{
  int q;

  q = -1;
  //fail[ 0 ][ pat[ 0 ] - 'a' ] = 1;
  pi[ 0 ] = -1;
  for( int i = 1 ; i < m ; ++ i )
    {
      while( q >= 0 and pat[ i + 1 ] not_eq pat[ q ] )
        q = pat[ q ];
      if( pat[ q ] == pat[ i + 1 ] )
        ++ q;
      pi[ i ] = q;
      
      for( int j = 0 ; j < 26 ; ++ j )
        fail[ i ][ j ] = fail[ i - 1 ][ j ];

      fail[ pat[ i ] - 'a' ] = i;
    }
  
  for( int i = 0 ; i < m ; ++ i )
    {
      for( int j = 0 ; j < 26 ; ++ j )
        cout<<fail[ i ][ j ]<<" ";
      cout<<"\b";
    }

  return ;
}

int main()
{
  cin>>text>>pat;
  n = test.size();
  m = pat.size();

  prefix();

  return 0;
}
