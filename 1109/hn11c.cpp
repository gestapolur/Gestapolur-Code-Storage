//2011 hunan collegiate contest C
#include<cstdlib>
#include<cstdio>
#include<cstring>
#define MAXN 12

int n , m , cnt , all , sx , sy ;
bool sw[ MAXN ][ MAXN ] , w[ MAXN ][ MAXN ];
bool cl[ MAXN ][ MAXN ];

const int dir[ 4 ][ 2 ] = { 0 , -1 , 0 , 1 , 1 , 0 , -1 , 0 };



void fill( int wx , int wy , int px , int py )
{
  int rear , front ;
  int tx , ty , cx , cy ;
  cl[ wx ][ wy ] = true;
  ++ cnt;
  for( int i = 0 ; i < 4 ; ++ i )
    {
      tx = px + dir[ i ][ 0 ] , ty = py + dir[ i ][ 1 ];
      
      if(tx <= m and tx > 0 and ty <= m and ty > 0 and sw[ tx ][ ty ] )
        {
          cx = wx + dir[ i ][ 0 ] , cy = wy + dir[ i ][ 1 ];
          if( cx <= n and cx > 0 and cy <= n and cy > 0 and w[ cx ][ cy ] and not cl[ cx ][ cy ] )
            fill( cx , cy , tx , ty );
        }
    }
  return ;
}

bool divide()
{
  int i , j , t = 0 ;
  cnt = 0 ;
  for( i = 1 ; i <= n ; ++ i )
    {
      for( j = 1 ; j <= n ; ++ j )
        if( not cl[ i ][ j ] and w[ i ][ j ] and t < 2 )
          {
            fill( i , j , sx , sy ); ++ t ;
            if( t == 2 )
              {
                if( cnt == all ) return true;
                else return false;
              }
          }
    }
  return false;
}

bool init()
{
  int i , j ;
  char ch;
  scanf("%d%d" , &n , &m );
  //scanf("%c" , &ch );
  all = 0;
  if( n == 0 and m == 0 ) return false;
  for( i = 1 ; i <= n; ++ i )
    {
      for( j = 1 ; j <= n ; ++ j )
        {
          scanf("%c" , &ch );
          if( ch == '*' ) { w[ i ][ j ] = true; ++ all;}
          else w[ i ][ j ] = false;
        }
      //scanf("%c" , &ch );
    }
  sx = 0 , sy = 0;
  for( i = 1 ; i <= m; ++ i )
    {
      for( j = 1 ; j <= m ; ++ j )
        {
          scanf("%c" , &ch );
          if( ch == '*' )
            {
              sw[ i ][ j ] = true;
              if( sx == 0 )
                sx = i , sy = j ;
            }
          else sw[ i ][ j ] = false;
        }
      //scanf("%c" , &ch );
    }
  memset( cl , 0 , sizeof( cl ));
  return true;
}

int main()
{
  while( init() )
    if ( divide() ) printf("1\n");
    else printf("0\n");
  return 0;
}
