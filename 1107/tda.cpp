//DA exercise
#include<iostream>
using std::cin;
using std::cout;

int da()
{
  int i,j;
  //sort for each single char
  for( i = 0 ; i < m ; ++ i ) ws[ i ] = 0 ;
  for( i = 0 ; i < m ; ++ i ) ++ ws[ r[ i ] ];
  for( i = 1 ; i < n ; ++ i ) ws[ i ] +=ws[ i - 1 ];
  for( i = n - 1 ; i >= 0 ; -- i ) x[ --ws[ i ] ] = i;  
  
  for( j = 1 , p = 1 ; p < n ; j <<= 1 , m = p  )
    {
      for( p = 0 , i = n - j ; i < n ; ++ i )
	y[ p ++ ] = i ;
      for( i = 0 ; i < n ; ++ i )
	if( sa[ i ] >= j ) y[ p ++ ] = sa[ i ] - j ;
    }
  return 0;
}
