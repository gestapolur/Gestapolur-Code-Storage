#include <stdio.h>
int cost[301][301] , a[31][301] , pos[301];
int main() 
{
 int V , P ;
 scanf("%d%d",&V,&P) ;
 for( int i=1 ; i<=V ; ++i )
  scanf("%d",&pos[i]);
 for( int i=1 ; i<=V ; ++i )  //从村落i到村落j由一个邮局控制时的最短距离和  
  for( int j=i ; j<=V ; ++j )
  {
   int mid = (i+j)>>1 ;
   for( int k=i ; k<mid ; ++k) cost[i][j] += pos[mid]-pos[k] ;
   for( int k=mid+1 ; k<=j ; ++k) cost[i][j] += pos[k]-pos[mid] ;
  }
 for( int i=0 ; i<=V ; ++i )
  a[1][i] = cost[1][i] ;
 for(int i=2 ; i<=P ; ++i )
  for(int j=i ; j<=V ; ++j )
  {
   int min = 65536 ;
   for ( int k=i-1 ; k<j ; ++k )
    if( a[i-1][k]+cost[k+1][j]<min )
     min = a[i-1][k]+cost[k+1][j] ;
   a[i][j] = min ;
  }
 printf("%d\n",a[P][V]);
 return 0 ;
}
