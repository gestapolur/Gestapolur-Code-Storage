#include<iostream>
#include<vector>
#define MAXN 52
using namespace std;

class NetworkXOneTimePad
{
public:
  int n , m ;
  long long st[ MAXN * MAXN ] , sc[ MAXN ] , sp[ MAXN ] ;

  bool check( long long k , int cp , int cc )
  {
    int i , j ;
    bool h[ MAXN ];
    for( i = 0 ; i < n ; ++ i ) h[ i ] = false;
    h[ cp ] = true;
    for( i = 0 ; i < m ; ++ i )
      if( i not_eq cc )
	{
	  for( j = 0 ; j < n ; ++ j )
	    if( sc[ i ] xor k == sp[ j ] and not h[ j ])
	      {h[ j ] = true;break;}
	  if( j == n ) return false;
	}
    return true;
  }
    
  int crack(vector <string> p, vector <string> c)
  {
    int i , j , k , tot = 0 , len;
    long long tmp;
    n = p.size() , m = c.size() ;
    len = p[ 0 ].size();

    for( i = 0 ; i < n ; ++ i )
      {
	tmp = 0 ;
	for( k = 0 ; k < len ; ++ k )
	  tmp = tmp * 10 + ( long long )( p[ i ][ k ] - 48 );
	sp[ i ] = tmp;
      }

    for( i = 0 ; i < m ; ++ i )
      {
	tmp = 0 ;
	for( k = 0 ; k < len ; ++ k )
	  tmp = tmp * 10 + (long long )(c[ i ][ k ] - 48 );
	sc[ i ] = tmp;
      }

    for( i = 0 ; i < m ; ++ i )
      for( j = 0 ; j < n ; ++ j )
	{
	  tmp = sc[ i ] xor sp[ j ];
	  
	  for( k = 1 ; k <= tot ; ++ k )
	    if( st[ k ] == tmp ) break;

	  if( k == tot + 1 and check( tmp , j , i ))
	    {st[ ++ tot ] = tmp;}
	}
    return tot;
  }
};

int main()
{
  return 0;
}
