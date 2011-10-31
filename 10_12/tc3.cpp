//SRM 486 DIV2 Crazyline
#include<iostream>
#include<vector>
#define MAXN 55
#define INF 2141483647
using namespace std;

int w[MAXN][MAXN],n,ans = 0;
int mark[MAXN];
bool in[MAXN];

class CrazyLine
{
 public:
  int abs(int a){return a > 0 ? a : -a;}
  /*
  void dijkstra(int s)
  {
    int i,j,k,maxt;
    int mark[MAXN];
    bool in[MAXN];
    in[0] = false , mark[ 0 ] = 0;
    for(i=1;i<=n;i++)
      {mark[i] = w[s][i];in[ i ] = false;}
    
    in[ s ] = true;

    for(i=1;i<=n;i++)
      {
	maxt = 0; k = 0;

	for(j=1;j<=n;j++)
	  if(not in[j] and maxt < mark[j])
	    {k = j;maxt = mark[j];}

	in[k] = true;

	for(j=1;j<=n;j++)
	  if(not in[j] and mark[j] < mark[k] + w[k][j])
	    mark[j] = mark[k] + w[k][j];

      }
    
    for(i=1;i<=n;i++)
      if(mark[i] > ans)
	ans = mark[i];

    return ;
  }
*/
  void dijkstra(int s)
  {
    int i,j,u,min;
    for(i=1;i<=n;i++)
      {mark[i]=w[s][i];in[i] = false;}

    //mark[s]=0,in[s]=true;
    in[s] = 0;
    for(i=1;i<=n;i++)
      {   
	min = 0;u = 0;
	for(j=i;j<=n;j++)
        if(in[j]==false and mark[j]>min)
	  {min=mark[j];u=j;} 
            
	in[u]=true; 

	for(j=1;j<=n;j++)
	  if(mark[j] < mark[u] + w[u][j] )
	    {mark[j] = mark[u] + w[u][j];}              
      }
    
    for(i=1;i<=n;i++)
      if(mark[i] > ans)
	ans = mark[i];
    
    return ;   
  }


  int maxCrazyness(vector <int> heights)
  {
    int i,j,k;
    n = heights.size();
    for(i=1;i<=n;++i)
      for(j=1;j<=n;++j)
	w[i][j] = abs(heights[i - 1] - heights[j - 1]);
    for(i=1;i<=n;i++)
      dijkstra(i);

    return ans;
  }
};

int main()
{
  int tt,dd;
  vector <int> data;
  CrazyLine test;
  
  cin>>tt;
  for(int i = 1;i<=tt;i++)
    {cin>>dd;data.push_back(dd);}
  cout<<test.maxCrazyness(data)<<"\n";
  
  return 0;
}
