#include<fstream>
#include<cstdlib>
#include<cstdio>
#define MAXN 1000
using namespace std;

ofstream cout("stp.in");

int n,m;
bool w[ MAXN ][ MAXN ];

int main()
{
  
  int i,u,v,val;
  srand( MAXN );
  n = rand() % MAXN + 1 ;
  m = rand() % ( n * n - n ) + n;
  cout<<n<<" "<<m<<"\n";
  for(i = 1 ; i <= m ; ++ i )
    {
      do{
	u = rand() % n + 1 ;
	v = rand() % n + 1 ;
      }while(w[ u ][ v ] or u == v );
      w[ u ][ v ] = w[ v ][ u ] = true;
      cout<<u<<" "<<v<<" "<<rand()%MAXN+1<<"\n";
    }

  return 0;
}
