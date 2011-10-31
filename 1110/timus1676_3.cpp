/*
  timus 1676
  write by gestapolur
  2011-10-09
*/
#include<cstdlib>
#include<cstdio>
#define MAXN 303
#define MAXM 3003

int n , m , cnt , pos , on , scc ; 
unsigned short int lnk[ MAXM ];
bool w[ MAXM ][ MAXM ] ;
bool vis[ MAXM ] , ins[ MAXM ];
unsigned short int low[ MAXM ] , dfn[ MAXM ] , st[ MAXM ] , con[ MAXM ]; 
// [ n ][ n + x ];

bool find( int x )
{
  for( int i = 1 ; i <= m ; ++ i )
    if( w[ x ][ i ] and not vis[ i ] )
      {
        vis[ i ] = true;
        if( lnk[ i ] == 0 or find( lnk[ i ] ) )
          {
            lnk[ i ] = x;
            return true;
          }
      }
  return false ;
}

int min( int a , int b ){ return a < b ? a : b ; }

bool hungary()
{
  int i , j ;
  
  for( i = 1 ; i <= n ; ++ i )
    {
      for( j = 1 ; j <= m ; ++ j )
        vis[ j ] = false ;
      if( find( i ) ) ++ cnt;
      if( cnt == n ) return true; 
    }
  return false;
}

void tarjan( int u )
{
  vis[ u ] = true; 
  ins[ u ] = true;
  st[ ++ st[ 0 ] ] = u ;
  dfn[ u ] = low[ u ] = ++ pos;
  int v , ed ;
  ed = ( u <= m ? 2 * m : m );
  for( v = ( u <= m ? m + 1 : 1 ) ; v <= ed ; ++ v )
    if( w[ u ][ v ] )
      {
        if( not vis[ v ] )
          {
            tarjan( v );
            low[ u ] = min( low[ u ] , low[ v ] ) ;
          }
        else if( ins[ v ] )
          low[ u ] = min( low[ u ] , dfn[ v ] );
      }
  if( low[ u ] == dfn[ u ] )
    {
      ++ scc ;
      do{
        v = st[ st[ 0 ] -- ];
        con[ v ] = scc;
        ins[ v ] = false ;
      }while( u not_eq v and st[ 0 ] > 0 );
    }
  return ;
}

void init()
{
  int i , j ;
  char ch;
  scanf("%d%d" , &n , &m );
  on = n;
  getchar();
  for( i = 1 ; i <= n ; ++ i )
    {
      for( j = 1 ; j <= m ; ++ j )
        {
          ch = getchar();
          w[ i ][ j ] = ( ch == '1' ) ? 1 : 0 ;
        }
      getchar();
    }
  // m > n 
  for( i = n + 1 ; i <= m ; ++ i )
    for( j = 1 ; j <= m ; ++ j )
      w[ i ][ j ] = 1 ;
  return ;
}

void work()
{
  int m2 = 2 * m;
  //construct new graph 
  for( int i = 1 ; i <= n ; ++ i )
    for( int j = 1 ; j <= m ; ++ j )
      {
        w[ i ][ m + j ] = w[ i ][ j ];
        w[ i ][ j ] = 0 ;
      }
  for( int i = n + 1 ; i <= m ; ++ i )
    for( int j = 1 ; j <= m ; ++ j )
      { w[ i ][ j ] = 0 ; w[ i ][ j + m ] = 1 ;} 
   
  //add to m * m perfect match and move the node that aready on the match 
  int tmp = 1 ;
  for( int i = 1 ; i <= m ; ++ i )//delete the edge in perfect match  
    if( lnk[ i ] > 0 )
      { w[ lnk[ i ] ][ m + i ] = 0 ; w[ m + i ][ lnk[ i ] ] = 1 ; } 
    else
      { w[ n + tmp ][ m + i ] = 0 ; w[ m + i ][ n + tmp ] = 1 ; ++ tmp ; }
  
  /*
  for( int i = 1 ; i <= m2 ; ++ i )
    {
      for( int j = 1 ; j <= m2 ; ++ j )
        printf( "%d" , w[ i ][ j ] );
      printf("\n");
    }
  for( int i = 1 ; i <= m ; ++ i ) printf( "%d " , lnk[ i ] ); printf("\n");
  */

  //compute scc
  for( int i = 1 ; i <= m2 ; ++ i ) vis[ i ] = false ;
  for( int i = 1 ; i <= m2 ; ++ i )
    if( not vis[ i ] )
      {
        st[ 0 ] = 0 ;
        tarjan( i );
      }
  //for( int i = 1 ; i <= m2 ; ++ i ) printf( "%d " , con[ i ] );printf("\n");
  //scc merge  
  for( int i = 1 ; i <= n ; ++ i )
    {
      for( int j = 1 ; j <= m ; ++ j )
        if( ( w[ i ][ m + j ] and con[ i ] == con[ m + j ] ) or ( lnk[ j ] == i ) )
          printf("0");
        else printf("1");
      printf("\n");
    }
  
  return ; 
}

int main()
{
  init();
  
  if ( hungary() )
    work();
  else
    for( int i = 1 ; i <= on ; ++ i )
      {
        for( int j = 1 ; j <= m ; ++ j )
          printf("1");
        printf("\n");
      }
  
  return 0;
}
