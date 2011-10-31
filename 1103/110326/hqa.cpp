//High Quality Add
#include<iostream>
#include<string>
#define MAXN 1000
using namespace std;

string ca,cb;
int a[ MAXN ] , b[ MAXN ];

int* add(int a[], int b[] )
{
  int i,*c;

  c = new int [ a[ 0 ] > b[ 0 ] ? a[ 0 ] : b[ 0 ] + 1];
  c[ 0 ] = a[ 0 ] > b[ 0 ] ? a[ 0 ] : b[ 0 ];
  for(i = c[ 0 ] + 1 ; i >= 1 ; -- i) c[ i ] = 0;
  
  for(i = 1 ; i <= c[ 0 ] ; ++ i)
    {
      c[ i ] += a[ i ] + b[ i ];
      if( c[ i ] >= 10)
	{
	  ++c[ i + 1];
	  c[ i ] %= 10;
	}
    }
  
  if(c[ c[ 0 ] + 1] > 0 ) ++c[ 0 ];

  for(i = c[ 0 ] ; i >= 1 ; --i)
    cout<<c[ i ]<<" ";
  cout<<"\n";
  return c;
}

void init()
{
  int i;
  a[ 0 ] = ca.size();
  b[ 0 ] = cb.size();

  //cout<<a[ 0 ]<<" "<<b[ 0 ]<<"\n";

  for(i = 1 ; i <= a[ 0 ] ; ++ i)
    a[ i ] = ca[ a[ 0 ] - i ] - 48;
  for(i = 1 ; i <= b[ 0 ] ; ++ i)
    b[ i ] = cb[ b[ 0 ] - i ] - 48;
  
  /*
  for(i = a[ 0 ] ; i >= 1 ; --i) cout<<a[ i ]<<" ";cout<<"\n";
  for(i = b[ 0 ] ; i >= 1 ; --i) cout<<b[ i ]<<" ";cout<<"\n";
  cout<<"==============\n";
  */

  return ;
}

int main()
{
  int i,*c;
  cin>>ca>>cb;
  init();
  
  c = add( a , b );
  /*
  for(i = c[0] ; i >= 0 ; --i)
    cout<<c[ i ]<<" ";
  */
  return 0;
}
