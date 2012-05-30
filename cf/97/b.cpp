#include<iostream>
#include<cmath>
#define MAXN 1002
using namespace std;

int a , b , c ;
int t[ 5 ][ MAXN ] ;

void change( int a , int cd )
{
  int tmp = a;
  t[ cd ][ 0 ] = 0;
  while( tmp > 0 )
    {
      ++ t[ cd ][ 0 ];
      t[ cd ][  t[ cd ][ 0 ] ] = tmp % 3 ;
      tmp = tmp / 3 ;
    }
  return;
}

void init()
{
  cin>>a>>c;
  change( a , 1 );
  change( c , 2 );
  //for( int i = 1 ; i <= t[ 1 ][ 0 ] ; ++ i ) cout<<t[ 1 ][ i ]<<" "; cout<<"\n";
  //for( int i = 1 ; i <= t[ 2 ][ 0 ] ; ++ i ) cout<<t[ 2 ][ i ]<<" "; cout<<"\n";
  /*
  for( int i = 1 ; i <= t[ 3 ][ 0 ] ; ++ i ) 
    cout<<t[ 3 ][ i ];
  */
  t[ 3 ][ 0 ] = t[ 1 ][ 0 ] > t[ 2 ][ 0 ] ? t[ 1 ][ 0 ] : t[ 2 ][ 0 ];
  for( int i = 1 ; i <= t[ 3 ][ 0 ] ; ++ i )
    t[ 3 ][ i ] = ( t[ 2 ][ i ] + 3 - t[ 1 ][ i ] ) % 3 ;
  
  //for( int i = 1 ; i <= t[ 2 ][ 0 ] ; ++ i ) cout<<t[ 2 ][ i ]<<" "; cout<<"\n";
  b = 0 ;
  for( int i = 1 ; i <= t[ 3 ][ 0 ] ; ++ i )
    {
      b += t[ 3 ][ i ] * pow( 3 , i - 1 );
    }
  cout<<b<<"\n";
  return ;
}

int main()
{

  init();

  return 0;
}
