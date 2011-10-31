#include<fstream>
#include<cstdio>
#include<cstdlib>
#define MAXN 100005
#define MAXM 50005
using namespace std;
ifstream cin("zoo.in");
ofstream cout("zoo.out");

struct Tseg
{
  int L,R,k,idx;
};


Tseg seg[MAXM];
int num[MAXN],pos[MAXN],key[MAXN];
int sum[MAXN << 3];
int res[MAXM];
int N,M,tot;

void init()
{
  int i;
  cin>>N>>M;
  for(i = 1 ; i <= N ; ++ i)
    cin>>num[i];
  for(i = 1 ; i <= M ; ++ i)
    {
      cin>>seg[i].L>>seg[i].R>>seg[i].k;
      seg[i].idx = i;
    }
}

void sort (int L ,int R)
{
  if (L >= R ) return ;
  int i,j,cmp,t;
  i = L ; j = R ; cmp = key [  L + R  >> 1 ];
  while(i <= j)
    {
      while (key [ i ] < cmp ) ++i;
      while (key [ j ] > cmp ) --j;
      if(i <= j)
	{
	  t = key[ i ] ; key[ i ] = key[ j ] ; key[ j ] = t;
	  ++i;
	  --j;
	}
    }
  sort ( L , j ); 
  sort ( i , R );
}

void sortS (int L , int R)
{
  if (L >= R) return;
  int i,j,cmp;
  Tseg t;
  i = L ; j = R ; cmp = seg [  L + R  >> 1 ] . L;
  while(i <= j )
    {
      while (seg [ i ] . L < cmp) ++i;
      while (seg [ j ] . L > cmp) --j;
      if (i <= j)
	{
	  t = seg[ i ] ; seg[ i ] = seg[ j ] ; seg[ j ] = t;
	  ++i;
	  --j;
	}
    }
  sortS ( L , j ) ;
  sortS ( i , R );
}

int find (int num )
{
  int L , R , mid;
  L = 1 ; R = tot;
  while(L <= R)
    {
      mid =  L + R  >> 1;
      if (key [ mid ] == num) 
	return mid ; 
      else if (key [ mid ] > num) 
	R = mid - 1; 
      else 
	L = mid + 1;
    }
}

void prepare()
{
  int i;
  sortS ( 1 , M );
  for(i = 1 ; i <= N ; ++ i )
    key[ i ] = num[ i ];
  sort ( 1 , N );
  tot = 0;

  for(i = 1 ; i <= N ; ++ i)
    if(i == 1 or key[ i ] != key[ i - 1 ])
      key[ ++tot ] = key[ i ];

  for(i = 1 ; i <= N ; ++ i)
    pos[ i ] = find(num[ i ]);
       
}

void insert (int cnt ,int L ,int R ,int p ,int delta )
{
  if ( L > p  or  R < p ) return ;
  sum[ cnt ] += delta;
  if (L == R) return ;
  int mid =  L + R  >> 1;
  insert ( cnt << 1 , L , mid , p , delta );
  insert ( (cnt << 1) + 1 , mid + 1 , R , p , delta );
}

int query (int cnt ,int L ,int R ,int k )
{
  if (L == R) 
    return key [ L ] ;

  int mid =  L + R  >> 1;

  if (sum [ cnt << 1 ] >= k)
    return query ( cnt << 1 , L , mid , k );
  else
    return query ( (cnt << 1) + 1 , mid + 1 , R , k - sum [ cnt << 1 ] );
}

int min (int a, int b){return a < b ? a : b;}

int max (int a, int b){return a > b ? a : b;}

void work()
{
  int i,j;
  //memset( sum , sizeof ( sum ) , 0 );
  for (i = 1 ; i <= M ; ++ i )
    {
      if (i > 1)
	{
	  for ( j = seg [ i - 1 ] . L ; j <= min ( seg [ i - 1 ] . R , seg [ i ] . L - 1 ) ; ++j)
	    insert ( 1 , 1 , tot , pos [ j ] , -1 );
	  for (j = max ( seg [ i ] . L , seg [ i - 1 ] . R + 1 ) ;j <= seg [ i ] . R ; ++j)
	    insert ( 1 , 1 , tot , pos [ j ] , 1 );
	}
      else
	for (j = seg [ i ] . L ; j <= seg [ i ] . R ; ++j)
	  insert ( 1 , 1 , tot , pos [ j ] , 1 );
      res [ seg [ i ] . idx ] = query ( 1 , 1 , tot , seg [ i ] . k );
    }
}

void out()
{
  int i;
  for (i = 1 ; i <= M ; ++ i)
    cout<<res[ i ]<<"\n";
}

int main()
{
  init();

  prepare();

  work();

  out();

  cin.close();
  cout.close();
  return 0;
}

