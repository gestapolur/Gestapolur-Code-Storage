//CF #88 B
#include<iostream>
using namespace std;

int a , b , m;

void output( int x )
{
  int st[ 10 ] , cnt ;
  for( cnt = 1 ; cnt <= 9 ; ++ cnt )
    st[ cnt ] = 0 ;
  cnt = 9 ;
  while( x > 0 )
    {
      st[ cnt -- ] = x % 10 ;
      x /= 10;
    }
  cout<<"1 ";
  for( cnt = 1 ; cnt <= 9 ; ++ cnt ) cout<<st[ cnt ];cout<<"\n";
  return ;
}

int main()
{
  cin>>a>>b>>m;
  
  if()
  return 0;
}
