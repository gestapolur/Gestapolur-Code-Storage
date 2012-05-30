/*
  SPOJ WPUZZLES
  2012-04-07
  2012-04-08
  TLE
  gestapolur
*/
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<queue>
#include<vector>
#define MAXN 1012
using namespace std;

const int dirn[ 8 ] = { -1 , -1 , 0 , 1 , 1 , 1 , 0 , -1 };
const int dirm[ 8 ] = { 0 , 1 , 1 , 1 , 0 , -1 , -1 , -1 };

class treenode
{
public:
  int pre , fail;
  int child[ 26 ];
  int end;
};

//queue <int> q;
int q[ MAXN * MAXN ];
treenode node[ MAXN * MAXN ];
bool inq[ MAXN * MAXN ];
char map[ MAXN ][ MAXN ];
int ansc[ MAXN ] , ansl[ MAXN ];
char ansdir[ MAXN ];

int n , m , wd , tot;

void init()
{
  int tn , pos;
  char str[ MAXN ];

  cin>>n>>m>>wd;
  for( int i = 1 ; i <= n ; ++ i )
    {
      //scanf( "%s" , &map[ i ] );
      cin>>map[ i ] + 1;
    }
  for( int i = 1 ; i <= wd ; ++ i )
    {
      cin>>str;
      //scanf( "%s" , &str );
      tn = strlen( str );
      pos = 0;
      for( int j = 0 ; j < tn ; ++ j )
        if( not node[ pos ].child[ str[ j ] - 'A' ] )
          {
            node[ pos ].fail = 0;
            node[ pos ].end = 0;
            node[ pos ].child[ str[ j ] - 'A' ] = ++ tot;
            node[ tot ].pre = pos;
            pos = tot;
          }
        else
          pos = node[ pos ].child[ str[ j ] - 'A' ];
      node[ pos ].end = i;
   }
  return ;
}
/*
void constr_fail()
{
  int i , pos , cur , self;
  
  for( i = 0 ; i <= tot ; ++ i )
    inq[ i ] = false;
  queue <int> q = queue<int>();
  
  inq[ 0 ] = true;
  
  q.push( 0 );

  do{
    //pos = q[ ++ front ];
    pos = q.front();
    q.pop();

    for( i = 0 ; i < 26 ; ++ i )
      if( node[ pos ].child[ i ] and not inq[ node[ pos ].child[ i ] ] )
        {
          q.push( node[ pos ].child[ i ] );
          inq[ node[ pos ].child[ i ] ] = true;
        }
    
    if( node[ pos ].pre )
      {
        for( i = 0 ; i < 26 ; ++ i )
          if( node[ node[ pos ].pre ].child[ i ] == pos )
            {
              self = i;
              break;
            }    

        cur = node[ node[ pos ].pre ].fail;
        while( not node[ cur ].child[ self ] and cur )
          cur = node[ cur ].fail;
        node[ pos ].fail = node[ cur ].child[ self ];
      }
  }while( not q.empty() );

  return;
}
*/

void constr_fail()
{
  int i , pos , cur , self;
  int front , rear;
  //memset( q , 0 , sizeof( q ) );
  for( i = 0 ; i <= tot ; ++ i )
    inq[ i ] = false;
  //q = queue<int>();
  front = 0;
  rear = 1;
  inq[ 0 ] = true;
  q[ 1 ] = 0;
  //q.push( 0 );

  do{
    pos = q[ ++ front ];
    //pos = q.front();
    //q.pop();

    for( i = 0 ; i < 26 ; ++ i )
      if( node[ pos ].child[ i ] and not inq[ node[ pos ].child[ i ] ] )
        {
          q[ ++ rear ] = node[ pos ].child[ i ];
          //q.push( node[ pos ].child[ i ] );
          inq[ node[ pos ].child[ i ] ] = true;
        }
    
    if( node[ pos ].pre )
      {
        for( i = 0 ; i < 26 ; ++ i )
          if( node[ node[ pos ].pre ].child[ i ] == pos )
            {
              self = i;
              break;
            }    

        cur = node[ node[ pos ].pre ].fail;
        while( not node[ cur ].child[ self ] and cur )
          cur = node[ cur ].fail;
        node[ pos ].fail = node[ cur ].child[ self ];
      }
  }while( front < rear );

  return;
}


void count()
{
  int i , j , k , tl , tc , pos;
  bool find;

  for( i = 1 ; i <= n ; ++ i )
    for( j = 1 ; j <= m ; ++ j )
      if( node[ 0 ].child[ map[ i ][ j ] - 'A' ] )
        {
          find = false;
          for( k = 0 ; k < 8 ; ++ k )
            {
              tl = i , tc = j , pos = node[ 0 ].child[ map[ i ][ j ] - 'A' ];
              do{
                if( node[ pos ].end )
                  {
                    ansl[ node[ pos ].end ] = i - 1;
                    ansc[ node[ pos ].end ] = j - 1;
                    ansdir[ node[ pos ].end ] = 'A' + k;
                    find = true;
                    break;
                  }

                if( not node[ pos ].child[ map[ tl + dirn[ k ] ][ tc + dirm[ k ] ] - 'A' ] )
                  pos = node[ pos ].fail;
                else
                  {
                    tl += dirn[ k ];
                    tc += dirm[ k ];                    
                    pos = node[ pos ].child[ map[ tl ][ tc ] - 'A' ];
                  }
              }while( pos and tc <= m and tc > 0 and tl <= n and tl > 0 );
              
              if( find ) 
                break;
            }
        }
  return ;
}

void out()
{
  for( int i = 1 ; i <= wd ; ++ i )
    cout<<ansl[ i ]<<" "<<ansc[ i ]<<" "<<ansdir[ i ]<<"\n";
  return;
}

void clr()
{
  for( int i = 0 ; i <= tot; ++ i )
    {
      memset( node[ i ].child , 0 , sizeof( node[ 0 ].child ) );
      node[ i ].pre = 0;
      node[ i ].end = 0;
    }
  tot = 0;
  return ;
}

int main()
{
  int t;
  
  cin>>t;
  
  while( t -- )
    {
      init();

      constr_fail();

      count();

      out();
      
      clr();
    }
  return 0;
}
