//binary index tree
#include<fstream>
#define MAXN 100001
using namespace std;

ifstream cin("pasture.in");
ofstream cout("pasture.out");

int c[MAXN],a[MAXN];
int n;

int abs(int a){ return a > 0 ? a : -a ;}

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
  int i,j,tmp;
  int sta,edg,ans = 2141483647;
  cin>>n;
  for(i = 1 ; i <= n ; ++ i)
    {
      cin>>a[ i ];
      for(j =  i - lowbit(i) + 1 ; j <= n ; ++ j )
	c[ i ]+=a[ j ];
    }
  
  //test
  for(i = 1 ;i <= n ; ++ i)
    for(j = i ; j <= n ; ++ j)
      {
	tmp = abs(sum(j) - sum(i - 1));
	if( tmp < ans or (tmp == ans and j - i > edg - sta))
	  {ans = tmp ; sta = i , edg = j;}
      }

  cout<<sta<<" "<<edg<<" "<<ans<<"\n";
  cin.close();
  cout.close();
  return 0;
}
