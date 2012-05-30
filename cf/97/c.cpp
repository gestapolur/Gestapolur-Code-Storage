#include<iostream>
#include<algorithm>
#define MAXN 100005
using namespace std;

int n; 
int a[ MAXN ] , b[ MAXN ];
/*
void sort( int i , int j )
{
  if( i >= j ) return ;
  int m , n , t , k;
  m = i , n = j ;
  k = a[ i + j >> 1 ];
  while( m <= n )
    {
      while( a[ m ] < k ) ++m;
      while( a[ n ] > k ) --n;
      if( m <= n )
        { t = a[ m ] ; a[ m ] = a[ n ] ; a[ n ] = t ; ++ m ; -- n ; }
    }
  sort( i , n );
  sort( m , j );
  return ;
}
*/
void init()
{
  bool sign = false;
  cin>>n;
  for( int i = 1 ; i <= n ; ++ i ) 
    {
      cin>>a[ i ];
      if( a[ i ] > 1 ) sign = true; 
    }
  sort( a + 1 , a + n + 1 );
  /*
    for( int i = 0 ; i < n - 1 ; ++ i )
    cout<<a[ i ]<<" ";
  cout<<a[ n - 1 ]<<"\n";
  */
  a[ 0 ] = 1 ;
  for( int i = 0 ; i < n - 1 ; ++ i )
    cout<<a[ i ]<<" ";
  if( not sign ) a[ n - 1 ] = 2 ;
  cout<<a[ n - 1 ]<<"\n";
  return ;
}

int main()
{
  init();

  return 0;
}
