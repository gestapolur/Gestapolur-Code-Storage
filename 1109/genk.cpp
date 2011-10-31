#include<iostream>
#include<cstdlib>
#include<cstdio>
#define MAXN 100000
#define MAXM 250000
using namespace std;

int n , m ;

int main()
{
  int i , j , tmp , tk ;
  srand( time( 0 ) );
  n = MAXN , m = MAXM;
  cout<<n<<" "<<m<<"\n";
  for( i = 1 ; i <= n ; ++ i )
    cout<<rand()%10 + 1<<" ";
  cout<<"\n";
  
  for( i = 1 ; i <= m ; ++ i )
    {
      if( rand( ) % 2 == 1 )
        {
          cout<<"shift(";
          tmp = rand( ) % 10 + 1 ;
          tk = 0 ;
          for( int j = 1 ; j <= tmp ; ++ j )
            {
              tk += rand( ) % n + 1;
              if( tk > n ) break;
              else cout<<tk<<",";
            }
          cout<<")\n";
        }
      else
        {
          cout<<"query(";
          tmp = rand() % n + 1 ;
          tk = rand() % ( n - tmp + 1 ) + tmp ;
          cout<<tmp<<","<<tk<<")\n";
        }
  
    }

  return 0;
}
