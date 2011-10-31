//CF#90 B
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#define MAXN 102 
#define ZERO 0.00000000000
#define INF 2141483647
using namespace std;

int n , k , m , p ; 
long double a[ MAXN ] , st[ MAXN ];
int c[ MAXN ][ MAXN ];
long double minp , maxp ; 
bool ins[ MAXN ];

int main()
{
    cout.setf(ios::showpoint|ios::fixed);
    cout.precision(10);
  //scanf( "%d%d" , &n , &k );
    cin>>n>>k;
  m = n / k ;
  for( int i = 1 ; i <= n ; ++ i ) cin>>a[ i ];
    //scanf( "%Lf" , &a[ i ] );
  //scanf( "%d" , &p );
  cin>>p;
  for( int i = 1 ; i <= p ; ++ i )
    for( int j = 1 ; j <= m ; ++ j )
      {
          cin>>c[ i ][ j ];
        ins[ c[ i ][ j ] ] = true ;
      }
  //cout<<m<<"\n";

  //owrk
  long double cnt ;
  minp = INF , maxp = ZERO ;
  //cout<<minp<<" "<<maxp<<"\n";
  //printf( "%.6Lf %.6Lf\n" , minp , maxp );
  for( int i = 1 ; i <= p ; ++ i )
    {
      cnt = ZERO ;
      for( int j = 1 ; j <= m ; ++ j )
        cnt += a[ c[ i ][ j ] ];
      cnt /= ( long double )( m );
      //cout<<i<<" "<<cnt<<"\n";
      minp = cnt < minp ? cnt : minp;
      maxp = cnt > maxp ? cnt : maxp;
      
    }//cout<<"========\n";
      /*
  printf( "%.6Lf %.6Lf\n" , minp , maxp );  
  for( int i = 1 ; i <= n ; ++ i )
    printf( "%d " , ins[ i ] ); printf( "\n" );
    */  

  int noin = 0 ; long double ava ;
  for( int i = 1 ; i <= n ; ++ i )
    if( not ins[ i ] ) st[ ++ noin ] = a[ i ] ;
  //printf( "%d\n" , m );
 
  int i , j ;
  if( noin >= m and ( n - noin ) / m < k )
    { 
      //printf( "!!!\n" );
      for( i = 1 ; i < noin ; ++ i ) 
        for( j = i + 1 ; j <= noin ; ++ j )
          if( st[ i ] > st[ j ] )
            { st[ 0 ] = st[ i ] ; st[ i ] = st[ j ] ; st[ j ] = st[ 0 ] ; }
      
      ava = ZERO ;
      //for( i = 1 ; i <= noin ; ++ i ) printf( "%Lf " , st[ i ] ); printf("\n");
      for( i = 1 ; i <= m ; ++ i )
        ava += st[ i ];
      ava /= (long double )( m );
      minp = ava < minp ? ava : minp;
      
      ava = ZERO ;
      for( i = noin - m + 1 ; i <= noin ; ++ i )
        ava += st[ i ];
      ava /= (long double )( m );
      maxp = ava > maxp ? ava : maxp; 
    }
  cout<<minp<<" "<<maxp<<"\n";
  
  return 0;
}
