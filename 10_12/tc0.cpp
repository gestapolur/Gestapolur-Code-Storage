/*
Class:
VacationTime
Method:
bestSchedule
Parameters:
int, int, vector <int>
Returns:
int
Method signature:
int bestSchedule(int N, int K, vector <int> workingDays)
*/
/*
#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#include<cstdlib>
#define MAXN 1002
using namespace std;

bool hash[MAXN];

class VacationTime
{
public:
  int bestSchedule(int N, int K, vector <int> workingDays)
  {
    int i,l,j,R,r,n,cnt,min=2141483647;

    n = workingDays.size();
    R = N - K + 1 ;

    for(i=1;i<=n;i++)
      hash[workingDays[i]] = true;

    for(l=1;l<=R;l++)
      {
	r = l + K - 1;
	cnt = 0;
	for(j=l;j<=r;j++)
	  if(hash[j])
	    cnt++;
	if(cnt < min)
	  min = cnt;
      }

    return min;

  }
};
*/

/*
Class:
Islands
Method:
beachLength
Parameters:
vector <string>
Returns:
int
Method signature:
int beachLength(vector <string> kingdom)
*/
#include<iostream>
#include<cstring>
#include<vector>
#define MAXN 52
using namespace std;

int n,m,bea;
bool mat[MAXN][MAXN];

class Islands
{
public:
  void check(int x,int y,bool val)
  {
    if(y < 0) return ;
    if(x >= n) return ;
    if(y >= m) return ;
    if(mat[x][y] xor val ) {bea++;cout<<x<<" "<<y<<" "<<val<<" "<<mat[x][y]<<"\n";}
    return ;
  }
  
  int beachLength(vector <string> kingdom)
  {
    int i,j;
    m = kingdom[0].size();
    n = kingdom.size();
    for(i=0;i<n;i++)
      for(j=0;j<m;j++)
	if(kingdom[i][j] == '.')
	  mat[i][j] = true;
	else
	  mat[i][j] = false;

    for(i=0;i<n;i++)
      {
	for(j=0;j<m;j++)
	  cout<<mat[i][j];
	cout<<"\n";
      }

    for(i=0;i<n;i++)
      {
	for(j=0;j<m;j++)
	  {
	    cout<<i<<" "<<j<<" : \n";
	    check(i+1,j,mat[i][j]);
	    check(i,j+1,mat[i][j]);
	    check(i+1,j-1,mat[i][j]);
	  }
	cout<<bea<<" "<<i<<" !!!!!!!!!\n"; 
      }
    return bea;
  }
};

vector <string> ch;
Islands test;

int main()
{ 
  int n,m,i;
  cin>>n>>m;
  ch.resize(n);
  for(i=0;i<n;i++)
    {
      ch[i].resize(0);
      cin>>ch[i];
    }

  cout<<test.beachLength(ch)<<"\n";
  return 0;
}
