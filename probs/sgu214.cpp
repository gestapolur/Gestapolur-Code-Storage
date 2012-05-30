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
int rec[ MAXN ][ MAXN ] , minp[ MAXA ] , mint[ MAXA ];
int lena , lenb;

void init()
{
  cin>>aph+1>>a+1>>b+1;

  n = strlen( a + 1 );
  m = strlen( aph + 1 );
  
  for( int i = 1 ; i <= m ; ++ i )
    {
      minp[ aph[ i ] - 32 ] = INF;
      for( int j = 1 ; j <= m ; ++ j )
        {
          cin>>v[ aph[ i ] - 32 ][ aph[ j ] - 32 ];
          if ( minp[ aph[ i ] - 32 ] > v[ aph[ i ] - 32 ][ aph[ j ] - 32 ] )
            {
              minp[ aph[ i ] - 32 ] = v[ aph[ i ] - 32 ][ aph[ j ] - 32 ];
              mint[ aph[ i ] - 32 ] = j;
            }
        }
    }

  /*
  for( int i = 1 ; i <= m ; ++ i )
    cout<<minp[ aph[ i ] - 32 ]<<" "; cout<<"\n";
  for( int i = 1 ; i <= m ; ++ i )
    cout<<mint[ aph[ i ] - 32 ]<<" "; cout<<"\n";
  for( int i = 1 ; i <= m ; ++ i )
    {
      for( int j = 1 ; j <= m ; ++ j )
        cout<<v[ aph[ i ] - 32 ][ aph[ j ] - 32 ]<<" ";
      cout<<"\n";
    }
  cout<<"===\n";
  */
  return ;
}

void dp()
{

  for( int i = 1 ; i <= n ; ++ i )
    for( int j = 1 ; j <= n ; ++ j )
      {
        f[ i ][ j ] = f[ i - 1 ][ j - 1 ] + v[ a[ i ] - 32 ][ b[ j ] - 32 ];
        cout<<v[ a[ i ] - 32 ][ b[ j ] - 32 ]<<" "<<v[ a[ i ] - 32 ][ b[ j ] - 32 ]<<"\n";
        rec[ i ][ j ] = 1;

        if( f[ i ][ j ] > f[ i - 1 ][ j ] + v[ a[ i ] - 32 ][ aph[ mint[ a[ i ] - 32 ] ] - 32 ] )
          {
            f[ i ][ j ] = f[ i - 1 ][ j ] + v[ a[ i ] - 32 ][ aph[ mint[ a[ i ] - 32 ] ] - 32 ];
            rec[ i ][ j ] = 2;
          }
        if( f[ i ][ j ] > f[ i ][ j - 1 ] + v[ aph[ mint[ b[ j ] - 32 ] ] - 32 ][ b[ j ] - 32 ] )
          {
            f[ i ][ j ] = f[ i ][ j - 1 ] + v[ aph[ mint[ b[ j ] - 32 ] ] - 32 ][ b[ j ] - 32 ];
            rec[ i ][ j ] = 3;
          }
      }

  for( int i = 1 ; i <= n ; ++ i )
    {
      for( int j = 1 ; j <= n ; ++ j )
        cout<<f[ i ][ j ]<<" ";
      cout<<"\n";
    }
  return ;
}

void out( int i , int j )
{
  if( rec[ i ][ j ] == 1 )
    {
      ra[ ++ lena ] = b[ i ];
      rb[ ++ lenb ] = a[ j ];
      out( i - 1 , j - 1 );
    }
  else if( rec[ i ][ j ] == 2 )
    {
      ra[ ++ lena ] = mint[ a[ i ] - 32 ];
      out( i - 1 , j );
    }
  else if( rec[ i ][ j ] == 3 )
      rb[ ++ lenb ] = char( minp[ b[ i ] - 32 ] + 32 );
      out( i , j - 1 );
    }
  return ;
}

void disp()
{
  cout<<"====\n";
  cout<<f[ n ][ n ]<<"\n";
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

  out( n , n );

  disp();

  return 0;
}
