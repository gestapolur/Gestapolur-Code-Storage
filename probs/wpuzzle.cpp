#include<cstdlib>
#include<cstdio>
#include<cstring>
#define MAXN 1005
#define MAXW 1500
#define MAXT 1000000

const int dirn[ 8 ] = { -1 , -1 , 0 , 1 , 1 , 1 , 0 , -1 };
const int dirm[ 8 ] = { 0 , 1 , 1 , 1 , 0 , -1 , -1 , -1 };

//char node[ MAXT ];
int child[ MAXT ][ 26 ] , pre[ MAXT ] , fail[ MAXT ] , endidx[ MAXT ];
char puz[ MAXN ][ MAXN ] , word[ MAXN ][ MAXW ];
int foundn[ MAXN ] , foundm[ MAXN ];
char foundd[ MAXN ]; 
int n , m , w , tot;

bool inq[ MAXT ];
int q[ MAXT ];
int front , rear;

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

void constr_fail()
{
  int i , pos , cur , self;

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

  return;
}

//root is zero
void constr_tries()
{
  int cur , pos , j;
  int ch;
  //tries
  tot = 0;
  memset( child[ 0 ] , 0 , sizeof( child[ 0 ] ) );

  for( int i = 1 ; i <= w ; ++ i )
    {
      cur = 0;
      pos = 1;
      
      while( word[ i ][ pos ] not_eq 10 )
        {
          ch = word[ i ][ pos ] -'A';
          if( child[ cur ][ ch ] == 0 )
            {
              pre[ ++ tot ] = cur;
              inq[ tot ] = false;
              fail[ tot ] = 0;
              endidx[ tot ] = 0;
              memset( child[ tot ] , 0 , sizeof( child[ 0 ] ) );
              child[ cur ][ ch ] = tot;
              cur = tot;
            }
          else
            cur = child[ cur ][ ch ];
          
          if( word[ i ][ pos + 1 ] == 10 )
            endidx[ cur ] = i;
          
          ++ pos;
        }
    }

  return ;
}

void find()
{
  int i , j , k;
  int tn , tm , cur , pos;
  bool found;

  for( i = 1 ; i <= n ; ++ i )
    for( j = 1 ; j <= m ; ++ j )
      for( k = 0 ; k < 8 ; ++ k )
        {
          found = false;
          tn = i;
          tm = j;
          cur = 0;
          do{
            
            pos = child[ cur ][ puz[ tn ][ tm ] - 'A' ];
            if( endidx[ pos ] )
              {
                //printf( "!\n" );
                foundn[ endidx[ pos ] ] = i - 1;
                foundm[ endidx[ pos ] ] = j - 1;
                foundd[ endidx[ pos ] ] = 'A' + k;
                found = true;
                break;
              }
            if( pos )
              {
                cur = pos;
                tn += dirn[ k ];
                tm += dirm[ k ];
              }
            else
              while( not child[ cur ][ puz[ tn ][ tm ] - 'A' ] and cur )
                cur = fail[ cur ];
            
          }while( tn > 0 and tn <= n and tm > 0 and tm <= m and cur );
          
          if( found )
            break;
        }
  //printf( "%d\n" , tot );
  
  for( int i = 1 ; i <= w; ++ i )
    printf( "%d %d %c\n" , foundn[ i ] , foundm[ i ] , foundd[ i ] );
 
  return ;
}
/*
void clr()
{
  int i , j;
  for( i = 0 ; i <= tot ; ++ i )
    {
      pre[ i ] = 0;
      endidx[ i ] = 0;
      fail[ i ] = 0;
      inq[ i ] = false;
      for( j = 0 ; j < 26 ; ++ j )
        child[ i ][ j ] = 0;
    }
  tot = 0;
  return ;
}
*/
/*
void test()
{
  printf( "%d\n" , tot );
  for( int i = 0 ; i <= tot ; ++ i )
    printf( "%d " , fail[ i ] );
  printf( "\n" );
  for( int i = 0 ; i <= tot ; ++ i )
    {
      for( int j = 0 ; j < 26 ; ++ j )
        printf( "%d " , child[ i ][ j ]);
      printf( "\n" );
    }
  for( int i = 0 ; i <= tot ; ++ i )
    printf( "%d " , endidx[ i ] );
  printf( "\n" );
  return ;
}
*/
int main()
{
  int t = 1;

  //scanf( "%d" , &t );
  //getchar();
  while( t -- )
    {
      init();
   
      constr_tries();
      
      constr_fail();
      
      //test();

      find();

      if( t > 0 )
        printf( "\n" );
      
    }

  return 0;
}
