#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;

char ch[ 20 ];

int main()
{
  int n,i;
  cin>>n;
  cin.get();
  for(i = 1 ; i <= n ; ++ i)
    ch[ i ] = cin.get();
  
  for(i = 1 ; i <= n ; ++ i)
    cout<<ch[ i ];
  cout<<"-\n";
  
  return 0;
}
