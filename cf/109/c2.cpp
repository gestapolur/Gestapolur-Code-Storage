#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#define MAXN 100002
using namespace std;

int n , m ;
bool w[ 27 ][ 27 ];
string a , b ;
int tcnt[ 30 ];
int cnt ;

void init()
{
  char ta , tb;
  int tmp;
  cin>>a>>n;
  m = a.size();
  
  
  cin.get();
  for( int i = 1 ; i <= n ; ++ i )
    {
      cin.get( ta );
      cin.get( tb );
      //cout<<ta<<" "<<tb<<"\n";
      cin.get();
      w[ ta - 64 ][ tb - 64 ] = w[ tb - 64 ][ ta - 64 ] = true ;
    }
 
  tcnt[ a[ 0 ] - 64 ] = 1 ; ta = a[ 0 ] - 64;

  for( int i = 1 ; i < m ; ++ i )
    {
      memset( tcnt , 0 , sizeof( tcnt ) );
      ta = ' '; tb = ' ';
      while( a[ i ] == a[ i - 1 ] or w[ a[ i ] - 64 ][ a[ i - 1 ] - 64 ] and i < m )
        {
          if( a[ i ] == a[ i - 1 ] )
            {
              ++ tcnt[ a[ i ] - 64 ];
            }
          else
            { 
              ta = a[ i ] ; 
              tb = a[ i - 1 ];
              ++ tcnt[ a[ i ] - 64 ];
            }
          ++ i ;
        }

      if( ta not_eq ' ' and tb not_eq ' ' )
        {
          if( tcnt[ ta - 64 ] > 0 and tcnt[ tb - 64 ] > 0 )
            cnt += min( tcnt[ ta - 64 ] , tcnt[ tb - 64 ]);
          else
            cnt += tcnt[ ta - 64 ] > tcnt[ tb - 64 ] ? tcnt[ ta - 64 ] : tcnt[ tb - 64 ];
        }
    }
  cout<<cnt<<"\n";
  return ;
}


int main()
{
  init();

  return 0;
}
