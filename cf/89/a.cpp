#include<iostream>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<vector>
using namespace std;

string a ;
int n ;

int main()
{
  int i , j; 
  cin>>a;
  n = a.size();
  for( i = 0 ; i < n ; ++ i )
    {
      if( a[ i ] == 'A' or a[ i ] == 'E' or a[ i ] == 'I' or a[ i ] == 'O' or a[ i ] == 'U' or a[ i ] == 'Y' or a[ i ] == 'a' or a[ i ] == 'e' or a[ i ] == 'i' or a[ i ] == 'o' or a[ i ] == 'u' or a[ i ] == 'y'  )
        {}
      else if( a[ i ] >= 'A' and a[ i ] <= 'Z' )
        cout<<"."<<char(a[ i ] + 32 );
      else
        cout<<"."<<char(a[ i ]);
    }
  cout<<"\n";
  return 0;
}
