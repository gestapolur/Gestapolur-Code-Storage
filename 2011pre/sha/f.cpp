#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#define MAXN 6
using namespace std;

int n , m , cnt , ord ; 
int w[ MAXN ][ MAXN ] , con[ MAXN ][ MAXN ] , st[ MAXN ][ MAXN ];
bool mat[ MAXN ][ MAXN ] ;
int ava[ MAXN ][ MAXN ][ MAXN * MAXN ][ 2 ];
int pre[ MAXN ][ MAXN ][ 2 ] , stv[ MAXN ][ MAXN ][ 2 ];

void dfs( int sr , int sc )
{
  int pos = 1 ;
  int i , cr , cc , tr , tc ;
  cr = sr , cc = sc;
  mat[ cr ][ cc ] = true;
  //init
  for( tr = 1 ; tr <= n ; ++ tr)
    for( tc = 1 ; tc <= m ; ++ tc )
      {
        st[ tr ][ tc ] = 1 ;
        pre[ tr ][ tc ][ 0 ] = pre[ tr ][ tc ][ 1 ] = 0 ;
      }
  //test
  /*
  for( tr = 1 ; tr <= n ; ++ tr)
    {
      for( tc = 1 ; tc <= m ; ++ tc )
        cout<<con[ tr ][ tc ]<<" ";
      cout<<"\n";
    }
  */

  do{
    bool turn = false;
    /*
    for( tr = 1 ; tr <= n ; ++ tr )
      {
        for( tc = 1 ; tc <= m ; ++ tc )
          cout<<mat[ tr ][ tc ]<<" ";
        cout<<"\n";
      }
    cout<<"cond : "<<st[ cr ][ cc ]<<" "<<con[ cr ][ cc ]<<" "<<cr<<" "<<cc<<"\n";
    cin.get();
    */
    if( pos < ord and st[ cr ][ cc ] <= con[ cr ][ cc ] )
      {
        for( i = st[ cr ][ cc ] ; i <= con[ cr ][ cc ] ; ++ i )
          {
            tr = ava[ cr ][ cc ][ i ][ 0 ];
            tc = ava[ cr ][ cc ][ i ][ 1 ];
            //cout<<"current : "<<tr<<" "<<tc<<"\n";
            if( not mat[ tr ][ tc ] )
              {
                if( w[ tr ][ tc ] == 0 )
                  ++ pos;
                mat[ tr ][ tc ] = true;
                pre[ tr ][ tc ][ 0 ] = cr , pre[ tr ][ tc ][ 1 ] = cc;
                st[ cr ][ cc ] = i + 1;
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
        st[ cr ][ cc ] = 1;
        tr = pre[ cr ][ cc ][ 0 ] , tc = pre[ cr ][ cc ][ 1 ];
        cr = tr, cc = tc ;
        -- pos;
      }
  }while( pos > 0 );

  return ;
}

int abs( int a ){ return a > 0 ? a : -a ;}

bool check( int r1 , int c1 , int r2 , int c2 )
{
  if( abs( c1 - c2 ) <= 1 and abs( r1 - r2 ) <= 1 )
    return true;
  if( abs( c1 - c2 ) == abs( r1 - r2 ) ) return false;
  if( c1 not_eq c2 and r1 not_eq r2 ) return true;
  return false;
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
  for( i = 1 ; i <= n ; ++ i )
    for( j = 1 ; j <= m ; ++ j )
      for( u = 1 ; u <= n ; ++ u )
        for( v = 1 ; v <= m ; ++ v )
          if( (( u > i ) or ( u == i and v > j) )
              and not ( i == u and j == v ) and w[ i ][ j ] not_eq 2 and w[ u ][ v ] not_eq 2 
              and check( i , j , u , v ) )
            {
              ++ con[ i ][ j ]; ++ con[ u ][ v ];
              //cout<<i<<" "<<j<<" "<<u<<" "<<v<<" "<<con[ i ][ j ]<<" "<<con[ u ][ v ]<<"\n";
              ava[ u ][ v ][ con[ u ][ v ] ][ 0 ] = i ;
              ava[ u ][ v ][ con[ u ][ v ] ][ 1 ] = j ;
              ava[ i ][ j ][ con[ i ][ j ] ][ 0 ] = u ;
              ava[ i ][ j ][ con[ i ][ j ] ][ 1 ] = v;
            }

  return ;
}

int main()
{
  int i , j ;
  while( cin>>n>>m )
    {
      init();
      //test
      /*
      for( i = 1 ; i <= n ; ++ i )
        for( j = 1 ; j <= m ; ++ j )
          {
            cout<<i<<":"<<j<<" "<<con[ i ][ j ]<<" ";
            for( int k = 1 ; k <= con[ i ][ j ] ; ++ k )
              cout<<ava[ i ][ j ][ k ][ 0 ]<<":"<<ava[ i ][ j ][ k ][ 1 ]<<" ";
            cout<<"\n";
          }
      cin.get();
      */
      //dfs()
      cnt = 0 ;
      for( i = 1 ; i <= n ; ++ i )
        for( j = 1 ; j <= m ; ++ j )
          {
            //cout<<"st "<<i<<" "<<j<<"-----------------\n";
            dfs( i , j );
            memset( mat , 0 , sizeof( mat ));
          }
      memset( con , 0 , sizeof( con ));
      memset( mat , 0 , sizeof( mat ));
      memset( ava , 0 , sizeof( ava ));
      memset( w , 0 , sizeof( w ) );
      
      cout<<cnt<<"\n";
    }
  return 0 ;
}
