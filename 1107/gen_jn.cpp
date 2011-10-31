#include<fstream>
#include<cstdlib>
#include<cstdio>
using namespace std;

ofstream cout("n.in" , ios::binary );

int main()
{
  cout<<"20\n";
  srand(1000);
  for( int i = 1 ; i <= 20; ++ i )
    {
      int n = rand() % 1000 + 1 ;
      for( int j = 1 ; j <= n ; ++ j )
	cout<<char(rand() % 26 + 97 );
      cout<<"\n";
    }
  return 0;
}
