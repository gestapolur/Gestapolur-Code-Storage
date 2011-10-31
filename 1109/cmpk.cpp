//hunan 2011 k direct cmpare
#include<cstdlib>
#include<cstdio>
#include<cstring>
#define MAXNODE 1 << 24
#define MAXN 100005
#define INF 1000000009

int n , q;
int base[ MAXN ] , qe[ MAXN ];

bool init()
{
  if ( scanf("%d%d" , &n , &q ) not_eq 2 ) return false;
  for(int i = 1 ; i <= n ; ++ i )
    scanf( "%d" , &base[ i ] ) ;
  
  return true;
}

void transfind( char ch [] )
{
  int i , len = strlen( ch ) , x = 0 ;
  bool trans ;
  trans = false;
  qe[ 0 ] = 0;
  for( i = 0  ; i < len ; ++ i )
    if( ch[ i ] <= '9' and ch[ i ] >= '0' and not trans )
      { qe[ ++ qe[ 0 ] ] = ch[ i ] - 48 ;trans = true ;}
    else if( ch[ i ] <= '9' and ch[ i ] >= '0' )
      { qe[ qe[ 0 ] ] = qe[ qe[ 0 ] ] * 10 + ( ch[ i ] - 48 ) ;}
    else trans = false;
  
  return ;
}

int find( int l , int r )
{
  int minv = INF;
  for( ; l <= r ; ++ l )
    minv = minv < base[ l ] ? minv : base[ l ];
  return minv;
}

void work( )
{
  char ch[ 255 ];
  gets( ch );
  for( int i = 1 ; i <= q ; ++ i )
    {
   
      gets( ch );
      
      transfind( ch );
      
      if( ch[ 0 ] == 's' )//shift
        {
          base[ 0 ] = base[ qe[ 1 ] ];
          
          for( int j = 1 ; j < qe[ 0 ] ; ++ j )
            if( base[ qe[ j ] ] not_eq base[ qe[ j + 1 ] ] )
              base[ qe[ j ] ] = base[ qe[ j + 1 ] ];
          
          base[ qe[ qe[ 0 ] ] ] = base[ 0 ];
            
        }
      else//query
        printf( "%d\n" , find( qe[ 1 ] , qe[ 2 ] ) );
      //test
      //for( int j = 1 ; j <= n ; ++ j ) printf("%d ",base[ j ] );printf("\n");
    }
  return ;
}

int main()
{
  init();
  
  work();

  return 0;
}
