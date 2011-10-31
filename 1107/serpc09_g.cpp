//SERPC 09 G
#include<iostream>
#include<string>
#define MAXN 1001
using namespace std;

string a , b , ans ;
int n,m;

void seek( int pa , int pb , string x )
{
  if(a[ pa ] == b[ pb ])
    seek( pa + 1 , pb + 1 , x + a[ pa ] );
  else if()
    {}
  else if( pa == m - 1 and (x.size() < ans.size() or x < ans ) )
    ans = x;
  return ;
}

int main()
{
  int i;
  while( cin>>a>>b )
    {
      ans = "";
      m = a.size();
      n = b.size();
      len = MAXN ;
      for( i = 0 ; i <= n - m  ; ++ i )
	seek( 0 , i , "" );
      cout<<len<<"\n";
    }
  return 0;
}
