//NEERC 02 D AC
#include<iostream>
#include<cstring>
#define MAXN 10010
using namespace std;

int n;
char a[ MAXN * 2 ] , b[ MAXN * 2 ];
int ea[ MAXN ] , eb[ MAXN ] , key[ MAXN ]; 

int fromhex( char x )
{
  switch ( x )
    {
    case 'A':
      return 10;
      break;
    case 'B':
      return 11;
      break;
    case 'C':
      return 12;
      break;
    case 'D':
      return 13;
      break;
    case 'E':
      return 14;
      break;
    case 'F':
      return 15;
      break;
    default:
      return ( x - 48 ); 
      break;
    }
}

void tohex( int x )
{
  int y , d = 0 ;
  char t[ 10 ];
  while( x )
    {
      ++ d;
      y = x % 16;
      switch ( y )
	{
	case 10:
	  t[ d ] = 'A';
	  break;
	case 11:
	  t[ d ] = 'B';
	  break;
	case 12:
	  t[ d ] = 'C';
	  break;
	case 13:
	  t[ d ] = 'D';
	  break;
	case 14:
	  t[ d ] = 'E';
	  break;
	case 15:
	  t[ d ] = 'F';
	  break;
	default:
	  t[ d ] = ( y + 48 );
	}
      x /= 16;
    }
  if( d > 1 )
    while( d ) cout<<t[ d -- ];
  else if( d == 1 ) cout<<0<<t[ 1 ];
  else cout<<"00";
  return ;
}

void work()
{
  int i , co = 32 ;
  for( i = 1 ; i <= n  ; ++ i )
    {
      key[ i ] = eb[ i ] xor co;
      co = key[ i ] xor ea[ i ];
    }
  key[ n + 1 ] = eb[ n + 1 ] xor co;
  
  for( i = 1 ; i <= n + 1 ; ++ i )
    tohex( key[ i ] );
  cout<<"\n";
  return ;
}

void init()
{
  int i ;
  cin >> a + 1 >> b + 1 ;
  n = strlen( a + 1 );
  for(i = 1 ; i < n ; i += 2 )
    ea[ i + 1 >> 1 ] = fromhex( a[ i ] ) * 16 + fromhex( a[ i + 1 ] );
  for( i = 1 ; i < n + 2 ; i += 2 )
    eb[ i + 1 >> 1 ] = fromhex( b[ i ] ) * 16 + fromhex( b[ i + 1 ]);
  n >>= 1 ;
  //test
  //for( i = 1 ; i <= n ; ++ i ) cout<<ea[ i ]<<" ";cout<<"\n";
  //for( i = 1 ; i <= n + 1 ; ++ i ) cout<<eb[ i ]<<" ";cout<<"\n";
  return ;
}

int main()
{
  init( );
  work( );
  return 0;
}
