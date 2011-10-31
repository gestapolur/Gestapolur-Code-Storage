/*
  AC automata
  2011-3-29
  input : 
  n : integer , as for n words ;
  next n lines : n words which characters were appeared in ASCALL 
  m : integer , as for m pattern ;
  next m lines : m patterns , which characters were appteared in ASCALL
  output : 
  
  by Gestapolur
*/
#include<iostream>
#include<string>
#define MAXN 1000000
#define APH 27
using namespace std;

class node
{
public:
  char ch;
  int child [ APH ];
  int par;
};

node tri[ MAXN ];
int top = 0;
int n,m;
int stack[ APH ][ MAXN ] , top[ APH ];

void add(char w , int par )
{
  tri[ ++ top].ch = w;
  tri[ top ].par = par;
  tri[ par ].child[ w - 'a' + 1] = top;
  stack[ w - 'a' + 1 ][ top[ 0 ] ++ ] = top ;
  return ;
}

void constr( string w )
{
  int i,t,p,pre;

  t = w.size();
  p = 0 , i = 0 ;

  while(i < t)
    {
      if(tri[ p ].child[ w[ i ] - 'a' + 1 ] == 0)
	{
	  add(w[ i ] , p );
	  p = top;
	}
      else
	p = tri[ p ].child[ w[ i ] - 'a' + 1 ];
      ++i;
    }

  return ;
}

void constr_ac()
{
  int i;
  for(i = 1 ; i <= 26 ; ++ i)
    if(top[])

}

void dis()
{
  int i,j;
  tri[ 0 ].ch = 'S';
  for(i = 0 ; i <= top ; ++ i)
    {
      cout<<tri[ i ].ch<<" : ";
      for(j = 1 ; j <= 26 ; ++ j)
	if(tri[ i ].child[ j ] not_eq 0)
	  cout<<tri[ tri[ i ].child[j] ].ch<<" ";
      cout<<"\n";
    }
  return ;
}

void init()
{
  int i;
  string tmp;

  tri[ 0 ].ch = ' ';

  cin>>n;
  for( i = 1 ; i <= n ; ++ i)
    {
      cin>>tmp;
      constr( tmp );
      dis();
    }
  //dis();
  return ;
}

int main()
{
  init();
  return 0;
}
