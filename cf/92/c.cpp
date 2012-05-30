#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#define MAXN 1002
using namespace std;

int n;
string c;
bool p[ MAXN ];
int cnt[ 27 ] , idx[ 27 ];
int f[ MAXN ] , idc[ MAXN ][ MAXN ];
char ans[ MAXN ];
bool re = false ;

void findp()
{
  int i ;
  for( i = 1 ; i <= n ; ++ i ) p[ i ] = false;  
  for( int k = 2 ; k <= n ; ++ k )
    {
      for( i = sqrt( k ) ; i > 1 ; -- i )
        if( k % i == 0 )
          break;
      if( i == 1 ) p[ k ] = true;
    }
  return ;
}

void init()
{
  int i , j , tmp ;
  cin>>c;
  n = c.size();
  for( i = 0 ; i < n ; ++ i )
      ++ cnt[ c[ i ] - 'a' ];
  for( i = 0 ; i <= 26 ; ++ i )
    idx[ i ] = i ;
  for( i = 0 ; i < 25 ; ++ i )
    for( j = i + 1 ; j <= 25 ; ++ j )
      if( cnt[ i ] > cnt[ j ] )
        {
          tmp  = cnt[ i ] ; cnt[ i ] = cnt[ j ] ; cnt[ j ] = tmp;
          tmp = idx[ i ] ; idx[ i ] = idx[ j ] ; idx[ j ] = tmp;
        }
  return ;
}

int getf( int x )
{
  if( x not_eq f[ x ] )
    x = getf( f[ x ] );
  return x;
}

void work()
{
  int i , j , k , cur , tmax ;
  //cout<<"fuck\n";
  for( i = 1 ; i <= n ; ++ i ) f[ i ] = i ;
  for( i = 1 ; i <= n ; ++ i )
    if( p[ i ] )
      {
        for( j = 2 ; i * j <= n ; ++ j )
          {
            //cout<<i*j<<" "<<i<<"\n"; 
            f[ getf( f[ i * j ] ) ] = f[ getf( f[ i ] ) ];
          }
      }
  for( i = 1 ; i <= n ; ++ i ) f[ i ] = f[ getf( i ) ];  
  //for( i = 1 ; i <= n ; ++ i ) cout<<f[ i ]<<" ";cout<<"\n";
  for( i = 1 ; i <= n ; ++ i )
    idc[ f[ i ] ][ ++ idc[ f[ i ] ][ 0 ] ] = i ;
  cur = 25 ;
  //for( int i = 0 ; i <= 25 ; ++ i ) cout<<cnt[ i ]<<" "; cout<<"\n";
  //for( i = 1 ; i <= n ; ++ i ) cout<<f[ i ]<<" "; cout<<"\n";
  do{

    k = 0 ; tmax = 0 ;

    for( i = 1 ; i <= n ; ++ i )
      if( f[ i ] > 0 and idc[ f[ i ] ][ 0 ] > tmax  )
        { tmax = idc[ f[ i ] ][ 0 ] ; k = i ;}

    if( k == 0 ) {re = true ; break;}

    while( cnt[ cur ] < idc[ f[ k ] ][ 0 ] and cur >= 0 ) -- cur;

    if( cur < 0 ) return ;
    
    k = f[ k ];
    for( i = 1 ; i <= idc[ k ][ 0 ] ; ++ i )
      {
        //cout<<idc[ k ][ i ]<<" "<<k<<" "<<cur<<"\n";
        ans[ idc[ k ][ i ] ] = idx[ cur ] + 'a';
        -- cnt[ cur ];
        f[ idc[ k ][ i ] ] = 0 ;
      }
  }while( 1 );
  return ;
}

int main()
{
  init();
  // cout<<"ffuck\n";
  findp();
  work();

  if( re )
    {
      cout<<"YES\n";
      for( int i = 1 ; i <= n ; ++ i )
        cout<<ans[ i ];
      cout<<"\n";
    }
  else
    cout<<"NO\n";
  return 0;
}
