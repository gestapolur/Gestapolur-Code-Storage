//uva 303 gen
#include<iostream>
#include<cstdlib>
#include<cstdio>
#define MAXL 1000000
using namespace std;

int main()
{
  double xi , yi;
  int n = 20 , cnt = 0 ;
  srand( time( 0 ) );
  while( cnt < 20 )
    {
      cout<<n<<"\n";
      xi = 0 ;
      for( int i = 1 ; i <= n ; ++ i )
        {
          xi = xi + rand() % MAXL + 1 ;
          yi = rand()%MAXL;
          cout<<xi<<" "<<yi<<"\n";
        }
      ++ cnt; 
    }
  cout<<"0\n";
  return 0;
}
