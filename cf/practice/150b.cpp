#include<iostream>
#define MOD 1000000007
using namespace std;

int n , m , k ;

int main()
{
  int tmp , cnt , ans ;

  cin>>n>>m>>k;
  if( n == k or k == 1 )
    {
      if( n == k )
        n >>= 1;
      ans = 1 ;
      while( n > 0 )
        {
          ans = ans * m % MOD ;
          -- n;
        }
      cout<<ans<<"\n";
    }
  else if( n < k )
    cout<<"1\n";
  else if( k % 2 == 1 )
    cout<< m * m % MOD <<"\n";
  else
    cout<<m<<"\n";
  
  return 0;
}
