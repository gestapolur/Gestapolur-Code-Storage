#include<iostream>
#include<cstdlib>
using namespace std;

int main()
{
  cout<<"2 5 5\n";
  srand( time( 0 ) );
  for( int i = 1 ; i <= 2 ; ++ i )
    {
      cout<<rand()%6<<" "<<rand()%6<<"\n";
    }
  return 0;
}
