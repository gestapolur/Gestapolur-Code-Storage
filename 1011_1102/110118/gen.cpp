#include<fstream>
#include<cstdlib>
#include<cstdio>
#define MAXN 10
using namespace std;

ofstream cout("lk.in");

int main()
{
  int x,y;
  srand(time(0));
  x = rand()%MAXN + 1;
  y = rand()%(x * x) + 1;
  cout<<x<<" "<<y<<"\n";
  cout.close();
  return 0;
}
