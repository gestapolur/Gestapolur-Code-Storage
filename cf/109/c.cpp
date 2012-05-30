/*
  CF #109 154A
  ACCEPTED
  2012-02-28
*/
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#define MAXN 100002
using namespace std;

int n , m ;
string a , cb ;
int b[ MAXN ];
bool w[ 30 ][ 30 ];

void init()
{
  char ca , cbb;
  cin>>a;
  m = a.size();
  cin>>n;
  cin.get();
  for( int i = 1 ; i <= n ; ++ i )
    {
      cin.get( ca );
      cin.get( cbb );
      cin.get();
   
      w[ ca - 'a' + 1 ][ cbb - 'a' + 1 ] = true;
      w[ cbb - 'a' + 1 ][ ca - 'a' + 1 ] = true;
    }
  
  b[ 0 ] = 1; b[ 1 ] = 1 ; cb.push_back( a[ 0 ] );

  for( int i = 1 ; i < m ; ++ i )
    {
      if( a[ i ] == a[ i - 1 ] )
        ++ b[ b[ 0 ] ];
      else
        { ++ b[ 0 ] ; b[ b[ 0 ] ] = 1 ; cb.push_back( a[ i ] ); }
    }

  return ;
}

int min( int a , int b ){ return a < b ? a : b ; }

void work()
{
  int cnt = 0 ;

  int ta , tb , rep ;
  for( int i = 2 ; i <= b[ 0 ] ; ++ i )
    {
     
      if( w[ cb[ i - 1 ] - 'a' + 1 ][ cb[ i - 2 ] - 'a' + 1 ] )
        {
          rep = 0; ta = 0 ; tb = 0 ;
          while( w[ cb[ i - 1 ] - 'a' + 1 ][ cb[ i - 2 ] - 'a' + 1 ] and i <= b[ 0 ] )
            { 
              if( rep == 0 )
                { ta = b[ i - 1 ]; tb = b[ i ] ; }
              else if( rep % 2 == 1 )
                ta += b[ i ];
              else
                tb += b[ i ];
              ++ rep ; ++ i ;
            }
          cnt += min( ta , tb );
        }
    }
  cout<<cnt<<"\n";

  return ;
}

int main()
{
  init();

  work();
  
  return 0;
}
