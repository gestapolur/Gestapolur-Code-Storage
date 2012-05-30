/*
  SPOJ PSTRING
  2012-03-29
  2012-04-05
  2012-04-07
  gestapolur
*/
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<string>
#define MAXM 1005
#define MAXN 10005
#define TESTN 1005
#define MAXC 128
using namespace std;

char pat[ MAXM ] , text[ MAXN ];
int n , m;

int f[ TESTN ][ MAXM ];
int pre[ TESTN ][ MAXM ];
int fail[ MAXN ];
int ans;

void constr_DFA()
{
  int i , pos;
  fail[ 0 ] = -1;

  for( i = 1 ; i <= m ; ++ i )
    {
      pos = fail[ i - 1 ];//pat[ pos + 1 ] is pos's only child
      
      while( pos >= 0 and pat[ pos + 1 ] not_eq pat[ i ] )
        pos = fail[ pos ];
      //cout<<i<<" "<<pos<<"\n";
      fail[ i ] = pos + 1;
    }

  for( i = 1 ; i <= m ; ++ i ) cout<<fail[ i ]<<" "; cout<<"\n";
  
  return ;
}

void count()
{
  int i , j;

  memset( f , -1 , sizeof( f ) );
  memset( pre , -1 , sizeof( pre ) );
  /*
  for( i = 0 ; i <= m ; ++ i )
    f[ 0 ][ i ] = 0;
  */
  f[ 0 ][ 0 ] = 0;
  //f[ 0 ][ 1 ] = 0;
  
  for( i = 1 ; i <= n ; ++ i )
    for( j = 0 ; j < m ; ++ j )
      if( f[ i - 1 ][ j ] not_eq -1 )
        {
          //for( int k = 0 ; k <= m ; ++ k ) cout<<f[ i ][ k ]<<" "; cout<<"\n";
          //3
          if( text[ i ] not_eq pat[ j ]
              and ( f[ i ][ j ] == -1 or f[ i ][ j ] > f[ i - 1 ][ j ] + 1 ) )
            {
              f[ i ][ j ] = f[ i - 1 ][ j ] + 1;
              pre[ i ][ j ] = j;
            }
          //1
          if( j + 1 < m
              and text[ i ] == pat[ j + 1 ]
              and ( f[ i ][ j + 1 ] == -1 or f[ i ][ j + 1 ] > f[ i - 1 ][ j ] ) )
            {
              f[ i ][ j + 1 ] = f[ i - 1 ][ j ];
              pre[ i ][ j + 1 ] = j;
            }
          if( j + 1 < m 
              and ( f[ i ][ fail[ j + 1 ] ] == -1 or f[ i ][ fail[ j + 1 ] ] > f[ i - 1 ][ j ] + j - fail[ j + 1 ] + 1 ) )
            {
              f[ i ][ fail[ j + 1 ] ] = f[ i - 1 ][ j ] + j - fail[ j + 1 ] + 1; 
              pre[ i ][ fail[ j + 1 ] ] = j;
            }
          if( j + 1 == m
              and (text[ i ] == pat[ j + 1 ] )
              and( f[ i ][ fail[ m ] ] == -1 or f[ i ][ fail[ m ] ] > f[ i - 1 ][ j ] + j - fail[ m ]))
            {
              f[ i ][ fail[ m ] ] = f[ i - 1 ][ j ] + j - fail[ m ];
              pre[ i ][ fail[ m ] ] = j;
            }
          //first node not text[ i ]
          if( j + 1 < m 
              and text[ i ] not_eq pat[ j + 1 ]
              and pat[ fail[ j + 1 ] + 1 ] not_eq text[ i ]
              and ( f[ i ][ fail[ j + 1 ] ] == -1 or f[ i ][ fail[ j + 1 ] ] > f[ i - 1 ][ j ])
             )
            {
              f[ i ][ fail[ j + 1 ] ] = f[ i - 1 ][ j ];
              pre[ i ][ fail[ j + 1 ] ] = j; 
            }
          //first node is text[ i ]
          if( text[ i ] not_eq pat[ j + 1 ] 
              and pat[ fail[ j + 1 ] + 1 ] == text[ i ]
              and ( f[ i ][ fail[ j + 1 ] + 1 ] == -1 or f[ i ][ fail[ j + 1 ] + 1 ] > f[ i - 1 ][ j ] )
              )
            {
              f[ i ][ fail[ j + 1 ] + 1 ] = f[ i - 1 ][ j ];
              pre[ i ][ fail[ j + 1 ] + 1 ] = j;
            }
        }
  ans = -1;
  for( i = 0 ; i < m ; ++ i )
    if( f[ n ][ i ] not_eq -1 and ( ans == -1 or ans > f[ n ][ i ] ) )
      ans = f[ n ][ i ];
  cout<<ans<<"\n";

  //test
  for( i = 0 ; i <= n ; ++ i )
    {
      for( j = 0 ; j <= m ; ++ j )
        cout<<f[ i ][ j ]<<" ";
      cout<<"\n";
    }
  cout<<"pre\n";
  for( i = 0 ; i <= n ; ++ i )
    {
      for( j = 0 ; j <= m ; ++ j )
        cout<<pre[ i ][ j ]<<" ";
      cout<<"\n";
    }  
  return ;
}

void init()
{
  cin>>text+1>>pat+1;

  n = strlen( text + 1 );
  m = strlen( pat + 1 );

  return ;
}

int main()
{
  init();

  constr_DFA();

  count();

  return 0;
}
