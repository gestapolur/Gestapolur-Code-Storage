#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
using namespace std;

class FortunateNumbers
{
public:
  bool work( long long x )
  {
    int y ;
    while( x > 0 )
      {
	y = x - x / 10 * 10;
	if( y not_eq 5 or y not_eq 7 ) return false;
	x /= 10;
      }
    return true;
  }
  int getFortunate(vector <int> a, vector <int> b, vector <int> c)
  {
    int sa , sb , sc;
    int i , j , k ;
    int cnt = 0 ;
    sa = a.size(); sb = b.size() ; sc = c.size();
    for( i = 0 ; i < sa ; ++ i )
      for( j = 0 ; j < sb ; ++ j )
	for( k = 0 ; k < sc ; ++ k )
	  if( work(a[ i ] + b[ j ] + c[ k ] ) )
	    ++cnt;
    return cnt;
  }
};

int main()
{
  return ;
}
