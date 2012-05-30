//cf#99 B
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;

string a , c , b ;
int n , st ;

int main()
{
  bool bra = false , onp = false ;
  int pcnt = 0 ;
  cin>>a;
  n = a.size();
  if( a[ 0 ] == '-' ) bra = true;
  for( int i = 0 ; i < n ; ++ i )
    if( onp and pcnt < 2 )
      {
        c.push_back( a[ i ] );
        ++ pcnt;
      }
    else if( a[ i ] == '.' )
      {
        onp = true;
        st = i - 1 ;
      }
  while( pcnt < 2 )
    { c.push_back( '0' ); ++pcnt ;}
  
  pcnt = 0 ;
  if( not onp )
    st = n - 1 ;
  while( st >= 0 )
    {
      //cout<<a[ st ]<<"\n";
      b.push_back( a[ st ] );
      ++ pcnt ;
      if( pcnt == 3 )
        { b.push_back( ',' ); pcnt = 0 ;}
      -- st;
    }
  if( bra )
    cout<<"(";
  cout<<"$";
  n = b.size() - 1 ;
  //st = 0;
  while( b[ n ] == '-' or b[ n ] == ',' ) -- n ;
  while( n >= 0 )
    cout<<b[ n-- ];
  cout<<"."<<c;
  if( bra ) cout<<")\n";
  else cout<<"\n";
             
  return 0;
}
