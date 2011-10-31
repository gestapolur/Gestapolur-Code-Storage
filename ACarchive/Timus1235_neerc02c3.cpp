//NEERC 02 C
#include<iostream>
#define MAXN 105
using namespace std;

int tx , ty , n ;
int maxw , mx , my ;
int px[ MAXN ] , py[ MAXN ] ;

int min( int a , int b ){ return a < b ? a : b;}

int max( int a , int b ){ return a > b ? a : b;}

int main()
{
  int i , j , k , sx , sy , wide , tw ;
  
  cin>>n>>tx>>ty;
  for( i = 1 ; i <= n ; ++ i )
      cin>>px[ i ]>>py[ i ];
  px[ 0 ] = py[ 0 ] = 0;
  for( i = 0 ; i <= n ; ++ i )
    {
      sx = px[ i ];
      for( j = 0 ; j <= n ; ++ j )
	{
	  sy = py[ j ];
	  wide = min( tx - sx  , ty - sy  );
	  for( k = 1 ; k <= n ; ++ k )
	    if( px[ k ] > sx and py[ k ] > sy )
	      {
		tw = max( px[ k ] - sx , py[ k ] - sy );
		if( tw < wide ) wide = tw;	
	      }
	  
	  if( maxw < wide )
	    { maxw = wide; mx = sx ; my = sy ;}
	}
    }

  cout<<mx<<" "<<my<<" "<<maxw<<"\n";
  return 0;
}
