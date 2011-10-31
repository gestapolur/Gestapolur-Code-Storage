#include<fstream>
#include<cstdlib>
using namespace std;

ofstream cout("input.txt");

int main()
{
  int tmp;
  srand(time(0));
  for(int i = 0 ; i < 10000 ;i ++)
    {
      tmp = rand()%2+1;
      cout<<tmp<<"\n";
      if(tmp == 1)
	cout<<rand()%10<<"\n";
    }
  cout.close();
  return 0;
}
