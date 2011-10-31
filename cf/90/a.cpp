//CF#90 A
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cstdio>
using namespace std;

int gcd( int a , int b )
{
  int t ;
  do{
    if( b == 0 ) return a ;
    if( a % b == 0 ) return b ;
    t = a % b ;
    a = b ; b = t ;
  }while( b not_eq 0 );
}

int main()
{
  int ma , mb , a , b , n ; 
  bool turn = true ;
  //cin>>a>>b>>n;
  scanf("%d%d%d" , &a , &b , &n );
  
  do{
    if( turn )
      {
        if( n > a )
          ma = gcd( n , a );
        else ma = gcd( a , n );
      }
    else 
      {
        if( n > b )
          ma = gcd( n , b );
        else
          ma = gcd( b , n );
      }
    if( ma > n ) break;
    //cout<<ma<<" "<<turn<<" "<<n<<"\n";
    n -= ma ;
    turn = ( turn xor 1 ) ;
  }while( 1 );

  if( turn ) printf("1\n");
  else printf("0\n");

  return 0;
}
