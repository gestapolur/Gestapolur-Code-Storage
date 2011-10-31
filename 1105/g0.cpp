#include<fstream>
using namespace std;

ifstream cin("A-large.in");
ofstream cout("ans.out");

long long n,pd,pg;

int main()
{
  int t,tt;
  long long wd;
  bool sign;
  cin>>tt;
  t = 1;
  while ( t <= tt )
    {
      cin>>n>>pd>>pg;
      sign = false;
      if((pg == 100 and pd not_eq 100) or (pd not_eq 0 and pg == 0 )) goto end;
      for(wd = 1 ; wd <= n ; ++ wd)
	if(wd * pd % 100 == 0 )
	  {sign = true;break;}
    end:
      if( sign )
	cout<<"Case #"<<t<<": Possible\n";
      else
	cout<<"Case #"<<t<<": Broken\n";
      ++ t;
    }

  return 0;
}
