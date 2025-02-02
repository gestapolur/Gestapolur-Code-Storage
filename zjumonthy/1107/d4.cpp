#include<iostream>
//#include<cstring>
#include<string>
#define MAXN 55
using namespace std;

string a[ MAXN ] ;
int ans , n , m ;
int f[ MAXN ] ;

bool cmp( string a , string b )
{
  int len = a.size() < b.size() ? a.size() : b.size();
  for( int i = 0 ; i < len ; ++ i )
    if( a[ i ] < b[ i ] ) return true;
    else if( a[ i ] > b[ i ] ) return false;
  if( a.size() <= b.size() ) return true ; 
  return false ;
}

int main()
{
  int i , j , k , pt , lmax ;
  string t;
  while( cin >> n >> m )
    {
      ans = 0 ;
      getline( cin , a[ 0 ] );
      
      for( i = 1 ; i <= n ; ++ i )
	{
	  for( j = 1 ; j <= m ; ++ j )
	    { getline( cin , a[ j ] ) ; f[ j ] = 1 ; }
	  lmax = 0 ;
	  for( j = 1 ; j <= m ; ++ j )
	    {
	      for( k = 1 ; k < j ; ++ k )
		if( f[ j ] < f[ k ] + 1 and a[ k ] <= a[ j ])
		  f[ j ] = f[ k ] + 1 ;
	      lmax = lmax > f[ j ] ? lmax : f[ j ];
	    }
	  ans += m - lmax;
	}
      cout<<ans<<"\n";
    }
  return 0;
}
