//#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#define MAXN 102
using namespace std;


ifstream cin("input.txt");
ofstream cout("output.txt");

int n , m , ans ;
int w[ MAXN ][ MAXN ];
int st[ MAXN ] , pre[ MAXN ] , cnt[ MAXN ];
bool vis[ MAXN ];

void dfs()
{
  bool move;
  int pos = 1 , i ;
  memset( pre , 0 , sizeof( pre ) );
  memset( vis , 0 , sizeof( vis ) );
  for( i = 1 ; i <= m ; ++ i )
    st[ i ] = 1 ;
  vis[ 1 ] = true ;
  /*
  for( i = 1 ; i <= m ; ++ i )
    {
      cout<<i<<": ";
      for( int j = 1 ; j <= w[ i ][ 0 ] ; ++ j )
        cout<<w[ i ][ j ]<<" ";
      cout<<"\n";
    }
  */
  do{
    move = false ;
    //cout<<pos<<"-\n";
    for( i = st[ pos ] ; i <= w[ pos ][ 0 ] ; ++ i )
      if( not vis[ w[ pos ][ i ] ] )
        {
          vis[ w[ pos ][ i ] ] = true;
          pre[ w[ pos ][ i ] ] = pos ;
          st[ pos ] = i + 1;
          move = true;
          pos = w[ pos ][ i ];
          break; 
        }
    if( not move )
      {
        st[ pos ] = 1 ;
        pos = pre[ pos ];
      }
  }while( pos > 0 );

  //for( i = 1 ; i <= m ; ++ i ) cout<<pre[ i ]<<" "; cout<<"\n";
  return ;
}

void length()
{
  int i , j , tc , td , maxd = 0 ;
  for( i = 1 ; i <= m ; ++ i )
    {
      for( j = 1 ; j <= m ; ++ j ) cnt[ j ] = 0 ;
      tc = i ; td = 0 ;

      while( pre[ tc ] > 0 )
        {
          tc = pre[ tc ];
          cnt[ tc ] = ++ td;
        }

      for( j = 1 ; j <= m ; ++ j )
        if( i not_eq j )
          {
            if( cnt[ j ] > 0 )
              maxd = cnt[ j ] > maxd ? cnt[ j ] : maxd ;
            else
              {
                td = 0 ; tc = j ;
                while( cnt[ tc ] == 0 and tc not_eq i )
                  {
                    tc = pre[ tc ];
                    ++ td;
                  }
                maxd = ( td + cnt[ tc ] ) > maxd ? ( td + cnt[ tc ] ) : maxd ;
              }
          }
    }
  ans += maxd;
  return ;
}

void init()
{
  int i , u , v ; 
  cin>>m;
  memset( w , 0 , sizeof( w ) );
  for( i = 1 ; i < m ; ++ i )
    {
      cin>>u>>v;
      w[ u ][ ++ w[ u ][ 0 ] ] = v;
      w[ v ][ ++ w[ v ][ 0 ] ] = u;
    }
  //cout<<"!!!!\n";
  return ;
}

int main()
{
  cin>>n;
  for( int i = 1 ; i <= n ; ++ i )
    {
      init();
      dfs();
      length();
    }
  cout<<ans<<"\n";
  return 0;
}
