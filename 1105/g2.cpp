#include<fstream>
#define MAXN 105
using namespace std;

ifstream cin("A-large.in");
ofstream cout("ans.out");

int n;
int w[ MAXN ][ MAXN ];
int tall[ MAXN ],tw[ MAXN ];
double owp[ MAXN ],oowp[ MAXN ];

int main()
{
  char ch;
  int i,j,k;
  int t,tt;

  cin>>tt;
  t = 1;
  while ( t <= tt )
    {
      cout<<"Case #"<<t<<":\n";
      cin>>n;
      for( i = 1 ; i <= n ; ++ i) {tall[ i ] = 0 ;tw[ i ] = 0;}
      for( i = 1 ;i <= n ; ++ i)
	for( j = 1 ;j <= n ; ++ j)
	  {
	    cin>>ch;
	    if(ch == '1') {w[ i ][ j ] = 1;++tall[ i ];++tw[ i ];}
	    else if(ch == '0') {w[ i ][ j ] = 0 ;++tall[ i ];}
	    else w[ i ][ j ] = 2;
	  }
      //for( i = 1 ; i <= n;  ++ i) cout<<tw[ i ]<<" "<<tall[ i ]<<"\n";
      //owp
      for( i = 1 ; i <= n ; ++ i )
	{
	  double tmp = 0.00000000000;
	  for( j = 1 ; j <= n ; ++ j)
	    if(w[ j ][ i ] not_eq 2)
	      {
		if(w[ j ][ i ] == 1 )
		  tmp += double(tw[ j ] - 1 )/double(tall[ j ] - 1);
		else
		  tmp += double(tw[ j ] )/double(tall[ j ] - 1 );
	      }
	  owp[ i ] = tmp/double(tall[ i ]);
	}
      //oowp
      for( i = 1 ; i <= n ; ++ i)
	{
	  double tmp = 0.000000000;
	  for( j = 1 ; j <= n ; ++ j )
	    if(w[ i ][ j ] not_eq 2 )
	      {
		tmp += owp[ j ];
	      }	
	  oowp[ i ] = tmp/double(tall[ i ]);   
	}
      for( i = 1 ; i <= n ; ++ i)
	cout<<(0.25*(double(tw[ i ])/double(tall[i]))+0.50*owp[ i ]+0.25*oowp[ i ])<<"\n";
      ++ t;
    }

  return 0;
}
