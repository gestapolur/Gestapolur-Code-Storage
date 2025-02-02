/*
  hunan 2011 E
  write by Gestapolur
  2011-09-20
  hint : make a hash list and then bfs
*/
#include<cstdlib>
#include<cstdio>
#include<cstring>
#define MAXN 12
#define MAXH 199113

int n , sx , sy , cnt , totc ;
bool w[ MAXN ][ MAXN ] ;
int cl[ MAXN ][ MAXN ] , ans[ MAXN ][ MAXN ] ;
bool sol;

const int dir[ 4 ][ 2 ] = { 1 , 0 , -1 , 0 , 0 , 1 , 0 , -1 };

class queue
{
public:
  int pos ;
  bool sw[ MAXN ][ MAXN ];
};

class hasht
{
public:
  bool sw[ MAXN ][ MAXN ];
  //short int sv[ 22 ]
  hasht *next;
};

queue q[ 1 << 20 ];

hasht *hash[ MAXH + 1 ] = {NULL};

//check hash table 
bool hashc( queue p )
{
  int code = 0 ;
  int i , j , mx = n , my = n ;
  
  for( i = 1 ; i <= n ; ++ i )
    for( j = 1 ; j <= n ; ++ j )
      if( p.sw[ i ][ j ] and i <= mx )
        mx = i ;
      else if( p.sw[ i ][ j ] and j <= my )
        my = j ;
 create :

  //start compress from minx and miny 
  for( i = mx ; i <= n ; ++ i )
    for( j = my ; j <= n ; ++ j )
      if( p.sw[ i ][ j ] )
        code = ( code + ( 1 << ( j - my + 1 ) ) * ( i - mx + 1 ) ) % MAXH;
  
  //add the stat
  
  if( hash[ code ] == NULL )
    {
      hash[ code ] = new hasht;
      
      for( i = 1 ; i <= n ; ++ i )
        for( j = 1 ; j <= n ; ++ j )
          hash[ code ]->sw[ i ][ j ] = p.sw[ i ][ j ];
      /*
      for( i = mx ; i <= n ; ++ i )
        for( j = my ; j <= n ; ++ j )
          hash[ code ]->sw[ i - mx + 1 ][ j - my + 1 ] = p.sw[ i - mx + 1 ][ j - my + 1 ];
      */
      hash[ code ]->next = NULL;
    }
  else
    {
      hasht *t = hash[ code ];
      do{
        
        for( i = 1 ; i <= n ; ++ i )
          for( j = 1 ; j <= n ; ++ j )
            if( hash[ code ]->sw[ i ][ j ] not_eq p.sw[ i ][ j ] )
              goto stop;
        
        /*
        for( i = mx ; i <= n ; ++ i )
          for( j = my ; j <= n ; ++ j )
            if( hash[ code ]->sw[ i - mx + 1 ][ j - my + 1 ] not_eq p.sw[ i - mx + 1 ][ j - my + 1 ] )
              goto stop;
        */
        if( i == n + 1 and j == n + 1 )
          return false;
        
      stop:t = t->next;
      }while( t not_eq NULL );

      hasht *ad = new hasht;
      ad->next = hash[ code ];

      for( i = 1 ; i <= n ; ++ i )
        for( j = 1 ; j <= n ; ++ j )
          ad->sw[ i ][ j ] = p.sw[ i ][ j ];
      
      /*
      for( i = mx ; i <= n ; ++ i )
        for( j = my ; j <= n ; ++ j )
          ad->sw[ mx - i + 1 ][ my - j + 1 ] = p.sw[ mx - i + 1 ][ my - j + 1 ];
      */
      hash[ code ] = ad;
    }
  return true;
}

//output ans 
void output()
{
  for(int i = 1 ; i <= n ; ++ i )
    {
      for( int j = 1 ; j <= n ; ++ j )
        if( ans[ i ][ j ] == 0 )
          printf(".");
        else
          printf("%c" , 'A' + ans[ i ][ j ] - 1 );
      printf("\n");
    }
  return ;
}

//compare ans with cl
bool cmp()
{
  int i , j;
  if( not sol ) { sol = true ; return true; }
  for( i = 1 ; i <= n ; ++ i )
    for( j = 1 ; j <= n ; ++ j )
      if( cl[ i ][ j ] < ans[ i ][ j ] )
        return true;
      else if( cl[ i ][ j ] > ans[ i ][ j ] )
        return false;
  return false;
}

void fill( int wx , int wy , int px , int py , int col , queue p )
{
  int tx , ty , cx , cy ;
  cl[ wx ][ wy ] = col ;
  ++ cnt;
  for( int i = 0 ; i < 4 ; ++ i )
    {
      tx = px + dir[ i ][ 0 ] , ty = py + dir[ i ][ 1 ];
      
      if(tx <= n and tx > 0 and ty <= n and ty > 0 and p.sw[ tx ][ ty ] )
        {
          cx = wx + dir[ i ][ 0 ] , cy = wy + dir[ i ][ 1 ];
          if( cx <= n and cx > 0 and cy <= n and cy > 0 and w[ cx ][ cy ] and not cl[ cx ][ cy ] )
            fill( cx , cy , tx , ty , col , p );
        }
    }
  return ;
}
//change dfs to bfs that will be okay ?
void bfs()
{
  int rear , front ;
  int tx , ty , cx , cy , i , j , u , v , clr ;
  queue p ;
  //init queue
  rear = 1 , front = 0 ;
  for( i = 1 ; i <= n ; ++ i )
    for( j = 1 ; j <= n ; ++ j )
      q[ 1 ].sw[ i ][ j ] = false;
  q[ 1 ].sw[ sx ][ sy ] = true;
  q[ 1 ].pos = 1 ;

  do{//state only contain effective state , add untill vaild???? 
    p = q[ ++ front ];
    if( front > ( 1 << 20 ) ) { printf("not found \n"); return ; }
    //printf("%d %d\n" , front , rear );
    //test
    /*
    if( p.pos == 6 )
      {
        printf("%d\n" , p.pos );
        for( u = 1 ; u <= n ; ++ u )
          {
            for( v = 1 ; v <= n ; ++ v )
              printf("%d " , p.sw[ u ][ v ] );
            printf("\n");
          }
        getchar();
      }
    */
    //pattern process 
    if( p.pos < ( totc >> 1 ) and totc % p.pos == 0 )
      {
        //clean the cl , pattern
        cnt = 0 , clr = 0 ;
        for( u = 1 ; u <= n ; ++ u )
          for( v = 1 ; v <= n ; ++ v )
            cl[ u ][ v ] = false;
        //pattern
        for( u = 1 ; u <= n ; ++ u )
          for( v = 1 ; v <= n ; ++ v )
            if( not cl[ u ][ v ] and w[ u ][ v ] )
              {
                int tmp = cnt ;
                ++ clr ;
                fill( u , v , sx , sy , clr , p );
                //printf( "%d %d\n" , clr , cnt );
                if( cnt - tmp not_eq p.pos )
                  goto end;
              }
        
        //compare cl with ans
        if( cnt == totc and cmp() )
          {
            for( u = 1 ; u <= n ; ++ u )
              for( v = 1 ; v <= n ; ++ v )
                ans[ u ][ v ] = cl[ u ][ v ];
            //output();printf("----------\n");
          }        

      }
  end:;
    //test
    /*
    if( p.pos == 6 )
      {
        printf("----\n");
        for( u = 1 ; u <= n ; ++ u )
          {
            for( v = 1 ; v <= n ; ++ v )
              printf("%d " , cl[ u ][ v ] );
            printf("\n");
          }
      }
    */
    //add state
    
    if( p.pos < ( totc >> 1 ) )
      for( cx = 1 ; cx <= n ;++ cx )
        for( cy = 1 ; cy <= n ; ++ cy )
          if( p.sw[ cx ][ cy ] )
            for( i = 0 ; i < 4 ; ++ i )
              {
                tx = cx + dir[ i ][ 0 ] , ty = cy + dir[ i ][ 1 ];
                if( tx <= n and tx > 0 and ty <= n and ty > 0 and w[ tx ][ ty ] and not p.sw[tx][ty])
                  {
                    p.sw[ tx ][ ty ] = true;
                    if( hashc( p ) )
                      {
                        ++ rear;
                        for( u = 1 ; u <= n ; ++ u )
                          for( v = 1 ; v <= n ; ++ v )
                            q[ rear ].sw[ u ][ v ] = p.sw[ u ][ v ];
                        q[ rear ].pos = p.pos + 1 ;
                      }
                    p.sw[ tx ][ ty ] = false;
                  }
              }
    
  }while( front < rear );
}

bool init()
{
  int i , j ;
  char ch;
  scanf("%d" , &n );
  getchar();
  if( n == 0 ) return false;

  sx = 0 , sy = 0 , totc = 0 ;
  for( i = 1 ; i <= n ; ++ i )
    {
      for( j = 1 ; j <= n ; ++ j )
        {
          ch = getchar();
          if( ch == '*' ) 
            {
              w[ i ][ j ] = true;
              ++ totc;
              if( sx == 0 )
                sx = i , sy = j;
            }
          else w[ i ][ j ] = false;
        }
      getchar();
    }
  //printf( "%d\n" , totc );
  return true;
}

int main()
{
  while( init() )
    {
      bfs();
      output();
      sol = false;
      memset( cl , 0 , sizeof( cl ) );
      memset( ans , 0 , sizeof( ans ) );
      memset( hash , NULL , sizeof( hash ) );
    }
  return 0 ;
}
