#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#define MOD 1000003 
using namespace std;

void init()
{
  string s;
  long long  cd = 1 , sum = 0 ;
  
  cin>>s;
  //cout<<( cd << 4 )<<"\n";
  for( int i = s.size() - 1 ; i >= 0 ; -- i )
    {
      //cout<<cd<<"-\n";
      if( s[ i ] == '>' )
        {
          sum = ( sum + ( cd << 3 ) ) % MOD;
          
        }
      else if( s[ i ] == '<' )
        {
          sum = ( sum + ( cd << 3 ) + cd ) % MOD;
          

        }
      else if( s[ i ] == '+')
        {
          sum = ( sum + ( cd << 3 ) + ( cd << 1 ) ) % MOD;
          //cd = ( cd + ( cd << 4 ) + ( cd << 2 ) ) % MOD;

        }
      else if( s[ i ] == '-')
        {
          sum = ( sum + ( cd << 3 ) + ( cd << 1 ) + cd ) % MOD;
          //cd = ( cd + ( cd << 4 ) + ( cd << 2 ) + ( cd << 1 ) ) % MOD;

        }
      else if( s[ i ] == '.')
        {
          sum = ( sum + ( cd << 3 ) + ( cd << 2 ) ) % MOD;
          //cd = ( cd + ( cd << 4 ) + ( cd << 3 ) ) % MOD;
        
        }
      else if( s[ i ] == ',')
        {
          sum = ( sum + ( cd << 3 ) + ( cd << 2 ) + cd  ) % MOD;
          //cd = ( cd + ( cd << 4 ) + ( cd << 3 ) + ( cd << 1 ) ) % MOD;

        }
      else if( s[ i ] == '[')
        {
          sum = ( sum + ( cd << 3 ) + ( cd << 2 ) + ( cd << 1 ) ) % MOD;
          //cd = ( cd + ( cd << 4 ) + ( cd << 3 ) + ( cd << 2 ) ) % MOD;

        }
      else if( s[ i ] == ']')
        {
          sum = ( sum + ( cd << 3 ) + ( cd << 2 ) + ( cd << 1 ) + ( cd ) ) % MOD;
          //cd = ( cd + ( cd << 4 ) + ( cd << 3 ) + ( cd << 2 ) + ( cd << 1 ) ) % MOD;

        }
      cd = ( cd << 4 ) % MOD;
    }

  cout<<sum<<"\n";

  return ;
}

int main()
{
  
  init();

  return 0;
}
