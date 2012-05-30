/*
  2012 CSU Campus Match E
  WA
  2012-04-16
*/
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
using namespace std;

const int sco[ 11 ] = { 200 , 275 , 325 , 400 , 475 , 575 , 675 , 800 , 900 , 1000 };

char ply[ 11 ][ 20 ];
int mon[ 11 ] , kil[ 11 ] , bkil[ 11 ];
int n , nl[ 11 ];

void work()
{
  int i , j , lenk , lenbk ;
  char k[ 20 ] , bk[ 20 ];
  int ik , ibk;

  scanf( "%d" , &n );
  
  for( i = 1 ; i <= n ; ++ i )
    {
      scanf( "%s %s" , &k , &bk );
      lenk = strlen( k );
      lenbk = strlen( bk );
      //cout<<lenk<<" "<<lenbk<<"\n";
      for( ik = 1 ; ik <= 10 ; ++ ik )
        if( lenk == nl[ ik ] )
          {
            for( j = 0 ; j < nl[ ik ] ; ++ j )
              if( k[ j ] not_eq ply[ ik ][ j ] )
                break;
              else if( j == nl[ ik ] - 1 )
                goto found1;
          }
    found1:;
      for( ibk = 1 ; ibk <= 10 ; ++ ibk )
        if( lenbk == nl[ ibk ] )
          {
            for( j = 0 ; j < nl[ ibk ] ; ++ j )
              if( bk[ j ] not_eq ply[ ibk ][ j ] )
                break;
              else if( j == nl[ ibk ] - 1 )
                goto found2;
          }
    found2:;
      //cout<<ik<<" "<<ibk<<" fff\n";
      if( ibk == ik )
        bkil[ ibk ] = ( bkil[ ibk ] + 1 ) < 9 ? ( bkil[ ibk ] + 1 ) : 9;
      else 
        {
          if( ( ibk < 5 and ik < 5 ) or ( ibk >= 5 and ik >= 5 ) )
            {

              mon[ ik ] += sco[ kil[ ik ] ];
              kil[ ik ] = ( kil[ ik ] + 1 ) < 9 ? ( kil[ ik ] + 1 ) : 9;              
              bkil[ ik ] = 0;
            }
          else
            {
              mon[ ibk ] = ( mon[ ibk ] - sco[ bkil[ ibk ] ] ) > 0 ? ( mon[ ibk ] - sco[ bkil[ ibk ] ]) : 0 ;
              bkil[ ibk ] = ( bkil[ ibk ] + 1 ) < 9 ? ( bkil[ ibk ] + 1 ) : 9;
              kil[ ibk ] = 0;
              mon[ ik ] += sco[ kil[ ik ] ];
              kil[ ik ] = ( kil[ ik ] + 1 ) < 9 ? ( kil[ ik ] + 1 ) : 9;              
              bkil[ ik ] = 0;
            }
        }
    }

  for( i = 1 ; i <= 10 ; ++ i )
    printf( "%d\n" , mon[ i ] );

  return ;
}

bool init()
{
  if( scanf( "%s" , ply[ 1 ] ) not_eq EOF )
    {
      mon[ 1 ] = 4726;
      nl[ 1 ] = strlen( ply[ 1 ] );  
      for( int i = 2 ; i <= 10 ; ++ i )
        {
          scanf( "%s" , ply[ i ] );
          nl[ i ] = strlen( ply[ i ] );
          mon[ i ] = 4726;         
        }
      memset( bkil , 0 , sizeof( bkil ) );
      memset( kil , 0 , sizeof( kil ) );
      
      return true;
    }
  return false;
} 

int main()
{
  while( init() )
    work();

  return 0;
}
