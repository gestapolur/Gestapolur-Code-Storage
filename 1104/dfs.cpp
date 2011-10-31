//all permutation in dfs
#include<iostream>
#define MAXN 20
using namespace std;

int p,cnt;
int con[ MAXN ];
int arr[ MAXN ];
bool hash[ MAXN ];

void dfs(int n)
{
  if(n == 0) return ;
  else if(n > p)
    {
      /*
      for(int i = 1 ; i <= p ; ++ i)
	cout<<arr[ con[ i ] ]<<" ";
      cout<<"\n condition : ";
      for(int i = 1 ; i <= p ; ++ i)
	cout<<con[ i ]<<" ";
      cout<<"\n";
      */
      ++cnt;
      //hash[ con[ n ] ] = false;
      //con[ n ] = 0 ;
      dfs( n - 1 );
    }
  else
    {
      hash[ con[ n ] ] = false;

      do{
	++con[ n ];
      }while(hash[ con[ n ] ]);
      
      if( con[ n ] > p)
	{
	  hash[ con[ n ] ] = false;
	  con[ n ] = 0 ;
	  dfs(n - 1);
	}
      else
	{
	  hash[ con[ n ] ] = true;
	  dfs(n + 1);
	}
    }
}

int main()
{
  int i;
  cin>>p;
  for(i = 1 ; i <= p ; ++ i)
    arr[ i ] = i;
  dfs(1);
  cout<<cnt<<"\n";
  return 0;
}
