#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#define MAXN 2002
using namespace std;

int n , la , lb;
int a[ MAXN ];

void sort( int i , int j )
{
  if( i >= j ) return ;
  int m , n , t , k;
  m = i , n = j ;
  k = a[ i + j >> 1 ];
  while( m <= n )
    {
      while( a[ m ] < k ) ++ m;
      while( a[ n ] > k ) -- n;

      if( m <= n )
        {
          t = a[ m ] ; a[ m ] = a[ n ] ; a[ n ] = t;
          ++ m ; -- n;
        }
    }
  
  sort( i , n );
  sort( m , j );

  return ;
}

void init()
{
  cin>>n>>la>>lb;
  for( int i = 1 ; i <= n ; ++ i )
    cin>>a[ i ];
  return ;
}

int main()
{
  init();

  sort( 1 , n );
  //cout<<a[ lb ]<<" "<<a[ la ]<<"\n";
  cout<<a[ lb + 1 ] - a[ lb ]<<"\n"; 
  
  return 0;
}
