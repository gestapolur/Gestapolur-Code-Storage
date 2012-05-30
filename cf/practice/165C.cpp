#include<iostream>
#include<cstring>
#define MAXN 10000005
using namespace std;

int n , m , k;
char ch[ MAXN ];
long long s[ MAXN ] , cnt[ MAXN ];
long long ans;

void init()
{
  cin>>k>>ch+1;
  n = strlen( ch + 1 ); 
  cnt[ 0 ] = 1;
  for( int i = 1 ; i <= n ; ++ i )
    {
      s[ i ] = s[ i - 1 ] + ch[ i ] - 48;
      ++ cnt[ s[ i ] ];
      m = s[ i ] > m ? s[ i ] : m;
      //cout<<s[ i ]<<" ";
    }
  //cout<<"\n";
  //for( int i = 0 ; i <= m ; ++ i ) cout<<cnt[ i ]<<" "; cout<<"\n";
  return ;
}

void count()
{ 
  for( int i = 0 ; i <= m ; ++ i )
    if( i - k >= 0 )
      {
        //cout<<cnt[ i - k ]<<" "<<cnt[ i ]<<"\n";
        if( i - k not_eq i )
          ans = ans + ( long long ) ( cnt[ i - k ] * cnt[ i ] );
        else
          ans = ans + ( long long ) ( cnt[ i ] * ( cnt[ i ] - 1 ) / 2 );
      }
  cout<<ans<<"\n";

  return ;
}

int main()
{
  init();

  count();

  return 0;
}
