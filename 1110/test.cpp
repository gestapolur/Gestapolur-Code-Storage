#include<cstdlib>
#include<cstdio>
#include<cstring>
/*
  求最大流的Dinic算法
*/
//define consts
int const maxv = 10000 + 5;
int const maxe = 10000010;
//define types 
struct node{ //邻接表的静态链接实现 
  int b, c, f, next; //目标、容量、流量、静态指针 
};

node ap[maxe * 2]; //存表，从1开始使用，0作废
int ou[maxv]; // 存表初始指针 
//存表的时候1, 2是一对， 3, 4 一对 ... 

int n , m ;
int h[maxv], Q[maxv + 1], G[maxv]; 

void init()
{
  int i , tx , ty , tw ;
  scanf( "%d" , n );
  for( i = 1 ; i <= n ; ++ i )
    scanf("%d%d" , tx , ty );
  for( i = 1 ; i <= m ; ++ i )
    {
      scanf( "%d%d%d" , tx , ty , tw );
      ap[ 1 ];
    }
  for( i = 1 ; i <= n ; ++ i ) ou[ i ] = 1 ;
  return ;
}

//构造层次图 
bool build( int s, int t )
{
  int x , y , f , r ; 
  
  memset( h , 255 , sizeof( h ) );
  memset( G , 0 , sizeof( G ) );
 
  f = r = h[ s ] = 0 ;
  Q[ r++ ] = s ; G[ s ] = ou[ s ];

  while( f < r )
    {
      x = Q[ f ++ ];
      for(int i= ou[ x ] ; i != 0 ; i = ap[i].next ) 
        {
          y = ap[ i ].b;
          if( ap[ i ].c && h[ y ]== -1 )
            {
              h[ y ] = h[ x ] + 1 ; G[ y ] = ou[ y ];
              if(y == t) return true;
              Q[ r ++ ] = y;              
            }
        }
    }
  return false;
}
//增广过程 
int find(int x, int t, int low=0xfffffff)
{
  if(x == t) return low;
  int ret = 0 , y ;
  for(int &p=G[x] ; p!=0 ; p=ap[p].next )
    { //这里p是引用 
      y=ap[p].b;
      if(ap[p].c && h[y]==h[x]+1 && (ret=find(y, t,low < ap[p].c ? low : ap[ p ].c )))
        {
          int tt = (p - 1 ^ 1) + 1;
          ap[ p ].c -= ret;  
          ap[ tt ].c+=ret; 
          return ret;
        }
    }
  return 0;
}
 
int maxflow(int n, int s, int t){
  int flow,cnt=0;
  while(build(s, t))
    while(flow=find(s, t))
      cnt+=flow;
  return cnt;
}
/*
void output()
{
  int ts , te ;
  for( int i = 1 ; i <= m ; ++ i )
    {
      if( node[ i ].f - node[ i ].c < 0 )
        { tx = }
      else 
        }
}
*/
int main()
{
  init();

  printf( "%d\n" , maxflow( n , 1 , n ) );

  //output();
  
  return 0;
}
