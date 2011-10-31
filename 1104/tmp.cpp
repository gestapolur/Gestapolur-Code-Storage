//poj 3768
#include<cstdlib>
#include<cstdio>
#include<cmath>
//using namespace std;


//ifstream cin("test.in");
//ofstream cout("ans.out");


int n,m,lv;
//bool tep[ 6 ][ 6 ];
char ch[ 6 ][ 6 ];
//bool out[ 3005 ][ 3005 ];
char tc[ 3005 ][ 3005 ];
//char mod;

void cal(int lev , int sr , int sc , int er , int ec , int wide)//wide is block wide
{
  int i,j;
  //if(lev == 2) cout<<sr<<" "<<sc<<" "<<er<<" "<<ec<<"\n";

  if(lev == 1)
    for(i = 1 ; i <= n ; ++ i)
      for(j = 1 ; j <= n ; ++ j)
	tc[sr + i - 1 ][sc + j - 1 ] = ch[ i ][ j ];
  else
    for(i = 1 ; i <= n ; ++ i)
      for(j = 1 ; j <= n ; ++ j)
	if( ch[ i ][ j ] not_eq ' ')
	  cal(lev - 1 , sr + ( i - 1 ) * wide , sc + ( j - 1 ) * wide , i * wide , j * wide , wide / n );
	
  return ;
}

void clr()
{
  int i,j;
  for(i = 1 ; i <= m ; ++ i)
    for(j = 1 ; j <= m ; ++ j)
      tc[ i ][ j ] = ' ';

  return ;
}

int main()
{
  int i , j;
  //init
  for(i = 1 ; i <= 3000 ; ++ i)
    for(j = 1 ; j <= 3000 ; ++ j)
      tc[ i ][ j ] = ' ';

  while( 1 )
    {
      scanf("%d",&n);
      if(n == 0)
	return 0;
      //getline(cin , ch[ 0 ] );
      getchar();
      for(i = 1 ; i <= n ; ++ i)
	{
	  for(j = 1 ; j <= n ; ++ j)
	    ch[ i ][ j ] = getchar();
	  getchar();
	}

      //test
      /*
      cout<<"base: \n";
      for(i = 1 ; i <= n ; ++ i)
	{
	  for(j = 1 ; j <= n ; ++ j)
	    cout<<ch[ i ][ j ];
	  cout<<"\n";
	}
      */
      scanf("%d",&lv);
      m = pow(n,lv);
      //cout<<m<<"\n";
      cal(lv , 1 , 1 , m , m , m / n);
      /*
      for(i = 1 ; i <= m ; ++ i)
	{
	  for(j = 1 ; j <= m ; ++ j)
	    printf("%c",tc[ i ][ j ]);
	  printf("\n");
	}
      */
      /*
      for(i = 1 ; i <= m ; ++ i)
	{puts(tc[ i ] + 1);printf("\n");}
      */
      puts(tc[ 1 ] + 1);printf("\n");
      clr();
    }
  return 0;
}
