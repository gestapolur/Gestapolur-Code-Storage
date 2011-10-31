#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#define MAXN 4000
using namespace std;

int n ;
int w[ MAXN ][ MAXN ];

int main()
{
  cin>>n;
  int k , r , t , t2 , rest ;
  k = 3 , r = 2 ;
  cout<<k<<"\n";
  w[ 1 ][ 1 ] = 1 , w[ 1 ][ 2 ] = 2 ;
  w[ 2 ][ 1 ] = 1 , w[ 2 ][ 2 ] = 3 ;
  w[ 3 ][ 1 ] = 2 , w[ 3 ][ 2 ] = 3 ;
  if( k > 3 )
    {
      rest = n - 3 ;
      pre = 6;
      while( rest > r + 1 )
        {
          t = pre , t2 = pre;
          ++ r ;
          for( i = 1 ; i <= k ; ++ i ) w[ i ][ r ] = t ++ ; 
          ++ k;
          for( i = 1 ; i <= r ; ++ i ) w[ k ][ i ] = t2 ++;
          pre = t;
          rest -= r ;
        }
    }
  
  for( i = 1 ; i <= k ; ++ i )
    {
      for( j = 1 ; j < r ; ++ r )
        cout<<w[ i ][ j ]<<" ";
      cout<<w[ i ][ r ]<<"\n";
    }
  return 0;
}
