/*
  SPOJ NAHY
  gestapolur
  2012-03-17
  ACCEPTED
*/
#include<cstdlib>
#include<cstdio>
#include<cstring>
#define MAXN 1002

char p[ MAXN ];
int n;

void kmp()
{
  int q , k;
  int pi[ MAXN ];
  long long cnt = 0;
  char ch;

  pi[ 1 ] = 0;
  k = 0;
  //puts( p );
  //printf("kmp start\n");
  for( q = 2 ; q <= n ; ++ q )
    {
      while( k > 0 and p[ k + 1 ] not_eq p[ q ] )
        k = pi[ k ];
      if( p[ k + 1 ] == p[ q ] )
        ++ k;
      pi[ q ] = k;
    }
  //kmp
  //printf( "pattern start\n" );
  q = 0;
  while( ch = getchar( ) )
    {
      //printf( "%c" , ch );
      if( ch == 10 ) break;

      while( q > 0 and p[ q + 1 ] not_eq ch )
        q = pi[ q ];
      if( p[ q + 1 ] == ch )
        ++ q;
      
      if( q == n )
        {
          printf( "%Ld\n" , cnt - n + 1 );
          q = pi[ q ];
        }
      ++ cnt;
    }
  printf("\n");
  //printf("finish\n");

  return ;
}

void init()
{
  getchar();
  for( int i = 1 ; i <= n ; ++ i )
    scanf( "%c" , &p[ i ] );
  getchar();
  //for( int i = 1 ; i <= n ; ++ i ) printf( "%c " , p[ i ] ); printf("\n");
  return ;
}

int main()
{
  //scanf( "%s%s" , &t , &p );
  //for( int i = 1 ; i <= 5 ; ++ i ) printf( "%c" , t[ i ] ); printf("\n");
  //printf( "%d %d\n" , strlen( t ) , strlen( p ) );
  while( scanf( "%d" , &n ) not_eq EOF )
    {
      //printf( "%d\n" , n );
      init();

      kmp();
    }
  return 0;
}
