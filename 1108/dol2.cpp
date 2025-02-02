/*
  WHU 2009 IC DOLPHIN
  write a hash and check the distance in a food chose condition
  write by Gestapolur
  2011-08-29
*/
#include<iostream>
#include<cstring>
#define MAXN 102
#define INF 2141483647
#define MAXC 199113
using namespace std;

int w[ MAXN ][ MAXN ] , lnk[ MAXN ][ MAXN ];
int n , m , s , e , ans , toc ;//totaly color
int type[ MAXN ] , ty[ MAXN ] , pos[ MAXN ];
int stack[ MAXN * MAXN ] , next[ MAXN * MAXN ];
int hash[ MAXC ][ 10 ] , hashm[ MAXC ][ 10 ];

class queue
{
public:
  int cnt , dist , cur;
  bool fd[ MAXN ] , verx[ MAXN ];

  void clr()
    {
      for( int i = 1 ; i <= toc ; ++ i )
	fd[ i ] = false;
      for( int i = 1 ; i <= n ; ++ i )
	verx[ i ] = false;
      cnt = 0 , dist = 0 , cur = 0 ;
    }
  int comp()
  { 
    int sum = 0 ;
    for( int i = 1 ; i <= n ; ++ i )
      sum += i * verx[ i ];
    return sum;
  }
};

queue q[ MAXN * MAXN ];

bool transhash( int x , int d )
{
  int y = x % MAXC;
  if( hash[ y ][ 0 ] > 0 )
    for( int i = 1 ; i <= hash[ y ][ 0 ] ; ++ i )
      if( hash[ y ][ i ] == x )
	{
	  if( hashm[ y ][ i ] > d )
	    {
	      hashm[ y ][ i ] = d;
	      return true;
	    }
	  else
	    return false;
	}
  hash[ y ][ ++ hash[ y ][ 0 ] ] = x;
  hashm[ y ][ hash[ y ][ 0 ] ] = d ;
  return true;
}

void bfs()
{
  int rear ,front , maxr ;
  int i ;
  queue p ;
  q[ 1 ].clr();
  q[ 1 ].cnt = 1 , q[ 1 ].dist = 0 , q[ 1 ].fd[ type[ s ] ] = true , q[ 1 ].cur = s;
  q[ 1 ].verx[ s ] = true; 
  rear = 1 , front = 0 ; next[ 0 ] = 1 ; maxr = 1 ;
  transhash( q[ 1 ].comp() , 0 );
  do{
    
    front = next[ front ];
    //cout<<stack[ 0 ]<<" "<<front<<" "<<maxr<<"\n";
    p = q[ front ];
    //cout<<p.cur<<" "<<p.dist<<" "<<p.cnt<<" ";
    //for( i = 0 ; i < toc ; ++ i ) cout<<p.fd[ i ];cout<<"\n";
    if( p.cur not_eq e )
      {
	for( i = 1 ; i <= lnk[ p.cur ][ 0 ] ; ++ i )
	  if( not p.fd[ type[ lnk[ p.cur ][ i ] ] ] )
	    {
	      p.verx[ lnk[ p.cur ][ i ] ] = true ;
	      if ( transhash( p.comp() , p.dist + w[ p.cur ][ lnk[ p.cur ][ i ] ] )  )
		{
		  //cout<<front<<" "<<rear<<" created ";
		  if( stack[ 0 ] > 0 ) 
		    { next[ rear ] = stack[ stack[ 0 ] ]; rear = stack [ stack[ 0 ] -- ];}
		  else
		    { next[ rear ] = maxr + 1 ; rear = ++ maxr ; }
		  //if( maxr >= MAXN * MAXN ) while( 1 ) {} 
		  //cout<<maxr<<" "<<front<<" "<<rear<<"\n";
		  //cout<<rear<<"\n";
		  next[ rear ] = 0 ;
		  q[ rear ] = p; 
		  q[ rear ].cnt ++ ;
		  q[ rear ].dist += w[ p.cur ][ lnk[ p.cur ][ i ] ];
		  q[ rear ].cur = lnk[ p.cur ][ i ];
		  q[ rear ].verx[ lnk[ p.cur ][ i ] ] = true;
		}
	      p.verx[ lnk[ p.cur ][ i ] ] = false ;	      
	    }
      }
    else if( p.cnt == toc and p.dist < ans )
      ans = p.dist ;
    stack[ ++ stack[ 0 ] ] = front;
    q[ front ].clr();
    //cout<<front<<" "<<next[ front ]<<" "<<rear<<"\n";
    //cin.get();
  }while( front not_eq 0 );

  return ;
}

void init()
{
  int i , j , u , v , wi ;
  cin>>n>>m>>s>>e;
  ++ s , ++ e ;
  for( i = 1 ; i <= m ; ++ i )
    {
      cin>>u>>v>>wi;
      ++ v , ++ u;
      w[ u ][ v ] = wi;
      w[ v ][ u ] = wi;
      lnk[ u ][ ++ lnk[ u ][ 0 ] ] = v ;
      lnk[ v ][ ++ lnk[ v ][ 0 ] ] = u ;
    }

  
  //count the differ foods
  
  for( i = 1 ; i <= n ; ++ i )
    { cin>>ty[ i ]; pos[ i ] = i ;}
  //cout<<"end\n";
  for( i = 1 ; i < n ; ++ i )
    for( j = i + 1 ; j <= n ; ++ j )
      if( ty[ i ] >  ty[ j ] )
	{  
	  wi = ty[ i ] ; ty[ i ] = ty[ j ] ; ty[ j ] = wi ; 
	  wi = pos[ i ] ; pos[ i ] = pos[ j ] ; pos[ j ] = wi;  
	}

  toc = 1;

  for( i = 2 ; i <= n ; ++ i )
    if( ty[ i ] == ty[ i - 1 ] )
      type[ pos[ i ] ] = type[ pos[ i - 1 ] ];
    else
      type[ pos[ i ] ] = type[ pos[ i - 1 ] ] + 1 , ++ toc;
  //cout<<toc<<"\n";
  //for( i = 1 ; i <= n ; ++ i ) cout<<type[ i ]<<" "; cout<<"\n";
  
  ans = INF;

  //test
  /*
  for( i = 1 ; i <= n;  ++ i )
    {
      cout<<i<<" : ";
      for( j = 1 ; j <= lnk[ i ][ 0 ] ; ++ j )
	cout<<lnk[ i ][ j ]<<":"<<w[ i ][ lnk[ i ][ j ] ]<<" ";
      cout<<"\n";
    }
  */
  return ;
}

void output()
{
  if( ans not_eq INF ) cout<<ans<<"\n";
  else cout<<-1<<"\n";
  memset( stack , 0 , sizeof( stack ) );
  memset( q , 0 , sizeof( q ) );
  memset( lnk , 0 , sizeof( lnk ) );
  memset( w , 0 , sizeof( w ) );
  memset( type , 0 , sizeof( type ) );
  memset( ty , 0 , sizeof( ty ) );
  memset( pos , 0 , sizeof( pos ) );
  memset( hash , 0 , sizeof( hash ) );
  memset( hashm , 0 , sizeof( hashm ) );
  memset( next , 0 , sizeof( next ) );
  toc = 0 ;
  return ;
}

int main()
{
  int t;
  cin>>t;
  while( t -- )
    {
      init();
      //cout<<" end in \n";
      bfs();
      //cout<<" end b \n";
      output();
    }  

  return 0;
}
