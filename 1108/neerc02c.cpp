//NEERC 02 C
#include<iostream>
#define MAXN 205
using namespace std;

int wi , hi , n ;
int maxw , mr , mc ;
int pr[ MAXN ] , pc[ MAXN ] ;

bool inside( int sx , int ex , int sy ,int ey , int x  )
{
  if( pr[ x ] > sx and pr[ x ] < ex and pc[ x ] < ey and pc[ x ] > sy )
    return true;
  return false;
}

void work()
{
  int i , j , k , v , wide , sy , ey ;
 
  for( i = 1 ; i < n - 1 ; ++ i )
    for( j = i + 2 ; j <= n ; ++ j )
      if( pr[ i ] not_eq pr[ j ] )
	{
	  for( k = i + 1 ; k < j ; ++ k )
	    {
	      sy = pc[ i ] < pc[ j ] ? pc[ i ] : pc[ j ] ;
	      ey = pc[ i ] > pc[ j ] ? pc[ i ] : pc[ j ] ;

	      if(  pc[ k ] <= sy or pc[ k ] >= ey )
		{
		  sy = sy < pc[ k ] ? sy : pc[ k ];
		  ey = ey > pc[ k ] ? ey : pc[ k ];
       
		  for( v = 1 ; v <= n ; ++ v )
		    if(inside( pr[ i ] , pr[ j ] , sy , ey , v ) ) break;
		  if( v == n + 1 )
		    {	  
		      
		      wide = ( ey - sy ) < ( pr[ j ] - pr[ i ] ) ? ( ey - sy ) : ( pr[ j ] - pr[ i ] );
		      if( wide > maxw )
			{
			  //cout<<wide<<" "<<pc[ i ]<<" "<<pr[ i ]<<" "<<pc[ j ]<<" "<<pr[ j ]<<"\n";
			  maxw = wide;
			  mr = pr[ i ] , mc = sy ;
			}
		    }
		  if( pr[ i ] == pr[ k ] )
		    {
		      sy = pc[ i ] < pc[ k ] ? pc[ i ] : pc[ k ] ;
		      ey = pc[ i ] > pc[ k ] ? pc[ i ] : pc[ k ] ;
		      
		      for( v = 1 ; v <= n ; ++ v )
			if(  inside( 0 , hi , sy , ey , v ) )
			  break;
		      if( v == n + 1 )
			{
			  
			  wide = ( ey - sy ) < hi ? ( ey - sy ) : hi ;
			  if( wide > maxw )
			    { mr = 0 , mc = sy ; maxw = wide; }
			}
		    }
		  else if( pr[ k ] == pr[ j ] )
		    {
		      sy = pc[ k ] < pc[ j ] ? pc[ k ] : pc[ j ] ;
		      ey = pc[ k ] > pc[ j ] ? pc[ k ] : pc[ j ] ;
		      
		      for( v = 1 ; v <= n ; ++ v )
			if( inside( 0 , hi , sy , ey , v ) )
			  break;
		      if( v == n + 1 )
			{
			  wide = ( ey - sy ) < hi ? ( ey - sy ) : hi ;
			  //cout<<wide<<" "<<pc[ k ]<<" "<<pr[ k ]<<" "<<pc[ j ]<<" "<<pr[ j ]<<"\n";
			  if( wide > maxw )
			    { mr = 0 , mc = sy ; maxw = wide; }
			}
		    }
		}
	    }	  
	}
      else
	{
	  sy = pc[ i ] < pc[ j ] ? pc[ i ] : pc[ j ] ;
	  ey = pc[ i ] > pc[ j ] ? pc[ i ] : pc[ j ] ;

	  for( k = 1 ; k <= n ; ++ k )
	    if( inside( 0 , hi , sy , ey , k ) )
	      break;
	  if( k == n + 1 )
	    {
	      
	      wide = ( ey - sy ) < hi ? ( ey - sy ) : hi ;
	      if( wide > maxw )
		{ mr = 0 , mc = sy ; maxw = wide; }	      
	    }
	}
  //cout<<"!!!\n";
  // column empty
  for( i = 1 ; i < n ; ++ i )
    for( j = i + 1 ; j <= n ; ++ j )
      {
	sy = pc[ i ] < pc[ j ] ? pc[ i ] : pc[ j ] ;
	ey = pc[ i ] > pc[ j ] ? pc[ i ] : pc[ j ] ;
	
	for( k = 1 ; k <= n ; ++ k )
	  if( inside( 0 , hi , sy , ey , k ) )
	    break;
	if( k == n + 1 )
	  {
	    
	    wide = ( ey - sy ) < hi ? ( ey - sy ) : hi ;
	    if( wide > maxw )
	      { mr = 0 , mc = sy ; maxw = wide; }	      
	  }
      }
  //cout<<"!!!\n";
  // row empty
  for( i = 1 ; i < n ; ++ i )
    for( j = i + 1 ; j <= n ; ++ j )
      {
	for( k = 1 ; k <= n ; ++ k )
	  if( inside( pr[ i ] , pr[ j ] , 0 , wi , k ) )
	    break;
	if( k == n + 1 )
	  {
	    wide = ( pr[ j ] - pr[ i ] ) < wi ? ( pr[ j ] - pr[ i ] ) : wi ;
	    if( wide > maxw )
	      { mr = pr[ i ] , mc = 0; maxw = wide; }	      
	  } 
      }

  cout<<mc<<" "<<mr<<" "<<maxw<<"\n";
  return ;
}

void sort( int i , int j)
{
  if( i >= j ) return ;
  int p , q , t , idx1 , idx2 ;
  p = i , q = j , idx1 = pr[ i + j >> 1 ] , idx2 = pc[ i + j >> 1 ];
  while( p <= q )
    {
      while( pr[ p ] < idx1 or ( pr[ p ] == idx1 and pc[ p ] < idx2 ) ) ++ p ;
      while( pr[ q ] > idx1 or ( pr[ q ] == idx1 and pc[ q ] > idx2 ) ) -- q ;
      if( p <= q )
	{ 
	  
	  t = pr[ p ] ; pr[ p ] = pr[ q ]; pr[ q ] = t;
	  t = pc[ p ] ; pc[ p ] = pc[ q ]; pc[ q ] = t;
	  ++ p , -- q ;
	}
    }
  sort( i , q );
  sort( p , j );
  return ;
}

int main()
{
  int i , j , tr , tc ;
  bool s[ 4 ];
  s[ 0 ] = s[ 1 ] = s[ 2 ] = s[ 3 ] = true;
  cin>>n>>wi>>hi;
  for( i = 1 ; i <= n ; ++ i )
    {
      cin>>pc[ i ]>>pr[ i ];
      if( pr[ i ] == 0 and pc[ i ] == 0 ) s[ 0 ] = false;
      else if( pr[ i ] == 0 and pc[ i ] == wi ) s[ 1 ] = false;
      else if( pr[ i ] == hi and pc[ i ] == 0 ) s[ 2 ] = false;
      else if( pr[ i ] == hi and pc[ i ] == wi ) s[ 3 ] = false;
    }
  if( s[ 0 ] )
    { pr[ ++ n ] = 0 , pc[ n ] = 0 ;}
  if( s[ 1 ])
    { pr[ ++ n ] = 0 ; pc[ n ] = wi;}
  if( s[ 2 ])
    { pr[ ++ n ] = hi ; pc[ n ] = 0;}
  if( s[ 3 ] )
    { pr[ ++ n ] = hi ; pc[ n ] = wi;}
  /*
  for( i = 0 ; i <= wi ; ++ i )
    { 
      pc[ ++ n ] = i , pr[ n ] = hi ; 
      pc[ ++ n ] = i , pr[ n ] = 0 ;
    }
  for( i = 1 ; i < hi ; ++ i )
    { 
      pc[ ++ n ] = 0 , pr[ n ] = i ; 
      pc[ ++ n ] = wi , pr[ n ] = i ;
    }
  */
  //cout<<n<<"\n";
  //for( i = 1 ; i <= n ; ++ i ) cout<<pc[ i ]<<" "<<pr[ i ]<<"\n";
  sort( 1 , n );
  //test
  //cout<<"\n";
  /*
  cout<<n<<"\n";
  for( i = 1 ; i <= n ; ++ i ) cout<<pc[ i ]<<" "<<pr[ i ]<<"\n";
  */
  work();
  return 0;
}
