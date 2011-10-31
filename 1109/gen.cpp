#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;

int main()
{
  srand( time( 0 ) );
  for( int  i = 1 ; i <= 8 ; ++ i )
    cout<<rand()%100<<" ";
  cout<<"\n";
  return 0;
}
