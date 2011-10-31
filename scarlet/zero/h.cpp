#include<iostream>
#define MAXN 100006
using namespace std;

long double a[ MAXN ];
bool hash[ MAXN ];
int n , cnt ;

int main()
{
  int i , j ;
  while( cin>>n )
    {
      for( i = 1 ; i <= n ; ++ i )
        {
          cin>>a[ i ];
          hash[ i ] = false ;
        }
      cnt = 0 ;
      for( i = 1 ; i <= n ;  )
        {
          if( hash[ i ] ) ++ i ;
          else
            {
              hash[ i ] = true;
              j = i + 1 ;
              while( a[ i ] + 1.0000000000 - a[ j ] > 1e-12 )
                {
                  hash[ j ] = true ;
                  ++ j ;
                }
              ++ cnt ;
            }
        }
      cout<<cnt<<"\n";
    }
  return 0;
}
