//CF#103 A
#include<iostream>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<vector>
#define MAXN 102
using namespace std;

int tmax , tmin , kmax , kmin ;
int a[ MAXN ] , n;

void init()
{
  cin>>n;
  tmin = MAXN + 1 ; tmax = 0 ;
  for( int i = 1 ; i <= n ; ++ i )
    {
      cin>>a[ i ];
      if( a[ i ] > tmax )
        { tmax = a[ i ] ; kmax = i ; }
      if( a[ i ] <= tmin )
        { tmin = a[ i ] ; kmin = i ; }
    }
  //cout<<kmax<<" "<<kmin<<"\n";
  int ans = kmax+n-kmin-1;
  if( kmax > kmin )
    -- ans;
  cout<<ans<<"\n";
  //cout<<kmax+n-kmin-2<<"\n";
  return ;
}

void work()
{
  return ;
}

int main()
{
  
  init();
  
  work();

  return 0;
}
