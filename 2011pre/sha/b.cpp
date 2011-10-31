//B
#include<iostream>
#define MAXN 100005
using namespace std;

int n , m , cx , cy , cnt ;
int nx[ MAXN ] , ny[ MAXN ] , ox[ MAXN ] , oy[ MAXN ];
int tm[ MAXN ];
bool ins[ MAXN ] , ty[ MAXN ];

void sortx( int i , int j )
{
  if( i >= j ) return ;
  int m , n , t , k;
  m = i , n = j , k = nx[ i + j >> 1 ] ;
  while( m <= n )
    {
      while( nx[ m ] < k ) ++ m ;
      while( nx[ n ] > k ) -- n;
      if( m <= n )
        {
          t = nx[ m ]; nx[ m ] = nx[ n ]; nx[ n ] = t;
          t = ox[ m ]; ox[ m ] = ox[ n ]; ox[ n ] = t;
          ++ m , -- n;
        }
    }
  sortx( i , n );
  sortx( m , j );
  return ;
} 

void sorty( int i , int j )
{
  if( i >= j ) return ;
  int m , n , t , k;
  m = i , n = j , k = ny[ i + j >> 1 ] ;
  while( m <= n )
    {
      while( ny[ m ] < k ) ++ m ;
      while( ny[ n ] > k ) -- n;
      if( m <= n )
        {
          t = ny[ m ]; ny[ m ] = ny[ n ]; ny[ n ] = t;
          t = oy[ m ]; oy[ m ] = oy[ n ]; oy[ n ] = t;
          ++ m , -- n;
        }
    }
  sorty( i , n );
  sorty( m , j );
  return ;
} 

void sx( int x )
{
  int l = 1 , r = n , mid ;
  while( l <= r )
    {
      mid = l + r >> 1;
      if( nx[ mid ] > x )
        r = mid ;
      else if( nx[ mid ] < x ) l = mid + 1;
      else break;
      if( l == r ) return ;
    }
  l = mid - 1 ;
  while( l > 0 and nx[ l ] == nx[ mid ]) ins[ ox[ l --  ] ] = true; 
  r = mid ;
  while( r <= m and nx[ r ] == nx[ mid ] ) ins[ ox[ r ++ ] ] = true;
  return ;
}

void sx( int x )
{
  int l = 1 , r = n , mid ;
  while( l <= r )
    {
      mid = l + r >> 1;
      if( ny[ mid ] > x )
        r = mid ;
      else if( ny[ mid ] < x ) l = mid + 1;
      else break;
      if( l == r ) return ;
    }
  l = mid - 1 ;
  while( l > 0 and ny[ l ] == ny[ mid ]) ins[ ox[ l --  ] ] = true; 
  r = mid ;
  while( r <= m and ny[ r ] == ny[ mid ] ) ins[ ox[ r ++ ] ] = true;
  return ;
}

int main()
{
  while( cin>>n>>m and ( n not_eq 0 or m not_eq 0 ) )
    {
      for( i =  1; i <= n ; ++ i ) ins[ i ] = false;

      for( int i = 1 ; i <= n ; ++ i )
        {
          cin>>nx[ i ]>>ny[ i ];
          ox[ i ] = oy[ i ] = i ;
        }
      cx = cy = cnt = 0 ;
      for( int i = 1 ; i <= m ; ++ i )
        cin>>ty[ i ]>>tm[ i ];

      sortx( 1 , n );
      sorty( 1 , n );

      for( int i = 1 ; i <= m ; ++  i )
        {
          cnt = 0;
          if( ty[ i ] )
            sx( tm[ i ] );
          else
            sy( tm[ i ] );
          cout<<cnt<<"\n";
        }
    }
  return 0;
}
