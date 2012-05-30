#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#define MAXN 100005
using namespace std;

int n;
int s[ MAXN ];
int one , two , three , four ;

void init()
{
  cin>>n;
  int tmp;
  for( int i = 1 ; i <= n ; ++ i )
    {
      cin>>tmp;
      if( tmp == 1 ) ++ one;
      else if( tmp == 2 ) ++ two;
      else if( tmp == 3 ) ++ three;
      else ++ four;
    }
  return ;
}

void work()
{
  int tmp;
  four += ( one < three ? one : three ) + ( two >> 1 ) ; 
  
  tmp = one;
  one -= three;
  two = two % 2 ? 1 : 0 ;
  three -= tmp;
  //cout<<one<<" "<<two<<" "<<three<<" "<<four<<"\n";
  if( one > 0 and two > 0 )
    { ++ four ; -- two ; one -= 2 ;}
  if( one > 0 )
    four += one / 4 + ( one % 4 ? 1 : 0 );
  if( two > 0 )
    four += two;
  if( three > 0 )
    four += three ;

  cout<<four<<"\n";

  return ;
}

int main()
{
  init();
  
  work();

  return 0;
}
