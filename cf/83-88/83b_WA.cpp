#include<iostream>
#include<algorithm>
using namespace std;

int a[ 100002 ] ;
int n;

int main()
{
  int i , j;
  cin>>n;
  for( i = 1 ; i <= n ; ++ i )
    cin>>a[ i ];
  sort( a + 1 , a + n + 1 );
  //for( i = 1 ; i <= n ; ++ i ) cout<<a[ i ]<<" ";cout<<"\n";
  for( i = 1 ; i < n ; ++ i )
    for( j = n ; j > i ; -- j )
      if( a[ i ] not_eq a[ j ] and a[ i ] * 2 > a[ j ] )
	{cout<<"YES\n";goto end;}
      else break;
  cout<<"NO\n";
 end:;
  return 0;
}
