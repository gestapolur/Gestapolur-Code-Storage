//high qulity minus
#include<iostream>
#include<string>
#define MAXN 1001
using namespace std;

string ca,cb;
int a[ MAXN ],b[ MAXN ];
bool revs = false;

int* mins(int a[] , int b[])
{
  int *c,i;
  c = new int [ (a[ 0 ] > b[ 0 ] ? a[ 0 ] : b[ 0 ]) + 2];
  
  
  c[ 0 ] = a[ 0 ] > b[ 0 ] ? a[ 0 ] : b[ 0 ];
  
  for(i = c[ 0 ] + 1 ; i >= 1 ; -- i)
    c[ i ] = 0;

  for(i = 1 ; i <= a[ 0 ] ; ++ i)
    {
      c[ i ] += a[ i ] - b[ i ];
      if(c[ i ] < 0 )
	{
	  c[ i ] += 10;
	  --c[ i + 1 ];
	}
    }
/* 
  for(i = c[ 0 ] ; i > 0 ; -- i)
    cout<<c[ i ]<<" ";
  cout<<"\n";
  return 0;
*/
  while(c[ c[ 0 ] ] == 0 and c[ 0 ] > 1)
    --c[ 0 ];
  
  if( revs ) cout<<"-";
  for(i = c[ 0 ] ; i > 0 ; -- i)
    cout<<c[ i ]<<" ";
  cout<<"\n";
  return 0;
}

bool cmp()
{
  if(b[ 0 ] > a[ 0 ])
    return true;
  else if(b[ 0 ] < a[ 0 ])
    return false;
  else
    for(int i = a[ 0 ] ; i >= 1 ; -- i)
      if(a[ i ] > b[ i ])
	return false;
      else
	return true;
  return false;
}

void init()
{
  int i;
  cin>>ca>>cb;
  a[ 0 ] = ca.size();
  b[ 0 ] = cb.size();
  for(i = 0 ; i < a[ 0 ] ; ++ i)
    a[ i + 1 ] = ca[ a[ 0 ] - i - 1] - 48;
  for(i = 0 ; i < b[ 0 ] ; ++ i)
    b[ i + 1 ] = cb[ b[ 0 ] - i - 1] - 48;
  if(cmp())
    {
      int tmp;
      revs = true;
      for(i = 1 ; i <= b[ 0 ] ; ++ i)
	{tmp = b[ i ] ; b[ i ] = a[ i ] ; a[ i ] = tmp;}
      tmp = b[ 0 ] ; b[ 0 ] = a[ 0 ] ; a[ 0 ] = tmp;
    }

  for(i = 1 ; i <= a[ 0 ] ; ++ i)
    cout<<a[ i ]<<" ";
  cout<<"\n";
  for(i = 1 ; i <= b[ 0 ] ; ++ i)
    cout<<b[ i ]<<" ";
  cout<<"\n";
}

int main()
{
  init();
  mins(a,b);
  return 0;
}
