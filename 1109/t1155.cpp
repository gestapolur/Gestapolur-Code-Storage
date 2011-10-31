//timus 1155 AC
#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;

int a[ 9 ] , b[ 9 ];
bool side[ 9 ]; 

const bool w[ 9 ][ 9 ] = 
  { 
    0,0,0,0,0,0,0,0,0,
    0,0,1,0,1,1,0,0,0,
    0,1,0,1,0,0,1,0,0,
    0,0,1,0,1,0,0,1,0,
    0,1,0,1,0,0,0,0,1,
    0,1,0,0,0,0,1,0,1,
    0,0,1,0,0,1,0,1,0,
    0,0,0,1,0,0,1,0,1,
    0,0,0,0,1,1,0,1,0
  };

int main()
{
  int i , j , cnt , sum , x , y ;

  for( i = 1 ; i <= 8 ; ++ i )
    { scanf("%d" , &a[ i ] ); a[ 0 ] += a[ i ];}
  sum = a[ 1 ] + a[ 3 ] + a[ 6 ] + a[ 8 ];
  
  if( a[ 0 ] > 0 and a[ 0 ] % 2 == 0 and a[ 0 ] - sum == sum )
    {
      for( j = 0 ; j <= 8 ; ++ j ) b[ j ] = a[ j ];
      side[ 1 ] = side[ 3 ] = side[ 6 ] = side[ 8 ] = true;
 
      while( b[ 0 ] > 0 )
        {
          //minus
          for( x = 1 ; x <= 8 ; ++ x )
            if( b[ x ] > 0 )
              for( y = 1 ; y <= 8 ; ++ y )
                if( w[ x ][ y ] == true and b[ y ] > 0 and ( side[ x ] ^ side[ y ] ) == 1 )
                  { 
                    int del = min( b[ x ] , b[ y ] );
                    b[ 0 ] -= 2 * del;
                    b[ x ] -= del;
                    b[ y ] -= del;
                    while( del > 0 )
                      {
                        printf( "%c%c-\n" , x + 'A' - 1 , y + 'A' - 1 );
                        -- del;
                      }
                    break;
                  }
          //transfer
          if( b[ 0 ] > 0 )
            for( x = 1 ; x <= 8 ; ++ x )
              if( b[ x ] > 0 )
                {
                  bool link = false;
                  for( y = 1 ; y <= 8 ; ++ y )
                    if( w[ x ][ y ] == true and b[ y ] > 0 and ( ( side[ x ] ^ side[ y ] ) == 1 ) )
                      { link = true ; break ; }
                  if( not link )
                    {
                      bool findx = false;
                      for( y = 1 ; y <= 8 ; ++ y )
                        if( x not_eq y and ( ( side[ x ] ^ side[ y ] ) == 0 ) )
                          {
                            for( j = 1 ; j <= 8 ; ++ j )
                              if( w[ y ][ j ] == true and w[ x ][ j ] == true  
                                  and ( (side[ j ] ^ side[ x ] ) == 1 ) )
                                {
                                  int del = b[ x ];
                                  b[ y ] += b[ x ];
                                  b[ x ] = 0 ;
                                  while( del > 0 )
                                    {
                                      printf("%c%c+\n" , y + 'A' - 1 , j + 'A' - 1 );
                                      printf("%c%c-\n" , x + 'A' - 1 , j + 'A' - 1 );
                                      -- del;
                                    }
                                  findx = true;
                                  break;
                                }
                            if( findx ) break;
                          }
                    }          
                }
          if( b[ 0 ] < 0 )
            for( x = 1 ; x <= 8 ; ++ x ) {printf("%d " , b[ x ] );printf("\n");}
        }
    }
  else printf("IMPOSSIBLE\n");
  
  return 0 ;
}
