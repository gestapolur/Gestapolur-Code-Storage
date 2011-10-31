#include<iostream>
#define MAXN 100
using namespace std;

int c,v[MAXN],p[ MAXN ];

void sort( int i , int j )
{
  if ( i >= j ) return ;
  int m,n,t,k;
  m = i , n = j , k = p[ i + j >> 1 ];
  while(m<=n)
    {
      while(p[ m ] < k ) ++m ;
      while(p[ n ] > k ) -- n ;
      if(m <=n )
	{
	  t = p[ m ] ; p[ m ] = p[ n ] ; p[ n ] = t;
	  t = v[ m ] ; v[ m ] = v[ n ] ; v[ n ] = t;
	  ++m ; -- n;
	}
    }
  sort( i , n );
  sort( m , j );
  return ; 
}

double abs(double a ){return a > 0 ? a : -a;}

double dist(double a , double b){return abs(a-b);}

int main()
{
  int i,j,k;
  int t,tt;
  bool change;
  double stt , d , td , tst , tans , ans;
  cin>>tt;
  t = 1;
  while ( t <= tt )
    {
      ans = 99999999;
      cin>>c;cin>>d;
      
      for( i = 1 ; i <= c ; ++ i)
	{
	  cin>>p[ i ];
	  cin>>v[ i ];
	}
      cout<<"!!!\n";
      sort( 1 , c );
      cout<<"!!!!\n";
      stt = p[ 1 ] - d*(v[ 1 ] - 1 );
      //cout<<stt<<"!!!\n";cin.get();
      
      do{
	change = false;
	tans = 0.00000;
	tst = stt;
	for( i = 1 ; i <= c ; ++ i)
	  {
	    td = max( dist(p[ i ] , tst ) , dist(p[ i ] , tst + d*(v[ i ] - 1 )));
	    if(td > tans )
	      tans = td;
	    tst = tst + d*v[ i ];
	  }
	cout<<tans<<" "<<stt<<" ";//cin.get();
	if(ans > tans ) {ans = tans;change = true;}
	stt = stt + 0.0001;
      }while( change );
      cout<<"Case #"<<t<<": "<<ans<<"\n";
      ++t;
    }
  return 0;
}
