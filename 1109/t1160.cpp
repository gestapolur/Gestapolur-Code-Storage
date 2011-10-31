//timus 1160
#include<iostream>
#include<cmath>
#define MAXN 102
using namespace std;

double a[ MAXN ] ;
int n;
double ans ;

void sort( int i , int j )
{
  if( i >= j ) return ;
  int m = i ,n = j  ;
  double t, k = a[ i + j >> 1 ] ;
  while( m <= n )
    {
      while( a[ m ] > k ) ++ m ;
      while( a[ n ] < k ) -- n; 
      if( m <= n )
        {
          t = a[ m ] ; a[ m ] = a[ n ] ; a[ n ] = t;
          ++ m , -- n ;
        }
    }
  sort( i , n );
  sort( m , j );
  return ;
}

int main()
{
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision( 2 );
  int i , j ;
  cin>>n;
  for( i = 1 ; i <= n ; ++ i )
    cin>>a[ i ];
  sort( 1 , n );
  //for( i = 1 ; i <= n ; ++ i ) cout<<a[ i ]<<" ";cout<<"\n";
  ans = a[ 1 ];
  for( i = 2 ; i <= n ; ++ i )
    ans = 2 * sqrt( ans * a[ i ] );
  cout<<ans<<"\n";
return 0;
}
