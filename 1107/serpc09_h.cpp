//SERPC 09 H 
#include<iostream>
#include<string>
using namespace std;

string a,b;
int t;

int cnt

inline bool cmp(string a , string b )
{
  if( a.size() > b.size()) return true;
}

void dfs(string x )
{
  if( cmp( x , b ) ) return ;
  if( cmp( x , a ) );
  return ;
}

int main()
{
  cin>>t;
  while( -- t)
    {
      cin>>a>>b;
      dfs("4");
      dfs("7");
    }
  return 0;
}
