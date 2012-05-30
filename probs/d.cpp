//117 DIV2
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#define MAXN 1002
using namespace std;

int n;
string a , b;
int lena , lenb;

void init()
{
  string t;
  cin>>a>>b;
  if( a.size() > b.size() )
    { t = a ; a = b ; b = t; }
  lena = a.size();
  lenb = b.size();

  return ;
}

void work()
{
  int i , j , tmp;
  for( i = 0 ; i < lena ; ++ i )
    {
      tmp = lena;
      while( tmp )
        {
          tmp >>=1;
        }
    }
  return ;
}

int main()
{
  init();

  work();
  
  return 0;
}
