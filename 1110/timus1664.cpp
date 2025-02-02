/*
  TIMUS1664
  write by gestapolur
  2011-10-14
*/
#include<cstdlib>
#include<cstdio>
#define MAXN 10000
//#define MAXC 1000000000

const int INF = 2141483647;
bool flag;/*标记是否有路径被增广*/
int h[ MAXN ];/*当前DFS流到该点的流量*/
short int pre[MAXN];/*某节点在DFS过程中标记的前驱节点*/
short int d[MAXN];/*DFS遍历的标号*/
short int vh[MAXN];/*记录标号为i的节点的个数*/
short int di[MAXN];/*某节点当前DFS的位置*/
int *f[ MAXN ][ MAXN ] = { NULL }, *w[MAXN][MAXN] = { NULL };/*网络当前的容量，用邻接矩阵表示*/
int mint , flow , aug;
short int m , n ;
short int u[ MAXN ] , v[ MAXN ];
/*
  aug 是当前增广路的流
  flow 为整个流网络的最大流
  m 图上的总边数
  n 图上的总节点数
*/
void dfs( int source , int sink)
{
  short int i , j ;
  short int tmp , rec = 0 ;
  
  vh[0] = n;

  for( i = 0 ; i < n; ++ i )/*di is the mark of DFS ,DFS当前节点遍历到的节点的标记*/
    di[ i ] = 0 ;

  i = source;/*从源点开始*/
  aug=INF;
  
  while(d[ source ] < n) //DFS过程，遍历结束
    {
      h[i] = aug;/*从当前节点标记的流开始*/
      flag = false;

      for(j = di[i] ; j < n ; ++ j )
	if( w[i][j] > 0 and d[ j ] + 1 == d[ i ] )
	  {/*DFS标记必须是连续的，为什么是连续的?DFS原理，关键！！！*/
	    flag = true;
	    
	    di[ i ] = j;
	    /*当前路径能够增广的流量取决于流量最小的那条边*/
	    if( w[i][j] < aug ) 
	      aug = w[i][j];

	    pre[ j ] = i;
	    i = j;

	    if(i == sink)/*发现了一条增广路*/
	      {
		flow += aug ;/*增加总的流量*/
		while(i not_eq source )/*回溯，调整网络中的剩余流量*/
		  {
		    tmp = i;
		    i = pre[i];
		    w[i][tmp]-=aug;
		    w[tmp][i]+=aug;
		  }
		aug = INF;
	      }
	    break;
	  }
      
      if(flag)  continue;
      /*以下是没有增广的情况，回溯到上一步增加节点的标号*/
      mint = n-1;
      /*关于下面的*/
      for(j = 0 ; j < n ; ++ j )/*搜寻和当前顶点i相连的最短的没有流满的顶点，标记在当前顶点的di上*/
	if(w[i][j] > 0 and d[j] < mint)/*标记最小的节点的原因是因为前面增广的过程是di[i] - n 的逐个扫描*/
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

void init()
{
  short int i , tx , ty ;
  int wi ; 
  scanf("%hd" , &n );
  for( i = 0 ; i < n ; ++ i )
    scanf( "%hd%hd" , &tx , &ty );

  scanf("%hd" , &m );
  for( i = 0 ; i < m ; ++ i )
    {
      scanf("%hd%hd%d", &u[ i ] , &v[ i ] , &wi );
      --u[ i ] , -- v[ i ];
      if( f[ u[ i ] ][ v[ i ] ] == NULL )
        { f[ u[ i ] ][ v[ i ] ] = new int ; f[ u[ i ] ][ v[ i ] ] = 0 ;}
      if( f[ v[ i ] ][ u[ i ] ] == NULL )
        { f[ v[ i ] ][ u[ i ] ] = new int ; f[ v[ i ] ][ u[ i ] ] = 0 ;}
      if( w[ u[ i ] ][ v[ i ] ] == NULL )
        { w[ u[ i ] ][ v[ i ] ] = new int ; w[ u[ i ] ][ v[ i ] ] = 0 ;}
      if( w[ v[ i ] ][ u[ i ] ] == NULL )
        { w[ v[ i ] ][ u[ i ] ] = new int ; w[ v[ i ] ][ u[ i ] ] = 0 ;}
      
      f[ u[ i ] ][ v[ i ] ] += wi;
      f[ v[ i ] ][ u[ i ] ] += wi;
      w[ u[ i ] ][ v[ i ] ] += f[ u[ i ] ][ v[ i ] ];
      w[ v[ i ] ][ u[ i ] ] += f[ v[ i ] ][ u[ i ] ];
    }
  return ;
}

void output()
{
  short int i , fr , to ;
  printf( "%d\n" , flow );
  for( i = 0 ; i < m ; ++ i )
    {
      if( f[ u[ i ] ][ v[ i ] ] - w[ u[ i ]][ v[ i ] ] < 0 ){ fr = v[ i ] ; to = u[ i ] ; }
       else {fr = u[ i ] ; to = v[ i ] ;}
      printf("%hd %hd %d\n" , fr + 1 , to + 1, abs( f[ u[ i ]][ v[ i ] ] - w[ u[ i ] ][ v[ i ] ] ) );
    }

  return ;
}

int main()
{

  init();

  dfs( 0 , n - 1 );

  output();
  
  return 0;
}
