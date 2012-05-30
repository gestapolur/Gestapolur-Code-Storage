#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cstdio>

using namespace std;

void init()
{
  string t;
  cin>>t;
  for( int i = t.size() - 1 ; i >= 0 ; -- i )
    if( t[ i ] == 'H' or t[ i ] == 'Q' or t[ i ] == '9' ) {cout<<"YES\n";return;}
  cout<<"NO\n";
  return ;
}

int main()
{
  
  init();

  return 0;
}
