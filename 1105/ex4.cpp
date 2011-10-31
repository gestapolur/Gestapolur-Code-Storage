//HNU 2011 J waste it!
#include<iostream>
#define MAXN 100002
using namespace std;
/*
ifstream cin("1.in");
ofstream cout("ans.out");
*/
class node
{
public:
  int x;
  node *next;
};

node *head[ MAXN ] = { NULL };

int n,m,ans;

void add(int d ,int v)
{
  int x;
  if( head[ d ] == NULL)
    {
      head[ d ] = new node;
      head[ d ]->next = NULL;
      head[ d ]->x = v;
    }
  else
    {
      node *p,*pre;
      p = head[ d ];
      while(p not_eq NULL and  p->x > v )
	{
	  pre = p;
	  p = p->next;
	}
      if( p == head[ d ])
	{
	  pre = new node ;
	  pre->x = v;
	  pre->next = head[ d ];
	  head[ d ] = pre;
	}
      else
	{
	  node *tmp = new node;
	  tmp->x = v;
	  pre->next = tmp;
	  tmp->next = p;
	}
    }
  return ;
}

int main()
{
  int i,v,d,tmax,tmp,tans,tpos;
  node *p;
  while(cin>>n>>m)
    {
      tmax = 0;
      for( i = 1 ; i <= n ; ++ i)
	{
	  cin>>d>>v;
	  if( d > tmax ) tmax = d ;
	  add( d , v );
	}
  
      //test
      /*
	for( i = 1 ; i <= m; ++ i )
	if( head[ i ] not_eq NULL )
	{
	cout<<i<<":";
	p = head[ i ];
	while( p not_eq NULL )
	{
	cout<<p->x<<" ";
	    p = p->next;
	  }
	cout<<"\n";
      }
      */
      //cout<<tmax<<"\n";
      for( i = 1 ; i <= tmax ; ++ i )
	{
	  p = head[ i ];
	  tans = 0 ; tmp = m; tpos = i ;
	  while( tmp > 0 and tpos > 0)
	    {
	      /*
		if( p not_eq NULL )
		cout<<p->x<<" "<<m<<"!\n";
	      */
	      if( p not_eq NULL )
		{
		  tans += p->x;			       
		  //cout<<p->x<<" "<<m<<"!\n";
		  p = p->next;
		}
	      -- tmp ; -- tpos;
	      //if( m == 2 ) cout<<head[ m ]->x<<"!\n";//<<" "<<p->x<<"!!\n";
	      if( (head[ tpos ] not_eq NULL and p not_eq NULL and head[ tpos ]->x > p->x) 
		  or p == NULL )
		p = head[ tpos ];
	    }
	  if( ans < tans ) ans = tans;
	}
      cout<<ans<<"\n";

      for( i = 1 ; i <= tmax ; ++ i ) head[ i ] = NULL;
      ans = 0 ;
    }
  
  return 0;
}
