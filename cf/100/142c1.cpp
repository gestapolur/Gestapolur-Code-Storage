#include<iostream>
#define MAXN 10
using namespace std;

class node
{
public:
  int ans;
  int sv[ MAXN ];
};

int n , m , ans ;

void bfs()
{
  int i , j , k;
  int front , rear ;
  node p ;


  do{
    if( ans < p.ans )
      {}
    //add
    for( i = 1 ; i <= n ; ++ i )
      for( j = 1 ; j <= m ; ++ j )
        for( k = 0 ; k < 4 ; ++ k )
               if( check( j ) )
          {
            
          }
               }while( front < rear );
  return ;
}

int main()
{
  cin>>n>>m;
  
  return 0;
}
