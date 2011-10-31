//Gprob #002 steins;gate
#include<fstream>
#define MAXN 1005
using namespace std;

ifstream cin("./testdata/sg.in");
ofstream cout("./testdata/sg.out",ios::binary);

double m,v[ MAXN ],w[ MAXN ],f[ MAXN * 10];
int n;

const double mmin = 0.00000001;

int main()
{

  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);
 
  int i,j,t;
  double tmp;
  cin>>t;
  while(t > 0)
    {
      cin>>n>>tmp;
      m = tmp * 100.00000000 + 0.5;
      for( i = 1 ; i <= n ; ++ i)
	{
	  cin>>w[ i ]>>v[ i ];
	  v[ i ] = v[ i ] * 100 + 0.5;
	}
      
      for( i = 1 ; i <= n ; ++ i)
	for( j = int( m ) ;j >= int(v[ i ]) ; -- j)
	  if( f[ j ] < f[ j - int(v[ i ]) ] + w[ i ] )
	    f[ j ] = f[ j - int(v[ i ]) ] + w[ i ];	
      cout<<f[ int(m) ]<<"\n";  
      for( i = int( m ) ; i >= 0 ; -- i ) f[ i ] = 0; 
      --t;
    }
  return 0;
}
