#include<fstream>
#include<cstdlib>
#include<cstdio>
#define MAXN 20
using namespace std;

ofstream cout("testm.in",ios::binary);

int main()
{
  int n, m ;
  cout<<"100\n";
  srand( 1000 );
  cout<<1<<" "<<0<<"\n";cout<<3<<"\n";
  cout<<10<<" "<<0<<"\n";cout<<"1234567890\n";
  for(int i = 3 ; i <= 100 ; ++ i)
    {
      n = rand() % ( MAXN - 1 ) + 2 ;
      m = rand() % ( n - 1 ) + 1;
      cout<<n<<" "<<m<<"\n";
      for( int j = 1 ; j <= n ; ++ j )
	cout<<rand()%10;
      cout<<"\n";
    }
  return 0;
}
