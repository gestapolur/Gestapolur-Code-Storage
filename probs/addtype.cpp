#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
#define MAXD 102
using namespace std;

int main()
{
  string cc;
  getline( cin , cc );
  cout<<cc<<"\n";
  for( int i = 0 ; i < cc.size() ; ++ i ) cout<<char(cc[ i ])<<"-"; cout<<"\n";
  
  return 0;
}
