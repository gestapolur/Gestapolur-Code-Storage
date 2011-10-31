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

const int dir[ 4 ][ 2 ] = { 1 , 0 , -1 , 0 , 0 , 1 , 0 , -1 };

class queue
{
public:
  int pos , len ;
  short int sv[ 22 ][ 2 ];
  bool sw[ MAXN ][ MAXN ];
};

class hasht
{
public:
  bool sw[ MAXN ][ MAXN ];
  hasht *next;
};

class verx
{
public:
  int wx , wy , px , py ;
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
        
        if( i == n + 1 and j == n + 1 )
          return false;
        
      stop:t = t->next;
      }while( t not_eq NULL );

      hasht *ad = new hasht;
      ad->next = hash[ code ];

      for( i = 1 ; i <= n ; ++ i )
        for( j = 1 ; j <= n ; ++ j )
          ad->sw[ i ][ j ] = p.sw[ i ][ j ];
      
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

/*
void fill( int wx , int wy , int px , int py , int col , queue t )
{
  int tx , ty , cx , cy ;
  int front = 0 , rear = 1 ;
  verx q[ 30 ] , p ;
  q[ 1 ].wx = wx , q[ 1 ].wy = wy , q[ 1 ].px = px , q[ 1 ].py = py ;
 
  do{
    p = q[ ++ front ];
    cl[ p.wx ][ p.wy ] = col;
    ++ cnt ;
    for( int i = 0 ; i < 4 ; ++ i )
      {
        tx = px + dir[ i ][ 0 ] , ty = py + dir[ i ][ 1 ];
        
        if(tx <= n and tx > 0 and ty <= n and ty > 0 and t.sw[ tx ][ ty ] )
          {
            cx = wx + dir[ i ][ 0 ] , cy = wy + dir[ i ][ 1 ];
            if( cx <= n and cx > 0 and cy <= n and cy > 0 and w[ cx ][ cy ] and not cl[ cx ][ cy ] )
              { 
                ++ rear ;
                q[ rear ].wx = cx , q[ rear ].wy = cy ;
                q[ rear ].px = tx , q[ rear ].py = ty ;
              }
          } 
      }
  }while( front < rear );
  return ;
}
*/
inline int max( int a , int b ){ return a > b ? a : b ; }

inline int min( int a , int b ){ return a < b ? a : b ; }

inline bool check( int stx , int sty , int ex , int ey , queue p )
{
  if( ex > n or ey > n or ex < 0 or ey < 0 ) return false;
  if( stx == ex )
    {
      int ed = max( sty , ey );
      for( int i = min( sty , ey ) ; i <= ed ; ++ i )
        if( ( not w[ ex ][ i ] or p.sw[ ex ][ i ] ) )
          return false;
      return true;
    }
  else
    {
      int ed = max( stx , ex );
      for( int i = min( stx , ex ) ; i <= ed ; ++ i )
        if( ( not w[ i ][ ey ] or p.sw[ i ][ ey ] ) )
          return false;
      return true;
    }
}

void bfs()
{
  int rear , front ;
  int tx , ty , cx , cy , i , j , k , u , v , clr ;
  queue p ;

  //init queue
  rear = 1 , front = 0 ;

  //create original state
  k = 1 , rear = 0 ;

  while( k <= n )
    {
      bool sign = false;
      for( i = 0 ; i < 4 ; ++ i )
        {
          tx = sx + dir[ i ][ 0 ] * k ;ty = sy + dir[ i ][ 1 ] * k ;
          //printf( "%d %d %d %d\n" , sx , sy , tx , ty );
          if( check( sx , sy , tx , ty , q[ 0 ] ) )
            {
              p = q[ 0 ];
              p.pos = 0 ;

              if( sy == ty )
                {
                  v = max( sx , tx );
                  for( j = min( sx , tx ) ; j <= v ; ++ j )
                    {
                      p.sw[ j ][ sy ] = true ;
                      p.sv[ ++ p.pos ][ 0 ] = j ;
                      p.sv[ p.pos ][ 1 ] = sy ;
                    }
                }
              else
                {
                  v = max( sy , ty );
                  for( j = min( sy , ty ) ; j <= v ; ++ j )
                    {
                      p.sw[ sx ][ j ] = true ;
                      p.sv[ ++ p.pos ][ 0 ] = sx ;
                      p.sv[ p.pos ][ 1 ] = j ;
                    }
                  
                }
              p.len = k ;
              //printf("%d\n" , p.pos );
              if( ( p.pos << 1 ) <= totc )
                {
                  //printf("added\n");
                  q[ ++ rear ] = p;
                  hashc( q[ rear ] );
                  sign = true;
                }
            }
        }
      ++ k ;
      if( not sign ) break;
    }
  if( rear == 0 ) return ;
  //printf("add finish \n");
  //bfs
  do{
    p = q[ ++ front ];
    //test
    
    //printf("%d %d %d %d\n" , front , rear , p.pos , p.len );
    //if( p.pos == 10 and p.len == 5 )
    //  {
    /*
    printf("%d %d %d %d\n" , front , rear , p.pos , p.len);
    for( i = 1 ; i <= n ; ++ i )
      {
        for( j = 1 ; j <= n ; ++ j )
          printf("%d" , p.sw[ i ][ j ] );
        printf("\n");
      }
    getchar();
    */
        //  }
    
    //pattern process 
    if( ( p.pos << 1 ) <= totc and totc % p.pos == 0 )
      {
        //printf("pattern start\n");
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
                if( cnt - tmp not_eq p.pos )
                  goto end;
              }
        
        //compare cl with ans
        if( cnt == totc and cmp( ) )
          {
            for( u = 1 ; u <= n ; ++ u )
              for( v = 1 ; v <= n ; ++ v )
                ans[ u ][ v ] = cl[ u ][ v ];    
           
        
            //if( p.pos == 10 )
            //  {
            /*
                printf("pattern %d %d :\n" , cnt , totc );
                for( u = 1 ; u <= n ; ++ u )
                  {
                    for( v = 1 ; v <= n ; ++ v )
                      printf( "%d" , cl[ u ][ v ] ) ;    
                    printf("\n");
                  }
                printf("-----------\n");
                for( u = 1 ; u <= n ; ++ u )
                  {
                    for( v = 1 ; v <= n ; ++ v )
                      printf( "%d" , p.sw[ u ][ v ] ) ;    
                    printf("\n");
                  }
                printf("------------\n");
                */
                //getchar();
            
                //}
          }
      }
  end:;

    //add state
    if( ( p.pos << 1 ) <= totc )
      for( k = 1 ; k <= p.pos ; ++ k )        
        for( i = 0 ; i < 4 ; ++ i )
          {
            cx = p.sv[ k ][ 0 ] + dir[ i ][ 0 ];
            cy = p.sv[ k ][ 1 ] + dir[ i ][ 1 ];
            if( cx > 0 and cx < n and cy > 0 and cy < n and not p.sw[ cx ][ cy ] and w[ cx ][ cy ])
              for( j = 0 ; j < 4 ; ++ j )
                {
                  tx = cx + ( p.len - 1 ) * dir[ j ][ 0 ];
                  ty = cy + ( p.len - 1 ) * dir[ j ][ 1 ];
                  /*
                  if( p.len == 4 ) 
                    {
                      printf("exist %d %d %d %d %d\n" , cx , cy , tx , ty , j );
                      for( u = 1 ; u <= n ; ++ u )
                        {
                          for( v = 1 ; v <= n ; ++ v )
                            printf( "%d" , p.sw[ u ][ v ] );
                          printf("\n");
                        }
                    }
                  */
                  if( check( cx , cy , tx , ty , p ) )
                    {
                      //create pattern 
                      queue tmp = p ;
                      if( dir[ j ][ 1 ] == 0 )
                        {
                          v = max( cx , tx );
                          for( u = min( cx , tx ) ; u <= v ; ++ u )
                            {
                              tmp.sw[ u ][ cy ] = true ;
                              tmp.sv[ ++ tmp.pos ][ 0 ] = u ;
                              tmp.sv[ tmp.pos ][ 1 ] = cy ;
                            }
                        }
                      else
                        {
                          v = max( cy , ty );
                          for( u = min( cy , ty ) ; u <= v ; ++ u )
                            {
                              tmp.sw[ cx ][ u ] = true ;
                              tmp.sv[ ++ tmp.pos ][ 0 ] = cx ;
                              tmp.sv[ tmp.pos ][ 1 ] = j ;
                            }
                        }
                      //check hash
                      if( ( tmp.pos << 1 ) <= totc and hashc( tmp ) )
                        q[ ++ rear ] = tmp;      
                    }
              }
          }
  }while( front < rear );

  return ;
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
  // create ans with lenth = 1 blocks
  cnt = 0 ;
  for( i = 1 ; i <= n ; ++ i )
    for( j = 1 ; j <= n ; ++ j )
      if( w[ i ][ j ] )
        ans[ i ][ j ] = ++ cnt;
  
  return true;
}

int main()
{
  while( init() )
    {
      bfs();
      output();
      
      memset( cl , 0 , sizeof( cl ) );
      memset( ans , 0 , sizeof( ans ) );
      memset( hash , NULL , sizeof( hash ) );
    }
  return 0 ;
}
