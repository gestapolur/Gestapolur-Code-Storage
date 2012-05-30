#include<iostream>
#include<cstdlib>
#include<cstdio>
#define N 11
using namespace std;

int n , K , pt , ul , ttc;
bool h[ 1 << N ];
int sv[ 1 << N ];

void compute( int row , int ld, int rd , int c )
{     
  int pos , p;
  if ( ( row & c ) != c )
    { 
      /*
      if( row )
        {
          int t = row;
          while( t ){ cout<<( t & 1 ); t >>= 1; }
          cout<<"\n";
        }
      */
      pos = c & ~( row | ld | rd);
      //cout<<pos<<" "<<(~( row | ld | rd ))<<"\n";
      while ( pos != 0 ) 
        {  
          p=pos & -pos;  
          pos-=p;  
          compute( row + p , ld + p << 1 , rd + p >> 1 , c );  
        }    
    } 
  else
    ++pt; 
 
  return ;
}  

void gen( int s , int cnt )
{
  if( cnt == n - K )
    {
      if( !h[ s ] )
        sv[ ++ ttc ] = s;
      h[ s ] = true;
    }
  else
    for( int i = 0; i < n ; ++ i )
      if( ( s >> i ) & 1 )
        gen( ( 1 << i ) ^ s , cnt + 1 );
  return ;
}

bool init()
{
  cin>>n>>K;
  if( K > n ) return false;
  ul = ( 1 << n ) - 1;
  return true;
}

int main()
{
  if ( init() )
    {
      gen( ul , 0 );
      cout<<ttc<<" ok\n";
      
      //sv[ 1 ] = 3 , sv[ 2 ] = 5 , sv[ 3 ] = 6; ttc = 3;
      for( int i = 1 ; i <= ttc ; ++ i )
        compute( 0 , 0 , 0 , sv[ i ] );
      
      //compute( 0 , 0 , 0 , 0 );
      cout<<pt<<"\n"; 
    }
  else
    cout<<0<<"\n";

  return 0;
}
