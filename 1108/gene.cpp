#include<iostream>
#include<cstdlib>
using namespace std;

int rec[ 6 ][ 3 ];

int main()
{
  int i , j ;
  cout<<5<<" "<<2<<"\n";
  srand( time( 0 ) );
  for( i = 1 ; i <= 5 ; ++ i )
    cout<<rand()%10<<" "<<rand()%10<<" "<<1<<"\n";
  cout<<rand()%10<<" "<<rand()%10<<" "<<2<<"\n";
  cout<<rand()%10<<" "<<rand()%10<<" "<<3<<"\n";
  rec[ 1 ][ 1 ] = 1 ;rec[ 2 ][ 1 ] = 1 ;
  rec[ 3 ][ 2 ] = 1 ; rec[ 4 ][ 2 ] = 1 ;
  rec[ 5 ][ 2 ] = 1 ;
  for( i = 1 ; i <= 5 ; ++ i )
    {
      for( j = 1 ; j<= 2 ; ++ j )
	cout<<rec[ i ][ j ]<<" ";
      cout<<"\n";
    }
  return 0;
}
