//#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cstdio>
using namespace std;

ifstream cin("input.txt");
ofstream cout("output.txt");

int main()
{
  string ch;
  int x ;
  cin>>ch>>x ;
  if( ( ch == "front" and x == 1 ) or ( ch == "back" and x == 2 ) )
    cout<<"L\n";
  else cout<<"R\n";
  return 0;
}
