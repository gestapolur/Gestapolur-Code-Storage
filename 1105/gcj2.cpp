#include<fstream>
#define MAXL 21
#define MAXN 1005
using namespace std;

ifstream cin("C-large.in");
ofstream cout("ans.out");

bool c[ MAXN ][ MAXL ];
int s[ MAXN ][ MAXL ];
int len[ MAXN ] , tl[ MAXL ];
int w[ MAXN ];
int n,ans,maxs;

void change(int x , int p)
{
  int k;
  k = 1 ;
  while(x > 0)
    {
      c[ p ][ k ] = x & 1;
      tl[ k ] += x & 1;
      x = x >> 1;
      ++k;
    }
  
  len[ p ] = k - 1;

  /*
  for(int i = 1 ; i <= len[ p ] ; ++ i)
    cout<<c[ p ][ i ];cout<<"\n";
  */
  return ;
}

void sort(int i , int j)
{
  if( i >= j ) return ;
  int m,n,t,k;
  m = i , n = j , k = w[ i + j >> 1 ];
  while( m <= n )
    {
      while( w[ m ] < k ) ++ m;
      while( w[ n ] > k ) -- n;
      if( m <= n )
	{
	  t = w[ m ];w[ m ] = w[ n ];w[ n ] = t;
	  -- n ; ++ m ;
	}
    }
  sort( i , n );
  sort( m , j );
  return ;
}

void clr()
{
  for(int i = 1 ; i <= tl[ 0 ] ; ++ i) tl[ i ] = 0;
  tl[ 0 ] = 0;
  return ;
}

int main()
{
  int i , j , t , tt , pos ;
 
  cin>>t;
  tt = t;
  while( t > 0 )
    {
      cin>>n;
      clr();
      
      maxs = 0 ;
      for(i = 1 ; i <= n ; ++ i)
	{
	  cin>>w[ i ];
	  maxs += w[ i ];
	}

      sort( 1, n );
      
      for(i = 1 ; i <= n ; ++ i)
	change( w [ i ] , i );
      
      for(i = 1 ;i <= n ; ++ i)
	if( tl[ 0 ] < len[ i ] )
	  tl[ 0 ] = len[ i ];

      cout<<"Case #"<<tt-t+1<<": ";
      for(i = 1 ; i <= tl[ 0 ] ; ++i )
	  if( tl[ i ] & 1 ) 
	    {cout<<"NO\n";goto end;}
      
      for(i = 1 ;i <= n ; ++ i)
	for(j = 1 ; j <= tl[ 0 ] ; ++ j)
	  {
	    s[ i ][ j ] = s[ i - 1 ][ j ];
	    if(c[ i ][ j ])
	      s[ i ][ j ] += c[ i ][ j ];
	  }
      
      //test
      /*
      cout<<"\n";
      for(i = 1 ; i <= n ; ++ i)
	{
	  for( j = 1 ; j <= tl[ 0 ] ; ++ j)
	    cout<<c[ i ][ j ]<<" ";
	  cout<<"\n";
	}
      cout<<"\n";
      for(i = 1 ;i <= n ; ++ i)
	{
	  for(j = 1 ;j <= tl[ 0 ] ; ++ j)
	    cout<<s[ i ][ j ]<<" ";
	  cout<<"\n";
	}
      */
      pos = 1;
      for(i = 1 ; i <= n ; ++ i)
	while(( s[ i ][ n ] - s[ i ][ pos ] - s[ i ][ pos ] ) & 1 == 0)
	  ++ pos;
      
      ans = 0 ;
      //cout<<pos<<" "<<w[ pos ]<<"\n";
      for(i = 1 ; i <= pos ; ++ i)
	ans += w[ i ];
      ans = ans > (maxs - ans ) ? ans : ( maxs - ans );
      cout<<ans<<"\n";
    end: --t ;
    }
  return 0;
}
