#include<iostream>
#define MAXN 1001
using std::cin;
using std::cout;

int r[ MAXN ];
int wa[ MAXN ],wb[ MAXN ],wv[ MAXN ],_ws[ MAXN ];
int sa[ MAXN ] , rank[ MAXN ];
int n,m;

int cmp(int *r , int a , int b , int l )
{return (r[ a ] == r[ b ] and r[ a + l ] == r[ b + l ]);}

void da( )
{
  int i,j,p,*t,*x=wa,*y=wb;
  //bucket sort for each char
  for( i = 0 ; i < m ; ++ i )
    _ws[ i ] = 0 ;
  for( i = 0 ; i < n ; ++ i )
    _ws[ x[ i ] = r[ i ] ] ++ ;
  for( i = 1 ; i < m ; ++ i )
    _ws[ i ] += _ws[ i - 1 ];
  for( i = n - 1 ; i >= 0 ; -- i )
    sa[ --_ws[ x[ i ] ] ] = i ;

  for( j = 1 , p = 1 ; p < n ; j <<= 1 , m = p  )
    {
      //use last time suffix array as index y      
      for( i = 0 ; i <= n ; ++ i ) y[ i ] = 0;
      for( p = 0 , i = n - j ; i < n ; ++ i ) y[ p ++ ] = i ;
      
      for( i = 0 ; i < n ; ++ i ) cout<<y[ i ]<<" ";cout<<"\n";
      for(i = 0 ; i < n ; ++ i )
	if( sa[ i ] >= j ) y[ p ++ ] = sa[ i ] - j ;
      for(i = 0 ; i < n ; ++ i )
	wv[ i ] = x[ y[ i ] ];//the order after sort index y
      //cout<<"-";for( i = 0 ; i < n ; ++ i ) cout<<wv[ i ]<<" ";cout<<"\n";
      //bucket sort
      for( i = 0 ; i < m ; ++ i ) _ws[ i ] = 0 ;
      for( i = 0 ; i < n ; ++ i ) _ws[ wv[ i ] ]++;
      for( i = 1 ; i < m ; ++ i ) _ws[ i ] += _ws[ i - 1 ];
      for( i = n - 1 ; i >= 0 ; -- i ) sa[ --_ws[ wv[ i ] ] ] = y[ i ] ;
      //record rank to y
      //for( i = 0 ; i < n ; ++ i ) cout<<x[ i ]<<" ";cout<<"\n";
      for( t = x , x = y , y = t , p = 1 , x[ sa[ 0 ] ] = 0 , i = 1 ; i < n ; ++ i )
	x[ sa[ i ] ] = cmp(y,sa[ i - 1 ],sa[ i ],j) ? p - 1 : p++;
      /*p is the rank if sa[ i - 1 ] & sa[ i ] are same , the order will not change
	otherwise , the rank p will increase . p - 1 because start from 0 
       */
    }
  //for( i = 0 ; i < n ; ++ i ) cout<<x[ i ]<<" ";cout<<"\n";//x is fucking rank index 
  return ;
}

int main()
{
  int i , j ;
  char ch;
  cin>>n;
  for( i = 0 ; i < n ; ++ i )
    {
      cin>>ch;
      r[ i ] = ch - 48;
      m = m > r[ i ] ? m : r[ i ] + 1 ;
    }
  //r[ n ++ ] = 0 ;
  da();
  
  for( i = 0 ; i < n ; ++ i )
    cout<<sa[ i ]<<" ";
  cout<<"\n";
  
  return 0;
}
