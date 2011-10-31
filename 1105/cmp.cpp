#include<fstream>
#include<string>
#define MAXN  10
#define MAXL 100005
using namespace std;

ifstream cin("input.in");
ofstream cout("output2.out");

int n,t[MAXL],num[MAXL][MAXN];
string ans[MAXL];
const string dic[5]={"   "," IV"," XL"," CD"," M"};
/*IV IX XL XC CD CM */
int nb[ MAXL ];

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

void sort()
{
  int i,j,tt;
  string t;
  for(i = 1 ; i <= n ; ++ i)
    for(j = i + 1 ; j <= n ; ++ j)
      if(not cmp(ans[ i ] , ans[ j ]))
	{
	  t = ans[ i ] ; ans[ i ] = ans[ j ] ; ans[ j ] = t;
	  tt = nb[ i ] ; nb[ i ] = nb[ j ] ; nb[ j ] = tt;
	}
  return ;
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
      ans[ k ] = "";
      for(i=t[k];i>=1;i--)
	if(num[k][i] == 4)
	  {
	    ans[k].push_back(dic[i][1]);
	    ans[k].push_back(dic[i][2]);
	  }
	else if(num[k][i] == 9)
	  {
	    ans[k].push_back(dic[i][1]);
	    ans[k].push_back(dic[i+1][1]);
	  }
	else 
	  {
	    if(num[k][i]<4)
	      for(j=1;j<=num[k][i];j++)
		ans[k].push_back(dic[i][1]);
	    else if(num[k][i]==5)
	      ans[k].push_back(dic[i][2]);
	    else if(num[k][i]>=6)
	      {
		ans[k]=dic[i][2];
		for(j=6;j<=num[k][i];j++)
		  ans[k].push_back(dic[i][1]);
	      }
	  }
    }
  
  return ;
}

int main()
{  int i,t,num;
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
      /*
      for(i = 1 ; i <= n ; ++ i)
	cout<<ans[ i ]<<ans[ i ].size()<<" "; cout<<"\n";
      */
      sort();
      for(i = 1 ;i < n ; ++ i)
	cout<<nb[ i ]<<" ";
      cout<<nb[ n ]<<"\n";
      for(i = 1 ; i <= n ; ++ i) cout<<ans[ i ]<<" ";cout<<"\n";
      --t;
    }
  return 0;
}
