#include<iostream>
#define MAXL 10000
using namespace std;

int a[ 100 ];

void testin()
{
  for( int i = 1 ; i <= 5 ; ++ i )
    cin>>a[ i ];
  a[ 0 ] = 5;
  return ;
}

void output()
{
  int tn = a[ 0 ] - 1, j , tmp , inv;
  string iv;
  inv = 0;
  tmp = a[ a[ 0 ] ];
  for( j = 0 ; j < 4 ; ++ j )
    {
      inv = inv * 10 + ( tmp - tmp/10*10 ) ;
      tmp /=10;
    }
  cout<<inv<<" ";
  for( int i = tn ; i ; -- i )
    {
      tmp = a[ i ];
      iv = "";
      for( j = 0 ; j < 4 ; ++ j )
        {
          iv.push_back( char( ( tmp - tmp/10*10 ) + '0') ) ;
          tmp /=10;
        }   
      cout<<iv<<" ";
    }
  cout<<"\n";
  return ;
}

int main()
{
  testin();

  output();

  return 0;
}
