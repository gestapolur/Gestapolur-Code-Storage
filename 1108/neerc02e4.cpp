// NEERC 02' E AC
#include<iostream>
#include<cstdlib>
#define MAXN 216
#define INF 1000000000
using namespace std;

int bn , sn , ccost ;
int sx[ MAXN ] , sy[ MAXN ] , bx[ MAXN ] , by[ MAXN ];

int n ;
int f[ MAXN ][ MAXN ] , c[ MAXN ][ MAXN ] , w[ MAXN ][ MAXN ] , tw[ MAXN ][ MAXN ];
int pre[ MAXN ] , mark[ MAXN ] , q[ MAXN * MAXN ];
int mincost , maxflow;
short int cnt[ MAXN ];//record refresh order
bool in[ MAXN ] , h[ MAXN ];
//source is 1 and sink is n 

//if we found any circle , end the loop , is there any no aug condition?
void findflow()
{
  int i , j , k , u , v , p , tmin , rec ;
  int rear , front ;
  rear = 1 , front = 0;

  for( i = 1 ; i <= n ; ++ i ) 
    { in[ i ] = 0 ; mark[ i ] = INF; pre[ i ] = 0 ; }

  q[ 1 ] = 1 ; mark[ 1 ] = 0 ; cnt[ 1 ] = 1 ;
  
  do{
    p = q[ ++ front ];
    in[ p ] = false;
    for( i = 1 ; i <= n ; ++ i )
      if( c[ p ][ i ] > 0 and  w[ p ][ i ] not_eq INF 
	  and mark[ i ] > mark[ p ] + w[ p ][ i ] )
	{ 
	  mark[ i ] = mark[ p ] + w[ p ][ i ] ;pre[ i ] = p;
	  
	  if( not in[ i ] )
	    { 
	      q[ ++ rear ] = i;
	      in[ i ] = true;
	      ++ cnt[ i ];
	      if( cnt[ i ] >= n )
		{
		  //cout<<"!!!!\n";
		  for( j = n ; j >= 1 ; -- j )
		    {
		      for( v = 1 ; v <= n; ++ v ) h[ v ] = false;
		      v = j ;
		      //find the circle 
		      do{
			h[ v ] = true;
			v = pre[ v ];
		      }while( not h[ v ] and v > 1 );
		      
		      if( v > 1 )
			{
			  //cout<<v<<"!\n";cin.get();cin.get();
			  k = v;
			  for( v = 1 ; v <= n ; ++ v ) h[ v ] = false;
			  
			  do{
			    //cout<<pre[ k ]<<"-"<<k<<" ";
			    -- c[ pre[ k ] ][ k ];
			    ++ c[ k ][ pre[ k ] ];
			    mincost += w[ pre[ k ] ][ k ];
			    h[ k ] = true;
			    k = pre[ k ];
			  }while( not h[ k ] );
			  //cout<<"\n";
			  //break;
			  goto end;//finish the loop 
			}
		    }
		  break;
		}
	    }
	}
  }while( front <= rear );
 end : ;
  return ;
}

void init()
{
  int i , j , tn ;
  cin>>bn>>sn;
  
  for( i = bn + sn + 2  ; i >= 1 ; -- i )
    for( j = bn + sn + 2  ; j >= 1 ; -- j )
      w[ i ][ j ] = INF;
  
  for( i = 1 ; i <= bn ; ++ i )
    {
      cin>>bx[ i ]>>by[ i ]>>f[ 1 ][ i + 1 ];
      c[ 1 ][ i + 1 ] = f[ 1 ][ i + 1 ];
      w[ 1 ][ i + 1 ] = w[ i + 1 ][ 1 ] = 0;
    }

  for( i = 1 ; i <= sn ; ++ i )
    {
      cin>>sx[ i ]>>sy[ i ]>>f[ bn + i + 1 ][ bn + sn + 2 ];
      c[ bn + i + 1 ][ bn + sn + 2 ] = f[ bn + i + 1 ][ bn + sn + 2 ];
      w[ bn + i + 1 ][ sn + bn + 2 ] = w[ sn + bn + 2 ][ bn + i + 1 ] = 0;
    }

  //count the dist
  for( i = 1 ; i <= bn ; ++ i )
    for( j = 1 ; j <= sn ; ++ j )
      {
	w[ i + 1 ][ bn + j + 1 ] = abs( bx[ i ] - sx[ j ] ) + abs( by[ i ] - sy[ j ] ) + 1 ;
	w[ bn + j + 1 ][ i + 1 ] = -w[ i + 1 ][ bn + j + 1 ];
	f[ i + 1 ][ bn + j + 1 ] = f[ 1 ][ i + 1 ];
	c[ i + 1 ][ bn + j + 1 ] = c[ 1 ][ i + 1 ];
      }

  //source = 1 , sink = bn + sn + 2
  n = sn + bn + 2 ; 

  // cal the council cost
  for( i = 1 ; i <= bn ; ++ i )
    for( j = 1 ; j <= sn ; ++ j )
      {
	cin>>tn;

	c[ i + 1 ][ bn + j + 1 ] -= tn;
	c[ bn + j + 1 ][ i + 1 ] += tn;

	c[ bn + j + 1 ][ bn + sn + 2 ] -= tn;
	c[ bn + sn + 2 ][ bn + j + 1 ] += tn;
 	ccost += w[ i + 1 ][ bn + j + 1 ] * tn  ;
	maxflow += tn;
      }
  mincost = ccost ;

  return ;
}

void output()
{

  if( mincost == ccost ) cout<<"OPTIMAL\n";
  else
    {
      cout<<"SUBOPTIMAL\n";
      for(int i = 1 ; i <= bn ; ++ i )
	{
	  for(int j = 1 ; j <= sn ; ++ j )
	    {
	      cout<<f[ i + 1 ][ bn + j + 1 ] - c[ i + 1 ][ bn + j + 1 ];
	      cout<<( j < sn  ? " " : "\n");
	    }
	}
    }

  return ;
}

int main()
{
  init();

  findflow();

  output();
  
  return 0;
}
