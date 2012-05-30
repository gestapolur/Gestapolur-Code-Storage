/*
  codeforces 154B
  2012-02-29
*/
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#define MAXN 10002
using namespace std;

int n , m ;
int prime[ MAXN ];
int hash[ MAXN ] , exist[ MAXN ] ;
bool nopm[ MAXN ] ;

void isp()
{
  int k; 
 
  for( int i = 2 ; i <= n ; ++ i )
    if( not nopm[ i ] )
      {
        prime[ ++ prime[ 0 ] ] = i ;
        k = 2 ;
        while( k * i <= n )
          {
            nopm[ k * i ] = true;
            ++ k;
          }
      }
  return ;
}

void cancel( int x )
{
  int i = 1 ;
  -- exist[ x ];
  
  i = 1 ;
  do{
    while( x % prime[ i ] == 0 )
      {
        -- hash[ prime[ i ] ];
        x /= prime[ i ];
      }
  }while( x > 1 and prime[ i ] <= x );
  
  return ;
}

void add( int x )
{
  int i = 1 ;
  ++ exist[ x ];
  while( x > 1 and prime[ i ] <= x )
    {
      while( x % prime[ i ] == 0 )
        {
          ++ hash[ prime[ i ] ];
          x /= prime[ i ];
        }
      ++ i ;
    }
  
  return ;
}

int cmpdiv( int x )
{
  int i = 1 ;
  while( x > 1 and prime[ i ] <= x )
    {
      if( x % prime[ i ] == 0 and hash[ prime[ i ] ] )
        {
          int j = i;
          while( exist[ j ] )
            {
              if( exist[ j ] % prime[ i ] == 0 )
                return j;
              ++ j ;
            }
        }
      ++ i; 
    }
  return 0 ;
}

void init()
{
  cin>>n>>m;
  int ins;
  char sign;
  for( int i = 1 ; i <= m ; ++ i )
    {
      cin>>sign>>ins;
      if( sign == '+' )
        {
          if( exist[ ins ] ) cout<<"Already on\n";
          else
            {
              ins = cmpdiv( ins );
              if ( ins == 0 )
                cout<<"Success\n";
              else
                cout<<"Conflict with "<<ins<<"\n";
            }
        }
      else
        {
          if( not exist[ ins ] ) cout<<"Already off\n";
          else
            {
              cancel( ins );
              cout<<"Success\n";
            }
        }
    }
  return ;
}

int main()
{
  init();
  
  return 0;
}
