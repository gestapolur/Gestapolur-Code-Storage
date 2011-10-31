#include<iostream>
#define MAXN 1001
using namespace std;

int a[ MAXN ] , b[ MAXN ] , c[ MAXN ];
int n,m;

int main()
{
  int i;
  cin>>n;
  for( i = 1 ; i <= n ; ++ i )
    {
      cin>>a[ i ];
      m = m > a[ i ] ? m : a[ i ];
    }
    

  for( i = 1 ; i <= n ; ++ i )
    ++ b[ a[ i ] ];
  for( i = 1 ; i <= m ; ++ i )
    b[ i ] += b[ i - 1 ];
  for( i = n ; i >= 1 ; -- i )
    c[ b[ a[ i ] ] -- ] = i ;
  for( i = 1 ; i <= n ; ++ i )
    cout<<c[ i ]<<" ";
  cout<<"\n";
  for( i = 1 ;i <= n ; ++ i )
    cout<<a[ c[ i ] ]<<" ";
  cout<<"\n";
  return 0;
}
