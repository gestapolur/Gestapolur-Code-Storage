#include<cstdlib>
#include<cstdio>
#define MAXN 1002
#define INF 2141483647

int w[ MAXN ][ MAXN ];
int n , p , tot ;
int inx[ MAXN ] , pre[ MAXN ] , nxt[ MAXN ];
int au[ MAXN ] , av[ MAXN ] , af[ MAXN ];

void sort( int i , int j )
{
  if( i >= j ) return ;
  int m , n , t , k ;
  m = i , n = j , k = au[ i + j >> 1 ];
  while( m <= n )
    {
      while( au[ m ] < k ) ++ m ;
      while( au[ n ] > k ) -- n ;
      if( m <= n )
	{
	  t = au[ m ] ; au[ m ] = au[ n ] ; au[ n ] = t;
	  t = av[ m ] ; av[ m ] = av[ n ] ; av[ n ] = t;
	  t = af[ m ] ; af[ m ] = af[ n ] ; af[ n ] = t;
	  ++ m , -- n ;
	}
    }
  sort( i , n );
  sort( m , j );
  return ;
}

int main()
{
  int i , ux , vx , q , flow ;
  scanf("%d%d",&n , &p );
  
  for( i = 1 ; i <= p ; ++ i )
    {
      //cout<<"ssss\n";
      scanf("%d%d" , &ux , &vx );
      scanf("%d" , &w[ ux ][ vx ]);
      //cin>>w[ ux ][ vx ];
      inx[ vx ] ++;
      pre[ vx ] = ux;
      //cout<<inx[ vx ]<<" "<<vx<<"\n";
      
      nxt[ ux ] = vx;
      //cout<<"sdfasd\n";
    } 


  for( i = 1 ; i <= n ; ++ i )
    if( inx[ i ] == 0 ) break;
  if( i == n + 1 or p == 0 )
    { printf("0\n") ; return 0 ;}
  
  //for( i = 1 ; i <= n ; ++ i ) printf("%d " , pre[ i ] );printf("\n");

  for( i = 1 ; i <= n ; ++ i )
    if( nxt[ i ] == 0 and inx[ i ] not_eq 0 )
      { 
	q = i; flow = INF; 
	do{
	  if( pre[ q ] not_eq 0 )
	    flow = flow < w[ pre[ q ] ][ q ] ? flow : w[ pre[ q ] ][ q ];
	  if( inx[ q ] == 0 )
	    { 
	      ++ tot;
	      au[ tot ] = q , av[ tot ] = i , af[ tot ] = flow;
	      break;
	    }
	  q = pre[ q ];
	  //printf("%d\n" , q );
	}while( q not_eq i and q not_eq 0 );
      }

  printf("%d\n" , tot );
  sort( 1 , tot );
  for( i = 1 ; i <= tot ; ++ i ) printf("%d %d %d\n",au[ i ] , av[ i ] , af[ i ] ) ; 

  return 0;
}
