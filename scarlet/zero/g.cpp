#include<iostream>
#include<cstring>
#include<string>
#define MAXN 16
#define MAXM 55
using namespace std;

int n , m ;
string cla[ MAXN ];
string prob[ MAXM ][ MAXN ];
int tc[ MAXN ] , nc[ MAXN ] , res[ MAXN ];
bool w[ MAXM ][ MAXN ];

void work()
{
  int i , j , k , tot ; 
  //test
  for( i = 1 ; i <= m ; ++ i )
    {
      for( j = 1 ; j <= tc[ i ] ; ++ j )
        cout<<prob[ i ][ j ]<<"- ";
      cout<<"\n";
    }
  //pre
  memset( w , 0 , sizeof( w ) );
  for( i = 1 ; i <= m ; ++ i )
    for( j = 1 ; j <= tc[ i ] ; ++ j )
      for( k = 1 ; k <= n ; ++ k )
        if( prob[ i ][ j ] == cla[ k ] )
          w[ k ][ i ] = true ;

  //pattern 
  for( i = 1 ; i <= n ; ++ i ) res[ i ] = 0 ;

  for( i = 1 ; i <= m ; ++ i )
    for( j = 1 ; j <= n ; ++ j )
      if( w[ j ][ i ] and res[ i ] < nc[ i ] )
        {
          ++ res[ i ];
          break;
        }
  tot = 0 ;
  for( i = 1 ; i <= n ; ++ i )
    if( res[ i ] == nc[ i ] )
      ++ tot ;
  cout<<tot<<"\n";
  return ;
}

bool init()
{
  if( cin>>n>>m )
    {
      string tmp;
      int tn;
      for( int i = 1 ; i <= n ; ++ i )
        cin>>cla[ i ]>>nc[ i ];
      for( int i = 1 ; i <= n ; ++ i ) cout<<cla[ i ]<<"- "; cout<<"\n";
      for( int i = 1 ; i <= n ; ++ i ) cout<<nc[ i ]<<" "; cout<<"\n";
      memset( prob , 0 , sizeof( prob ) );
      cout<<"-----\n";
      for( int i = 1 ; i <= m ; ++ i )
        {
          getline( cin , tmp );
          tn = tmp.size();
          cout<<tmp<<"---\n";
          tc[ i ] = 0 ;
          for( int j = 0 ; j < tn ; ++ j )
            {
              cout<<tmp[ j ]<<"\n";
              if( tmp[ j ] == ' ' or j == 0 ) ++ tc[ i ] ;
              if( tmp[ j ] not_eq ' ' )
                prob[ i ][ tc[ i ] ].push_back( tmp[ j ] );
              cout<<prob[ i ][ tc[ i ] ]<<"=\n";
            }
        }
      return true ;
    }
  return false ;
}

int main()
{
  while( init() )
      work();
  return 0;
}
