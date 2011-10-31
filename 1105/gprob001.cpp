/*
  grob #001 collect that Upa!
  on test
  write by gestapolur
*/
#include<fstream>
#define MAXN 55 
#define INF 19911113
using namespace std;

ifstream cin("./testdata/upa.in");
ofstream cout("./testdata/upac.out",ios::binary);

const short int dir[2][4] = {{0,0,1,-1},{1,-1,0,0}};/* moving directions */

int n,m,tb;//tb is the total buildings
int w[ MAXN ][ MAXN ];//scape condition
int col[ MAXN][ MAXN ];//building numbers
int con[ MAXN * MAXN ][ MAXN * MAXN ] , mark[ MAXN * MAXN ] ;//shortest dist between buildings
bool in[ MAXN * MAXN ] , bla[ MAXN ][ MAXN ];
int ans;//total distance 

void floodfill( int c , int r )
{
  col[ c ][ r ] = tb;
  if(c + 1 <= n and w[ c + 1 ][ r ] == 1 and not col[ c + 1 ][ r ]) floodfill( c + 1 , r );
  if(r + 1 <= m and w[ c ][ r + 1 ] == 1 and not col[ c ][ r + 1 ]) floodfill( c , r + 1 );
}

void bfs( int c , int r , int orgc ,int step , bool in[ MAXN ][ MAXN ])
{
  //cout<<c<<" "<<r<<" "<<orgc<<" "<<step<<"\n";
  for( int i = 0 ; i < 4 ; ++ i)
  if( c + dir[ 0 ][ i ] <= n and c + dir[ 0 ][ i ] > 0 
      and r + dir[ 1 ][ i ] <= m and r + dir[ 1 ][ i ] > 0  
      and col[ c + dir[ 0 ][ i ] ][ r + dir[ 1 ][ i ]] not_eq orgc 
      and not in[ c + dir[ 0 ][ i ] ][ r + dir[ 1 ][ i ] ])
    {
      if(col[ c + dir[ 0 ][ i ] ][ r + dir[ 1 ][ i ]] == 0 )
	{
	  in[ c + dir[ 0 ][ i ] ][ r + dir[ 1 ][ i ]] = true;
	  bfs( c + dir[ 0 ][ i ] , r + dir[ 1 ][ i ], orgc , step + 1 , in );
	  in[ c + dir[ 0 ][ i ] ][ r + dir[ 1 ][ i ] ] = false;
	}
      else if(con[ orgc ][ col[ c + dir[ 0 ][ i ] ][ r + dir[ 1 ][ i ] ] ] > step + 1 )
	{
	  con[ orgc ][ col[ c + dir[ 0 ][ i ] ][ r + dir[ 1 ][ i ]] ] = step + 1 ;
	  con[ col[ c + dir[ 0 ][ i ] ][ r + dir[ 1 ][ i ]] ][ orgc ] = step + 1 ;
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
      //cout<<mark[ i ]<<" ";
    }
  //cout<<"\n";
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
	cout<<col[ i ][ j ]<<" ";
      cout<<"\n";
    }
  */
  //init
  for( i = 1 ; i <= tb ; ++ i)
    for( j = 1 ; j <= tb ; ++ j)
      con[ i ][ j ] = INF;
  //count the distance between buildings
  for( i = 1 ; i <= n ; ++ i)
    for( j = 1 ; j <= m ; ++ j)
      if(col[ i ][ j ])
	{
	  bla[ i ][ j ] = true;
	  bfs( i , j , col[ i ][ j ] , 0 , bla);
	  bla[ i ][ j ] = false;
	}

  //test
  /*
  cout<<tb<<"\n";
  for( i = 1 ; i <= tb ; ++ i )
    {
      for( j = 1 ; j <= tb ; ++ j)
	if( con[ i ][ j ] not_eq INF )
	  cout<<con[ i ][ j ]<<" ";
	else cout<<"x ";
      cout<<"\n";
    }
  */
  prim();

  cout<<ans<<"\n";

  return 0;
}
