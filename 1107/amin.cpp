//accurate minus
#include<iostream>
#define MAXN 1001
using std::cin;
using std::cout;

int a[ MAXN ] , b[ MAXN ];
char ca[ MAXN ],cb[ MAXN ];

void minus()
{
  int i , j ;
  for( i = 1 ; i <= n ; ++ i )
    {
      a[ i ] -= b[ i ];
      if( a[ i ] < 0 )
	{
	  a[ i ] += 10;
	  -- a[ i + 1 ];
	}
    }
  while( a[ a[ 0 ] ] == 0 ) --a[ 0 ];
  for( i = a[ 0 ] ; i > 0 ; -- i )
    cout<<a[ i ];
  cout<<"\n";
  return ;
}

int main()
{
  int i,j;
  cin>>ca>>cb;
  a[ 0 ] = strlen(ca);
  b[ 0 ] = strlen(cb);
  for( i = 0 ; i < n ; ++ i )
  return 0;
}
