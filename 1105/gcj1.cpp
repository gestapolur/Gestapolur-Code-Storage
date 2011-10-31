#include<fstream>
#include<string>
#define MAXN 100
using namespace std;

ifstream cin("B-large.in");
ofstream cout("ans.out");

int c,d,n,t;
bool opp[ MAXN ][ MAXN ];
char com[ MAXN ][ MAXN ];
int stp[ MAXN ];
char ch[ MAXN ];

void clr()
{
  int i,j;
  for(i = 0 ; i < MAXN ; ++ i)
    for(j = 0 ; j < MAXN ; ++ j)
      {
	com[ i ][ j ] = 0;
	opp[ i ][ j ] = 0;
      }
  return ;
}

bool op(char k , int pos)
{
  int p,i;
  
  p = stp[ 0 ];
  //cout<<"cmp "<<k<<" "<<pos<<" "<<p<<"\n";
  while(p > 0)
    {
      //cout<<"stack "<<ch[ stp[ p ] ]<<" "<<p<<"\n";
      if( opp[ k ][ ch[ stp[ p ] ] ] )
	{
	  for( i = 0 ; i <= pos ; ++ i)
	    ch[ i ] = ' ';
	  stp[ 0 ] = 0;
	  return true; 
	}
      -- p;
    }
  return false;
}

int main()
{
  int tt,i,j,notz;
  string tmp;
  cin>>t;
  tt = t;
  while(t > 0)
    {
      clr();
      cin>>c;
      for(i = 1 ; i <= c ; ++ i)
	{
	  cin>>tmp;
	  com[ tmp [ 0 ]][ 0 ] = com[ tmp[ 1 ]][ 0 ] = 1;
	  com[ tmp[ 0 ] ][ tmp[ 1 ] ] = tmp[ 2 ] ;
	  com[ tmp[ 1 ] ][ tmp[ 0 ] ] = tmp[ 2 ] ;
	  //cout<<com[ tmp[ 1 ] ][ tmp[ 0 ] ]<<" "<<int(tmp[1])<<" "<<int(tmp[0])<<"\n";
	}
      cin>>d;
      for(i = 1 ; i <= d ; ++ i)
	{
	  cin>>tmp;
	  opp[tmp[ 0 ]][ 0 ] = true ; opp[tmp[ 1 ]][ 0 ] = true;
	  opp[ tmp[ 0 ] ][ tmp[ 1 ] ] = true;
	  opp[ tmp[ 1 ] ][ tmp[ 0 ] ] = true;
	}

      cin>>n;
      for(i = 0 ; i < n ; ++ i)
	cin>>ch[ i ];

      stp[ 0 ] = 0 ;
      for(i = 0 ; i < n ; ++ i)
	{
	  //cout<<"q "<<com[ ch[ i ] ][ ch[ i - 1 ] ]<<" "<<int(ch[i])<<"\n";
	  notz = i - 1;
	  while(notz > 0 and ch[ notz ] == ' ') -- notz;
	  if(i > 0 and com[ ch[ i ] ][ ch[ notz ]] not_eq 0 )
	    {
	      ch[ i ] = com[ ch[ i ] ][ ch[ notz ] ];
	      ch[ notz ] = ' ';
	      if(notz > 0 and stp[ stp[ 0 ] ] == notz ) --stp[ 0 ];
	    }
	  else if((opp[ ch[ i ] ][ 0 ] == true ) and op(ch[ i ] , i ))
	    {}
	  else if(opp[ ch[ i ] ][ 0 ] == true)
		stp[ ++stp[ 0 ] ] = i;
	}
      cout<<"Case #"<<tt-t+1<<": [";
      bool pt = false;
      for(i = 0 ; i < n ; ++ i)
	if(ch[ i ] not_eq ' ')
	  {
	    if( pt ) cout<<", ";
	    cout<<ch[ i ];
	    pt = true;
	  }
      cout<<"]\n";
      --t;
    }
  return 0;
}
