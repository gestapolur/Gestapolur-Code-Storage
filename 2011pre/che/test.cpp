#include<iostream>
#define INF 1000000000
#define MAXN 102
using namespace std;

int n , m ;
int w[ MAXN ][ MAXN ] , f[ MAXN ][ MAXN ];

void work()
{
  int i , j , k , u , v , ev ;
  bool sign ;
  m = n * ( n - 1 ) ;
  do{
    sign = false;

    for( u = 1 ; u <= n ; ++ u )
      for( v = 1 ; v <= n ; ++ v )
        if( u not_eq v )
          {
            f[ u ][ v ] = INF ;
            for( i = 1 ; i <= n ; ++ i )
              for( j = 1 ; j <= n ; ++ j )
                if( not ( i == u and j == v ) )
                  f[ i ][ j ] = w[ i ][ j ];

            for( k = 1 ; k <= n ; ++ k )
              for( i = 1 ; i <= n ; ++ i )
                for( j = 1 ; j <= n ; ++ j )
                  if(i not_eq j and j not_eq k and i not_eq k and
                     f[ i ][ j ] > f[ i ][ k ] + f[ k ][ j ] )
                    f[ i ][ j ] = f[ i ][ k ] + f[ k ][ j ];
            if( f[ u ][ v ] == w[ u ][ v ] )
              {w[ u ][ v ] = INF ; -- m ; sign = true;}
          }
    
  }while( sign );

  return ;
}

bool check()
{
  int i , j , k ;
  for( k = 1 ; k <= n ; ++ k )
    for( i = 1 ; i <= n ; ++ i )
      for( j = 1 ; j <= n ; ++ j)
        if( k not_eq i and i not_eq j and j not_eq k and 
            w[ i ][ j ] > w[ i ][ k ] + w[ k ][ j ] )
          return false;
  return true;
}

void init()
{
  int i , j ;
  cin>>n;
  for( i = 1 ; i <= n ; ++ i )
    for( j = 1 ; j <= n ; ++ j )
      cin>>w[ i ][ j ];
  return ;
}

int main()
{
  int t , tt ;
  cin>>t;
  tt = 0 ;
  while( t -- )
    {
      ++ tt;
      init();
      //cout<<"???\n";
      if( check() )
        {
          work();
          cout<<"Case "<<tt<<": "<<m<<"\n";
        }
      else
        cout<<"Case "<<tt<<": impossible\n";
    }
  return 0;
}
