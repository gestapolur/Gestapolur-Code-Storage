#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#define MAXN 1002
#define ZERO 0.00000001
using namespace std;

int n;
double h[ MAXN ] , a[ MAXN ] , b[ MAXN ] , k , t1 , t2;
int mark[ MAXN ];
bool sync_with_stdio( bool sync = false );

void init()
{
  cin>>n>>t1>>t2>>k;
  for( int i = 1 ; i <= n ; ++ i )
    {
      cin>>a[ i ]>>b[ i ];
      mark[ i ] = i;
    }
  return ;
}

void work()
{
  int i , j;
  double tmpa , tmpb;
  int t;

  cout.setf(ios::fixed|ios::showpoint);
  cout.precision( 2 );
  
  for( i = 1 ; i <= n ; ++ i )
    {
      tmpa = a[ i ] * t1 * ( 1.0000 - ( k / 100.0000 ) ) + b[ i ] * t2;
      tmpb = b[ i ] * t1 * ( 1.0000 - ( k / 100.0000 ) ) + a[ i ] * t2;
      h[ i ] = tmpa > tmpb ? tmpa : tmpb;
    }
  
  //for( i = 1 ; i <= n ; ++ i ) cout<<h[ i ]<<" "; cout<<"\n";

  for( i = 1 ; i <= n ; ++ i )
    for( j = i + 1  ; j <= n ; ++ j )
      if( h[ j ] - h[ i ] > 0 or ( fabs( h[ j ] - h[ i ] ) < ZERO and mark[ j ] < mark[ i ] ) )
        {
          t = mark[ i ]; mark[ i ] = mark[ j ]; mark[ j ] = t;
          tmpa = h[ i ]; h[ i ] = h[ j ]; h[ j ] = tmpa;
        }

  for( i = 1 ; i <= n ; ++ i )
    cout<<mark[ i ]<<" "<<h[ i ]<<"\n";
}

int main()
{
  init();
  
  work();

  return 0;
}
