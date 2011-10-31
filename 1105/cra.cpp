#include<fstream>
#include<cstdlib>
#include<cstdio>
#define MAXN 4000
using namespace std;

ofstream cout("input.in");

int main()
{
  int n;
  int i , t;
  srand(time(0));
  t = rand() % 100 + 1;
  cout<<t<<"\n";
  while(t > 0)
    {
      n = rand() % 10 + 1;
      cout<<n<<"\n";
      for(i = 1 ; i <= n ; ++ i)
	cout<<rand() % MAXN + 1 <<" ";
      cout<<"\n";
      --t;
    }
  return 0;
}
