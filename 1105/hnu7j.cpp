#include<fstream>
#include<algorithm>
#define MAXN 2000005
using namespace std;
/*
ifstream cin("1.in");
ofstream cout("ans.out",ios::binary);
*/

class theap
{
public:
  int v,d;
};

theap heap[ MAXN ];
theap a[ MAXN ];

int n,m,hsize,ans;

int cmp(theap a, theap b ){return a.d < b.d ; }

void mheapify(int i )
{
  int l,r,largest;
  theap t;
  l = i << 1;
  r = ( i << 1 ) + 1;
  if( l <= hsize and heap[ i ].v < heap[ l ].v)
    largest = l;
  else largest = i;
  if( r <= hsize and heap[ largest ].v < heap[ r ].v )
    largest = r;
  if( largest not_eq i)
    {
      t = heap[ largest ] ; heap[ largest ] = heap[ i ] ; heap[ i ] = t;
      mheapify( largest );
    }
  return ;
}

/*
void create()
{
  int i;
  hsize = n;
  for( i = n / 2  ; i >= 1 ; -- i)
    mheapify( i );
  return ;
}
*/

theap exmax()
{
  theap tmax;
  tmax = heap[ 1 ];
  heap[ 1 ] = heap[ hsize ];
  --hsize;
  mheapify( 1 );
  return tmax;
}

void insert( theap x)
{
  hsize++;
  heap[ hsize ] = x;
  int i = hsize;
  theap t;
  while( i > 1 and heap[ i >> 1 ].v < heap[ i ].v )
    {
      t = heap[ i ] ; heap[ i ] = heap[ i >> 1 ] ; heap[ i >> 1 ] = t;
      i = i >> 1 ;
    }
  return ;
}

int main()
{
  int i ;
  theap tmp;
  freopen("1.in","r",stdin);
  freopen("ans.out","w",stdout);
    while(scanf("%d%d",&n,&m) not_eq EOF )//while(cin>>n>>m)
    {
 
      for( i = 0 ;i < n ; ++ i)
	{
	  //cin>>a[ i ].d>>a[ i ].v;
	  scanf("%d%d" , &a[ i ].d , &a[ i ].v);
	  if( a[ i ].d > m ) a[ i ].d = m;
	}
      sort( a , a+n , cmp );
      //for( i = 0 ; i < n ; ++ i ) cout<<a[ i ].d<<" "<<a[ i ].v<<"\n";
      ans = 0 ; i = n - 1 ;
      hsize = 0;
      while( i >= 0 )
	{
	  while( a[ i ].d < m and hsize > 0 )
	    {
	      tmp = exmax();
	      ans += tmp.v;
	      //cout<<tmp.v<<"!\n";
	      --m;
	    }
	  insert( a[ i ] );
	  m = a[ i ].d;
	  -- i;
	  //cout<<m<<" size "<<hsize<<" "<<i<<"\n";cin.get();
	}
      //for( i = hsize ; i >= 1 ; -- i ) cout<<heap[ i ].v<<" "<<heap[ i ].d<<"\n";
      while( m > 0 and hsize > 0 )
	{
	  tmp = exmax();
	  //cout<<tmp.v<<"!\n";
	  ans += tmp.v;
	  --m;
	}

      //cout<<ans<<endl;
      printf("%d\n",ans);
    }
  return 0;
}
