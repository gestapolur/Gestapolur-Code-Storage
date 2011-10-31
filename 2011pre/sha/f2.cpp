#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#define MAXN 6
using namespace std;

int n , m , cnt , ord ; 
int w[ MAXN ][ MAXN ] ;
bool mat[ MAXN ][ MAXN ] ;
int pre[ MAXN ][ MAXN ][ 2 ] , stv[ MAXN ][ MAXN ][ 2 ];

int abs( int a ){ return a > 0 ? a : -a ;}

int max( int a, int b ){ return a > b ? a : b ;}

int min( int a , int b ){ return a < b ? a : b ;}

bool check( int r1 , int c1 , int r2 , int c2 )
{
  int l , r;
  if( r1 == r2 )
    {
      l = min( c1 , c2 ); r = max( c1 , c2 );
      for( ; l <= r ; ++ l)
        if( mat[ r1 ][ l ] == 1 or w[ r1 ][ l ] == 1 ) return false;
    }
  else if( c1 == c2 )
    {
      l = min( r1 , r2 ) ; r = max( r1 , r2 );
      for( ; l < r ; ++ l )
        if( mat[ l ][ c1 ] == 1 or w[ l ][ c1 ] == 1 ) return false;
    }
  else if( abs( c1 - c2 ) == abs( r1 - r2 ) )
    {
      int minr , minc , maxr , maxc ;
      minr = min( r1 , r2 ); maxr = max( r1 , r2 );
      minc = min( c1 , c2 ); maxc = max( c1 , c2 );
      for( ; minr <= maxr ; ++ minr )
        for( l = minc ; l <= maxc ; ++ l )
          if( mat[ minr ][ l ] == 1 or w[ minr ][ l ] == 1 )
            return false;
    }
  return true;
}

void dfs( int sr , int sc )
{
  int pos = 1 ;
  int i , j , cr , cc , tr , tc ;
  cr = sr , cc = sc;
  mat[ cr ][ cc ] = true;
  //init
  for( tr = 1 ; tr <= n ; ++ tr)
    for( tc = 1 ; tc <= m ; ++ tc )
      {
        stv[ tr ][ tc ][ 0 ] = 1 ;stv[ tr ][ tc ][ 1 ] = 1 ;
        pre[ tr ][ tc ][ 0 ] = pre[ tr ][ tc ][ 1 ] = 0 ;
      }

  do{
    bool turn = false;

    if( pos < ord and stv[ cr ][ cc ][ 0 ] <= n )
      {
        for( i = stv[ cr ][ cc ][ 0 ] ; i <= n ; ++ i )
          for( j = stv[ cr ][ cc ][ 1 ] ; j <= m ; ++ j )
            if(w[ i ][ j ] not_eq 1 and not mat[ i ][ j ] and check( i , j , cc , cr ) )
          {
            tr = i ;
            tc = j ;
            if( not mat[ tr ][ tc ] )
              {
                if( w[ tr ][ tc ] == 0 )
                  ++ pos;
                mat[ tr ][ tc ] = true;
                pre[ tr ][ tc ][ 0 ] = cr , pre[ tr ][ tc ][ 1 ] = cc ;
                stv[ cr ][ cc ][ 0 ] = i ;
                stv[ cr ][ cc ][ 1 ] = j + 1 ;
                if( stv[ cr ][ cc ][ 1 ] > m )
                  { ++ stv[ cr ][ cc ][ 0 ]; stv[ cr ][ cc ][ 1 ] = 1 ; }
                cr = tr , cc = tc;
                turn = true;
                break;
              }
          }
        
      }

    if( not turn )
      {
        if( pos == ord )
          ++ cnt;
        mat[ cr ][ cc ] = false; 
        stv[ cr ][ cc ][ 0 ] = 1 ; stv[ cr ][ cc ][ 1 ] = 1;
        tr = pre[ cr ][ cc ][ 0 ] , tc = pre[ cr ][ cc ][ 1 ];
        cr = tr, cc = tc ;
        -- pos;
      }
  }while( pos > 0 );

  return ;
}


void init()
{
  int i , j , u , v ;
  ord = 0 ;
  for( i = 1 ; i <= n ; ++ i )
    for( j = 1 ; j <= m ; ++ j )
      {
        cin>>w[ i ][ j ];
        if( w[ i ][ j ] == 0 ) ++ ord ;
      }
  return ;
}

int main()
{
  int i , j ;
  while( cin>>n>>m )
    {
      init();

      //dfs()
      cnt = 0 ;
      for( i = 1 ; i <= n ; ++ i )
        for( j = 1 ; j <= m ; ++ j )
          {
            dfs( i , j );
            memset( mat , 0 , sizeof( mat ));
          }
      //memset( con , 0 , sizeof( con ));
      memset( mat , 0 , sizeof( mat ));
      //memset( ava , 0 , sizeof( ava ));
      memset( w , 0 , sizeof( w ) );
      
      cout<<cnt<<"\n";
    }
  return 0 ;
}
