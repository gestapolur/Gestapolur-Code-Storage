//cf#99 A
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;

int r1 , r2 , d1 , d2 , c1 , c2 ;
int a , b , c , d;

void init()
{
  cin>>r1>>r2>>c1>>c2>>d1>>d2;
  return ;
}

void work()
{
  bool pat = false ;
  for( a = 1 ; a <= 9 ; ++ a )
    for( b = 1 ; b <= 9 ; ++ b )
      for( c = 1 ; c <= 9 ; ++ c )
        for( d = 1 ; d <= 9 ; ++ d )
          if( a not_eq b and a not_eq c and a not_eq d and b not_eq c and b not_eq d and c not_eq d )
          if( a + b == r1 and c + d  == r2 and a + c == c1 and b + d == c2 and a + d == d1 and b + c == d2 )
            {cout<<a<<" "<<b<<"\n"<<c<<" "<<d<<"\n"; return ;}
  cout<<"-1\n";
  return ;
}

int main()
{

  init();

  work();

  return 0;
}
