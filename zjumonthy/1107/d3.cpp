#include<cstdio>
#include<cstdlib>
#include<cstring>
#define MAXN 55

char a[ MAXN ][ MAXN ] ;
int ans , n , m ;
int f[ MAXN ] , pos[ MAXN ] , ord[ MAXN ];

bool cmp( char a[ ] , char b[ ] )
{
  int len = strlen( a ) < strlen( b ) ? strlen( a ) : strlen( b );
  for( int i = 0 ; i < len ; ++ i )
    if( a[ i ] < b[ i ] ) return true;
    else if( a[ i ] > b[ i ] ) return false;
  if( strlen( a ) < strlen( b ) ) return true ; 
  return false ;
}
/*
void sort( int i , int j )
{
  if( i >= j ) return ;
  int m , n , pt ;
  char *k , t[ MAXN ];
  m = i , n = j; k = a[ i + j >> 1 ];
  while( m <= n )
    {
      while( cmp( a[ m ] , k ) ) ++ m ;
      while( cmp( k , a[ n ] ) ) -- n ;
      if( m <= n )
	{
	  for( pt = strlen( a[ m ] ) - 1 ; pt >= 0 ; -- pt ) t[ pt ] = a[ m ][ pt ];
	  for( pt = strlen( a[ n ] ) - 1 ; pt >= 0 ; -- pt ) a[ m ][ pt ] = a[ n ][ pt ];
	  for( pt = strlen( t ) - 1 ; pt >= 0 ; -- pt ) a[ n ][ pt ] = t[ pt ];
	  //t = a[ m ] ; a[ m ] = a[ n ] ; a[ n ] = t;
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
  char tmp , t[ MAXN ];
  while( scanf( "%d%d" , &n , &m ) not_eq EOF )
    {
      ans = 0 ;
      gets( a[ 0 ] );
      for( i = 1 ; i <= n ; ++ i )
	{
	  //printf("!!!\n");
	  for( j = 1 ; j <= m ; ++ j )
	    {
	      gets( a[ j ] );
	      f[ j ] = 1 ; pos[ j ] = j ;
	    }
	  /*
	  for( j = 1 ; j <= m ; ++ j )
	    {
	      for( k = 0 ; k < strlen( a[ j ] ) ; ++ k ) 
		printf("%c" , a[ j ][ k ]);
	      printf("-\n");
	    }
	  */
	  //sort( 1 , m );
	  for( j = 2 ; j <= m ; ++ j )
	    for( k = 1 ; k < j ; ++ k )
	      if( cmp( a[ j ] , a[ k ] ) )
		{
		  for( pt = strlen( a[ j ] ) - 1 ; pt >= 0 ; -- pt ) t[ pt ] = a[ j ][ pt ];
		  for( pt = strlen( a[ k ] ) - 1 ; pt >= 0 ; -- pt ) a[ j ][ pt ] = a[ k ][ pt ];
		  for( pt = strlen( t ) - 1 ; pt >= 0 ; -- pt ) a[ k ][ pt ] = t[ pt ];
		  //t = a[ m ] ; a[ m ] = a[ n ] ; a[ n ] = t;
		  pt = pos[ j ] ; pos[ j ] = pos[ k ] ; pos[ k ] = pt;
		}
	  //printf("sort end\n");
	  for( j = 1 ; j <= m ; ++ j )
	    ord[ pos[ j ] ] = j;
	  
	  //for( j = 1 ; j <= m ; ++ j ) printf("%d " , ord[ j ] );printf("\n");

	  for( j = 1 ; j <= m ; ++ j )
	    for( k = 1 ; k < j ; ++ k )
	      if( f[ j ] < f[ k ] + 1 and ord[ k ] < ord[ j ])
		f[ j ] = f[ k ] + 1 ;
	  
	  ans += m - f[ m ];
	  //memset( f, 0 , sizeof( f ) );
	  //memset( a , ' ' , sizeof( a ) );
	}
      printf("%d\n" , ans );
    }
  return 0;
}
