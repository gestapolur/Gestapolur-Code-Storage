//2011 hunan collegiate contest C
#include<iostream>
#include<cstring>
#define MAXN 12
using namespace std;

int n , m , cnt , all , sx , sy , scnt , bcnt ;
bool sw[ MAXN ][ MAXN ] , w[ MAXN ][ MAXN ];
bool cl[ MAXN ][ MAXN ];

const int dir[ 4 ][ 2 ] = { 0 , -1 , 0 , 1 , 1 , 0 , -1 , 0 };

void fill( int wx , int wy , int px , int py )
{
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
  if( scnt * 2 not_eq bcnt ) return false;
  int i , j , t = 0 ;
  cnt = 0 ;
  for( i = 1 ; i <= n ; ++ i )
    {
      for( j = 1 ; j <= n ; ++ j )
        if( not cl[ i ][ j ] and w[ i ][ j ] )
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
  char ch[ MAXN ];
  cin>>n>>m ;

  all = 0 ; scnt = 0 ; bcnt = 0 ;
  if( n == 0 and m == 0 ) return false;
 
  for( i = 1 ; i <= n; ++ i )
    {
      cin>>ch;
      for( j = 0 ; j < n ; ++ j )
        {     
          if( ch[ j ] == '*' ) { w[ i ][ j + 1 ] = true; ++ all; ++ bcnt ; }
          else w[ i ][ j + 1 ] = false;
        }
    }
  sx = 0 , sy = 0;
  for( i = 1 ; i <= m; ++ i )
    {
      cin>>ch;
      for( j = 0 ; j < m ; ++ j )
        {
          if( ch[ j ] == '*' )
            {
              ++ scnt ;
              sw[ i ][ j + 1 ] = true;
              if( sx == 0 )
                sx = i , sy = j + 1 ;
            }
          else sw[ i ][ j + 1 ] = false;
        }
    }

  memset( cl , 0 , sizeof( cl ));
  return true;
}

int main()
{
  while( init() )
    if ( divide() ) cout<<"1\n";
    else cout<<"0\n";
  return 0;
}
