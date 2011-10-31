/*
  treap
  gestapolur
  here changed node compare into binary tree compare 
  2009.4.16 
 */
#include<iostream>
#include<cstdlib>
#define MAXN 1000
using std::cin;
using std::cout;

int root,n;

class treenode
{
public:
  int key,rank,lc,rc,pa;
};

treenode node[MAXN];

void rr(int x)
{
  int y = node[x].pa;
  if(y == root)
    root = x;
  node[x].pa=node[y].pa;
  node[y].lc = node[x].rc;
  node[node[x].rc].pa = y;
  node[x].rc = y;
  if(node[node[y].pa].key > node[y].key)
    node[node[y].pa].lc = x;
  else 
    node[node[y].pa].rc = x;
  node[y].pa = x;
  return ; 
}

void lr(int x)
{
  int y = node[x].pa;
  if(y == root)
    root = x;
  node[x].pa=node[y].pa;
  node[y].rc=node[x].lc;
  node[node[x].lc].pa=y;
  node[x].lc=y;
  if(node[node[y].pa].key > node[y].key)
    node[node[y].pa].lc=x;
  else 
    node[node[y].pa].rc=x;
  node[y].pa=x;
  return ;
}

void insert(int val)
{
  int x=root,y=0;
  node[++n].key=val;
  node[n].rank=rand();
  node[n].lc=node[n].rc=node[n].pa=0;
  while(x)
    {
      y=x;
      if(node[n].key < node[y].key)
	x=node[y].lc;
      else 
	x=node[y].rc;
    }
  if(y)
    {
      node[n].pa = y;
      if(node[n].key < node[y].key)
	node[y].lc = n;
      else
	node[y].rc = n; 
    }
  else
    root=n;
  while(node[n].pa and node[node[n].pa].rank < node[n].rank)
    if(node[node[n].pa].key > node[n].key)    
      rr(n);
    else
      lr(n);
  return ;
}

void del(int pos)
{
  while(node[pos].lc or node[pos].rc)
    if(node[node[pos].lc].rank < node[node[pos].rc].rank)
      lr(node[pos].rc);
    else
      rr(node[pos].lc);
  if(node[node[pos].pa].lc == pos)
    node[node[pos].pa].lc=0;
  else
    node[node[pos].pa].rc=0;
  node[pos].rank =0 ;
  node[pos].key =0 ;
  return ;
}

void dis(int pos)
{
  if(node[pos].lc)
    dis(node[pos].lc);  
  cout<<"num:"<<pos<<" key: "<<node[pos].key<<" rank: "<<node[pos].rank<<" lc:"<<node[pos].lc<<" rc:"<<node[pos].rc<<" p: "<<node[pos].pa<<"\n";
  if(node[pos].rc)
    dis(node[pos].rc);
  return ;
}

int main()
{
  int ins;
  
  while(1)
    {
      cin>>ins;
      if(ins == 1){cin>>ins;insert(ins);}
      else if(ins == 2){cin>>ins;del(ins);}
      else break;
      dis(root);
    }
  return 0;
}
