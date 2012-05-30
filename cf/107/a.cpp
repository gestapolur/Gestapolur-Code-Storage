#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#define MAXN 1002
using namespace std;

int min( int a , int b ){ return a < b ? a : b ; }

void init()
{
  int n, k, l, c, d, p, nl, np;
  
  cin>>n>>k>>l>>c>>d>>p>>nl>>np;
  
  l = l * k;

  c = c * d;

  int tot ;

  tot = min( l / nl , p / np );
  
  tot = min( c , tot );

  cout<<tot/n<<"\n";

  return ;
}

int main()
{
  
  init();

  return 0;
}
