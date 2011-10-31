#include<iostream>
#define MAXN 101
#define INF 2141483647
using namespace std;

int n,r,s,t,d;
int w[ MAXN ][ MAXN ];

int rear,front;
int f[ MAXN ];
int pre[ MAXN ];
int q[ MAXN * MAXN ];

bool inway(int x, int y )
{
  //cout<<"p : "<<x<<" "<<y<<"\n";
  while(x not_eq 0)
    {
      if(x == y)
	return true;
      x = pre[ x ];
    }
  return false;
}

int cmin(int a, int b)
{
  if(a > b and b not_eq 0 ) return b;
  else return a; 
}

void bfs()
{
  int i,h,tmp,ans;
  for(i = 1 ;i <= n; ++ i)
    f[ i ] = 0;
  pre[ s ] = 0;
  front = 0 ;rear = 1 ;
  q[ 1 ] = s;
  
  do{
    h = q[ ++ front];
    //cout<<"head : "<<h<<"\n";
    //cout<<front<<":"<<rear<<"\n";
    for(i = 1 ;i <= n ; ++ i)
      if(i not_eq h and 
	 not inway( h , i ) and 
	 f[ i ] < cmin(w[ h ][ i ] , f[ h ]))
	{
	  //cout<<"!\n";
	  f[ i ] = cmin(w[ h ][ i ] , f[ h ]);
	  pre[ i ] = h;
	  q[ ++ rear ] = i;
	}
    /*
    cout<<"head "<<front<<" rear "<<rear<<"\n";
    for(i = front ; i <= rear ; ++ i)
      cout<<q[ i ]<<" ";
    cout<<"\n dist : ";
    for(i = 1 ; i <= n ; ++ i )
      cout<<f[ i ]<<" ";
    cout<<"\n pre : ";
    for(i = 1 ; i <= n ; ++ i )
      cout<<pre[ i ]<<" ";
    cout<<"\n";
    cin.get();
    */
  }while(front < rear);
  //cout<<"ans "<<f[ t ]<<"\n";
  ans = d/f[ t ] + 1;
  if(d % f[ t ] not_eq 0)
    ++ans;
  cout<<ans<<"\n";
  
  return ;
}

int main()
{
  int i,u,v,way;
  cin>>n>>r;
  for(i = 1 ; i <= r ; ++ i)
    {
      cin>>u>>v>>way;
      w[ u ][ v ] = way;
      w[ v ][ u ] = w[ u ][ v ];
    }
  cin>>s>>t>>d;
  bfs();
  return 0;
}
