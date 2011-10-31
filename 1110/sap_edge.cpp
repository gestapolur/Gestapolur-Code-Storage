/*
  SAP非递归代码
  过程解释
  gestapolur
  2010.10.26 v1.0
  2010.12.11 v1.1
 */
#include<iostream>
#define MAXN 10002
#define MAXE 50000000
#define INF 2141483647
using namespace std;

class edge
{
public:
  int v , rest , con ;
  next *edge;
};

class path
{
public:
  edge *aug ;
};

bool flag;/*标记是否有路径被增广*/
int h[MAXN];/*当前DFS流到该点的流量*/
int d[MAXN];/*DFS遍历的标号*/
int vh[MAXN];/*记录标号为i的节点的个数*/
int di[MAXN];/*某节点当前的流量*/
int u[ MAXE ] , v[ MAXE ] ;
int mint,flow,aug,m,n;
edge *e[ MAXE ] = { NULL };
edge *path = NULL;
/*
  aug 是当前增广路的流
  flow 为整个流网络的最大流
  m 图上的总边数
  n 图上的总节点数
*/

edge* findway( int u , int v )
{
  edge *p = NULL;
  p = e[ u ];
  while( p not_eq NULL )
    {
      if( p->v == v ) return p;
      p = p->next;
    }
}

void addpath( int u , edge *p )
{
  path *augadd , *revadd;
  augadd = new path ;
  revadd = new path ;
  augadd->
  revadd = find( u , p->v );
  if( path == NULL );
  return ;
}

void addedge( int st , int ed , int w )
{
  edge *p = NULL;
  p = new edge ;
  p->v = ed ;
  p->w = st;
  if( edge u[ st ] == NULL ) { }
  return ;
}

void init()
{
  scanf("");
  for()
  return ;
}

void output()
{
  return ;
}

void dfs(int source,int sink)
{
  int i , j , tmp , rec = 0 ;
  edge *p = NULL ; 
  vh[0] = n;/* */

  for(i = 1 ; i <= n ; ++ i )/*di is the mark of DFS ,DFS当前节点遍历到的节点的标记*/
    di[ i ] = 1;

  i = source;/*从源点开始*/
  aug = INF;
  
  while(d[source] < n) //DFS过程，遍历结束
    {
      h[ i ] = aug;/*从当前节点标记的流开始*/
      flag = false;
      
      for( p = st[ i ] ; p not_eq NULL ; p = p->next )
	if( d[ p->v ] + 1 == d[ i ] )
	  {/*DFS标记必须是连续的，为什么是连续的?DFS原理，关键！！！*/
	    flag = true;
	    
	    di[ i ] = p->v;
	    /*当前路径能够增广的流量取决于流量最小的那条边*/
	    if( p->rest < aug ) 
	      aug = p->rest ;
            /*
	    pre[j] = i;
	    i=j;
            */
            addpath( i , p );
            u[ p->v ]->psd.pushback( i ) ; 
            i = p->v;

	    if(i == sink)/*发现了一条增广路*/
	      {
		flow += aug;/*增加总的流量*/
		while( path not_eq NULL )/*回溯，调整网络中的剩余流量*/
		  {
                    /*
		    tmp = i;
		    i = pre[ i ];
		    map[i][tmp]-=aug;
		    map[tmp][i]+=aug;
                    */
                    u[ path ]->rest -= aug ;
                    u
                    path = path->next;
		  }
		aug = INF;
	      }
	    break;
	  }
      
      if(flag)  continue;
      /*以下是没有增广的情况，回溯到上一步增加节点的标号*/
      mint = n-1;
      /*关于下面的*/
      for(j=1;j<=n;j++)/*搜寻和当前顶点i相连的最短的没有流满的顶点，标记在当前顶点的di上*/
	if(map[i][j] > 0 and d[j] < mint)/*标记最小的节点的原因是因为前面增广的过程是di[i] - n 的逐个扫描*/
	  {rec = j; mint = d[j]; }/*以此保持DFS遍历的性质*/

      /*下面这几步的意思是在没有增广路可选择的情况下，给当前节点的标号+1然后回溯至上一顶点继续寻找*/

      di[i]=rec;/*标记顶点i*/

      vh[d[i]]--;

      if(vh[d[i]] == 0)//没有通路了。
	break;

      d[i] = mint + 1;/*给节点i的标号+1*/
      
      vh[d[i]]++;//
      
      if(i not_eq source)/*回溯至前一个标记的顶点*/
	{i = pre[i];aug = h[i];}

    }

  return ;
}

int main()
{
  int i,x,y,w;
  cin>>n>>m;
  for(i=1;i<=m;i++)
    {
      cin>>x>>y>>w;
      map[x][y]+=w;
    }

  dfs( 1 , n );

  
  /*
  cin.close();
  cout.close();
  */
  return 0;
}
