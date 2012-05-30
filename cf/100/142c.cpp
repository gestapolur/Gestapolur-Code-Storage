/*
  codeforces 142C
  TLE MLE
*/
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#define MAXN 10
using namespace std;

int n , m , ans ;
char opt[ MAXN ][ MAXN ] ;
const bool svk[ 4 ][ 3 ][ 3 ] = 
  {
    0 , 1 , 0 , 0 , 1 , 0 , 1 , 1 , 1,
    1 , 1 , 1 , 0 , 1 , 0 , 0 , 1 , 0,
    1 , 0 , 0 , 1 , 1 , 1 , 1 , 0 , 0,
    0 , 0 , 1 , 1 , 1 , 1 , 0 , 0 , 1
  };

const int sr[ 4 ] = { 0 , 0 , 1 , -1 };
const int sc[ 4 ] = { 1 , -1 , 0 , 0 };

class node
{
public:
  int ans;
  char sv[ MAXN ][ MAXN ];
};

node q[ 5000000 ];

void init()
{
  cin>>n>>m;
  return ;
}

bool check( int sr , int sc , char ch[ ][ MAXN ] , int dir )
{
  for( int i = 0 ; i < 3 ; ++ i )
    for( int j = 0 ; j < 3 ; ++ j )
      if( svk[ dir ][ i ][ j ] 
          and ( sr + i > n or sc + j > m or ch[ sr + i ][ sc + j ] not_eq '.' )) return false ;
  return true ;
}

void bfs()
{
  if( n < 3 or m < 3 )
    {
      cout<<0<<"\n";
      for( int i = 1 ; i <= n ; ++ i )
        {
          for( int j = 1 ; j <= m ; ++ j)
            cout<<".";
          cout<<"\n";
        }
      return ;
    }
  
  int front , rear ;
  int i , j , k , ti , tj , u , v , dir ;
  char tmp[ MAXN ][ MAXN ];
  node p ;
  bool added ;
  front = 0 , rear = 1 ;
  ans = 0 ;

  for( i = 1 ; i <= n ; ++ i )
    for( j = 1 ; j <= m ; ++ j )
      q[ 1 ].sv[ i ][ j ] = '.';
  q[ 1 ].ans = 0 ;

  do{
    p = q[ ++ front ];
    //test
    /*
    cout<<p.ans<<"\n";
    for( i = 1 ; i <= n ; ++ i ) { for( j = 1 ; j <= m ; ++ j ) cout<<p.sv[ i ][ j ]; cout<<"\n";}
    getchar();
    */
    //system("cat");
    if( ans < p.ans )
      {
        ans = p.ans;
        for( i = 1 ; i <= n ; ++ i )
          for( j = 1 ; j <= m ; ++ j )
            opt[ i ][ j ] = p.sv[ i ][ j ];
      }
    //add
    //added = false ;
    for( i = 1 ; i <= n ; ++ i )
      for( j = 1 ; j <= m ; ++ j )
        if( p.sv[ i ][ j ] not_eq '.' or p.ans == 0 )
          for( dir = 0 ; dir < 4 ; ++ dir )
            for( k = 0 ; k < 4 ; ++ k )
              {
                ti = i + sr[ dir ] ; tj = j + sc[ dir ];
                if( check( ti , tj , p.sv , k ) )
                  {
                    //added = true ;
                    ++ rear;
                    q[ rear ].ans = p.ans + 1 ;
                    for( u = 1 ; u <= n ; ++ u )
                      for( v = 1 ; v <= m ; ++ v )
                        q[ rear ].sv[ u ][ v ] = p.sv[ u ][ v ];
                    for( u = 0 ; u < 3 ; ++ u )
                      for( v = 0 ; v < 3 ; ++ v )
                        if( q[ rear ].sv[ ti + u ][ tj + v ] == '.' and svk[ k ][ u ][ v ] )
                          q[ rear ].sv[ ti + u ][ tj + v ] = 'A' + q[ rear ].ans - 1 ;
                  }
              }
               
  }while( front < rear );

  //out
  cout<<ans<<"\n";
  for( i = 1 ; i <= n ; ++ i )
    {
      for( j = 1 ; j <= m ; ++ j )
        cout<<opt[ i ][ j ];
      cout<<"\n";
    }

  return ;
}

int main()
{

  init();

  bfs();
\
  return 0;
}
