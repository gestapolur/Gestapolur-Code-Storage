//Google Code Jam practice
#include<fstream>
#define MAXN 2005
using namespace std;

ifstream cin("A-large-practice.in");
ofstream cout("ans.out");

int a[ MAXN ];
int n,c,l;

int main()
{
  int i,j,ax,bx,k;
  cin>>n;
  //cout<<n<<"\n";
  k = n;
  while( k > 0 )
    {
      cin>>c>>l;
      for(i = 1 ; i <= l ; ++ i)
	cin>>a[ i ];
      for(i = 1 ; i <= l ; ++ i)
	for(j = i + 1 ; j <= l ; ++ j)
	  if(a[ i ] + a[ j ] == c)
	    {
	      cout<<"Case #"<<n-k+1<<": "<<i<<" "<<j<<"\n";
	      goto end;
	    }
    end:--k;
    }

  cin.close();
  cout.close();

  return 0;
}
