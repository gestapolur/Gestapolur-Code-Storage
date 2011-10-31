//#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
using namespace std;


ifstream cin("input.txt");
ofstream cout("output.txt");

int n , m , tot; 

int main()
{
  int i ;
  cin>>n;
  for( i = 1 ; i <= n ; ++ i )
    {
      cin>>m;
      if( m % 2 == 0 ) cout<<"1\n";
      else cout<<"0\n";
    }
  return 0;
}
