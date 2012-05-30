#include<cstdlib>
#include<cstdio>
#include<cstring>
#define MAXN 1002
#define MAXW 1500
#define MAXT 1000000

const int dirn[ 8 ] = { -1 , -1 , 0 , 1 , 1 , 1 , 0 , -1 };
const int dirm[ 8 ] = { 0 , 1 , 1 , 1 , 0 , -1 , -1 , -1 };

char node[ MAXT ];
//int child[ MAXW * MAXN ][ 27 ] , pre[ MAXW * MAXN ] , fail[ MAXW * MAXN ] , endidx[ MAXW * MAXN ];
int child[ MAXT ][ 26 ] , pre[ MAXT ] , fail[ MAXT ] , endidx[ MAXT ];
char puz[ MAXN ][ MAXN ] , word[ MAXN ][ MAXW ];
int foundn[ MAXN ] , foundm[ MAXN ];
char foundd[ MAXN ]; 
int slen[ MAXW ];
int n , m , w , tot;

void init()
{
  char ch;
  int tlen;

  scanf( "%d%d%d" , &n , &m , &w );
  //cin>>n>>m>>w;
  getchar();
  //cin.get();
  for( int i = 1 ; i <= n ; ++ i )
    {
      for( int j = 1 ; j <= m ; ++ j )
        puz[ i ][ j ] = getchar();
      //cin.get( puz[ i ][ j ] );
      getchar();
      //cin.get();
    }
 
  for( int i = 1 ; i <= w ; ++ i )
    {
      tlen = 0;
      while( ch = getchar() )
        {
          if( ch == 10 )
            break;
          word[ i ][ ++ tlen ] = ch;
        }
      slen[ i ] = tlen;
      //scanf( "%s" , &word[ i ] );
    }
    //cin>>word[ i ]+1;
  
  return ;
}

//root is zero
void cons()
{
  int cur , pos , len , j ;
  int ch;
  //tries
  for( int i = 1 ; i <= w ; ++ i )
    {
      cur = 0;
      pos = 1;
      len = slen[ i ]; //strlen( slen[ i ] + 1 );
      while( pos <= len )
        {
          ch = word[ i ][ pos ] - 'A';
          if( child[ cur ][ ch ] == 0 )
            {
              node[ ++ tot ] = word[ i ][ pos ];
              pre[ tot ] = cur;
              child[ cur ][ ch ] = tot;
              cur = tot;
            }
          else
            cur = child[ cur ][ ch ];
          
          if( pos == len )
            endidx[ cur ] = i;
          
          ++ pos;
        }
    }
  //fail
  for( int i = 1 ; i <= tot ; ++ i )
    {
      pos = pre[ i ];
      while( pos > 0 )
        {
          if( child[ pre[ pos ] ][ node[ i ] - 'A' ] > 0 )
            { 
              fail[ i ] = child[ pre[ pos ] ][ node[ i ] - 'A' ];
              break;
            }
          pos = pre[ pos ];
        }
    }

  return ;
}

#ifdef _TEST
void disp()
{
  cout<<tot<<"\n";
  for( int i = 0; i < 26 ; ++ i ) cout<<child[ 0 ][ i ]<<" ";
  cout<<"\n";
  for( int i = 1; i <= tot ; ++ i )
    printf("node %c pre %d end %d fail %d\n", node[ i ] , pre[ i ] , endidx[ i ] , fail[ i ] );
  return ;
}
#endif

void find()
{
  int tn , tm , cur ;

  for( int i = 1 ; i <= n ; ++ i )
    for( int j = 1 ; j <= m ; ++ j )
      for( int k = 0 ; k < 8 ; ++ k )
        {
          tn = i;
          tm = j;
          cur = 0;
          //cout<<i<<" "<<j<<" "<<puz[ i ][ j ]<<" "<<k<<"\n";
           
          do{
            cur = child[ cur ][ puz[ tn ][ tm ] - 'A' ];
            //cout<<node[ cur ]<<" "<<cur<<"\n";
            if( endidx[ cur ] )
              {
                foundn[ endidx[ cur ] ] = i - 1;
                foundm[ endidx[ cur ] ] = j - 1;
                foundd[ endidx[ cur ] ] = char( 'A' + k );
                //cout<<i-1<<" "<<j-1<<" "<<char( 'A' + k )<<"\n";
                break;
              }
            tn += dirn[ k ];
            tm += dirm[ k ];
          }while( tn > 0 and tn <= n and tm > 0 and tm <= m and cur > 0 );
        }
  
  for( int i = 1 ; i <= w; ++ i )
    printf("%d %d %c\n" , foundn[ i ] , foundm[ i ] , foundd[ i ] );
    //cout<<foundn[ i ]<<" "<<foundm[ i ]<<" "<<foundd[ i ]<<"\n";

  return ;
}

void clr()
{
  int i , j;
  for( i = 0 ; i <= tot ; ++ i )
    {
      pre[ i ] = 0;
      endidx[ i ] = 0;
      fail[ i ] = 0;
      for( j = 0 ; j < 26 ; ++ j )
        child[ i ][ j ] = 0;
    }
  tot = 0;
  return ;
}

int main()
{
  int t;

  scanf( "%d" , &t );
  //cin>>t;
  while( t -- )
    {
      init();
   
      cons();

#ifdef _TEST
      cout<<"!!!\n";
      disp();
#endif
      find();
      if( tot > MAXT ) return 0;
      if( t > 0 )
        {
          printf("\n");
          //cout<<"\n";
          clr();
        }
    }

  return 0;
}
