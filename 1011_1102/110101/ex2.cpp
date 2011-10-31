/*
  USACO 2002 winter Pastrue Fences
  2010.1.1
  write by Gestapolur
*/
//in seg tree
#include<fstream>
#define INF 2141483647
#define MAXN 3005
using namespace std;

ifstream cin("pasture.in");
ofstream cout("pasture.out");

class treenode
{
public:
  int sum;
  int l,r;
};

int n,ans = INF,sta,edg;

treenode node[MAXN];

void create(int l,int r,int s)
{
  //if(node[ s ] == NULL ) node[s] = new treenode ;

  node[ s ].l = l ;
  node[ s ].r = r;
  node[ s ].sum = 0;
 
  if(l not_eq r)
    {
      int mid = l + r >> 1;
      create(l,mid,s<<1);
      create(mid + 1 , r , (s<<1) + 1);
    }
  return ;
}

int abs(int a){return a>0?a:-a;}

void upswit(int val ,int lev)
{
  node[ lev ].sum+=val;
  if(lev >> 1 not_eq 0)
    upswit( val , lev >> 1);
  return ;
}

void insert(int l,int r,int val,int s)
{
  if(node[ s ].l == l and node[s].r == r)
    {
      node[ s ].sum = val;
      if(s >> 1 not_eq 0)
	upswit(val,s >> 1);
      return ;
    }
  else if(node[ s ].l == node[ s ].r)
    return ;
  else
    {
      int mid = node[ s ].l + node[ s ].r >> 1;
      if( mid >= r )
	insert(l,r,val,s<<1);
      else if(mid < l)
	insert(l,r,val,(s<<1) + 1);
      else
	{
	  insert(l,mid,val,s<<1);
	  insert(mid + 1,r,val,(s<<1) + 1);
	}
    }
  return ;
}

int search(int l , int r , int s)
{
  if(node[ s ].l == l and node[ s ].r == r)
    return node[ s ].sum;
  else if(node[ s ].l == node[ s ].r )
    return 0;
  else
    {
      int mid = node[ s ].l + node[ s ].r >> 1;
      if(mid >= r)
	return search(l,r,s<<1);
      else if(mid < l)
	return search(l,r,(s<<1) + 1);
      else
	return ( search(l,mid,s<<1) + search(mid + 1,r,(s<<1) + 1) );
    }
}

void output(int s)
{
  cout<<s<<" "<<node[ s ].l<<" "<<node[ s ].r<<" "<<node[ s ].sum<<"\n";
  if(node[ s ].l not_eq node[ s ].r )
    {
      output( s<<1 );
      output(( s<<1 ) + 1);
    }
  return ;
}

int main()
{
  int i,j,k,si;
  bool check;
  cin>>n;
  create(1,n,1);
  for(i=1;i<=n;++i)
    {
      cin>>si;
      insert(i,i,si,1);
    }
  /*
  for( i = 1 ; i <= n ; ++ i)
    for(j = i ; j <= n ; ++ j)
      {
	si = abs(search(i,j,1));
	if(si < ans or (si == ans and j - i > edg - sta))
	  {ans = si; sta = i , edg = j ;}
      }
  */
  k = 0;check = false;
  while(k <= n)
    {
      for(i = 1 ; i <= n ; ++ i)
	si = abs(search(i,i + k , 1));
      if(si < ans or (si == ans and j - i > edg - sta))
	{ans = si ; sta = i , edg = j;check = true;}
      if( check )
	check = false;
      else
	break;
      ++k;
    }
  //output(1);
  cout<<sta<<" "<<edg<<" "<<ans<<"\n";
  cin.close();
  cout.close();
  return 0;
}
