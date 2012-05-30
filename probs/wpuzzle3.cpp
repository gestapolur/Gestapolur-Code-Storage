/*
  SPOJ WPUZZLES
  a simple trie
  passed original testcases
  differ in SPOJ : a word could appear more than once
  2012-04-11
*/
#include<cstdlib>
#include<cstdio>
#include<cstring>
#define MAXN 1002
#define MAXW 1500
#define MAXT 1000000
     
const int dirn[ 8 ] = { -1 , -1 , 0 , 1 , 1 , 1 , 0 , -1 };
const int dirm[ 8 ] = { 0 , 1 , 1 , 1 , 0 , -1 , -1 , -1 };
     
int child[ MAXT ][ 26 ] , endidx[ MAXT ];
char puz[ MAXN ][ MAXN ] , word[ MAXN ][ MAXW ];
int foundn[ MAXN ] , foundm[ MAXN ];
char foundd[ MAXN ];
int n , m , w , tot;
     
void init()
{
  int i , j;
  char ch;

  scanf( "%d%d%d" , &n , &m , &w );
  getchar();
     
  for( i = 1 ; i <= n ; ++ i )
    {
      for( j = 1 ; j <= m ; ++ j )
        puz[ i ][ j ] = getchar();
      getchar();
    }

  for( i = 1 ; i <= w ; ++ i )
    {
      j = 0 ;
      while( 1 )
        {
          ch = getchar();
          word[ i ][ ++ j ] = ch;
          if( ch == 10 )
            break;
        }
    }
  return ;
}
     
//root is zero
void cons()
{
  int cur , pos;
  int ch;
  //tries
  tot = 0;
  memset( child[ 0 ] , 0 , sizeof( child[ 0 ] ) );
  
  for( int i = 1 ; i <= w ; ++ i )
    {
      cur = 0;
      pos = 1;
      while( 1 )
        {
          ch = word[ i ][ pos ] - 'A';
          if( not child[ cur ][ ch ] )
            {
              ++ tot;
              memset( child[ tot ] , 0 , sizeof( child[ 0 ] ) );
              endidx[ tot ] = 0;
              child[ cur ][ ch ] = tot;
              cur = tot;
            }
          else
            cur = child[ cur ][ ch ];
          if( word[ i ][ pos + 1 ] == 10 )
            {
              endidx[ cur ] = i;
              break;
            }
          ++ pos;
        }
      //init word save
      foundd[ i ] = 0;
    }
     
  return ;
}
     
void find()
{
  int i , j , k;
  int tn , tm , cur ;
  bool found;
     
  for( i = 1 ; i <= n ; ++ i )
    for( j = 1 ; j <= m ; ++ j )
      for( k = 0 ; k < 8 ; ++ k )
        {
          found = false;
          tn = i;
          tm = j;
          cur = 0;
          /*
          if( puz[ i ][ j ] == 'M' and k == 7 )
            printf("%d %d\n" , i , j );
          */
          do{
            /*
            if( puz[ i ][ j ] == 'M' and k == 7 )
              printf("%c " , puz[ tn ][ tm ] );
            */
            cur = child[ cur ][ puz[ tn ][ tm ] - 'A' ];
            if( endidx[ cur ] and not foundd[ endidx[ cur ] ])
              {
                foundn[ endidx[ cur ] ] = i - 1;
                foundm[ endidx[ cur ] ] = j - 1;
                foundd[ endidx[ cur ] ] = 'A' + k;
                found = true;
                break;
              }
            tn += dirn[ k ];
            tm += dirm[ k ];
          }while( tn > 0 and tn <= n and tm > 0 and tm <= m and cur );
          /*
          if( puz[ i ][ j ] == 'M' and k == 7 )
            printf("\n");
          */
          /*
          if( found )
            break;
          */
        }

  for( i = 1 ; i <= w; ++ i )
    printf( "%d %d %c\n" , foundn[ i ] , foundm[ i ] , foundd[ i ] );

  return ;
}
/*
void test()
{
  for( int i = 0 ; i <= tot ; ++ i )
    {
      for( int j = 0 ; j < 26 ; ++ j )
        printf( "%d " , child[ i ][ j ] );
      printf("\n");
    }
  return ;
}
*/
int main()
{
  int t = 1;
     
  //scanf( "%d" , &t );
  while( t -- )
    {
      init();

      cons();
      //test();
      find();
      if( t )
        printf( "\n" );
    }
     
  return 0;
}
