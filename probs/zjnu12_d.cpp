/*
  2012 ACM-ICPC JINHUA INVITED PROB D Garden
  BIT TREE ( TLE )
  2012-05-09
*/
#include<cstdlib>
#include<cstdio>
#include<cstring>
#define MAXN 200005
#define INF 2141483647
//using namespace std;

int n , m , wide;
int idt[ MAXN ] , a[ MAXN ];

inline int L( int k )
{ return ( k & -k ); }

inline int getsum( int idx )
{
  int s = 0;
  while( idx )
    {
      s += idt[ idx ];
      idx -= L( idx );
    }
  return s;
}

inline void bit_update( int idx , int del )
{
  while( idx <= n )
    {
      idt[ idx ] += del;
      idx += L( idx );
    }
  return ;
}

void init()
{
  int i , ins , sx , sy , ans , del , tmp , k;
  
  //memset( idt , 0 , sizeof( idt ) );
  //memset( a , 0 , sizeof( a ) );

  //cin>>n>>m>>wide;
  scanf( "%d%d%d" , &n , &m , &wide );
  
  for( i = 1 ; i <= n ; ++ i )
    idt[ i ] = 0;

  for( i = 1 ; i <= n ; ++ i )
    {
      scanf( "%d" , &a[ i ] );
      bit_update( i , a[ i ] );
    }

  for( i = 1 ; i <= m ; ++ i )
    {
      scanf( "%d%d%d" , &ins , &sx , &sy );
      //cin>>ins>>sx>>sy;
      if( not ins )
        {
          bit_update( sx , sy - a[ sx ] );
          a[ sx ] = sy;
        }
      else if( ins == 1 )
        {
          bit_update( sx , a[ sy ] - a[ sx ] );
          bit_update( sy , a[ sx ] - a[ sy ] );
          tmp = a[ sx ];
          a[ sx ] = a[ sy ];
          a[ sy ] = a[ sx ];
          
        }
      else
        {
          ans = -INF;
          for( k = sy - wide + 1 ; k >= sx ; -- k )
            {
              del = getsum( k + wide - 1 ) - getsum( k - 1 );
              ans = ans > del ? ans : del;
            }
          printf( "%d\n" , ans );
          //cout<<ans<<"\n";
        }
    }
 
  return ;
}

int main()
{
  int t;
  scanf( "%d" , &t );

  while( t -- )
    init();
  return 0;
}
