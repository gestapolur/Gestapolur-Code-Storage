#include<iostream>
#define MAXN 2000000
using namespace std;

int n,m;
int f[ MAXN ];
int a[ 12 ];
int state;

int main()
{
  int i,j,r,tmp;

  cin>>n>>m;
  for(i = 0 ; i < n ; ++ i)
    a[ 0 ] = a[ 0 ] | ( 1 << i);
  for(i = 1 ; i <= n ; ++ i)
    a[ i ] = a[ i - 1];
  //cout<<a[ 0 ]<<"\n";
  //return 0;
  for(i = 1 ; i <= m ; ++ i)
    {
      cin>>tmp;      
      for(j = 1 ;j <= tmp ; ++ j)
	{
	  cin>>r;
	  a[ i ] = a[ i ] & ~(1 << (r - 1));
	}
    }
  
  for(i = 0 ; i < n ; ++ i)
    state = state | ( 1 << i);

  f[ 0 ] = 1;
  cout<<state<<"\n";
  for(i = 1 ; i <= state ; ++ i)
    {
      r = 0;
      for(j = 1 ; j <= n ; ++ j)
	if( i >> (j - 1) & 1 )
	  ++r;
      tmp = a[ r ] & i;
      cout<<tmp<<" "<<i<<" "<<r<<" "<<a[ r ]<<" add list : ";
      for(j = 1 ; j <= n ; ++ j)
	{
	  cout<<(tmp^(tmp<<(j-1)))<<" ";//if condition is 3 , what is the move ? 
	  if(tmp >> (j - 1 ) & 1 == 1)
	    {f[ tmp ] = f[ tmp ] + f[ tmp ^ (tmp << (j - 1)) ];cout<<"! ";}
	}
      cout<<" state : "<<f[ tmp ]<<"\n";
    } 

  cout<<f[ state ]<<"\n";

  return 0;
}
