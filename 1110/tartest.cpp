//tarjan test 
#include<iostream> 
#define MAXN 1001 
#define INF 32767 
using namespace std; 

int lnk[ MAXN ][ MAXN ]; 
int mark[ MAXN ] , st[ MAXN ] , con[ MAXN ] , low[ MAXN ]; 
int n , m , idx , scc ; 

bool in[ MAXN ]; 

void tarjan( int u ) 
{ 
  int i , v ; 
  mark[ u ] = low[ u ] = ++ idx; 
  st[ ++st[ 0 ] ] = u; 
  in[ u ] = true; 
  //for( i = 1 ; i <= n ; ++ i ) cout<<low[ i ]<<" ";cout<<"\n";
  for( i = 1 ; i <= lnk[ u ][ 0 ] ; ++ i ) 
    if( mark[ lnk[ u ][ i ] ] == 0 )
    //if( not in[ lnk[ u ][ i ] ] )
      { 
	tarjan( lnk[ u ][ i ] ); 
	low[ u ] = low[ u ] < low[ lnk[ u ][ i ] ] ? low[ u ] : low[ lnk[ u ][ i ] ]; 
      } 
    else if( in[ lnk[ u ][ i ] ] ) 
      low[ u ] = low[ u ] < mark[ lnk[ u ][ i ] ] ? low[ u ] : mark[ lnk[ u ][ i ] ]; 
  
  if( low[ u ] == mark[ u ]) 
    { 
      ++scc; 
      do{ 
	v = st[ st[ 0 ] -- ]; 
	con[ v ] = scc; 
	in[ v ] = false; 
      }while( u not_eq v ); 
    } 
  return ; 
} 


int main() 
{ 
  int i , j , k , u , v ; 
  cin>>n; 

  for( int i = 1 ; i <= n ; ++ i )
    for( int j = 1 ; j <= n ; ++ j )
      {
        cin>>k;
        if( k )
          lnk[ i ][ ++ lnk[ i ][ 0 ] ] = j ; 
      }
  idx = 0 ; 
  
  for( i = 1 ; i <= n ; ++ i ) 
    if( mark[ i ] == 0 ) 
      { 
 	st[ 0 ] = 0 ; 
	tarjan( i ); 
      } 
  cout<<scc<<"\n";
  for( i = 1 ; i <= n ; ++ i ) 
    cout<<low[ i ]<<" ";
  cout<<"\n"; 
  for( i = 1 ; i <= n ; ++ i ) cout<<con[ i ]<<" ";cout<<"\n";
  return 0 ; 
}
