#include<iostream>
#include<string>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<vector>
#define MAXN 9 
using namespace std;

char m[ 10 ][ 10 ];
bool org[ MAXN ][ MAXN ];
int bot;

class queue
{
public:
  int rest;
  bool w[ MAXN ][ MAXN ];
  short int rr[ MAXN * MAXN ] , rc[ MAXN * MAXN ];
  int pr , pc;
};

const int dirr[ 9 ] = { 1 , -1 , 0 , 0 , 1 , 1 , -1 , -1 };
const int dirc[ 9 ] = { 0 , 0 , 1 , -1 , 1 , -1 , 1 , -1 };

queue q[ 500000 ]; 

bool check( int pr , int pc , queue p )
{
  for( int i = 1 ; i <= p.rest ; ++ i )
    if( p.rr[ i ] + 1 == pr and p.rc[ i ] == pc )
      return false;
  return true ;
}

bool bfs()
{
  int rear = 1 , front = 0 ;
  int i , j , k , tr , tc ;
  queue p;
  q[ 1 ].rest = 0 ;
  for( i = 1 ; i <= 8 ; ++ i )
    for( j = 1 ; j <= 8 ; ++ j )
      {
        q[ 1 ].w[ i ][ j ] = org[ i ][ j ];
        if( org[ i ][ j ] )
          { q[ 1 ].rr[ ++ q[ 1 ].rest ] = i ; q[ 1 ].rc[ q[ 1 ].rest ] = j ; }
      }
  q[ 1 ].pc = 1 , q[ 1 ].pr = 8 ;

  do{
    p = q[ ++ front ];
    /*
    cout<<p.rest<<" "<<p.pr<<" "<<p.pc<<"\n";
    for( i = 1 ; i <= 8 ; ++ i )
      {
        for( j = 1 ; j <= 8 ; ++ j )
          if( i == p.pr and j == p.pc ) cout<<'A';
          else
            cout<<p.w[ i ][ j ];
        cout<<"\n";
      }
    for( i = 1 ; i <= p.rest ; ++ i ) cout<<p.rr[ i ]<<" "<<p.rc[ i ]<<"\n";
    cin.get();
    */
    if( p.pr == 1 and p.pc == 8 or p.rest == 0 ) return true;
    for( j = 0 ; j <= 8 ; ++ j )
      {
        tr = p.pr + dirr[ j ] ; tc = p.pc + dirc[ j ];
        if( tr <= 8 and tr > 0 and tc <= 8 and tc > 0 and not p.w[ tr ][ tc ] and check( tr , tc , p ) )
          {
            ++ rear ;
            q[ rear ].pr = tr ; q[ rear ].pc = tc ;
            q[ rear ].rest = 0;
            for( k = 1 ; k <= p.rest ; ++ k )
              if( p.rr[ k ] + 1 <= 8 )
                {
                  q[ rear ].rr[ ++ q[ rear ].rest ] = p.rr[ k ] + 1 ;
                  q[ rear ].rc[ q[ rear ].rest ] = p.rc[ k ];
                  q[ rear ].w[ p.rr[ k ] + 1 ][ p.rc[ k ] ] = true ;
                }
            if( q[ rear ].rest == 0 ) return true ;
          }
      }
    
  }while( front < rear );

  return false ;
}

void init()
{
  for( int i = 1 ; i <= 8 ; ++ i )
      cin>>m[ i ] + 1 ;
  for( int i = 1 ; i <= 8 ; ++ i )
    for( int j = 1 ; j <= 8 ; ++ j )
      if( m[ i ][ j ] == 'S' )
        org[ i ][ j ] = true , ++ bot;
      else
        org[ i ][ j ] = false;
  return ;
}

int main()
{

  init();

  if ( bfs() ) cout<<"WIN\n";
  else cout<<"LOSE\n";

  return 0;
}
