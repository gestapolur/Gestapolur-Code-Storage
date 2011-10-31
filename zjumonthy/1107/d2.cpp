#include<iostream>
//#include<cstring>
#include<string>
#define MAXN 55
using namespace std;

string a[ MAXN ] ;
int ans , n , m ;
int f[ MAXN ] , pos[ MAXN ] , ord[ MAXN ];

bool cmp( string a , string b )
{
  int len = a.size() < b.size() ? a.size() : b.size();
  for( int i = 0 ; i < len ; ++ i )
    if( a[ i ] < b[ i ] ) return true;
    else if( a[ i ] > b[ i ] ) return false;
  if( a.size() <= b.size() ) return true ; 
  return false ;
}

/*
void sort( int i , int j )
{
  if( i >= j ) return ;
  int m , n , pt ;
  string k , t ;
  m = i , n = j; k = a[ i + j >> 1 ];
  while( m <= n )
    {
      while( a[ m ] < k ) ++ m ;
      while( a[ n ] > k ) -- n ;
      if( m <= n )
	{
	  t = a[ m ] ; a[ m ] = a[ n ] ; a[ n ] = t;
	  pt = pos[ m ] ; pos[ m ] = pos[ n ] ; pos[ n ] = pt;
	  ++ m , -- n ;
	}
    }
  sort( i , n );
  sort( m , j );
  return ;
}
*/

int main()
{
  int i , j , k , pt ;
  string t;
  while( cin >> n >> m )
    {
      ans = 0 ;
      getline( cin , a[ 0 ] );
      
      for( i = 1 ; i <= n ; ++ i )
	{
	  for( j = 1 ; j <= m ; ++ j )
	    { getline( cin , a[ j ] ) ; f[ j ] = 1 ; pos[ j ] = j ;}
	  //sort( 1 , m );
	  
	  for( j = 2 ; j <= m ; ++ j )
	    for( k = 1 ; k < j ; ++ k )
	      if( cmp( a[ j ] , a[ k ] ) )
		{
		  t = a[ j ] ; a[ j ] = a[ k ] ; a[ k ] = t;
		  pt = pos[ j ] ; pos[ j ] = pos[ k ] ; pos[ k ] = pt;
		}
	  
	  for( j = 1 ; j <= m ; ++ j )
	    ord[ pos[ j ] ] = j;
	  

	  for( j = 1 ; j <= m ; ++ j )
	    for( k = 1 ; k < j ; ++ k )
	      if( f[ j ] < f[ k ] + 1 and ord[ k ] < ord[ j ])
		f[ j ] = f[ k ] + 1 ;
	  
	  ans += m - f[ m ];
	  //memset( f, 0 , sizeof( f ) );
	  //memset( a , ' ' , sizeof( a ) );
	}
      cout<<ans<<"\n";
    }
  return 0;
}
