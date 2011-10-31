#include<iostream>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<cstdio>
using namespace std;

void init()
{
  string k;
  int n , four = 0 , sev = 0 ;
  cin>>k;
  n = k.size();
  for( int i = 0 ; i < n ; ++ i )
    if( k[ i ] == '4' ) ++ four;
    else if( k[ i ] == '7' ) ++ sev;
  if( four == 0 and sev == 0 ) cout<<"-1\n";
  else if( four >= sev ) cout<<"4\n";
  else cout<<"7\n";
}

int main()
{
  init();
  return 0;
}
