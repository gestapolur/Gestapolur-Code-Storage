#include<iostream>
#include<cstdlib>
#include<cstdio>
#define MAXN 1002
#define MAXL 1000
#define MAXC 1000
#define MAXW 1000
#define WORD_LEN 999
using namespace std;

char w[ MAXN ][ MAXN ];

int main()
{
  int t;
  cout<<"10\n";
  cout<<"5 5 5\nABCDE\nABCDE\nABCDE\nABCDE\nABCDE\nAAAAA\nBBBBB\nCCCCC\nDDDDD\nEEEEE\n";
  cout<<MAXL<<" "<<MAXC<<" "<<MAXW<<"\n";
  for( int i = 1 ; i <= MAXL ; ++ i )
    {
      cout<<'B';
      for( int j = 2 ; j < MAXC ; ++ j )
        cout<<'A';
      cout<<"B\n";
    }
  for( int i = 1 ; i <= MAXL ; ++ i )
    {
      cout<<'B';
      for( int j = 2 ; j < MAXC ; ++ j )
        cout<<'A';
      cout<<"B\n";
    }  
    
  t = 8;
  srand( time( 0 ) );
  while( t -- )
    {
      cout<<MAXL<<" "<<MAXC<<" "<<MAXW<<"\n";
      for( int i = 1 ; i<= MAXL ; ++ i )
        {
          for( int j = 1 ; j <= MAXC ; ++ j )
            {
              w[ i ][ j ] = char( 'A' + rand()%26 );
              cout<<w[ i ][ j ];
            }
          cout<<"\n";
        }
   
      for( int i = 1 ; i<= MAXW ; ++ i )
        {
          for( int j = 1 ; j <= WORD_LEN ; ++ j )
            cout<<w[ i ][ j ];
          cout<<char( 'A' + rand() % 26 )<<"\n";
        }
    }
  return 0;
}
