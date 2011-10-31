#include<iostream>
#include<string>
using namespace std;

class NetworkXZeroOne
{
public:
  string reconstruct(string message)
  {
    int n = message.size() , i , x = -1 ;
    for( i = 0 ; i < n ; ++ i )
      if( message[ i ] not_eq '?' )
	{x = i ;break;}
    if( x == -1 )
      {
	for( i = 0 ; i < n ; ++ i )
	  if( i % 2 == 0 ) message[ i ] = 'o';
	  else message[ i ] = 'x';
      }
    else
      {
	for( i = x - 1 ; i >= 0 ; -- i )
	  if( message[ i + 1 ] == 'x' ) message[ i ] = 'o';
	  else message[ i ] = 'x';
	for( i = x + 1 ; i < n ; ++ i )
	  if( message[ i - 1 ] == 'x' ) message[ i ] = 'o';
	  else message[ i ] = 'x';
      }
    return message;
  }
};


int main()
{
  return 0;
}
