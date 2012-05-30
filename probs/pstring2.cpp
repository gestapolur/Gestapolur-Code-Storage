#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<cstdio>
#include<string>
#define MAXN 1005
using namespace std;

int n , m;
int fail[ MAXN ][ 27 ] , f[ MAXN ][ 27 ];
int pi[ MAXN ];
string t , p;

void prefix()
{
  int q;

  q = -1;
  pi[ 0 ] = -1; 
  fail[ 0 ][ p[ 0 ] - 'a' ] = -1;

  for( int i = 1 ; i < m ; ++ i )
    {
      while( q >= 0 and p[ i + 1 ] not_eq p[ q ] )
        q = pi[ q ];
      if( p[ i + 1 ] == p[ q ] )
        ++ q;
      pi[ i ] = q;
      //cout<<"!!!\n";
      for( int j = 0 ; j <= 26 ; ++ j )
        fail[ i ][ j ] = fail[ pi[ i - 1 ] + 1 ][ j ];
      //pi[ i - 1 ] may be -1
      //cout<<"!!!!\n";
      fail[ i ][ p[ i ] - 'a' ] = i;
      //cout<<"!!\n";
    }
  
  for( int i = 0 ; i < m ; ++ i )
    {
      for( int j = 0 ; j <= 26 ; ++ j )
        cout<<fail[ i ][ j ]<<setw( 2 );
      cout<<"\n";
    }
  return ;
}

void dp()
{
  int j , k , ans , cnt;

  for( int i = 0 ; i < 26 ; ++ i) 
    f[ 0 ][ i ] = -1;
  f[ 0 ][ t[ 0 ] - 'a' ] = 0;
  cout<<'i'<<setw( 3 )<<'j'<<setw( 3 )<<'k'<<setw( 4 )<<"f[ i ][ j ]"<<"\n";
  for( int i = 1 ; i < n ; ++ i )
    {
      j = fail[ m - 1 ][ t[ i ] - 'a' ];
      k = j;
      cnt = 0;
      while( k )
        {
          cout<<i<<setw( 3 )<<j<<setw( 3 )<<k<<setw( 3 )<<f[ i ][ j ]<<"\n";
          cin.get();
          f[ i ][ k ] = f[ i ][ k ] < f[ i - 1 ][ j ] + cnt ? f[ i ][ k ] : f[ i - 1 ][ j ] + cnt;
          k = fail[ i - 1 ][ k ];
          ++ cnt;
        }
    }

  ans = -1;
  for( int i = 0 ; i <= 26 ; ++ i )
    if( ans == -1 or ans > f[ n - 1 ][ i ] )
      ans = f[ n - 1 ][ i ];

  cout<<ans<<"\n";

  return ;
}

bool init()
{
  if( cin>>t>>p )
    {
      n = t.size();
      m = p.size();
    
      return true;
    }
  return false;
}

int main()
{

  while( init() )
    {
      prefix();
      
      dp();
    }
  return 0;
}
