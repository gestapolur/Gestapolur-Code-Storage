/*
  CF 150 A
  ACCEPTED
  2012-02-19
  gestapolur
*/
#include<iostream>
#include<cmath>
#define MAXN 10000005
using namespace std;

long long n ;
int tot;

int stk[ MAXN ];

bool notp[ MAXN ];

void prime()
{
  tot = sqrt( n ) ;
  int k ;

  for( int i = 2 ; i <= tot ; ++ i )
    if( not notp[ i ] )
      {
        stk[ ++stk[ 0 ] ] = i ; 
        k = 2;
        while( k * i <= tot )
          { notp[ k * i ] = true; ++ k ; }
        
      }

  return ;
}

void work()
{
  int div = 0 , tmp = 1 ;
 
  for( int i = 1 ; i <= stk[ 0 ] ; ++ i )
    {
      //cout<<stk[ i ]<<"x\n";
      while( n % stk[ i ] == 0 )
        {
          ++ div;
          tmp *= stk[ i ];
          if( div == 2 )
            { cout<<"1\n"<<tmp<<"\n"; return ; }
          if( n / stk[ i ] <= tot ) 
            n /= ( n / stk[ i ] ) ;
          n /= stk[ i ];
        }
      if( n == 1 ) break;
    }
  if( div == 1 )
    cout<<"2\n";
  else
    cout<<"1\n0\n";
  return ;
}

int main()
{
  
  cin>>n;

  prime();

  work();

  return 0;
}
