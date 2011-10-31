#include<fstream>
#include<cstdlib>
#include<cstdio>
using namespace std;

ofstream cout("c.in",ios::binary);

int main()
{
  int i,j;
  cout<<8<<"\n";
  //1
  cout<<"5 5\n";
  cout<<"1 1 5 5\n";
  cout<<"00000\n";
  cout<<"01010\n";
  cout<<"00000\n";
  cout<<"01010\n";
  cout<<"00000\n";
  //2
  cout<<"10 20\n";
  cout<<"1 6 9 8\n";
  cout<<"11111011111111110111\n11111011110111110111\n11110000000111110111\n11000001110111110111\n11011111100000000111\n11000000001110110111\n11111110111110110111\n11111110111110110111\n11111110000000110111\n11111111111111110111\n";
  //3
  cout<<"20 20\n";
  cout<<"3 5 12 19\n";
  for( i = 1 ; i <= 20 ; ++ i )
    {
      for( j = 1 ; j <= 20 ; ++ j )
	cout<<'0';
      cout<<"\n";
    }
  //4
  srand( 100 );
  cout<<"50 50\n";
  cout<<"10 10 40 40\n";
  for( i = 1 ; i <= 50 ; ++ i )
    {
      for( j = 1 ; j <= 50 ; ++ j )
	if( not ( ( i == 10 and j == 10 ) or ( i == 40 and j == 40 ) ))
	  cout<<rand()%2;
	else
	  cout<<"0";
      cout<<"\n";
    }
  
  //5
  cout<<"3 3\n";
  cout<<"1 1 1 2\n";
  cout<<"111\n111\n111\n";
  //6
  cout<<"50 50\n";
  cout<<"1 1 50 50\n";
  for( i = 1 ; i <= 50 ; ++ i ) cout<<0;cout<<"\n";
  for( i = 1 ;i <= 48 ; ++ i )
    cout<<"01111111111111111111111111111111111111111111111110\n";
  for( i = 1; i <= 50 ; ++ i ) cout<<0;cout<<"\n";
  //9
  cout<<"50 50\n";
  cout<<"1 2 50 50\n";
  for( int i = 1 ; i <= 50 ; ++ i )
    {
      for( int j = 1 ; j <= 50 ; ++ j )
	if(i % 2 == 0 and j % 2 == 1 )
	  cout<<1;
	else
	  cout<<0;
      cout<<"\n";
    } 
  //10
  cout<<"50 50\n";
  cout<<"1 1 50 50\n";
  for( int i = 1 ; i <= 50 ; ++ i )
    {
      for( int j = 1 ; j <= 50 ; ++ j )
	cout<<0;
      cout<<"\n";
    } 
  return 0;
}
