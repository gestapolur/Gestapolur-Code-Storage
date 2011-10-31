/*
  CSU 2011 JULY CONTEST PROB M standrad
  write by gestapolur
  2011-07-10
*/
#include<iostream>
#include<cstring>
#define MAXN 22
using namespace std;

unsigned long long f[ MAXN ][ MAXN ] , w[ MAXN ][ MAXN ];
unsigned short int a[ MAXN ]; 
int n,m;

int main()
{
  int t , i , j , k , v;
  char ch;
  cin>>t;
  while( t --  )
    {
      cin>>n>>m;
      memset( w , 0 , sizeof( w ));
      memset( f , 0 , sizeof( w ));
      cin.get();
      for( i = 1 ; i <= n ; ++ i )
	{
	  ch = cin.get();
	  a[ i ] = ch - 48;
	}
      //for( i = 1 ; i <= n ; ++ i ) cout<<a[ i ]<<" ";cout<<"\n";
      //init
      for( i = 1 ; i <= n ; ++ i )
	for( j = i ; j <= n ; ++ j )
	  for( k = i ; k <= j ; ++ k )
	    w[ i ][ j ] = w[ i ][ j ]*10 + a[ k ];
      /*
      for( i = 1 ; i <= n ; ++ i )
	{
	  for( j = i ; j <= n ; ++ j )
	    cout<<w[ i ][ j ]<<" ";
	  cout<<"\n";
	}
      */
      //dp
      for( i = 1 ; i <= n ; ++ i ) f[ i ][ 0 ] = w[ 1 ][ i ];
      
      for( i = 1 ; i <= n ; ++ i )
	for( j = 1 ; j <= (m < i - 1  ? m : i - 1 ) ; ++ j )
	  for( k = 1 ; k < i ; ++ k )
	    {
	      //if( i == 3 and j == 2 ) cout<<" k "<<k<<" "<<f[ i ][ j ]<<"\n";
	      if( k > j and f[ i ][ j ] < f[ k ][ j ] + w[ k + 1 ][ i ] )//not divide
		f[ i ][ j ] = f[ k ][ j ] + w[ k + 1 ][ i ];
	      if( k > j - 1 )
		for( v = k + 1; v <= i ; ++ v )//divide
		  if( f[ i ][ j ] < f[ k ][ j - 1 ] + w[ k + 1 ][ v ] + w[ v + 1 ][ i ])
		    f[ i ][ j ] = f[ k ][ j - 1 ] + w[ k + 1 ][ v ] + w[ v + 1 ][ i ];
	    }
      /*
      for( i = 1 ; i <= n ; ++ i)
	{
	  for( j = 0 ; j <= m ; ++ j )
	    cout<<f[ i ][ j ]<<" ";
	  cout<<"\n";
	}
      */
      //for( i = 1 ; i <= n; ++ i ) cout<<f[ i ][ 0 ]<<" ";cout<<"\n";
      cout<<f[ n ][ m ]<<"\n";
    }
  return 0;
}
