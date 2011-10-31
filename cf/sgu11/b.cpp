//#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#define MAXN 1002
using namespace std;

ifstream cin("input.txt");
ofstream cout("output.txt");

int n , k;
bool a[ MAXN ];

int main()
{
  int i; 
  cin>>n>>k;
  for ( i = 1 ; i <= n ; ++i )
    cin>>a[ i ];
  while( 1 )
    {
      if( a[ k ] == 1 ) { cout<<k<<"\n"; break;}
      else ++ k ;
      if( k > n ) k = 1 ;
    }
  return 0;
}
