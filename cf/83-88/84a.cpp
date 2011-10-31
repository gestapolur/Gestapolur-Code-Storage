//CF#84 A
#include<iostream>
#include<string>
using namespace std;

unsigned long long n;

int main()
{
  unsigned long long cnt = 0 ;
  cin>>n;
  while( n > 0 )
    {
      if( (long long) (n % 10) == 4 or (long long) ( n % 10) == 7 )
	++ cnt;
      n /= 10;
    }
  //cout<<cnt<<"\n";
  if( cnt == 0 ) {cout<<"NO\n";return 0;}
  while( cnt > 0 )
    {
      if( ( long long ) ( cnt % 10 ) not_eq 4 and ( long long ) ( cnt % 10 ) not_eq 7 ) 
	{ cout<<"NO\n"; return 0 ;}
      cnt /= 10 ;
    }
  cout<<"YES\n";
  return 0;
}
