/*
  gprob #000 D-mail
  testdata tested
  2011-05-26
  write by gestapolur
*/
#include<fstream>
#define DAYSEC 86400
using namespace std;

ifstream cin("test.in");
ofstream cout("test.ans",ios::binary);

const long long md[14] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

long long year[2],mon[2],day[2],hour[2],mins[2],sec[2];
long long cnt;
long long s[ 2 ];

bool isleap( int y )
{
  if(( y % 100 and y % 4 == 0 ) or ( y % 100 == 0 and y % 400 == 0 )) return true;
  return false;
}

void cntyear( short int i)
{
  int j ;
  bool leap ;
  leap = isleap( year[ i ] );
  s[ i ] = 0;
  for( j = mon[ i ] - 1  ; j > 0 ; -- j )
    if( j not_eq 2 or not leap )
      s[ i ] += md[ j ] * DAYSEC;
    else
      s[ i ] += ( md[ j ] + 1 ) * DAYSEC;
  s[ i ] += ( day[ i ] - 1 ) * DAYSEC;
  s[ i ] += hour[ i ] * 3600;  
  s[ i ] += mins[ i ] * 60; 
  s[ i ] += sec[ i ];
  return ;
}

void work()
{
  int i;
  bool leap;
  cnt = 0 ;
  cntyear( 0 );
  cntyear( 1 );
  cnt = s[ 0 ] - s[ 1 ];
  if( year[ 0 ] not_eq year[ 1 ])
    {
      cnt += ( year[ 0 ] - year[ 1 ] ) * DAYSEC * 365 ;
      for( i = year[ 0 ] + 1 ; i < year[ 1 ] ; ++ i)
	if( isleap( i ) )
	  cnt += DAYSEC;
    }
  return ;
}

int main()
{
  int t,i,j;
  char ch;
  cin>>t;cin.get();
  while( t > 0 )
    {
      cnt = 0;
      for( j = 0 ; j < 2 ; ++ j)
	{
	  year[ j ] = 0 , mon[ j ] = 0 , day[ j ] = 0 ;
	  hour[ j ] = 0 , mins[ j ] = 0 , sec[ j ] = 0 ;
	  for( i = 0 ; i < 4 ; ++ i)
	    year[ j ] = year[ j ] * 10 + cin.get() - 48;
	    
	  cin.get();
	  for( i = 0 ; i < 2 ; ++ i)
	    day[ j ] = day[ j ] * 10 + cin.get() - 48;
	  cin.get();
	  for( i = 0 ; i < 2 ; ++ i)
	    mon[ j ] = mon[ j ] * 10 + cin.get() - 48;
	  cin.get();
	  for( i = 0 ; i < 2 ; ++ i)
	    hour[ j ] = hour[ j ] * 10 + cin.get() - 48;
	  cin.get();
	  for( i = 0 ; i < 2 ; ++ i)
	    mins[ j ] = mins[ j ] * 10 + cin.get() - 48;
	  cin.get();
	  for( i = 0 ; i < 2 ; ++ i)
	    sec[ j ] = sec[ j ] * 10 + cin.get() - 48;
	  cin.get();
	}
      /*
      if( t > 1 )
	cin.get();
      */
      work();
      while( cnt % 300 not_eq 0 )
	++cnt;
      cout<<cnt/300<<"\n";
      --t;
    }
  return 0;
}
