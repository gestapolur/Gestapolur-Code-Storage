#include<fstream>
#include<cstdlib>
#include<cstdio>
using namespace std;

ofstream cout("./testdata/upa.in",ios::binary);

int main()
{
  int i,j,s;
  cout<<10<<" "<<10<<"\n";
  for( i = 1 ;i <= 10 ; ++ i)
    {
      for( j = 1 ;j <= 10 ; ++ j)
	{
	  srand(time(0) + i + j );
	  s = rand() * i - j / i ;
	  if(s % 2 == 0 )
	    cout<<"S";
	  else 
	    cout<<"B";
	}
      cout<<"\n";
    }
  return 0;
}
