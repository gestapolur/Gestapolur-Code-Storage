/*
  timus 1676
  write by gestapolur
  2011-10-09
*/
#include<cstdlib>
#include<cstdio>
#include<cstring>
#define MAXN 1505
#define MAXM 1505

int n , m , cnt , pos ; 
int lnk[ MAXN ];
bool w[ MAXN ][ MAXM ] ;
bool vis[ MAXM ] , ins[ MAXN ];
int low[ MAXN ] , dfn[ MAXN ] , st[ MAXN ]; 
bool rec[ MAXN ][ MAXM ];

bool find( int x )
{
  for( int i = 1 ; i <= m ; ++ i )
    if( w[ x ][ i ] )
      {
        if( vis[ i ] ) continue ;
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
  memset( lnk , 0 , sizeof( lnk ) );
  cnt = 0;

  for( i = 1 ; i <= n ; ++ i )
    {
      for( j = 1 ; j <= m ; ++ j )
        vis[ j ] = false ;
      if( find( i ) ) ++ cnt;
    }
  
  printf( "%d\n" , cnt );
  for( i = 1 ; i <= m ; ++ i ) printf("%d " , lnk[ i ] ); printf("\n");
  if( cnt not_eq min( n , m ) ) return false;
  return true;
}

void tarjan( int u )
{
  vis[ u ] = true; 
  ins[ u ] = true;
  st[ ++ st[ 0 ] ] = u ;
  dfn[ u ] = low[ u ] = ++ pos;
  int v ;
  for( v = 1 ; v <= m ; ++ v )
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
    do{
      v = st[ st[ 0 ] -- ];
      ins[ v ] = false ;
    }while( u not_eq v and st[ 0 ] > 0 );
  return ;
}

void init()
{
  int i , j ;
  char ch;
  scanf("%d%d" , &n , &m );
  getchar();
  for( i = 1 ; i <= n ; ++ i )
    {
      //getchar();
      for( j = 1 ; j <= m ; ++ j )
        {
          ch = getchar();
          //( ch == '1' ) ? ( w[ i ][ ++ w[ i ][ 0 ] ] = j ) : 0 ;
          w[ i ][ j ] = ( ch == '1' ) ? 1 : 0 ;
        }
      getchar();
    }

  return ;
}

void output()
{
  int i , j ;
  /*
  for( i = 1 ; i <= n ; ++ i )
    {
      for( j = 1 ; j <= m ; ++ j )
        printf( "%d" , rec[ i ][ j ] );
      printf("\n");
    }
  */
  for( i = 1 ; i <= m ; ++ i )
    if( lnk[ i ] > 0 )
      for( j = 1 ; j <= m ; ++ j )
        if( lnk[ j ] > 0 and  w[ lnk[ i ] ][ j ] and w[ j ][ i ] 
            and low[ j ] == low[ i ] and low[ j ] == low[ lnk[ i ] ] )
          rec[ i ][ j ] = 0; rec
  //change the scc set 
  for( i = 1 ; i <= n ; ++ i )
    {
      for( j = 1 ; j <= m ; ++ j )
        printf( "%d" , w[ i ][ j ] );
      printf("\n");
    }
  printf("-------\n");
  for( i = 1 ; i <= n ; ++ i )
    {
      for( j = 1 ; j <= m ; ++ j )
        printf( "%d" , rec[ i ][ j ] );
      printf("\n");
    }
  return ;
}

void work()
{
  //edge in perfect match must be 0 
  for( int i = 1 ; i <= m ; ++ i )
    for( int j = 1 ; j <= m ; ++ j )
      rec[ i ][ j ] = 1 ;
  for( int i = 1 ; i <= m ; ++ i )
    rec[ lnk[ i ] ][ i ] = 0 ;

  //pre
  pos = 0 ;
  memset( vis , 0  , sizeof( vis ) );
  //delete the edge in perfect match  
  for( int i = 1 ; i <= m ; ++ i ) w[ lnk[ i ]][ i ] = 0 ; 
  
  for( int i = 1 ; i <= n ; ++ i )
    if( not vis[ i ] )
      tarjan( i );

  for( int i = 1 ; i <= m ; ++ i )
    printf( "%d " , low[ i ] );
  printf("\n");

}

int main()
{
  init();
  if ( hungary() )
    {
      work();
      output();
    }
  else
    for( int i = 1 ; i <= n ; ++ i )
      {
        for( int j = 1 ; j <= m ; ++ j )
          printf("1");
        printf("\n");
      }
  return 0;
}
