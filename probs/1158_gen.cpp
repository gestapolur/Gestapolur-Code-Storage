#include<iostream>
#include<cstdlib>
#include<cstdio>
#define MAXN 50
#define LEN 50
#define PAT 10
using namespace std;

bool hash[ 300 ];

int main()
{
  char a[ 55 ];
  char t;
  int n = 0 ;
  srand( time( 0 ) );
  cout<<MAXN<<" "<<LEN<<" "<<PAT<<"\n";
  /*
  for( int i = 1 ; i <= MAXN ; ++ i ) 
    {
    
      do{
        t = char( rand() % 256 );
      }while( hash[ t ] );
      hash[ t ] = true;
    
      a[ ++ n ] = t;
      cout<<a[ n ];
    }
  cout<<"\n";
  */
  n = 0;
  for( int i = 0 ; i < 26 ; ++ i ) a[ ++ n ] = 'a' + i;
  for( int i = 0 ; i < 26 ; ++ i ) a[ ++ n ] = 'A' + i;
  for( int i = 1 ; i <= MAXN ; ++ i ) cout<<a[ i ]; cout<<"\n";
  
  for( int i = 1 ; i <= PAT ; ++ i )
    {
      for( int j = 1 ; j <= 10 ; ++ j )
        cout<<a[ rand() % MAXN + 1 ];
      cout<<"\n";
    }
  
  return 0;
}
