/*
ID: gestapo1
PROG: preface
LANG: C++
*/
#include<iostream>
#include<string>
#define MAXN  5
#define MAXL 3505
using namespace std;
/*
using std::cin;
using std::cout;
*/
/*
using std::string;

using std::ifstream;
using std::ofstream;
ifstream cin("preface.in");
ofstream cout("preface.out");
*/
unsigned short int n,t[MAXL],num[MAXL][MAXN];
int hash[8];
string ans[MAXL][9];
const string dic[5]={"   "," IV"," XL"," CD"," M"};
const char word[8]={' ','I','V','X','L','C','D','M'};
/*IV IX XL XC CD CM */

void change(int k)
{
  int i,tk;
  i=0,tk=k;
  while(tk not_eq 0)
    {
      ++i;
      num[k][i]=tk%10;
      tk/=10;
    }
  t[k]=i;
  return ;
}

void work()
{
  int i,j,k;

  for(k=1;k<=n;k++)
    {
    for(i=t[k];i>=1;i--)
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
    
    cout<<k<<" ";
    for(j=1;j<=7;j++)
      cout<<ans[k][j]<<" ";
    cout<<"\n";
    
    for(i=1;i<=7;i++)
      for(j=0;j<ans[k][i].size();j++)
	{
	  if(ans[k][i][j]=='I')
	    hash[1]++;
	  else if(ans[k][i][j]=='V')
	    hash[2]++;
	  else if(ans[k][i][j]=='X')
	    hash[3]++;
	  else if(ans[k][i][j]=='L')
	    hash[4]++;
	  else if(ans[k][i][j]=='C')
	    hash[5]++;
	  else if(ans[k][i][j]=='D')
	    hash[6]++;
	  else if(ans[k][i][j]=='M')
	    hash[7]++;
	}
    }
  return ;
}

int main()
{
  int i;
  cin>>n;
  for(i=1;i<=n;i++)
    change(i);
  work();
  for(i=1;i<=7;i++)
    if(hash[i] not_eq 0)
      cout<<word[i]<<" "<<hash[i]<<"\n";
  /*
  cin.close();
  cout.close();
  */
  return 0;
}
