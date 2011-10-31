//binary index tree
#include<iostream>
#define MAXN 1001
using namespace std;

int c[MAXN],a[MAXN];
int n;

//int lowbit(int a) {return a&(-a);}
int lowbit(int a) {return a & (a ^ (a - 1));}

void modify(int p,int delta)
{
  while (p<=n)
    {
      c[p]+=delta;
      p+=lowbit(p);
    }
}

int sum(int p)
{
  int rs = 0;
  while (p > 0)
    {
      rs += c[ p ];
      p -= lowbit( p );
    }
  return rs;
}

int main()
{
  int i,j,ins,pos;
  cin>>n;
  for(i = 1 ; i <= n ; ++ i)
    {
      cin>>a[ i ];
      for(j =  i - lowbit(i) + 1 ; j <= n ; ++ j )
	c[ i ]+=a[ j ];
    }
  
  //test
  while( 1 )
    {
      cin>>ins;
      if(ins == 1)
	{
	  cin>>pos>>ins;
	  modify( pos , ins );
	}
      else
	{
	  cin>>pos;
	  cout<<sum( pos )<<"\n";
	}
    }
  return 0;
}
