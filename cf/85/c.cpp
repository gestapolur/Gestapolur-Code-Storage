//YX 2011 C
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#define MAXN 100005
using namespace std;

class treenode
{
public:
  int l , r , lw , rw , mr , ml , p , val ;
};

int n , root ;
treenode node[ MAXN ];
int st[ MAXN ];
bool inq[ MAXN ];
queue <int> q;

void init()
{
  int cur;
  
  cin>>n;
  for( int i = 1 ; i <= n ; ++ i )
    cin>>node[ i ].p>>node[ i ].val;

  for( int i = 1 ; i <= n ; ++ i )
    if( node[ i ].p not_eq -1 )
      {
        if( node[ node[ i ].p ].val < node[ i ].val )
          node[ node[ i ].p ].r = i ;
        else
          node[ node[ i ].p ].l = i ; 
      }
    else
      root = i ;  

  for( int i = 1 ; i <= n ; ++ i )
    if( node[ i ].l == 0 and node[ i ].r == 0 )
      {
        q.push( i );
        node[ i ].lw = node[ i ].rw = node[ i ].ml = node[ i ].mr = node[ i ].val;
        inq[ i ] = true;
      }

  return ;
}

void bfs()
{
  int cur ;
  do{
    cur = q.front();
    if( node[ cur ].p > 0 )
      {
        if( node [ node[ cur ].p ].l == cur )
          {
            //if( node[ cur ].p == 8 ) cout<<node[ cur ].mr<<" "<<cur<<"!!\n";
            node[ node[ cur ].p ].lw = node[ cur ].mr;
            node[ node[ cur ].p ].ml = node[ cur ].ml;
            //q.push( node[ cur ].p );
            if( not inq[ node[ cur ].p ] and inq[ node[ node[ cur ].p ].r ] )
              { q.push( node[ cur ].p ); inq[ node[ cur ].p ] = true; }
          }
        else if( node[ node[ cur ].p ].r == cur )
          {
            node[ node[ cur ].p ].rw = node[ cur ].ml;
            node[ node[ cur ].p ].mr = node[ cur ].mr;
            //q.push( node[ cur ].p );
            if( not inq[ node[ cur ].p ] and inq[ node[ node[ cur ].p ].l ] )
              { q.push( node[ cur ].p ); inq[ node[ cur ].p ] = true; }
          }
      }
    q.pop();
  }while( q.size() > 0 );

  /*
  for( int i = 1 ; i <= n ; ++ i )
    cout<<node[ i ].lw<<" "<<node[ i ].rw<<" "<<node[ i ].ml<<" "<<node[ i ].mr<<"\n";
  */
  return ;
}

void work()
{
  cout.setf(ios::showpoint|ios::fixed);
  cout.precision( 9 );
 
  int tk , cur , cnt , key ;
  long double ans ;

  cin>>tk;
  
  for( int i = 1 ; i <= tk ; ++ i )
    {
      cin>>key;
      
      cur = root ;
      ans = 0.000000000;
      cnt = 0;
      while( cur > 0 and node[ cur ].l > 0 )
        {
          if( node[ cur ].val > key )
            {
              //if( node[ cur ].l not_eq 0 and node[ cur ].r not_eq 0 )
              ans += node[ cur ].rw; ++ cnt;
              cur = node[ cur ].l;
            }
          else
            {
              //if( node[ cur ].l not_eq 0 and node[ cur ].r not_eq 0 )
              ans += node[ cur ].lw; ++ cnt;
              cur = node[ cur ].r;
            }
        }
      cout<<ans/ ( long double ) cnt <<"\n";
    }

  return ;
}

int main()
{
  init();
  
  bfs();

  work();

  return 0;
}
