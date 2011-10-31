#include<iostream>
#include<string>
#define MAXN  10
#define MAXL 100005
using namespace std;
/*
ifstream cin("input.in");
ofstream cout("output1.out");
*/
int n,t[MAXL],num[MAXL][MAXN];
string ans[MAXL][ MAXN ];
const string dic[5]={"   "," IV"," XL"," CD"," M"};
/*IV IX XL XC CD CM */
int nb[ MAXL ];
string sv[ MAXL ];

bool cmp(string a,string b)
{
  int i , tt;
  if( a.size() >= b.size() )
    {
      tt = b.size();
      for(i = 0 ; i < tt ; ++ i)
	if(a[ i ] > b[ i ] ) return false;
	else if(a[ i ] < b[ i ]) return true;
      return false;
    }
  else 
    {
      tt = a.size();
      for(i = 0 ; i < tt ; ++ i)
	if(a[ i ] > b[ i ])
	  return false;
	else if(a[ i ] < b[ i ])
	  return true;
      return true;
    }

}

void sort(int i , int j)
{
  if(i >= j ) return ;
  int m,n,tt;
  string k,t;
  m = i , n = j , k = sv[i + j >> 1];
  while(m <= n )
    {
      while(cmp(sv[ m ] , k )) ++ m;
      while(cmp(k , sv[ n ] )) -- n;

      if(m <= n)
	{
	  t = sv[ m ] ; sv[ m ] = sv[ n ]; sv[ n ] = t;
	  tt = nb[ m ] ; nb[ m ] = nb[ n ]; nb[ n ] = tt;
	  ++ m ; -- n ;
	}
    }
  sort(i,n);
  sort(m,j);
}

void change(int k ,int x )
{
  int i,tk;
  i=0,tk=k;
  while(tk not_eq 0)
    {
      ++i;
      num[ x ][ i ] = tk%10;
      tk/=10;
    }
  t[ x ] = i;
  
  return ;
}

void work()
{
  int i,j,k;

  for(k=1;k<=n;k++)
    {
      for(i=t[k];i>=1;i--)
	{
	  ans[ k ][ i ] = "";
	  if(num[k][i] == 4)
	    {
	      ans[k][i].push_back(dic[i][1]);
	      ans[k][i].push_back(dic[i][2]);
	    }
	  else if(num[k][i] == 9)
	    {
	      ans[k][i].push_back(dic[i][1]);
	      ans[k][i].push_back(dic[i+1][1]);
	    }
	  else 
	    {
	      if(num[k][i]<4)
		for(j=1;j<=num[k][i];j++)
		  ans[k][i].push_back(dic[i][1]);
	      else if(num[k][i]==5)
		ans[k][i].push_back(dic[i][2]);
	      else if(num[k][i]>=6)
		{
		  ans[k][i]=dic[i][2];
		  for(j=6;j<=num[k][i];j++)
		    ans[k][i].push_back(dic[i][1]);
		}
	    }
	}
      /*
      cout<<k<<" ";
      for(j=1;j<=7;j++)
	cout<<ans[k][j]<<" ";
      cout<<"\n";
      */
      sv[ k ] = "";
      for(j = t[ k ] ; j >= 1 ; -- j)
	  sv[ k ] = sv[ k ] + ans[ k ][ j ];
      //cout<<sv[ k ]<<"\n";
      
    }
  return ;
}

int main()
{  
  int i,t,num;
  cin>>t;
  while(t > 0)
    {
      cin>>n;
      for(i=1;i<=n;i++)
	{
	  cin>>num;
	  nb[ i ] = num;
	  change( num , i );
	}
      work();
      sort(1 , n );
      for(i = 1 ;i < n ; ++ i)
	cout<<nb[ i ]<<" ";
      cout<<nb[ n ]<<"\n";
      //for(i = 1 ; i <= n ; ++ i) cout<<sv[ i ]<<""<<sv[ i ].size()<<" ";cout<<"\n";
      
      --t;
    }
 
  return 0;
}
