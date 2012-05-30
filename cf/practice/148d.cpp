#include<iostream>
#include<cmath>
#define MAXN 1002
using namespace std;

long double f[ MAXN ][ MAXN ];
int w , b;

void dp()
{
  cout.setf(ios::fixed|ios::showpoint);
  cout.precision(9);
  cin>>w>>b;
  for( int i = 1 ; i <= w ; ++ i )
    {
      f[ i ][ 0 ] = 1.0000000000;
      f[ 0 ][ i ] = 0.0000000000;
    }

  long double tmp;

  for( int i = 1 ; i <= w ; ++ i )
    for( int j = 1 ; j <= b ; ++ j )
      {
        f[ i ][ j ] = ( long double ) i / ( long double )( i + j );
      
        if( j >= 3 )
          f[ i ][ j ] += ( long double ) j / ( long double )( i + j ) * 
            ( f[ i ][ j - 3 ] * ( ( long double )( j - 1 ) / ( long double )( i + j - 1 ) ) ) ;
  
        if( j >= 2 )
          f[ i ][ j ] += ( long double ) j / ( long double )( i + j ) *
            ( f[ i - 1 ][ j - 2 ] * ( ( long double )( j - 1 ) / ( long double )( i + j - 1 )) ) ;
      }
  cout<<tmp<<"\n";
  cout<<f[ w ][ b ]<<"\n";
  for( int i = 1 ; i <= w ; ++ i )
    for( int j = 1 ; j <= b ; ++ j )
      
  return ;
}

int main()
{

  dp();

  return 0;
}
