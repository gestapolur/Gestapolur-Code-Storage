/*
  A tries tree sample 
  write by Gestapolur
  2011-01-18
  input N and next N lines are words
  line N+2 line are keys , if it appear in the dictionary , print "pattern occured"
  aphabet just include a-z
*/
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#define MAXN 1001
using namespace std;

struct node
{
public:
  char aph;
  int num; //number of child
  node *child[MAXN]; 
};

node *tree[ MAXN ] = {NULL};
node *root = NULL;
int n,len;


void add(char word [],int indc , node *indx)//indc is the number of word , indx is pos of tree
{
  int i,tmp;
  if(indc == len ) 
    return ;
  tmp = word[ indc ] - 96 ;
  cout<<word[ indc ]<<" "<<indc<<" "<<indx->aph<<"\n";
  if(indx->child[ tmp ] == NULL)
    {
      if(indc == 0)//is root
	{
	  tree[ tmp ] = new node;
	  root->child[ tmp ] = tree[ tmp ];
	  tree[ tmp ]->aph = word[ indc ];
	  //cout<<"add child on root : "<<tree[ tmp ]->aph<<"\n";
	  add( word , indc + 1 , tree[ tmp ] );
	}
      else
	{
	  node *p;
	  p = new node;
	  p->aph = word[ indc ];
	  indx->child[ tmp ] = p;
	  //cout<<"add child : "<<p->aph<<"\n";
	  add( word , indc + 1 , p );
	}
    }
  else
    {
      //cout<<"!\n";
      indx = indx->child[ tmp ];
      add(word , indc + 1 , indx);
    }
  return ;
}

bool search(char word[] , int indx , node *current)
{
  int tmp = word[ indx ] - 96;
  if(current->child[ tmp ] == NULL)
    return false;
  else if(indx < len)
    search(word , indx + 1 , current->child[ tmp ]);
  return false;
}

void disp(node *indx)
{
  int i;
  cout<<indx->aph<<" : ";
  for(i = 1 ;i <= 26 ; ++ i)
    if(indx->child[ i ] not_eq NULL)
      {
	cout<<indx->child[ i ]->aph<<" ";
	//disp(indx->child[ i ]);
      }
  cout<<"\n";
  for(i = 1 ; i <= 26 ; ++ i)
    if(indx->child[ i ] not_eq NULL)
      disp( indx->child[ i ]);
  return ;
}

int main()
{
  int i;
  //init
  root = new node ;
  root->aph = ' ';
  char word[ MAXN ];
  cin>>n;
  for(i=1;i<=n;i++)
    {
      cin>>word;
      len = strlen( word );
      //cout<<word<<" "<<len<<"\n";
      add( word , 0 , root );
      //disp( root );
    }
 
  disp( root );
  cout<<"\n"; 
  /*
  cin>>word;
  if(search( word , root ))
    cout<<"Pattern Occured \n";
  */
  return 0;
}
