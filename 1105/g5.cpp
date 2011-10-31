#include<fstream>
#define MAXN 10005
using namespace std;

ifstream cin("C-large.in");
ofstream cout("ans.out");

int n,low,hi;
int a[ MAXN ];

int main()
{
  int t,tt,i,j;
  bool sign;
  cin>>tt;
  t = 1 ;
  while(t <= tt )
    {
      cin>>n>>low>>hi;
      for( i = 1 ;i <= n ; ++ i)
	cin>>a[ i ];
      sign = false;
      //cout<<"---------\n";
      cout<<"Case #"<<t<<": ";
      for( i = low ; i <= hi ; ++ i)
	{
	  
	  for( j = 1 ; j <= n ; ++ j )
	    {
	      //cout<<i<<" "<<a[ j ]<<" "<<j<<"\n";
	      if( i % a[ j ] not_eq 0 and a[ j ] % i not_eq 0 )
		break;
	    }
	  
	  //if( j == 4 ) cout<<i%a[j]<<"!!!!\n";
	  if ( j == n + 1 )
	    {cout<<i<<"\n";sign = true;break;}
	}
      if( not sign )
	cout<<"NO\n";
      ++t;
    }
  return 0;
}
