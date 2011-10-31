#include<iostream>
#define MAXN 100005
using namespace std;

int n;
char ch[ MAXN ];

int main()
{
  int i , j ;
  char c;
  cin>>n;
  c = 'a';
  for( i = 1;  i <= n ; ++ i ) ch[ i ] = ' ';
  i = 1 ;
  while( i <= n )
    {
      if( ch[ i ] == ' ')
	{
	  j = i ;
	  while( j <= n )
	    {
	      ch[ j ] = c;
	      j += 4;
	    }
	  ++ c;
	}
      ++ i ;
    }
  for( i = 1 ; i <= n ; ++ i ) cout<<ch[ i ];
  cout<<"\n";
  return 0;
}
