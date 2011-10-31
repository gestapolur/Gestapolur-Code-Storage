//NEERC 02 C
#include<iostream>
#define MAXN 105
using namespace std;

int tx , ty , n ;
int maxw , mx , my ;
int px[ MAXN ] , py[ MAXN ] ;

bool inside( int sx , int ex , int sy ,int ey , int x  )
{
  if( px[ x ] > sx and px[ x ] < ex and py[ x ] < ey and py[ x ] > sy )
    return true;
  return false;
}

inline int min( int a , int b ){ return a < b ? a : b;}

inline int max( int a , int b ){ return a > b ? a : b;}

void work()
{
  int i , j , k , v , wide , sx , sy , ex , ey ;
  bool sign;

  for( i = 1 ; i < n ; ++ i )
    for( j = i + 1 ; j <= n ; ++ j )
      {
	sx = min( px[ i ] , px[ j ] );
	ex = max( px[ i ] , px[ j ] );
	sy = min( py[ i ] , py[ j ] );
	ey = max( py[ i ] , py[ j ] );

	sign = false;
	for( k = 1 ; k <= n ; ++ k )
	  {
	    if( ( px[ k ] >= sx and px[ k ] <= ex ) and ( py[ k ] <= sy or py[ k ] >= ey ))
	      {
		/*
		if( i == 5 and px[ j ] == tx and py[ j ] == ty )
		  cout<<"!!! "<<sx<<" "<<sy<<" "<<ex<<" "<<ey<<" "<<k<<"\n";
		*/
		for( v = 1 ; v <= n ; ++ v )
		  if( inside( sx , ex , min( py[ k ] , sy ) , max( py[ k ] , ey ) , v ) )
		    break;
		if( v == n + 1 )
		  {
		    wide = min( ex - sx , max( py[ k ] , ey ) - min( py[ k ] , sy ) );
		    if( wide > maxw)
		      { maxw = wide ; mx = sx , my = min( sy , py[ k ] );}
		  }
		
	      }
	    if( inside( sx , ex , sy , ey , k ) ) sign = true;
	  }

	if( not sign )
	  {
	    wide = min( ex - sx , ey - sy );
	    if( wide > maxw)
	      { maxw = wide ; mx = sx , my = sy;}
	  }
      }

  cout<<mx<<" "<<my<<" "<<maxw<<"\n";
  
  return ;
}

int main()
{
  int i , j ;
  bool s[ 4 ];
  s[ 0 ] = s[ 1 ] = s[ 2 ] = s[ 3 ] = true;
  cin>>n>>tx>>ty;
  for( i = 1 ; i <= n ; ++ i )
    {
      cin>>px[ i ]>>py[ i ];
      if( px[ i ] == 0 and py[ i ] == 0 ) s[ 0 ] = false;
      else if( px[ i ] == 0 and py[ i ] == ty ) s[ 1 ] = false;
      else if( px[ i ] == tx and py[ i ] == 0 ) s[ 2 ] = false;
      else if( px[ i ] == tx and py[ i ] == ty ) s[ 3 ] = false;
    }
  if( s[ 0 ] )
    { px[ ++ n ] = 0 , py[ n ] = 0 ;}
  if( s[ 1 ])
    { px[ ++ n ] = 0 ; py[ n ] = ty;}
  if( s[ 2 ])
    { px[ ++ n ] = tx ; py[ n ] = 0;}
  if( s[ 3 ] )
    { px[ ++ n ] = tx ; py[ n ] = ty;}  


  work();

  return 0;
}
