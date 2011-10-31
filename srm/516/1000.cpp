#include<iostream>
#include<vector>
#include<string>
#define MAXN 52
using namespace std;

int f[ MAXN ][ MAXN * MAXN ];

class NetworkXMessageRecovery
{
public:
  string recover(vector <string> m)
  {
    int n , la , lb ;
    int i , j ;
    string ans = "" , tmp ;
    
    n = m.size();
    for( i = 0 ; i < n - 1 ; ++ i )
      for( j = i + 1 ; j < n ; ++ j )
	if( m[ i ] > m[ j ] )
	  { tmp = m[ i ] ; m[ i ] = m[ j ] ; m[ j ] = tmp ; }
    
    for( i = 0 ; i < n - 1 ; ++ i )
      for( j = i + 1 ; j < n ; ++ j )
	w[ i ][ j ] = w[ j ][ i ] = bin( m[ i ] , m[ j ]);
    
    for( i = 0 ; i < n ; ++ i )
      for( j = 0 ; j < n ; ++ i )
	f[][

    return ans;
  }
};


NetworkXMessageRecovery test;

int main()
{
  vector < string > k ;
  k.push_back("acd");
  k.push_back("bce");
  cout<<test.recover( k )<<"\n";
  return 0;
}
