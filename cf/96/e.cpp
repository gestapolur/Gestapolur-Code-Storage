#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#define MAXN 102   
using namespace std;

string s ;
int n , m , tur , cnt ;
int f[ MAXN ][ MAXN ] , w[ MAXN ] , v[ MAXN ] ;

void init()
{
  int i , j , st , tmp ;
  cin>>s;
  n = s.size();
  cin>>m;
  for( i = 0 ; i < n ; ++ i )
    if( s[ i ] == 'T' )
      ++ tur ;
  
  

  if( m >= tur )
    {
      tur = m - tur ;
      n = n - tur ;
      cout<<n<<"\n";
      return ;
    }
  
  for( i = 0 ; i < n ; ++ i )
    for( j = i + 1 ; j < n ; ++ j )
      for( k = i + 1 ; k < j ; ++ k )
        if( f[ i ][ j ] < max ( f[ i ][ k ] , f[ k ][ j ] ) )
        {
          
        }


  return ;
}

int main()
{
  
  init();

  return 0;
}
