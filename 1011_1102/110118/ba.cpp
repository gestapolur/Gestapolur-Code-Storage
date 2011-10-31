/*TIMUS 1018 binary apple tree*/
#include<iostream>
#define MAXN 102
using namespace std;

struct treenode
{
  int lc,rc,par;
  int val;
};

treenode tree[MAXN];

int n,q,ans;

int max(int a,int b){return a > b ? a : b;}

int dfs(int bran , int rest)
{
  int res = 0 , tmp = 0,mark;
  int k;
  
  if(tree[ bran ].lc == 0 and tree[ bran ].rc == 0)
    return tree[ bran ].val;

  for(k = 0 ; k < rest ; ++ k)
    {
      tmp =  max( dfs( tree[ bran ].lc , rest - k - 1) , dfs( tree[ bran].rc , k));
      if( tmp > res)
	{
	  res = tmp;
	  mark = k;
	}
    }
  cout<<"node : "<<bran<<" "<<k<<" "<<(rest - k - 1)<<"\n";
  res+=tree[ bran ].val;
  return res;
}

int main()
{
  int i,u,v,w,tmp;
  cin>>n>>q;
  for(i = 1 ; i < n ; ++ i)
    {
      cin>>u>>v>>w;
      if(tree[ u ].par not_eq 0 and tree[ v ].par == 0)
	{tmp = u ; u = v ; v = tmp ; }
      tree[ v ].par = u;
      if(tree[ u ].lc == 0 )
	tree[ u ].lc = v;
      else
	tree[ v ].rc = v;
      tree[ v ].val = w;
    }
  for(i = 1 ; i <= n; ++ i)
    cout<<tree[i].val<<" "<<tree[i].lc<<" "<<tree[i].rc<<"\n";

  cout<<dfs(n,q)<<"\n";
  return 0;
}
