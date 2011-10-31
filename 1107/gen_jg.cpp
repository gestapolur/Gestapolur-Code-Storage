#include<fstream>
#include<cstdlib>
#include<cstdio>
#define MAXN 1000
using namespace std;

ofstream cout("g.in",ios::binary);

int main()
{
  cout<<20<<"\n";
  cout<<"0\n0\n";
  cout<<"0\n-123456789012345678901234567890\n";
  cout<<"-123456789012345678901234567890\n0\n";
  cout<<"0\n123456789012345678901234567890\n";
  cout<<"123456789012345678901234567890\n0\n";
  cout<<"9999999999999999999999999999999999\n1\n";
  cout<<"-999999999999999999999999999999999\n-1\n";
  cout<<"-99999999999999999999999999999999\n1\n";
  srand( 1000 );
  for( int i = 9 ; i <= 19 ; ++ i )
    {
      int n = rand() % MAXN + 1 ;
      if(rand() % 2 ) cout<<"-"; 
      cout<<rand()%9+1; 
      for( int j = 2 ; j <= n ; ++ j )
	cout<<rand()%10;
      cout<<"\n";
      
      n = rand() % MAXN + 1 ;
      if(rand() % 2 ) cout<<"-"; 
      cout<<rand()%9+1; 
      for( int j = 2 ; j <= n ; ++ j )
	cout<<rand()%10;
      cout<<"\n";
      
    }

  cout<<rand()%9+1; 
  for( int j = 2 ; j <= 1000 ; ++ j )
    cout<<rand()%10;
  cout<<"\n";

  cout<<rand()%9+1; 
  for( int j = 2 ; j <= 1000 ; ++ j )
    cout<<rand()%10;
  cout<<"\n";
  
  return 0;
}
