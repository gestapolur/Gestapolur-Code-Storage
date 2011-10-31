#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#define MAXN 1002
using namespace std;

string a;
string b[ MAXN ];
bool w[ MAXN ][ MAXN ];
int block , n , cnt ;
int st[ MAXN ] , sv[ MAXN ];

int main()
{
  int i , j , pre ;
  string tmp ;
  cin>>a;
  n = a.size();
  for( i = 0 ; i < n ; ++ i )
    if( a[ i ] == '<' ) pre = i ;
    else if( a[ i ] == '>' )
      {
        ++ cnt;
        for( j = pre ; j <= i ; ++ j )
          b[ cnt ].push_back( a[ j ] );
      }

  //for( i = 1 ; i <= cnt ; ++ i ) cout<<b[ i ]<<"\n";
  for( i = 1 ; i < cnt ; ++ i )
    for( j = i + 1  ; j <= cnt ; ++ j )
      if( b[ i ][ 1 ] == b[ j ][ 2 ] )
        w[ i ][ j ] = w[ j ][ i ] = true;

  block = 0 ; pre = 0 ; st[ 0 ] = 0 ;
  bool back = false;
  for( i = 1 ; i <= cnt ; ++ i )
    {
      if( w[ st[ st[ 0 ] ] ][ i ] )
        {
          block = sv[ st[ 0 ] -- ] ;
          back = true;
        }
      else 
        {
          st[ ++ st[ 0 ] ] = i ;
          sv[ st[ 0 ] ] = block ;
        }
      for( j = 1 ; j <= block ; ++ j ) cout<<"  ";
      if( not back )
        ++ block;
          back = false ;
      cout<<b[ i ]<<"\n";
    }

  return 0;
}
