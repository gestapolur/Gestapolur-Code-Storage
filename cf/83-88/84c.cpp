#include<iostream>
using namespace std;

int n , ans , dig = 2141483647;

bool bfs()
{
  int i , tnf;
  tnf = n / 4 ;
  for( i = tnf + 1 ; i >= 0 ; -- i )
    if( n - i * 4 >= 0 and ( n - i * 4 ) % 7 == 0 and dig > ( i + ( n - i * 4 ) / 7 ) )
      { ans = i ; dig = (i + ( n - i * 4 ) / 7) ; }
  return dig < 2141483647 ;
}

void con()
{
  int i ;
  for( i = 1 ; i <= ans ; ++ i ) cout<<4;
  //cout<<ans<<"\n";
  ans = ( n - ans * 4 ) / 7 ;
  //cout<<ans<<"\n";
  for( i = 1 ; i <= ans ; ++ i ) cout<<7;
  cout<<"\n";
  return ;
}

int main()
{
  cin>>n;
  //for( n = 1 ; n <= 1000000 ; ++ n )
    if(bfs()) 
      con();
    else cout<<"-1\n";

  return 0;
}
