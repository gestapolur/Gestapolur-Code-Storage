/*
  CSU 2011 JULY CONTEST PROB G standrad
  write by gestapolur
  2011-07-10
*/
#include<fstream>
#include<cstring>
#define MAXN 1002
using std::ifstream;
using std::ofstream;
using std::ios;

ifstream cin("g.in",ios::binary);
ofstream cout("g.out",ios::binary);

char ca[ MAXN ] , cb[ MAXN ];
int a[ MAXN ] , b[ MAXN ];
bool sa,sb;

int cmp( int a[] , int b[] )
{
  if(a[ 0 ] > b[ 0 ]) return 1;
  else if( a[ 0 ] < b[ 0 ] ) return -1;
  for(int i = 1 ; i <= a[ 0 ] ; ++ i )
    if( a[ i ] > b[ i ] ) return 1;
    else if( a[ i ] < b[ i ] ) return -1;
  return 0;
}

void add( int a[] , int b[] )
{
  a[ 0 ] = a[ 0 ] > b[ 0 ] ? a[ 0 ] : b[ 0 ] ;
  for( int i = 1 ; i <= a[ 0 ] ; ++ i)
    {
      a[ i ] += b[ i ];
      if( a[ i ] >= 10 )
	{
	  ++a[ i + 1 ];
	  a[ i ] %= 10;
	}
    }
  if(a[ a[ 0 ] + 1 ] ) ++ a[ 0 ];
  while( a[ 0 ] > 0 ) cout<<a[ a[ 0 ] -- ];
  cout<<"\n";
  return ;
}

void minus( int a[ ] , int b[ ] )
{
  a[ 0 ] = a[ 0 ] > b[ 0 ] ? a[ 0 ] : b[ 0 ];
  for( int i = 1 ; i <= a[ 0 ] ; ++ i )
    {
      a[ i ] -= b[ i ];
      if( a[ i ] < 0 ) 
	{
	  -- a[ i + 1 ];
	  a[ i ] += 10;
	}
    }
  while( a[ a[ 0 ] ] == 0 ) --a[ 0 ];
  for(int i = a[ 0 ] ; i > 0 ; -- i ) cout<<a[ i ];
  cout<<"\n";
  return ;
}

int main()
{
  int i , t;
  cin>>t;
  cin.get();
  while( t -- )
    {
      memset(a , 0 , sizeof( a ) );
      memset(b , 0 , sizeof( b ) );

      cin>>ca+1>>cb+1;
      a[ 0 ] = strlen( ca + 1 );
      b[ 0 ] = strlen( cb + 1 );
      if( ca[ 1 ] == '-')
	{
	  sa = false;
	  for( i = 1 ; i < a[ 0 ] ; ++ i )
	    ca[ i ] = ca[ i + 1 ];
	  --a[ 0 ];
	}
      else sa = true;

      if( cb[ 1 ] == '-')
	{
	  sb = false;
	  for( i = 1 ; i < b[ 0 ] ; ++ i )
	    cb[ i ] = cb[ i + 1 ];
	  --b[ 0 ];
	}
      else sb = true;
	

      //cout<<a[ 0 ]<<"\n";for( i = a[ 0 ] ; i > 0 ; -- i ) cout<<ca[ i ]<<" ";cout<<"\n";
      //cout<<b[ 0 ]<<"\n";for( i = b[ 0 ] ; i > 0 ; -- i ) cout<<cb[ i ]<<" ";cout<<"\n";

      for( i = 1 ; i <= a[ 0 ] ; ++ i ) a[ i ] = ca[ a[ 0 ] - i + 1 ] - 48;
      for( i = 1 ; i <= b[ 0 ] ; ++ i ) b[ i ] = cb[ b[ 0 ] - i + 1 ] - 48; 
      //cout<<a[ 0 ]<<" "<<b[ 0 ]<<"\n";
      //for( i = a[ 0 ] ; i >= 1 ; -- i ) cout<<a[ i ]; cout<<" "<<sa<<"\n";
      //for( i = b[ 0 ] ; i >= 1 ; -- i ) cout<<b[ i ]; cout<<" "<<sb<<"\n";
      //cout<<"---\n";
      if( sa ^ sb )
	{
	  if( not sa and cmp( a , b ) == 1 )
	    {
	      cout<<"-";
	      minus( a , b );
	    }
	  else if( not sb and cmp( a , b ) == -1 )
	    {
	      cout<<"-";
	      minus( b , a );
	    }
	  else if( not sa )
	    minus( b , a );
	  else
	    minus( a , b );
	}
      else
	{
	  if(not (sa & sb) ) cout<<"-";
	  add( a , b );
	}
    }
  return 0;
}
