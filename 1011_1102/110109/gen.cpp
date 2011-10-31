/*
  data generator
  data format :
  n verx , m edge
  u , v , w (in next m line )
*/
#include<fstream>
#include<cstdlib>
#include<cstdio>
#define MAXN 100
#define MAXV 1002
using namespace std;

ofstream cout("data.in");

int main()
{
  int i,n,m,u,v;
  srand(time(0));
  n = rand()%MAXN + 1;
  m = n + rand()%( n * ( n - 1 ) >> 1 ) ;
  cout<<n<<" "<<m<<"\n";
  for(i = 1 ; i <= m ; ++ i)
    {
      u = rand()%n + 1;//no self circuit in the graph
      do{ v = rand()%n + 1;}while(v == u);
      cout<<u<<" " <<v<<" "<<rand()%MAXV + 1<<"\n";
    }
  cout.close();
  return 0;
}
