/*
  grob #001 collect that Upa!
  all done.
  write by gestapolur
*/
#include<fstream>
#define MAXN 55
#define INF 19911113 
using namespace std;

ifstream cin("./testdata/upa9.in");
ofstream cout("./testdata/upa9.out",ios::binary);

int n,m,tb;//tb is the total buildings
int w[ MAXN ][ MAXN ];//scape condition
int col[ MAXN][ MAXN ];//building numbers in each district
bool in[ MAXN * MAXN ];//prim process : whether in tree
int ans;//total distance
int con[ MAXN * MAXN ][ MAXN * MAXN ] , mark[ MAXN * MAXN ]; 

//calculate buildings
void floodfill( int c , int r )
{
  col[ c ][ r ] = tb;
  if(c + 1 <= n and w[ c + 1 ][ r ] == 1 and not col[ c + 1 ][ r ]) floodfill( c + 1 , r );
  if(r + 1 <= m and w[ c ][ r + 1 ] == 1 and not col[ c ][ r + 1 ]) floodfill( c , r + 1 );
  if(r - 1 > 0 and w[ c ][ r - 1 ] == 1 and not col[ c ][ r - 1 ]) floodfill( c , r - 1 );
  if(c - 1 > 0 and w[ c - 1 ][ r ] == 1 and not col[ c - 1 ][ r ]) floodfill( c - 1 , r );
  return ;
}

void cnt()
{
  int i,j,k,v,p[ 4 ],d[ 4 ],tmp;

  //init
  for( i = 1 ; i <= tb ; ++ i )
    for( j = 1 ; j <= tb ; ++ j )
      con[ i ][ j ] = INF;
  
  //cal
  for( i = 1 ; i <= n ; ++ i )
    for( j = 1 ; j <= m ; ++ j )
      if(not col[ i ][ j ] )
	{
	  for( k = 0 ; k < 4 ; ++ k )
	    { p[ k ] = 0 , d[ k ] = INF ;}
	  tmp = i + 1 ;
	  while(tmp <= n)
	    {
	      if( col[ tmp ][ j ] )
		{p[ 0 ] = col[ tmp ][ j ] ; d[ 0 ] = tmp - i ; break ;}
	      ++tmp;
	    }
	  tmp = i - 1 ;
	  while(tmp > 0 )
	    {
	      if( col[ tmp ][ j ] )
		{p[ 1 ] = col[ tmp ][ j ] ; d[ 1 ] = i - tmp ; break ;}
	      --tmp;
	    }
	  tmp = j + 1 ;
	  while(tmp <= m )
	    {
	      if( col[ i ][ tmp ] )
		{p[ 2 ] = col[ i ][ tmp ] ; d[ 2 ] = tmp - j ; break ;}
	      ++tmp;
	    }
	  tmp = j - 1 ;
	  while(tmp > 0 )
	    {
	      if( col[ i ][ tmp ] )
		{p[ 3 ] = col[ i ][ tmp ] ; d[ 3 ] = j - tmp ; break ;}
	      --tmp;
	    }

	  for( k = 0 ; k < 4 ; ++ k )
	    for( v = 0 ; v < 4 ; ++ v )
	      if( k not_eq v and p[ k ] not_eq p[ v ] 
		  and con[ p[ k ] ][ p[ v ] ] > d[ k ] + d[ v ] )
		{
		  //cout<<p[ k ]<<" "<<p[ v ]<<" "<<k<<" "<<v<<" "<<d[ k ]<<" "<<d[ v ]<<"\n";
		  con[ p[ k ] ][ p[ v ] ] = d[ k ] + d[ v ];
		  con[ p[ v ] ][ p[ k ] ] = d[ k ] + d[ v ];
		}
	}

  return ;
}

void prim()
{
  int i,j,k,mint;
  
  for( i = 1 ; i <= tb ; ++ i)
    {
      mark[ i ] = con[ 1 ][ i ];
      in[ i ] = false;
    }
  in[ 1 ] = true;
  
  for( i = 1 ; i < tb ; ++ i)
    {
      mint = INF;
      for( j = 1 ; j <= tb ; ++ j)
	if(not in[ j ] and mint > mark[ j ])
	  {mint = mark[ j ]; k = j;}
      in[ k ] = true;
      ans += mark[ k ];
      //cout<<k<<" ";
      for( j = 1 ; j <= tb ; ++ j)
	if( mark[ j ] > con[ k ][ j ])
	  mark[ j ] = con[ k ][ j ];
    }
  //cout<<"\n";
  return ;
}


int main()
{
  int i,j;
  char ch;
  cin>>n>>m;
  for( i = 1 ; i <= n ; ++ i)
    for( j = 1 ; j <= m ; ++ j)
      {
	cin>>ch;
	if( ch == 'B' ) w[ i ][ j ] = 1 ;
	else w[ i ][ j ] = 0;
      }

  //test
  /*
  for( i = 1 ; i <= n ; ++ i )
    {
      for( j = 1 ; j <= m ; ++ j)
	cout<<w[ i ][ j ]<<" ";
      cout<<"\n";
    }
  */
  //calculate buildings
  for( i = 1 ; i <= n ; ++ i)
    for( j = 1 ; j <= m ; ++ j)
      if(w[ i ][ j ] == 1 and not col[ i ][ j ] )
	{
	  ++tb;
	  floodfill( i , j );
	}

  //test
  /*
  for( i = 1 ; i <= n ; ++ i)
    {
      for( j = 1 ; j <= m ; ++ j)
	cout<<col[ i ][ j ];
      cout<<"\n";
    }
  */
  cnt();
  /*
  cout<<tb<<"\n";
  for( i = 1 ; i <= tb ; ++ i )
    {
      for( j = 1 ; j <= tb ; ++ j )
	cout<<con[ i ][ j ]<<" ";
      cout<<"\n";
    }
  */
  prim();
  
  cout<<ans<<"\n";

  return 0;
}
