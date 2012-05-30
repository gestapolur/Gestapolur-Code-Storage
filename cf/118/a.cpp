#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#define MAXN 1002
using namespace std;

int n , m;
bool sync_with_stdio( bool sync = false );
string s , t;

void work()
{
  int i;
  cin>>s>>t;
  n = s.size();
  m = t.size();
  if( n not_eq m )
    cout<<"NO\n";
  else
    {
      
      int fi = -1, si = -1;
      for( i = 0 ; i < n ; ++ i )
        if( s[ i ] not_eq t[ i ] )
          {
            if( fi < 0 )
              fi = i;
            else if( si < 0 )
              si = i;
            else
              { cout<<"NO\n"; return ; }
          }
      if( si >= 0 and fi >= 0 and s[ si ] == t[ fi ] and s[ fi ] == t[ si ] )
        cout<<"YES\n";
      else
        cout<<"NO\n";
    }
  return ;
}

int main()
{
  work();
  
  return 0;
}
