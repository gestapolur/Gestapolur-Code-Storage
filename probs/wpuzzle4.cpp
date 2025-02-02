/*
  SPOJ WPUZZLE
  2012-04-11
  recoding
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
int deep[ MAXT ] , pre[ MAXT ];

int fail[ MAXN ];
int q[ MAXT ];
bool inq[ MAXT ];

int ansm[ MAXN ] , ansn[ MAXN ];
char ansd[ MAXN ];

int n , m , w , tot;

inline void pattern( int sn , int sm , int k )
{
  int pos , tn , tm;
  tn = sn;
  tm = sm;
  pos = 0;
  /*
  if( sm == 14 and k == 1 )
    printf( "new : %d %d %c\n" , sn , sm , k + 'A' );
  */
  do{
    /*
    if( sm == 14 and k == 1 )
      printf( "pos: %d | %d %d start: %d %d %c cur: %c\n" , pos , tn , tm , sn , sm , k + 'A' , puz[ tn ][ tm ]);
    */
    if( child[ pos ][ puz[ tn ][ tm ] - 'A' ] )
      {
        /*
        if( sm == 14 and k == 1 )
          printf( "!\n" );
        */
        pos = child[ pos ][ puz[ tn ][ tm ] - 'A' ];
        tn += dirn[ k ];
        tm += dirm[ k ];      
      }
    else if( pos )
      {
        sn = sn + ( deep[ pos ] - deep[ fail[ pos ] ] ) * dirn[ k ];
        sm = sm + ( deep[ pos ] - deep[ fail[ pos ] ] ) * dirm[ k ];
        pos = fail[ pos ];  
        /*
        if( sm == 14 and k == 1 )
          {
            printf( "%d %d!\n" , sn , sm ); 
            printf( "%d\n" , pos );
          }
        */
      }
    else
      {
        sn += dirn[ k ];
        sm += dirm[ k ];
        tn = sn;
        tm = sm;
      }
    while( endidx[ pos ] )
      {
        ansn[ endidx[ pos ] ] = sn - 1;
        ansm[ endidx[ pos ] ] = sm - 1;
        ansd[ endidx[ pos ] ] = 'A' + k;
        //printf( "%d %d %d %d\n" , sn , sm , deep[ pos ] , deep[ fail[ pos ] ] );
        sn = sn + ( deep[ pos ] - deep[ fail[ pos ] ] ) * dirn[ k ];
        sm = sm + ( deep[ pos ] - deep[ fail[ pos ] ] ) * dirm[ k ];        
        pos = fail[ pos ];
        //printf( "%d %d %d\n" , sn , sm , pos );
      }
  }while( ( tn <= n and tn and tm <= m and tm ) 
          and ( sn <= n and sn and sm <= m and sm ));
  return ;
}

void find()
{
  int i , j;
  //printf( "start work\n" );
  //A
  for( i = 1 ; i <= m ; ++ i )
    pattern( n , i , 0 );
  //B
  for( i = 1 ; i <= n ; ++ i )
    pattern( i , 1 , 1 );
  for( i = 1;  i <= m ; ++ i )
    pattern( n , i , 1 );
  //C
  for( i = 1 ; i <= n ; ++ i )
    pattern( i , 1 , 2 );
  //D
  for( i = 1 ; i <= n ; ++ i )
    pattern( i , 1 , 3 );
  for( i = 1 ; i <= m ; ++ i )
    pattern( 1 , i , 3 );
  //E
  for( i = 1 ; i <= m ; ++ i )
    pattern( 1 , i , 4 );
  //F
  for( i = 1 ; i <= n ; ++ i )
    pattern( i , m , 5 );
  for( i = 1 ; i <= m ; ++ i )
    pattern( 1 , i , 5 );
  //G
  for( i = 1 ; i <= n ; ++ i )
    pattern( i , m , 6 );
  //H
  for( i = 1 ; i <= n ; ++ i )
    pattern( i , m , 7 );
  for( i = 1 ; i <= m ; ++ i )
    pattern( n , i , 7 );
  
  //out
  for( i = 1 ; i <= w ; ++ i )
    printf( "%d %d %c\n" , ansn[ i ] , ansm[ i ] , ansd[ i ] );
  
  return ;
}

void constr_fail()
{
  int i , pos , cur , self;
  int rear , front;
  front = 0;
  rear = 1;
  inq[ 0 ] = true;
  q[ 1 ] = 0;
  
  do{
    pos = q[ ++ front ];

    for( i = 0 ; i < 26 ; ++ i )
      if( child[ pos ][ i ] and not inq[ child[ pos ][ i ] ] )
        {
          q[ ++ rear ] = child[ pos ][ i ];
          inq[ child[ pos ][ i ] ] = true;
        }
    
    if( pre[ pos ] )
      {
        for( i = 0 ; i < 26 ; ++ i )
          if( child[ pre[ pos ] ][ i ] == pos )
            {
              self = i;
              break;
            }    

        cur = fail[ pre[ pos ] ];
        while( not child[ cur ][ self ] and cur )
          cur = fail[ cur ];
        fail[ pos ] = child[ cur ][ self ];
      }
  }while( front < rear );
  /*
  for( int i = 0 ; i <= tot ; ++ i )
    printf( "%d " , fail[ i ] );
  printf( "\n" );
  */
  return;
}

void constr_trie()
{
  int cur , pos , tdeep;
  int ch;
  
  tot = 0;
  memset( child[ 0 ] , 0 , sizeof( child[ 0 ] ) );
  
  for( int i = 1 ; i <= w ; ++ i )
    {
      cur = 0;
      pos = 1;
      tdeep = 0;
      while( 1 )
        {
          ++ tdeep;
          ch = word[ i ][ pos ] - 'A';
          if( not child[ cur ][ ch ] )
            {
              ++ tot;

              deep[ tot ] = tdeep;
              memset( child[ tot ] , 0 , sizeof( child[ 0 ] ) );
              fail[ tot ] = 0;
              endidx[ tot ] = 0;
              inq[ tot ] = false;
              child[ cur ][ ch ] = tot;
              pre[ tot ] = cur;

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
      ansd[ i ] = 0;
    }
  return ;
}

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
  
int main()
{
  int t = 1;
  
  scanf( "%d" , &t );
  getchar();
  
  while( t -- )
    {
      init();
      //printf( "init ok\n" );
      constr_trie();
      //printf( "trie ok\n" );
      constr_fail();
      
      find();

      if( t ) printf("\n");
    }
  return 0;
}
