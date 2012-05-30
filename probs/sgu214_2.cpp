/*
  SGU 214
  2012-03-14
  gestapolur
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define MAXA 202
#define MAXN 2002
#define INF 2141483647
using namespace std;

int n , m;
char aph[ MAXA ];
char a[ MAXN ] , b[ MAXN ];
char ra[ MAXN ] , rb[ MAXN ];
int v[ MAXA ][ MAXA ];
int f[ MAXN ][ MAXN ];
int rec[ MAXN ][ MAXN ] , minap[ MAXA ] , minat[ MAXA ] , minbp[ MAXA ] , minbt[ MAXA ];
int suma[ MAXN ] , sumb[ MAXN ];
int range[ MAXN ][ MAXN ];
int lena , lenb;

void init()
{
  cin>>aph+1>>a+1>>b+1;

  n = strlen( a + 1 );
  m = strlen( aph + 1 );
  
  for( int i = 1 ; i <= m ; ++ i )
    {
      minap[ aph[ i ] - 32 ] = INF;
      minbp[ aph[ i ] - 32 ] = INF;
    }

  for( int i = 1 ; i <= m ; ++ i )
    for( int j = 1 ; j <= m ; ++ j )
      {
        cin>>v[ aph[ i ] - 32 ][ aph[ j ] - 32 ];
        if ( minap[ aph[ i ] - 32 ] > v[ aph[ i ] - 32 ][ aph[ j ] - 32 ] )
          {
            minap[ aph[ i ] - 32 ] = v[ aph[ i ] - 32 ][ aph[ j ] - 32 ];
            minat[ aph[ i ] - 32 ] = j;
          }
        if( minbp[ aph[ j ] - 32 ] > v[ aph[ i ] - 32 ][ aph[ j ] - 32 ] )
          {
            minbp[ aph[ j ] - 32 ] = v[ aph[ i ] - 32 ][ aph[ j ] - 32 ];
            minbt[ aph[ j ] - 32 ] = i;
          }
      }
  
  for( int i = 1 ; i <= n ; ++ i )
    {
      suma[ i ] = suma[ i - 1 ] + minap[ a[ i ] - 32 ];
      sumb[ i ] = sumb[ i - 1 ] + minbp[ b[ i ] - 32 ];
    }

  return ;
}

void dp()
{
  cout<<"min\n";
  for( int i = 1 ; i <= n ; ++ i )
    cout<<minat[ i ]<<" "; cout<<"\n";
  for( int i = 1 ; i <= n ; ++ i )
    cout<<minbt[ i ]<<" "; cout<<"\n";
  cout<<"sum\n";
  for( int i = 1 ; i <= n ; ++ i )
    cout<<suma[ i ]<<" "; cout<<"\n";
  for( int i = 1 ; i <= n ; ++ i )
    cout<<sumb[ i ]<<" "; cout<<"\n";
  cout<<"=======\n";

  for( int i = 1 ; i <= n ; ++ i )
    {
      f[ i ][ 0 ] = INF;
      f[ 0 ][ i ] = INF;
    }
  rec[ 0 ][ 0 ] = -1;

  for( int i = 1 ; i <= n ; ++ i )
    for( int j = 1 ; j <= n ; ++ j )
      {
        f[ i ][ j ] = f[ i - 1 ][ j - 1 ] + v[ a[ i ] - 32 ][ b[ j ] - 32 ];
        //cout<<v[ a[ i ] - 32 ][ b[ j ] - 32 ]<<" "<<v[ a[ i ] - 32 ][ b[ j ] - 32 ]<<"\n";
        rec[ i ][ j ] = 0;
        range[ i ][ j ] = 0;
        //cout<<i<<" "<<j<<"\n";
        for( int k = 1 ; k <= j ; ++ k )
          if( f[ i ][ j ] > f[ i ][ k ] + sumb[ j ] - sumb[ k ] )
            {
              f[ i ][ j ] = f[ i ][ k ] + sumb[ j ] - sumb[ k ];
              rec[ i ][ j ] = 1;
              range[ i ][ j ] = k + 1;
            }
        for( int k = 1 ; k <= i ; ++ k )
          if( f[ i ][ j ] > f[ k ][ j ] + suma[ i ] - suma[ k ] )
            { 
              f[ i ][ j ] = f[ k ][ j ] + suma[ i ] - suma[ k ];
              rec[ i ][ j ] = 2;
              range[ i ][ j ] = k + 1;
            }
      }

  cout<<"test\n";
  cout<<f[ n ][ n ]<<"\n";
  for( int i = 1 ; i <= n ; ++ i )
    {
      for( int j = 1 ; j <= n ; ++ j )
        cout<<f[ i ][ j ]<<" ";
      cout<<"\n";
    }
  for( int i = 1 ; i <= n ; ++ i )
    {
      for( int j = 1 ; j <= n ; ++ j )
        cout<<rec[ i ][ j ]<<":"<<range[ i ][ j ]<<" ";
      cout<<"\n";
    }
  return ;
}

void out( int i , int j )
{
  int k ;
  cout<<i<<" "<<j<<"\n";
  cin.get();
  if( rec[ i ][ j ] == 0 )
    {
      ra[ ++ lena ] = b[ j ];
      rb[ ++ lenb ] = a[ i ];
      out( i - 1 , j - 1 );
    }
  else if( rec[ i ][ j ] == 1 )
    {
      for( k = range[ i ][ j ] ; k <= j ; ++ k )
        ra[ ++ lena ] = aph[ minat[ a[ k ] - 32 ] ];
      out( i , range[ i ][ j ] - 1 );
    }
  else if( rec[ i ][ j ] == 2 )
    {     
      for( k = range[ i ][ j ] ; k <= i ; ++ k )
        rb[ ++ lenb ] = aph[ minbt[ b[ k ] - 32 ] ];
      out( range[ i ][ j ] - 1 , j );
    }
  return ;
}

void disp()
{
  cout<<"display\n";
  cout<<f[ n ][ n ]<<"\n";
  cout<<lena<<" "<<lenb<<"\n";
  for( int i = 1 ; i <= lena ; ++ i )
    cout<<ra[ i ];
  cout<<"\n";
  for( int i = 1 ; i <= lenb ; ++ i )
    cout<<rb[ i ];
  cout<<"\n";
  return ;
}

int main()
{
  init();

  dp();
  cout<<"out\n";
  out( n , n );

  disp();

  return 0;
}
