#include<iostream>
using namespace std;

int main()
{
  int n , m , i , j ;
  n = 300 , m = 1500;
  cout<<n<<" "<<m<<"\n";
  for( i = 1 ; i <= n ; ++ i )
    {
      for( j = 1 ; j <= m ; ++ j )
        if( ( i + j ) % 2 ) cout<<1;
        else cout<<0;
      cout<<"\n";
    }
  return 0;
}
