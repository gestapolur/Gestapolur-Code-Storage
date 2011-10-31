#include<iostream>
#include<cstring>
#define MAXN 1012
using namespace std;

int f[ MAXN ];
int a[ MAXN ] , b[ MAXN ] , c[ MAXN ] , d[ MAXN ];
int n ;

void init()
{
  for( int i = 1 ; i <= n ; ++ i )
    {
      cin>>a[ i ]>>b[ i ]>>c[ i ]>>d[ i ];
    }
  return ; 
}

void dp()
{
  int i , j ;
  memset( f , 0  ,sizeof( f ) );

  for( i = 1 ; i <= n; ++ i )
    {
      for( j = 1 ; j < i ; ++ j )
	 {
	   if(d[ i ] == 0 and  f[ i ] < f[ j ] + c[ i ] and a[ j ] <= a[ i ] and b[ j ] <= b[ i ] )
	     f[ i ] = f[ j ] + c[ i ] ;
	   else if(d[ i ] == 1 and f[ i ] < f[ j ] + c[ i ] and a[ j ] <= a[ i ] and b[ j ] <= b[ i ] and a[ i ] * b[ i ] < a[ i ] * b[ j ])
	     f[ i ] = f[ j ] + c[ i ];
	   else if(d[ i ] == 2 and f[ i ] < f[ j ] + c[ i ] and a[ j ] < a[ i ] and b[ j ] < a[ i ] )
	     f[ i ] = f[ j ] + c[ i ] ;
	}
    }
  cout<<f[ n ]<<"-\n";
  return ;
}

int main()
{
  while( cin>>n and n not_eq 0 )
    {
      init();
      
      dp();
     
    }

}
