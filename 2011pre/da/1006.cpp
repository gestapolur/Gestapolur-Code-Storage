#include<iostream> 
#include<cstring>
#include<cstdlib>
#define MAXN 1001 
using std::cin; 
using std::cout; 

int n,root; 

class Node 
{ 
public: 
  int key,rank,lc,rc,pa; 
}; 

Node node[MAXN]; 

int find(int k) 
{ 
  int x=root; 
  while( x and node[x].key not_eq k ) 
    { 
      if( k < node[x].key) 
	x=node[x].lc; 
      else 
	x=node[x].rc; 
    } 
  return x; 
} 

int getmin(int x) 
{ 
  while(node[x].lc) 
    x=node[x].lc; 
  return x; 
} 

int getmax(int x) 
{ 
  while(node[x].rc) 
    x=node[x].rc; 
} 

int successor(int x) 
{ 
  if(node[x].rc) 
    return getmin(node[x].lc);   
  int y=node[x].pa; 
  while( y and x==node[y].rc) 
    { 
      x=y; 
      y=node[y].pa; 
    } 
  return y; 
} 
int pred(int x) 
{ 
  if(node[x].lc) 
    return getmax(node[x].lc); 
  int y=node[x].pa; 
  while( y and x==node[y].lc) 
    { 
      x=y; 
      y=node[y].pa; 
    } 
  return y; 
} 

void leftratote(int x) 
{ 
  int y = node[x].pa; 
  if(y==root) root=x; 
  node[x].pa=node[y].pa; 
  node[node[x].rc].pa=y; 
  node[y].lc=node[x].rc; 
  node[x].rc=y; 
  if(node[node[y].pa].lc==y) 
    node[node[y].pa].lc=x; 
  else 
    node[node[y].pa].rc=x; 
  node[y].pa=x; 
  return; 
} 


void rightratote(int x) 
{ 
  int y=node[x].pa; 
  if(y==root) root = x; 
  node[x].pa=node[y].pa; 
  node[node[x].lc].pa=y; 
  node[y].rc=node[x].lc; 
  node[x].lc=y; 
  if(node[node[y].pa].lc==y) 
    node[node[y].pa].lc=x; 
  else 
    node[node[y].pa].rc=x; 
  node[y].pa=x; 
  return; 
} 
 
/*
void rightratote(int x) 
{ 
  int y; 
  y=node[x].pa; 
  node[y].lc=node[x].rc; 
  if(y) root = x; 
  node[x].pa=node[y].pa; 
  if(node[node[y].pa].lc == y) 
    node[y].lc = x; 
  if(node[node[y].pa].rc == y) 
    node[y].rc = x; 
  node[x].rc = y; 
  node[y].pa = x; 
  return ; 
} 

void leftratote(int x) 
{ 
  int y; 
  y=node[x].rc; 
  node[x].rc=node[y].lc; 
  if(node[y].lc) 
    node[node[y].lc].pa=x; 
  node[y].pa=node[x].pa; 
  if(node[x].pa)//x is the root 
    root = y; 
  if(node[node[x].pa].lc == x)//where is x original stayed 
    node[node[x].pa].lc=y;//and change the x and y's position 
  else 
    node[node[x].pa].rc=y; 
  node[y].lc=x; 
  node[x].pa=y; 
  return ; 
} 
*/

void insert(int val) 
{ 
 node[++n].key=val; 
 node[n].lc=node[n].rc=node[n].pa=0; 
 node[n].rank=rand(); 
 int x = root,y=0; 
 while(x) 
 { 
   y=x; 
   if(node[n].key < node[x].key) 
     x=node[x].lc; 
   else 
     x=node[x].rc; 
 } 

 if(y) 
   { 
     node[n].pa=y; 
     if(node[n].key < node[y].key) 
       node[y].lc=n; 
     else 
       node[y].rc=n; 
   } 
 else 
   root=n; 
 //keep the heap 
 while(node[n].pa and node[node[n].pa].rank > node[n].rank ) 
   if( node[node[n].pa].lc==n) 
     leftratote(n); 
   else 
     rightratote(n); 
 return; 
} 

void del(int pos) 
{ 
  while(node[pos].lc or node[pos].rc) 
    if(node[node[pos].lc].rank < node[node[pos].rc].rank) 
      leftratote(node[pos].lc); 
    else 
      rightratote(node[pos].rc); 
  if(node[node[pos].pa].lc==pos) 
    node[node[pos].pa].lc=0; 
  else 
    node[node[pos].pa].rc=0; 
  node[pos].key=0; 
  node[pos].rank=0; 
  node[pos].pa=0; 
  return; 
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

void clr()
{
  root = 0 , n = 0 ;
  memset( node , 0 , sizeof( node ));
  return ;
}

int main() 
{ 
  int ins,k; 
  int ask , cnt ;
  char ch;
  while( cin>>ask ) 
    { 
      cin>>k;
      cnt = 0 ;
      for( int i = 1 ; i <= ask ; ++ i )
	{
	  cin>>ch;
	  if( ch == 'I' )
	    {
	      ++ cnt; 
	      cin>>ins;
	      insert( ins );
	      //dis( root );
	      if( cnt > k )
		{
		  //cout<<getmin( root )<<"\n";
		  del( getmin( root ) );
		  
		}
	    }
	  else
	    cout<<node[ getmin( root ) ].key<<"\n";
	  dis( root );
	}
      clr();
   
    } 
 return 0; 
}
