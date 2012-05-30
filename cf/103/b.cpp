#include<iostream>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<vector>
#define MAXN 1002
using namespace std;

int n;
double ax , ay , bx , by ;

class node
{
public:
  double r, rx, ry;
};

node p1[ MAXN ] ;

double dist( double x1 , double y1 , double x2 , double y2 )
{ return sqrt( ( x1 - x2 ) * ( x1 - x2 ) + ( y1 - y2 ) * ( y1 - y2 ) );}


bool find( double tx , double ty )
{
  //int l = 1 , r = n ;
  //int mid;
  /*
  while( l <= r )
    {
      mid = l + r >> 1 ;
      if( p1[ mid ].r - dist( p1[ mid ].rx , p1[ mid ].ry , tx , ty ) > 0.00000001 )
        return true;
      else if( p1[ mid].rx < tx )
        l = mid + 1 ;
      else
        r = mid ;
    }
  */
  for( int i = 1 ; i <= n ; ++ i )
    if( p1[ i ].r - dist( p1[ i ].rx , p1[ i ].ry , tx , ty ) >= 0 )
      return true;
  //cout<<tx<<" "<<ty<<"\n";
  return false;
}

void init()
{
  cin>>ax>>ay>>bx>>by;
  cin>>n;
  for( int i = 1 ; i <= n ; ++ i )
    cin>>p1[ i ].rx>>p1[ i ].ry>>p1[ i ].r;
  //sort( 1 , n , p1 );
  return ;
}

int min( int a , int b ){ return a < b ? a : b ;}

int max( int a , int b ){ return a > b ? a : b ;}

void work()
{
  int ans = 0 ;
  int i , t = max( ax , bx ) ;
  for( i = min( ax , bx ) ; i <= t ; ++ i )
    {
      //cout<<i<<" "<<ay<<" "<<by<<"\n";
      if( not find( i , by ) )
        ++ans;
      if( not find( i , ay ) )
        ++ans;
    }
  t = max( ay , by ) ;
  for( i = min( by , ay ) + 1 ; i < t ; ++ i )
    {
      //cout<<i<<" "<<ax<<" "<<ay<<"\n";
      if( not find( ax , i ) )
        ++ ans;
      if( not find( bx , i ) )
        ++ ans;
    }
  cout<<ans<<"\n";
  return ;
}

int main()
{
  
  init();
  
  work();

  return 0;
}
