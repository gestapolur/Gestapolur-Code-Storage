//#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#define MAXN 52
using namespace std;


ifstream cin("input.txt");
ofstream cout("output.txt");

int n , m , ans , sum ;
int w[ MAXN ][ MAXN ] , rcnt[ MAXN ][ MAXN ] , ccnt[ MAXN ][ MAXN ];
int c[ 4 ] , p[ 4 ]; 

int main()
{
  int i , j , k , v , t ; 
  cin>>n>>m;
  for( i = 1 ; i <= n ; ++ i )
    {
      for( j = 1 ; j <= m ; ++ j )
        { 
          cin>>w[ i ][ j ]; 
          sum += w[ i ][ j ];
          ccnt[ i ][ j ] = w[ i ][ j ] + ccnt[ i ][ j - 1 ];
          rcnt[ i ][ j ] = rcnt[ i - 1 ][ j ] + w[ i ][ j ];
        }
    }

  cin>>c[ 0 ]>>c[ 1 ]>>c[ 2 ];
  for( i = 0 ; i < 2 ; ++ i )
    for( j = i + 1 ; j <= 2 ; ++ j )
      if( c[ i ] > c[ j ] )
        { t = c[ i ] ; c[ i ] = c[ j ] ; c[ j ] = t ; }
  //for( i = 0 ; i <= 2 ; ++ i ) cout<<c[ i ]<<" "; cout<<"\n";
  /*
  for( i = 1 ; i <= n ; ++ i )
    cout<<ccnt[ i ][ m ]<<" "; cout<<"\n";
  for( i = 1 ; i <= m ; ++ i )
    cout<<rcnt[ n ][ i ]<<" "; cout<<"\n"; 
  */
  /*
  for( i = 1 ; i <= n ; ++ i )
    for( j = 1 ; j <= m ; ++ j )
      {
        cout<<i<<" "<<j<<"\n";
        //1
        p[ 0 ] = p[ 1 ] = p[ 2 ] = 0;
        for( k = 1 ; k <= n ; ++ k )
          p[ 0 ] += ccnt[ k ][ j ] ; 
        for( k = 1 ; k <= i ; ++ k )
          p[ 1 ] += ccnt[ k ][ m ] - ccnt[ k ][ j ];
        p[ 2 ] = sum - p[ 0 ] - p[ 1 ];
        for( k = 0 ; k < 2 ; ++ k )
          for( v = k + 1 ; v <= 2 ; ++ v )
            if( p[ k ] > p[ v ] )
              { t = p[ k ] ; p[ k ] = p[ v ] ; p[ v ] = t ; }
        if( p[ 0 ] == c[ 0 ] and p[ 1 ] == c[ 1 ] and p[ 2 ] == c[ 2 ] ) ++ ans;
        cout<<p[ 0 ]<<" "<<p[ 1 ]<<" "<<p[ 2 ]<<"\n";
        //2
        p[ 0 ] = p[ 1 ] = p[ 2 ] = 0;

        for( k = 1 ; k <= i ; ++ k )
          p[ 0 ] += ccnt[ k ][ m ] ;
 
        for( k = i + 1 ; k <= n ; ++ k )
          p[ 1 ] += ccnt[ k ][ j ] ;

        p[ 2 ] = sum - p[ 0 ] - p[ 1 ];
        for( k = 0 ; k < 2 ; ++ k )
          for( v = k + 1 ; v <= 2 ; ++ v )
            if( p[ k ] > p[ v ] )
              { t = p[ k ] ; p[ k ] = p[ v ] ; p[ v ] = t ; }
        if( p[ 0 ] == c[ 0 ] and p[ 1 ] == c[ 1 ] and p[ 2 ] == c[ 2 ] ) ++ ans;
        cout<<p[ 0 ]<<" "<<p[ 1 ]<<" "<<p[ 2 ]<<"\n";
        //3
        p[ 0 ] = p[ 1 ] = p[ 2 ] = 0;
        for( k = 1 ; k <= n ; ++ k )
          p[ 0 ] += ccnt[ k ][ m ] - ccnt[ k ][ j ] ; 
        for( k = 1 ; k <= i ; ++ k )
          p[ 1 ] += ccnt[ k ][ j ] ;
        p[ 2 ] = sum - p[ 0 ] - p[ 1 ];
        for( k = 0 ; k < 2 ; ++ k )
          for( v = k + 1 ; v <= 2 ; ++ v )
            if( p[ k ] > p[ v ] )
              { t = p[ k ] ; p[ k ] = p[ v ] ; p[ v ] = t ; }
        if( p[ 0 ] == c[ 0 ] and p[ 1 ] == c[ 1 ] and p[ 2 ] == c[ 2 ] ) ++ ans;
        cout<<p[ 0 ]<<" "<<p[ 1 ]<<" "<<p[ 2 ]<<"\n";
        //4
        p[ 0 ] = p[ 1 ] = p[ 2 ] = 0;
        for( k = i + 1 ; k <= n ; ++ k )
          p[ 0 ] += ccnt[ k ][ m ] ; 
        for( k = 1 ; k <= i ; ++ k )
          p[ 1 ] += ccnt[ k ][ j ] ; 
        p[ 2 ] = sum - p[ 0 ] - p[ 1 ];
        for( k = 0 ; k < 2 ; ++ k )
          for( v = k + 1 ; v <= 2 ; ++ v )
            if( p[ k ] > p[ v ] )
              { t = p[ k ] ; p[ k ] = p[ v ] ; p[ v ] = t ; }
        if( p[ 0 ] == c[ 0 ] and p[ 1 ] == c[ 1 ] and p[ 2 ] == c[ 2 ] ) ++ ans;
        cout<<p[ 0 ]<<" "<<p[ 1 ]<<" "<<p[ 2 ]<<"\n";
        cout<<"----\n";
      }
  cout<<ans<<"\n";
  */
  //5
  for( i = 1 ; i < n - 1 ; ++ i )
    for( j = i + 1 ; j < n ; ++ j )
      {
        p[ 0 ] = p[ 1 ] = p[ 2 ] = 0;
        for( k = 1 ; k <= i ; ++ k )
          p[ 0 ] += ccnt[ k ][ m ] ; 
        for( k = i + 1 ; k <= j ; ++ k )
          p[ 1 ] += ccnt[ k ][ m ] ; 
        p[ 2 ] = sum - p[ 0 ] - p[ 1 ];
        for( k = 0 ; k < 2 ; ++ k )
          for( v = k + 1 ; v <= 2 ; ++ v )
            if( p[ k ] > p[ v ] )
              { t = p[ k ] ; p[ k ] = p[ v ] ; p[ v ] = t ; }
        //cout<<p[ 0 ]<<" "<<p[ 1 ]<<" "<<p[ 2 ]<<"\n";
        if( p[ 0 ] == c[ 0 ] and p[ 1 ] == c[ 1 ] and p[ 2 ] == c[ 2 ] ) ++ ans;        
      }
  //cout<<"----\n";
  //6
  for( i = 1 ; i < m - 1 ; ++ i )
    for( j = i + 1 ; j < m ; ++ j )
      {
        //cout<<i<<"-"<<j<<"\n";
        p[ 0 ] = p[ 1 ] = p[ 2 ] = 0;
        for( k = 1 ; k <= i ; ++ k )
          p[ 0 ] += rcnt[ n ][ k ] ; 
        for( k = i + 1 ; k <= j ; ++ k )
          p[ 1 ] += rcnt[ n ][ k ] ; 
        p[ 2 ] = sum - p[ 0 ] - p[ 1 ];
        for( k = 0 ; k < 2 ; ++ k )
          for( v = k + 1 ; v <= 2 ; ++ v )
            if( p[ k ] > p[ v ] )
              { t = p[ k ] ; p[ k ] = p[ v ] ; p[ v ] = t ; }
        //cout<<p[ 0 ]<<" "<<p[ 1 ]<<" "<<p[ 2 ]<<"\n";
        if( p[ 0 ] == c[ 0 ] and p[ 1 ] == c[ 1 ] and p[ 2 ] == c[ 2 ] ) ++ ans;        
      }
  
  cout<<ans<<"\n";
  return 0;
}
