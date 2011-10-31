#include<cstdlib>
#include<cstdio>
#define MAXN 22002
#define MAXP 250000
#define MOD 1000000000
using namespace std;

int p[ MAXN ];
bool a[ MAXP + 2 ];

void genp()
{
  int i , j , k = 2 ;
  int cnt = 0 ;
  while( cnt <= 22000 )
    {
      while( a[ k ] ) ++ k ;
      p[ ++ cnt ] = k ;
      i = k ; j = 2 ;
      while( i < MAXP)
        {
          a[ i ] = true;
          i = k * j ;
          ++ j ;
        }    
    }
  return ;
}


int main()
{
  int n; 
  genp();
  while( scanf( "%d" , &n ) )
    {
      if( n == 0 ) return 0 ;
      else if( n == 1  ) printf("2\n");
      else if( n == 2 ) printf("3\n");
      else
        {
          int a = 1 , b = 1 , c = 2 , t ;
          while( c < p[ n ] )
            { 
              t = b ;
              b = ( a + b ) % MOD ;
              a = t ;
              ++ c ;
            }
          printf( "%d\n" , b ) ;
        }
    }
  return 0;
}
