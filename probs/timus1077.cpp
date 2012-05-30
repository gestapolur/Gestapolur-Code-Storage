/*
  TIMUS 1077
  2012-04-12
  2012-04-20
  2012-04-22
  write by gestapolur
*/
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#define MAXN 205
using namespace std;

int n , m , tot , tts;
int w[ MAXN ][ MAXN ];
int u[ MAXN * MAXN ] , v[ MAXN * MAXN ] , pre[ MAXN ];
bool in[ MAXN * MAXN ];
int sset[ MAXN * MAXN ] , deep[ MAXN ];
vector <int> sv[ MAXN ];

void work()
{
  int i , j , t;
  int tu , tv , tl;
  int lc[ MAXN ];
  bool path[ MAXN ];
  bool added;

  do{
    /*
    for( i = 1 ; i <= n ; ++ i )
      cout<<sset[ i ]<<" ";
    cout<<"edge : "; for( i = 1 ; i <= m ; ++ i ) cout<<in[ i ]<<" "; cout<<"\n";
    cout<<"\n";
    */
    /*
    cout<<" pre : ";
    for( i = 1 ; i <= n ; ++ i ) cout<<pre[ i ]<<" "; cout<<"\n";
    cout<<" deep : ";
    for( i = 1 ; i <= n ; ++ i ) cout<<deep[ i ]<<" "; cout<<"\n";
    cin.get();
    */
    added = false;
    for( i = 1 ; i <= m ; ++ i )
      if( not in[ i ] and sset[ u[ i ] ] and sset[ u[ i ] ] == sset[ v[ i ] ] )
        {
          //cout<<"!\n";
          in[ i ] = true;
          added = true;
          
          tu = u[ i ];
          tv = v[ i ];
          if( deep[ tu ] > deep[ tv ] )
            { tu = v[ i ] ; tv = u[ i ]; }
          
          //lca & loop
          tl = 0;
          ++ tot;
          memset( path , 0 , sizeof( path ) );
          //cout<<"tu tv "<<tu<<" "<<tv<<"\n";
          while( tv )
            {
              lc[ ++ tl ] = tv;
              path[ tv ] = true;
              if( tu == tv ) break;
              tv = pre[ tv ];
            }
          
          //cout<<"tv path : "; for( t = 1 ; t <= tl ; ++ t ) cout<<lc[ t ]<<" "; cout<<"\n";
   
          while( not path[ tu ] and tu )
            {
              sv[ tot ].push_back( tu );
              tu = pre[ tu ]; 
            }
          if( tu )
            while( tl and lc[ tl ] not_eq tu )
              -- tl;
    
          while( tl )
            sv[ tot ].push_back( lc[ tl -- ] );
          //cout<<"loop size : "<<sv[ tot ].size()<<"\n";
        }
    
    if( not added )
      for( i = 1 ; i <= m ; ++ i )
        if( not in[ i ] and ( sset[ u[ i ] ] or sset[ v[ i ] ] ) )
          {
            //cout<<"!!\n";
            in[ i ] = true;
            added = true;

            tu = u[ i ];
            tv = v[ i ];
            if( not sset[ tu ] )
              { tv = u[ i ]; tu = v[ i ]; }
            sset[ tv ] = sset[ tu ];
            deep[ tv ] = deep[ tu ] + 1;
            pre[ tv ] = tu;

            break;
          }

    if( not added )
      for( i = 1 ; i <= m ; ++ i )
        if( not in[ i ] )
          {
            //cout<<"!!!\n";
            in[ i ] = true;
            added = true;
            
            ++ tts;
            sset[ u[ i ] ] = tts;
            sset[ v[ i ] ] = tts;
            pre[ v[ i ] ] = u[ i ];

            break;
          }
  }while( added );

  cout<<tot<<"\n";
  for( i = 1 ; i <= tot ; ++ i )
    {
      cout<<sv[ i ].size()<<" ";
      for( t = sv[ i ].size() - 1 ; t ; -- t )
        cout<<sv[ i ][ t ]<<" ";
      cout<<sv[ i ][ 0 ]<<"\n";
    }

  return ;
}

void init()
{
  int i , s , t;

  cin>>n>>m;
  for( i = 1 ; i <= m ; ++ i )
    {
      cin>>s>>t;
      u[ i ] = s;
      v[ i ] = t;
      w[ s ][ t ] = i;
      w[ t ][ s ] = i;
    }

  return ;
}

int main()
{
  init();

  work();

  return 0;
}
