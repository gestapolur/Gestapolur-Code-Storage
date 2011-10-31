#include<cstdio>
#include<cstdlib>
#include<cstring>
#define MAXN 1005

int n ;
int st[ MAXN ] , par[ MAXN ][ 2 ] , child[ MAXN ][ MAXN ];
bool hashc[ MAXN ];

void down( int x )
{
  hashc[ x ] = true;
  for( int i = 1 ; i <= child[ x ][ 0 ] ; ++ i )
      down( child[ x ][ i ] );
  return ;
}

void up( int x )
{
  hashc[ x ] = true; 
  if( par[ x ][ 0 ] > 0 )
    up( par[ x ][ 0 ] );
  if( par[ x ][ 1 ] > 0 )
    up( par[ x ][ 1 ] );
  return ;
}

void init()
{
  int i , tx , ty ;
  scanf("%d" , &n );
  memset( hashc , 0 , sizeof( hashc ) );
  while( scanf( "%d%d" , &tx , &ty ) == 2 )
    {
      ( par[ tx ][ 0 ] == 0 ? par[ tx ][ 0 ] : par[ tx ][ 1 ] ) = ty;
      child[ ty ][ ++child[ ty ][ 0 ] ] = tx;
    }
 
  for( i = 1 ; i <= 6 ; ++ i ) getchar();

  while( scanf( "%d" , &i ) not_eq EOF )
    {
      up( i );
      down( i );
    }

  //for( i = 1 ; i <= n ; ++ i ) printf( "%d " , hashc[ i ] );printf("\n");
  return ;
}

void work()
{
  int i ;
  for( i = 1 ; i <= n ; ++ i )
    if( not hashc[ i ] )
      st[ ++ st[ 0 ] ] = i ;
  if( st[ 0 ] > 0 )
    {
      for( i = 1 ; i < st[ 0 ] ; ++ i )
        printf( "%d " , st[ i ]);
      printf( "%d\n" , st[ st[ 0 ] ]);
    }
  else
    printf("0\n");
    
  return ;
}


int main()
{
  init();
  work();
  return 0;
}
