#include<fstream>
#include<cstdlib>
#define MAXN 300
#define MAXM 160
#define MAXV 20
using namespace std;

int n,m;

ofstream cout("choice.in");

int main()
{
  srand(time(0));
  n = rand() % MAXN + 1;
  m = rand() % (MAXM < n ? MAXM : n) + 1;
  int i;
  for(i = 1 ; i <= n ; ++ i)
    cout<<rand()%n+1<<" "<<rand()%MAXV+1<<"\n";
  cout.close();
  return 0;
}
