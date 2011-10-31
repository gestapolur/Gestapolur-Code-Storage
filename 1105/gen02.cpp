//steins;gate test generator
#include<fstream>
#include<cstdlib>
#include<cstdio>
#define MAXN 1000
#define MAXM 100
using namespace std;

ofstream cout("g2.in",ios::binary);

int main()
{
  int n,m1,m2,t,tt;
  cout<<10<<"\n";
    tt = 10;
    while( tt > 0)
      {
  srand(time(0));
  while( n < 500)
    n = rand() % MAXN + 1 ;
  cout<<n<<" ";
  m1 = rand() % MAXM ;
  cout<<m1<<".";
  m2 = rand() % MAXM ;
  cout<<m2<<"\n";
  
  for( int i = 1 ; i <= n ; ++ i)
    {
      cout<<"0.";
      t = rand()%MAXM ; 
      if( not t ) ++ t;
      if( t < 10 ) cout<<"0";
      cout<<t<<" ";

      do{
	t = rand()%MAXM;
      }while(t > m1);
      cout<<t<<".";
      t = rand()%MAXM;
      if( t < 10 ) cout<<"0";
      if(t % 10 == 0) cout<<t/10<<"\n";
      else cout<<t<<"\n";
      
    }
  getchar();
  --tt;
      }
  return 0;
}
