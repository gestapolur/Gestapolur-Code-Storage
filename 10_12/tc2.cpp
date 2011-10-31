/*
    
Class:
KiwiJuiceEasy
Method:
thePouring
Parameters:
vector <int>, vector <int>, vector <int>, vector <int>
Returns:
vector <int>
Method signature:
vector <int> thePouring(vector <int> capacities, vector <int> bottles, vector <int> fromId, vector <int> toId)
(be sure your method is public)
 */
/*
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<vector>
#include<string>
  
using namespace std;

class KiwiJuiceEasy
{
public:
  vector <int> thePouring(vector <int> capacities, vector <int> bottles,
			  vector <int> fromId, vector <int> toId)
  {
    int i,n,m,tmp;
    n = capacities.size();
    vector <int> res(n+1);
    m = fromId.size();
    for(i=0;i<n;i++)
      res[i] = bottles[i];
    for(i=0;i<m;i++)
      {
	tmp = bottles[fromId[i]];
	if(tmp > capacities[toId[i]] - bottles[toId[i]])
	  tmp = capacities[toId[i]] - bottles[toId[i]];
	bottles[fromId[i]] -=tmp;
      }
    return bottles;
  }

};
*/
/*
    
Class:
CarrotJumping
Method:
theJump
Parameters:
int
Returns:
int
Method signature:
int theJump(int init)
(be sure your method is public)
   
*/

#include<iostream>
#define MAXN 10001
#define DIV 1000000007
using namespace std;

int p[MAXN],des[MAXN],tmp[2][MAXN];
bool find;

class CarrotJumping
{
public:
  int abs(int a)
  {return a>0?a:-a;}

  void tcmp()
  {
    bool sign = false;
    if(abs(tmp[0][0] - des[0]) < abs(tmp[1][0] - des[0]))
      sign = true;
    else if(abs(tmp[0][0] - des[0]) > abs(tmp[1][0] - des[0]))
      sign = false;
    else
      {
	
      }
    return ;
  }

  void add()
  {
    int i;
    i = 1;
    des[i]+=7;
    while(des[i]>=10)
      {
	des[i+1]++;
	des[i]/=10;
      }
    i = 10;
    des[i]++;
    while(des[i]>=10)
      {
	des[i+1]++;
	des[i]/=10;
      }
    return ;
  }

  int mut(int type)
  {
    int i,j,k;
    k = type + 3;
    for(i=0;i<=p[0];i++)
      tmp[type][i] = p[i];

    for(i=1;i<=p[0];i++)
      {
	tmp[type][i] = p[i] * k;
	j = i;
	while(tmp[type][j] >= 10)
	  {
	    tmp[type][j+1]+=tmp[type][j]%10;
	    tmp[type][j++]/=10;
	    if(j > tmp[type][0])
	      tmp[type][0]++;
	  }
      }
    return ;
  }

  int cmp()
  {
    int i;
    bool sign = false;
    if(p[0] < des[0])
      sign = true;
    if(p[0] == des[0])
    for(i=p[0];i>=1;--i)
      if(p[i] > des[i])
	sign = true;
    
    if(i == 1 and p[i] == des[i])
      {
	find = true;
	return true;
      }

    if(sign == true)
      add();
    return false;
  }

  int theJump(int init)
  {
    int i;
    int ans = 0;
    i = 0;
    while(init > 0)
      {
	p[++i] = init - init / 10 * 10;
	init /=10;
      }
    p[0] = i;
    des[0] = 1;
    des[1] = 0;

    while(not cmp() and ans < 100000)
      {
	++ans;
	mut(0);
	mut(1);
	tcmp();
      }
    if(not find) ans = -1;
    return ans;    
  }
};

int main()
{
  //cout<<test.func(xxx); rememeber it!
  return 0;
}
