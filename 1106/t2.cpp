#include<fstream>
using namespace std;

ifstream cin("test.in");
ofstream cout("out1.out");

class treenode
{
public:
  int sum,l,r;
};
			   
treenode node[ 300000 ];
int a,b,n,m;

void create(int  l, int r, int s)
{
   node[ s ].l = l;
   node[ s ].r = r;
   node[ s ].sum = 0;
   
   if (l not_eq r)
     {
       int mid = l + r >> 1 ;
       create(l,mid,s << 1 );
       create(mid + 1 , r , s << 1 | 1 );
     }

   return ;
}

void insert(int l,int r,int s)
{
  if ((node[ s ].l == l) and ( node[ s ].r == r ) and (node[ s ].sum == 0 ))
    {
      node[ s ].sum = 1 ;
      node[ s << 1 ].sum = 1 ;
      node[ s << 1 | 1 ].sum = 1 ;
    }
  else if ( node[ s ].sum == 0 )
    node[ s ].sum = 2;
  
  if (node[ s ].l == node[ s ].r)
    return ;
   
   int mid = node[ s ].l + node[ s ].r >> 1;
  
   if (mid >= r)
     insert( l , r , s << 1 );
   else if (mid < l)
     insert( l , r , s << 1 | 1 );
   else
     {
       insert( l , mid , s << 1 );
       insert( mid + 1 , r , s << 1 | 1 );
     }

   if (node[ s << 1 ].sum == node[ s << 1 | 1 ].sum)
     node[ s ].sum = node[ s << 1 ].sum;
   return ;
}

int find(int l, int r, int s)
{
  if (( node[ s ].l == l ) and ( node[ s ].r == r ) and ( node[ s ].sum not_eq 2 ))
    {
      if (node[ s ].sum == 1)
	return (r - l + 1) ;
      else
	return 0;
    }
  if (node[ s ].l == node[ s ].r)
    return 0;
  else
    {
      int mid = node[ s ].l + node[ s ].r >> 1 ;
      if (mid >= r)
	return find( l , r , s << 1 );
      else if (mid < l)
	return find( l , r , s << 1 | 1 );
      else
	return (find( l , mid , s << 1 ) + find( mid + 1 , r , s << 1 | 1 ));
    }
}


int main()
{
  while(cin>>n>>m)
    {
      create(1,n,1);
      for(int i = 1 ; i <= m ; ++ i)
	{
	  cin>>a>>b;
	  cout<<find(a,b,1)<<"\n";
	  insert(a,b,1);
	}
      cout<<"\n";
    }
  return 0;
}
