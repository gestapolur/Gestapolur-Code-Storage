#include<iostream>
#include<algorithm>
#define MAXN 100005
#define MOD 1000000007
using namespace std;

int n , m ;
long long f[ MAXN ];

void init()
{
  int i;
  cin>>n>>m;
  for( i = 1 ; i <= n ; ++ i )
    cin>>f[ i ];
  sort( f + 1 , f + n + 1 );
  return ;
}

void dp()
{
  long long i , j , k , tmp;
  if( m <= n )
    {

      if( m < n )
        for( i = 1 ; i <= m ; ++ i )
          f[ i ] ++;
      else
        for( i = 1 ; i <= n ; ++ i )
          f[ i ] ++ ;

      for( i = 2 ; i <= n ; ++ i )
        f[ i ] = f[ i - 1 ] * f[ i ] % MOD;
      f[ n ] = f[ n ] % MOD ;
      //cout<<f[ n ]<<"\n";
    }
  else
    {
      tmp = m % 3;
      for( i = 1 ; i <= n ; ++ i )
        f[ i ] += 3;
      for( i = 2 ; i <= n ; ++ i )
        f[ i ] = ( f[ i - 1 ] ) * f[ i ] % MOD ;

      for( i = tmp - n ; i > 0 ; -- i )
        f[ n ] = ( f[ n ] * 3 ) % MOD ;
    }

  cout<<f[ n ]<<"\n";

  return ;
}

int main()
{
  int t , tt ;

  cin>>t;
  tt = 0 ;

  while( t -- )
    {
      ++ tt;
      
      init();
      
      cout<<"Case "<<tt<<":\n";
      
      dp();

    }
  return 0;
}
