#include<iostream>
#include<string>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<vector>
#define MAXN 102 
using namespace std;

int n , m ;
int con[ MAXN ] ;
bool w[ MAXN ][ MAXN ];
bool ins[ MAXN ];
int sta[ MAXN ] , stb[ MAXN ];
int cnt;

int main()
{
  cin>>n>>m;
  int ta , tb ;
  for( int i = 1 ; i <= m ; ++ i )
    {
      cin>>ta>>tb;
      w[ ta ][ tb ] = true;
      w[ tb ][ ta ] = true;
      ++ con[ ta ];
      ++ con[ tb ];
    }

  //for( int i = 1 ; i <= n ; ++ i ) cout<<con[ i ]<<" "; cout<<"\n";
  for( int i = 1 ; i <= n ; ++ i ) ins[ i ] = true ;

  cnt = 0 ;
  bool kick ;
  do{
    kick = false;
    for( int i = 1 ; i <= n ; ++ i )
      if( con[ i ] == 1 and ins[ i ] )
        {
          ins[ i ] = false;
          for( int j = 1 ; j <= n ; ++ j )
            if( w[ i ][ j ] and ins[ j ] )
              {
                kick = true;
                sta[ ++ sta[ 0 ] ] = i;
                stb[ sta[ 0 ] ] = j;
              }
        }
    while( sta[ 0 ] > 0 )
      {
        //cout<<sta[ sta[ 0 ] ]<<" "<<stb[ sta[ 0 ] ]<<"x\n";
        -- con[ sta[ sta[ 0 ] ] ] ; -- con[ stb[ sta[ 0 ] ] ];
        w[ sta[ sta[ 0 ] ] ][ stb[ sta[ 0 ] ] ] = false;
        w[ stb[ sta[ 0 ] ] ][ sta[ sta[ 0 ] ] ] = false;
        -- sta[ 0 ];
      }
    if( kick )
      ++ cnt;
  }while( kick );
  
  cout<<cnt<<"\n";

  return 0;
}
