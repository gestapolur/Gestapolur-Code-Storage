/*
  TIMUS 1158
  POJ 
  2012-04-03
  2012-04-04
  2012-04-05
 */
#include<iostream>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<queue>
#define MAXN 852
#define MAXM 54
#define MAXC 850
using namespace std;

typedef short int longdig[ 100 ];

int n , m , p , tot;
string str[ 12 ] , aph;
int fail[ MAXN ] , pa[ MAXN ] , idx[ MAXN ]; // parent[ i ] , aph[ i ] - 32 result
longdig ans , f[ MAXM ][ MAXN ]; // f[ i , j ] combine in step i and node j  
int w[ MAXN ][ MAXC ];// the child / edge of node i 's j child
bool isword[ MAXN ];

queue <int> q;
bool inq[ MAXN ];

void add( longdig a , longdig b )
{
  a[ 0 ] = a[ 0 ] > b[ 0 ] ? a[ 0 ] : b[ 0 ];
  
  for( int i = 1 ; i <= a[ 0 ] ; ++ i )
    {
      a[ i ] += b[ i ];
      if( a[ i ] >= 10 )
        {
          ++ a[ i + 1 ];
          a[ i ] -= 10;
        }
    }

  if( a[ a[ 0 ] + 1 ] )
    ++ a[ 0 ];

  return ;
}

void count()
{
  int i , j , k;

  f[ 0 ][ 0 ][ 0 ] = 1;// 0 is on root
  f[ 0 ][ 0 ][ 1 ] = 1;
  
  for( i = 1 ; i <= m ; ++ i )
    for( j = 0 ; j <= tot ; ++ j )
      if( not isword[ j ] )
        for( k = 0 ; k < n ; ++ k )
          if( w[ j ][ idx[ k ] ] and not isword[ w[ j ][ idx[ k ] ] ] )
            add( f[ i ][ w[ j ][ idx[ k ] ] ] , f[ i - 1 ][ j ] );
  
  ans[ 0 ] = 0; 
  for( i = 1 ; i <= tot ; ++ i )
    add ( ans , f[ m ][ i ] );
  
  if( ans[ 0 ] )
    for( i = ans[ 0 ] ; i ; -- i )
      cout<<ans[ i ];
  else 
    cout<<"0";
  cout<<"\n";

  //test
  /*
  for( i = 0 ; i <= m ; ++ i )
    {
      for( j = 1 ; j <= tot ; ++ j )
        cout<<f[ i ][ j ]<<" ";
      cout<<"\n";
    }  
  */
  return ;
}

void bfs()
{
  int i , pos , next;
  q = queue<int>();
  memset( inq , 0 , sizeof( inq ) );
  
  q.push( 0 );  
  do{
    pos = q.front();
    q.pop();
    for( i = 0 ; i < n ; ++ i )
      {
        next = w[ pos ][ idx[ i ] ];
        if( not next and not isword[ w[ fail[ pos ] ][ idx[ i ] ] ] )
          w[ pos ][ idx[ i ] ] = w[ fail[ pos ] ][ idx[ i ] ];
        else if( next 
                 and not isword[ next ]
                 and not inq[ next ] )//tree edge
          {
            q.push( next );
            inq[ next ] = true;
          }
      }
  }while( not q.empty() );

  return ;
}

void constr_fail()
{
  int i , pos , cur;

  fail[ 0 ] = 0;
  inq[ 0 ] = true;
  q.push( 0 );
  
  do{
    pos = q.front();
    q.pop();
    for( i = 0 ; i < n ; ++ i )
      if( w[ pos ][ idx[ i ] ] and not isword[ w[ pos ][ idx[ i ] ] ] and not inq[ w[ pos ][ idx[ i ] ] ] )
        {
          q.push( w[ pos ][ idx[ i ] ] );
          inq[ w[ pos ][ idx[ i ] ] ] = true;
        }
    if( pa[ pos ] )
      for( i = 0 ; i < n ; ++ i )
        if( w[ pa[ pos ] ][ idx[ i ] ] == pos )
          {
            cur = fail[ pa[ pos ] ];
            while( not w[ cur ][ idx[ i ] ] and cur )
              cur = fail[ cur ];
            fail[ pos ] = w[ cur ][ idx[ i ] ];
            isword[ pos ] = isword[ fail[ pos ] ];
            break;
          }
  }while( not q.empty() );
  
  return ;
}

void init()
{
  int len;
  int i , j , k , pos , pre;
  
  cin>>n>>m>>p;
  getline( cin , aph );
  getline( cin , aph );
  
  for( i = 1 ; i <= p ; ++ i )
    {
      getline( cin , str[ i ] );
      idx[ int(str[ i ][ 0 ]) + 128 ] = -1;
    }
  // add the chars that not appear in forbiden words firstly
  for( i = 0 ; i < n ; ++ i )
    if( idx[ int(aph[ i ]) + 128 ] == 0 )
      {
        w[ 0 ][ int(aph[ i ]) + 128 ] = ++ tot;
        w[ tot ][ int(aph[ i ]) + 128 ] = tot;
        pa[ tot ] = 0;        
      }
  
  for( i = 0 ; i < n ; ++ i )
    idx[ i ] = int(aph[ i ]) + 128;
  //trie tree
  for( i = 1 ; i <= p ; ++ i )
    {
      len = str[ i ].size();
      pre = 0;
      for( j = 0 ; j < len ; ++ j )
        if( not isword[ pre ] )
          {
            if( w[ pre ][ int(str[ i ][ j ]) + 128 ] )
              pre = w[ pre ][ int(str[ i ][ j ]) + 128 ];
            else
              {
                w[ pre ][ int(str[ i ][ j ]) + 128 ] = ++ tot;
                pa[ tot ] = pre;
                pre = tot;
              }
            if( j == len - 1 )
              isword[ pre ] = true;
          }
        else
          break;
    }
  //fail
  constr_fail();
  /*
  fail[ 0 ] = 0;
  for( i = 1 ; i <= tot ; ++ i )
    if( not isword[ i ] and pa[ i ] )
      {    
        //find i's node char k
        for( j = 0 ; j < n ; ++ j )
          if( w[ pa[ i ] ][ idx[ j ] ] == i )
            {
              k = j;
              break;
            }
        //point to it's fail point
        pos = fail[ pa[ i ] ];
        while( not w[ pos ][ idx[ k ] ] and pos )
          { pos = fail[ pos ]; }
        fail[ i ] = w[ pos ][ idx[ k ] ];
        isword[ i ] = isword[ fail[ i ] ];
      }
  */
  //DFA
  bfs();
  /*
  cout<<tot<<"\n";
  
  for( i = 0 ; i < n ; ++ i ) cout<<idx[ i ]<<" "; cout<<"\n";
  for( i = 0 ; i <= tot ; ++ i )
    {
      for( j = 0 ; j < n ; ++ j )
        cout<<w[ i ][ idx[ j ] ]<<" ";
      cout<<"\n";
    }
  cout<<"end:\n";
  for( i = 1 ; i <= tot ; ++ i ) cout<<isword[ i ]<<" "; cout<<"\n";
  
  cout<<"fail:\n";
  for( i = 1 ; i <= tot ; ++ i ) cout<<fail[ i ]<<" "; cout<<"\n";
  
  cout<<"pa:\n";
  for( i = 1 ; i <= tot ; ++ i ) cout<<pa[ i ]<<" "; cout<<"\n";
  */
  return ;
}

int main()
{
  init();

  count();

  return 0;
}
