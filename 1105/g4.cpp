#include<fstream>
#define MAXN 55
using namespace std;

ifstream cin("A-large.in");
ofstream cout("ans.out");

int n,m;
int w[ MAXN ][ MAXN ];
int cnt,dfill;

void bfs( int sx ,int sy)
{
  int i , j ;
  i = sx , j = sy;
  if(i + 1 <= n and j + 1 <= m and  w[ i + 1 ][ j + 1 ] == 1 and w[ i ][ j + 1 ] == 1 and w[ i + 1 ][ j ] == 1 )
    {
      w[ i ][ j + 1 ] = 2 ; w[ i + 1 ][ j ] = 2;
      w[ i + 1 ][ j + 1 ] = 3;w[ i ][ j ] = 3;
      dfill += 4;
      for( i = 1 ; i <= n ; ++ i )
	for( j = 1 ; j <= m ; ++ j)
	  if(w[ i ][ j ] == 1 )
	    bfs( i , j );
    }
  return ;
}

int main()
{
  int i,j,sx,sy;
  int t,tt;
  char ch;
  cin>>tt;
  t = 1;
  while( t <= tt)
    {
      cnt = 0 ;
      dfill = 0 ;
      cin>>n>>m;
      for( i = 1 ;i <= n ; ++ i)
	for( j = 1 ; j <= m ; ++ j)
	  {
	    cin>>ch;
	    if(ch == '.') w[ i ][ j ] = 0;
	    else {w[ i ][ j ] = 1 ; ++cnt;}
	    
	  }
      //cout<<cnt<<"\n";
      cout<<"Case #"<<t<<":\n";
      if( cnt % 4 == 0 )
	{
	  dfill = 0 ;
	  //cout<<"!!!!\n";
	  for( i = 1 ; i <= n ; ++ i)
	    for( j = 1 ; j <= m ; ++ j)
	      if( w[ i ][ j ] == 1) {sx = i , sy = j;goto start;}
	start :
	  bfs( sx , sy );
	  if(dfill == cnt )
	    for( i = 1 ; i <= n ; ++ i)
	      {
		for( j = 1 ; j <= m ; ++ j)
		  if(w[ i ][ j ] == 2) cout<<"\\";
		  else if(w[ i ][ j ] == 3) cout<<"/";
		  else cout<<".";
		cout<<"\n";
	      }
	  else
	    cout<<"Impossible\n";
	}
      else
	cout<<"Impossible\n";
      ++ t;
    }
  return 0;
}
