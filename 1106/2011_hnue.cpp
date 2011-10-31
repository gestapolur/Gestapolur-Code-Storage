/*
  HNU 2011 E
  write by Gestapolur
  daily training
  2011-06-15
*/
#include<fstream>
#define MAXN 1048577
using namespace std;

ifstream cin("1.in");
ofstream cout("1.ans");

int s[ MAXN ] , pos[ MAXN ] , con[ MAXN ];
int f[ MAXN ];
int w[ 20 ] , c[ 20 ][ 20 ] , val[ MAXN ];
int n,m,tp,fst,tot,ans;

void bin( int x )
{
  while( x )
    {
      cout<<x%2;
      x >>= 1 ;
    }
  cout<<"\n";
  return ;
}

void gen( int x )
{
  int i , p , now , cnt ;

  for( i = 1 ; i <= fst ; ++ i)
    pos[ i ] = 0 , con[ i ] = 0 ;
  
  p = x ;now = 1 << x - 1 ;con[ now ] = 1 ;pos[ now ] = 1;

  while( p > 0 )
    {
      if( p < n and con[ now ] < 3 )
	{
	  pos[ now ] = ++p; //p is the last digit that sequence in
	  now |= 1 << p - 1  ;
	  con[ now ] = con[ now ^ ( 1 << p - 1 ) ] + 1;
	}
      else
	{
	  //count the value
	  if( con[ now ] == 3 )
	    {
	      s[ ++ tot ] = now;
	      int tmp[ 4 ];
	      for ( i = 0 ; i <= 3 ; ++ i )
		tmp[ i ] = 0;
	      i = now ; cnt = 0 ;
	      while( i )
		{
		  ++cnt;
		  if( i % 2 )
		    tmp[ ++ tmp[ 0 ] ] = cnt;
		  i>>=1;
		}
	      val[ tot ] = w[ tmp[ 1 ] ] + w[ tmp[ 2 ] ] + w[ tmp[ 3 ] ] 
		+ c[ tmp[ 1 ] ][ tmp[ 2 ] ] + c[ tmp[ 2 ] ][ tmp[ 3 ] ] + c[ tmp[ 1 ] ][ tmp[ 3 ] ];
	    }
	  //decrease the leftest 1 digit
	  i = 0 ;
	  while( 1 << i < now )
	    ++ i;
	  if( i ) -- i;
	  now ^= 1 << i;
	  p = pos[ now ];
	}
    }
  return ;
}

int main()
{
  int t,i,j;
  cin>>t;
  while ( t > 0 )
    {
      cin>>m>>n;
      fst = (1 << n) - 1 >> ( n - 3 * m ) << ( n - 3 * m );
      //cout<<fst<<" ";bin( fst );
      //clear
      for( i = 0 ; i <= fst ; ++ i)
	f[ i ] = 0;
      
      for( i = 1 ; i <= n ; ++ i)
	cin>>w[ i ];
      for( i = 1 ; i <= n ; ++ i )
	for( j = 1 ; j <= n ; ++ j )
	  cin>>c[ i ][ j ];
      tot = 0;

      for( i = 1 ; i <= n - m + 1 ; ++ i )
	gen( i );
      /*
      cout<<" tot "<<tot<<"\n";
      for( i = 1 ; i <= tot ; ++ i )
	{
	  cout<<s[ i ]<<" "<<val[ i ]<<" ";
	  bin( s[ i ] );
	}
      
      cout<<"-----------\n";
      */
      //dynamci programming
      ans = 0 ;
      for( i = 1 ; i <= fst ; ++ i)
	{
	  for( j = 1 ; j <= tot ; ++ j )
	    if( (i & s[ j ]) == s[ j ] and f[ i ] < f[ i ^ s[ j ] ] + val[ j ] )
	      {
		f[ i ] = f[ i ^ s[ j ] ] + val[ j ];
		//cout<<i<<" "<<j<<" ";bin( i );
	      }
	  if( ans < f[ i ])
	    ans = f[ i ];//cout<<i<<" ";bin(i);}
	}
      cout<<ans<<"\n";
      //clear
      -- t;
    }
  return 0;
}
