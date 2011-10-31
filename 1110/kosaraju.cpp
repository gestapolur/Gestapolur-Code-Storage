/*
  SCC kosaraju algorithm
  write by gestapolur 
  2011-10-12
*/
#include<cstdlib>
#include<cstdio>
#include<cstring>
#define MAXN 1002
using namespace std;

int n , m , scc ;
int mark[ MAXN ] , st[ MAXN ] , re[ MAXN ] , pre[ MAXN ];
int w[ MAXN ][ MAXN ] , rev[ MAXN ][ MAXN ];

void dfs2( )
{
  int i , j , cur = 0 , pos ;
  bool move ;
  for( int i = 1 ; i <= n ; ++ i )
    { re[ i ] = 1 ; pre[ i ] = 0 ; mark[ i ] = 0 ; }
  for( int i = 1 ; i <= st[ 0 ] ; ++ i ) printf( "%d- " , st[ i ] );
  for( int i = 1 ; i <= st[ 0 ] ; ++ i )
    if( mark[ st[ i ] ] == 0 )
      {
        mark[ st[ i ] ] = ++ cur ;
        pos = st[ i ] ;
        printf( "%d===\n" , st[ i ] );
        do{
          move = false ;
          for( j = re[ pos ] ; j <= rev[ pos ][ 0 ] ; ++ j )
            if( not mark[ rev[ pos ][ j ] ] )
              {
                mark[ rev[ pos ][ j ] ] = cur ;
                pre[ rev[ pos ][ j ] ] = pos ;
                re[ pos ] = j + 1 ;
                pos = rev[ pos ][ j ] ;
                move = true ;
                break ;
              }
          if( not move )
            {
              re[ pos ] = 1 ;
              pos = pre[ pos ];
            }
        }while( pos > 0 );
      }
  
  return ;
}

void dfs1( )
{
  int i , j , cur = 0 , pos ;
  bool move ;
  for( int i = 1 ; i <= n ; ++ i )
    { re[ i ] = 1 ; pre[ i ] = 0 ; mark[ i ] = 0 ; }
  
  for( int i = 1 ; i <= n ; ++ i )
    if( mark[ i ] == 0 )
      {
        mark[ i ] = ++ cur ;
        st[ ++ st[ 0 ] ] = i ;
        pos = i ;
        do{
          move = false ;
          for( j = re[ pos ] ; j <= w[ pos ][ 0 ] ; ++ j )
            if( not mark[ w[ pos ][ j ] ] )
              {
                mark[ w[ pos ][ j ] ] = ++ cur ;
                st[ ++ st[ 0 ] ] = w[ pos ][ j ];
                pre[ w[ pos ][ j ] ] = pos ;
                re[ pos ] = j + 1 ;
                pos = w[ pos ][ j ] ;
                move = true;
                break;
              }
          if( not move )
            {
              re[ pos ] = 1 ;
              pos = pre[ pos ];
            }
        }while( pos > 0 );
      }
  for( i = 1 ; i <= n ; ++ i ) printf( "%d " , mark[ i ] ); printf( "\n" );
  return ;
}

void init()
{
  int u , v ;
  scanf( "%d%d" , &n , &m );
  for( int i = 1 ; i <= m ; ++ i )
    {
      scanf( "%d%d" , &u , &v );
      w[ u ][ ++ w[ u ][ 0 ] ] = v ;
      rev[ v ][ ++ rev[ v ][ 0 ] ] = u ;
    }
  return ;
}

void output()
{
  printf( "%d\n" , scc );
  for( int i = 1 ; i <= n ; ++ i )
    printf( "%d " , mark[ i ] );
  printf( "\n" );
  return ;
}

int main()
{
  init();

  dfs1();

  dfs2();

  output();

  return 0;
}
