/*
Class:
Badgers
Method:
feedMost
Parameters:
vector <int>, vector <int>, int
Returns:
int
Method signature:
int feedMost(vector <int> hunger, vector <int> greed, int totalFood)
(be sure your method is public)
 */
#include<iostream>
#include<vector>
#define MAXN 51
#define INF 32767
using namespace std;

int n,th;
int f[MAXN];
//枚举n后做线性DP

class Badgers
{
public:
  int feedMost(vector <int> hunger , vector <int> greed , int totalFood)
  {
    int i,j,k;
    th = hunger.size();
    for(i=1;i<=totalFood;i++)
      f[i] = INF;
    f[0] = 0;

    while(1)
      {
	++n;
	for(i=0;i<n;i++)
	  {
	    for(k=0;k<=totalFood;k++)
	      if(f[k] > f[k-(hunger[i]+greed[i]*(n-1))] + 1)
		f[k] = f[k-(hunger[i]+greed[i]*(n-1))] + 1;
	  }
	if(suc > totalFood)
	  return n;
      }

  }
};

Badgers test;

int main()
{

  return 0;
}
