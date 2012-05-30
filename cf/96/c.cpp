#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#define MOD 256 
using namespace std;

int st[ 9 ];

void init()
{
  string s;
 
  int n , x , tt , tmp , pre = 0 ;
  
  getline( cin , s );
  n = s.size();

  for( int i = 0 ; i < n ; ++ i )
    {
      tmp = int ( s[ i ] ) ;
      st[ 0 ] = 0 ;
      //cout<<tmp<<"\n";
      while( tmp > 0 )
        {
          st[ ++ st[ 0 ] ] = tmp % 2 ;
          tmp >>= 1 ;
        } 
      while( st[ 0 ] < 8 ) st[ ++ st[ 0 ] ] = 0 ;
      
      //for( int j = 1 ; j <= st[ 0 ] ; ++ j ) cout<<st[ j ]<<" "; cout<<"\n";
      x = 0;
      while( st[ 0 ] > 0 )
        {
          tmp = tmp + st[ st[ 0 ] -- ] * ( 1 << x ) ;
          ++ x ;
        }
      //cout<<tmp<<"\n";
      tt = tmp ;
      tmp = ( pre - tmp + MOD ) % MOD ;
      cout<<tmp<<"\n";
      pre = tt ;
    }
  return ;
}

int main()
{
  
  init();

  return 0;
}
