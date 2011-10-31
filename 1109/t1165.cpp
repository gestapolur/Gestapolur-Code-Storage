//timus 1165
#include<iostream>
#include<cstring>
#define MAXN 202
using namespace std;

char ca[ MAXN ];
int a[ MAXN ] , tans[ MAXN ] , ans[ MAXN ];
int rec[ MAXN ][ MAXN ];
int n , cnt ;

void update()
{
  bool sign = false;;
  if( tans[ 0 ] < ans[ 0 ] ) sign = true;
  else if( tans[ 0 ] == ans[ 0 ] )
    for( int i = a[ 0 ] ; i > 0 ; -- i )
      if( tans[ i ] < ans[ i ] )
        { sign = true ; break; }
      else if( tans[ i ] > ans[ i ] )
        break;
  if( sign )
    for( int  i = 0 ; i <= tans[ 0 ] ; ++ i )
      ans[ i ] = tans[ i ];
  return ;
}

void add9( int a[ ] , )
{
  
  return ;
}

bool cmp( int a[ ] , int b[ ] )
{
  if( a[ 0 ] not_eq b[ 0 ] ) return false;
  for( int i = a[ 0 ] ; i > 0 ; -- i )
    if( a[ i ] not_eq b[ i ] ) return false;
  return true ;
}


bool pat( int l , int r , int len , int pre[ ] )
{
  if( l > r ) return false;
  ++ cnt ;
  if( cnt == 1 )
    {
      rec[ cnt ][ 0 ] = 0 ;
      for( int k = l + len - 1 ; k >= l ; -- k )
        rec[ cnt ][ ++ rec[ cnt ][ 0 ] ] = a[ k ];
    }
  else
    {
      int tmp[ MAXN ];
      for( int k = 0 ; k <= pre[ 0 ] ; ++ k ) tmp[ k ] = pre[ k ];
      add1( tmp );
      rec[ cnt ][ 0 ] = 0 ;
      if( l + tmp[ 0 ] - 1 > r ) return false;
      for( int k = l + tmp[ 0 ] - 1 ; k >= l ; -- k )
        if( tmp[ ++ rec[ cnt ][ 0 ] ] not_eq a[ k ] )
          return false;
        else rec[ cnt ][ rec[ cnt ][ 0 ] ] = a[ k ];
    }
  if( len < r )
    pat( l + rec[ cnt ][ 0 ] + 1 , r , rec[ cnt ][ 0 ] , rec[ cnt ] );
  else return true;
}

void work( )
{
  int l , r , k , i , j ;
  bool org ;
  for( l = 1 ; l < n ; ++ l )
    for( r = l + 1 ; r <= n ; ++ i )
      {
        // create first ;
        org = false;
        cnt = 0;
        rec[ 1 ][ 0 ] = 0 ;
        if( l > 1 )
          {
            org = true;
            ++ cnt;
            rec[ 1 ][ 0 ] = l ;
            for( k = l - 1 ; k > 0 ; -- k )
              rec[ 1 ][ l - k ] = a[ k ];  
          }
        for( k = 1 ; k <= r - l + 1  ; ++ k )//second number's lenth
          {
            if( l > 1 ) cnt = 1 ;
            if( pat( l , r , k , rec[ 1 ] ) )
              {
                //pattern first
                int tmp = rec[ 2 ][ 0 ];
                for( i = l - 1  ; i >= 0 ; -- i ) 
                  {
                    if( rec[ 1 ][ i ] not_eq rec[ 2 ][ tmp -- ] )
                      break;
                  }
                if( i not_eq -1 ) continue ;
                // pattern last
                if( n - r > 0  )
                  {
                    int tmp = rec[ cnt ][ 0 ];
                    for( i = r + 1 ; i <= n ; ++ i )
                      if( a[ i ] not_eq rec[ cnt ][ tmp -- ] )
                        break;
                    if( i not_eq n + 1 ) continue;
                  }
                // update ans
                if( org )//whether has first
                  { 
                    min1( rec[ 2 ] ); 
                    cal( rec[ 2 ] );//rec2 to tans digit
                    minus( rec[ 2 ][ 0 ] - rec[ 2 ][ 1 ] )//tans - x; ;
                    
                  }
                else
                  cal( rec[ 1 ] );
                update( );//ans ? tans 
              }
          }
      }
  return ; 
}

void init()
{
  cin>>ca;
  n = strlen( ca );
  for( int i = 0  ; i < n ; ++ i )
    a[ i + 1 ] = ca[ i ] - 48 ;
  return ; 
}

int main()
{
  init();

  work();

  return 0;
} 
