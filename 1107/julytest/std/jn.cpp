/*
  CSU 2011 JULY CONTEST PROB N standrad
  write by gestapolur
  2011-07-10
*/
#include<iostream>
#include<cstring>
#define MAXS (1 << 19) + 1
using namespace std;

int tr[ MAXS ][ 128 ];
char s[ 1002 ];
int n , p , t , tt ;

void dfs( int x , int ad)
{
  char c;
  int r;
  for( int i = x ; i <= n ; ++ i )
    {
      c = s[ i ] ; r = tr[ ad ][ c ];
      if( r <= ( t << 19 ) )
	{
	  ++p;
	  tr[ ad ][ c ] = p | ( t << 19 );
	  ad = p;
	}
      else
	ad = r & (1 << 19) - 1 ;
    }
  return ;
}

int main()
{
  cin>>tt;
  t = 1 ;
  while( t <= tt )
    {
      cin>>s+1;
      p = 1 ;
      n = strlen( s + 1 );
      for(int i = 1 ; i <= n ; ++ i )
	dfs( i , 1 );
      cout<<p-1<<"\n";
      ++ t;
    }
  return 0;
}
