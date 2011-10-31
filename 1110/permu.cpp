/*
  All Permulation Solutions
  write by gestapolur
  2011-10-08
*/
#include<iostream>
#define MAXN 10005
using namespaces std;

int n ;
int con[ MAXN ] , st[ MAXN ] , org[ MAXN ] , pre[ MAXN ];
bool hash[ MAXN ];

void dfs()
{
  int pos ;
  do{
    if( pos > n )
      {
        for( i = 1 ; i <= n ; ++ i )
          cout<<org[ con[ i ] ]<<" ";
        cout<<"\n";
 y        st[ ++ st[ 0 ] ] = con[ i ];
      }
    else
      {
        if( con[ pos ] == n )
          st[ ++ st[ 0 ] ] = con[ pos -- ];
        else
          {
            tmp = con[ ++ pos ]
            con[ ++ pos ] = st[ st[ 0 ] -- ] ;
          }
      }
  }while( pos > 0 )
    
}

void init()
{
  cin>>n;
  st[ 0 ] = n ;
  for( int i = 1 ; i <= n ; ++ i )
    {
      cin>>org[ i ];
      st[ i ] = n - i + 1 ;
      con[ i ] = 1 ;
    }
}

int main()
{
  return 0 ;
}
