#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#define MAXN 1002
using namespace std;

class aclass
{
public:
  int first , second;
};

int n;
queue<aclass> test;

void init()
{
  //cin>>n;
  test.push_back( 1 , 2 );
  cout<<test.front->first<<" "<<test.front->second<<"\n";
  return ;
}

int main()
{
  init();
  
  return 0;
}
