#include<iostream>
#define MAXN 22002
using namespace std;

int p[ MAXN ];
bool a[ MAXP ];

int main()
{
  int i , j , k = 2 ;
  int cnt = 0 ;
  while( cnt <= 22000 )
    {
      while( a[ k ] ) ++ k ;
      cout<<k<<",";
      ++ cnt;
      //cout<<cnt<<"\n";
      i = k ; j = 2 ;
      while( i < 50000000)
        {
          a[ i ] = true;
          i = k * j ;
          ++ j ;
        }
      
    }
  cout<<"\n";
  /*
  for( i = 1 ; i <= cnt ; ++ i )
    cout<<p[ i ]<<" ";
  cout<<"\n";
  */
  return 0;
}
