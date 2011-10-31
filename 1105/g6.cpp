#include<fstream>
#define MAXN 50000005
using namespace std;

ifstream cin("B-small-practice.in");
ofstream cout("ans.out");

long long  li,tp,n,c;
long long  a[ MAXN ],dis[ MAXN ];
long long p[ MAXN ];

void sort( int i , int j )
{
  if( i >= j ) return ; 
  long long m,n,t,k;
  m = i ,n = j , k = p[ i + j >> 1];
  while(m <= n)
    {
      while(p[ m ] < k ) ++ m;
      while(p[ n ] > k ) -- n;
      if(m<=n)
	{
	  t = p[ m ] ; p[ m ] = p[ n ] ; p[ n ] = t;
	  ++m ; --n;
	}
    }
  sort( i , n );
  sort( m , j );
  return ; 
}

int main()
{
  long long t,tt,i,k,j,prest,rest;
  long long ans;
  cin>>tt;
  t = 1;
  while(t <= tt )
    {
      cin>>li>>tp>>n>>c;
      for( i = 1 ; i <= c; ++ i)
	  cin>>a[ i ];
      
      for( i = 1 ; i <= c ; ++ i)
	for(k = 0 ; k * c + i <= n ; ++ k )
	  dis[ k * c + i  ] = a[ i ];

      prest = tp;ans = 0 ;
      for( i = 1 ; i <= n ; ++ i )
	if( prest > 0 )
	    {
	      if( prest - dis[ i ]*2 >= 0 )
		{prest -= dis[ i ]*2 ; ans += dis[ i ]*2;}
	      else
		{
		  ans += prest ;
		  dis[ i ] = dis[ i ] - prest / 2 ;
		  for( j = i ; j <= n ; ++ j)
		    p[ j - i + 1 ] = dis[ j ];
		  rest = n - i + 1 ;
		  sort( 1 , n - i + 1 );
		  break;
		}
	    }

      i = rest;
      while( i > 0 )
	{
	  if( li > 0)
	    {
	      ans += p[ i ];
	      --li;
	    }
	  else
	    ans += p[ i ] * 2;
	  --i;
	}

      cout<<"Case #"<<t<<": "<<ans<<"\n";
      ++t;
    }
  return 0;
}
