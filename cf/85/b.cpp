/*
  2012-03-03
  TLE
*/
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#define MAXN 100005
#define INF 2141483647
using namespace std;

int n;
queue <int> wid[ 4 ];
queue <int> intime[ 4 ];
int t[ MAXN ];
int t1 , t2 , t3 ;
int k1 , k2 , k3 ;
long long tmax;

void init()
{
  cin>>k1>>k2>>k3>>t1>>t2>>t3;
  cin>>n;
  for( int i = 1 ; i <= n ; ++ i )
    cin>>t[ i ];
  return ;
}

inline long long min( long long a , long long b )
{ return a < b ? a : b ; }

void work( )
{
  int p , done ;
  long long curt;

  curt = 1 ;
  p = 1 ;
  done = 0;

  while( done < n )
    {      
      while( wid[ 3 ].size() > 0 and intime[ 3 ].front() + t3 <= curt )
        {
          tmax = ( curt - wid[ 3 ].front() ) > tmax ? ( curt - wid[ 3 ].front() ) : tmax;
          wid[ 3 ].pop();
          intime[ 3 ].pop();
          ++ done;
        }

      while( wid[ 2 ].size() > 0 and intime[ 2 ].front() + t2 <= curt and wid[ 3 ].size() < k3 )
        {
          wid[ 3 ].push( wid[ 2 ].front() );
          intime[ 3 ].push( curt );
          wid[ 2 ].pop();
          intime[ 2 ].pop();
        }

      while( wid[ 1 ].size() > 0 and intime[ 1 ].front() + t1 <= curt and wid[ 2 ].size() < k2 )
        {
          wid[ 2 ].push( wid[ 1 ].front() );
          intime[ 2 ].push( curt );
          wid[ 1 ].pop();
          intime[ 1 ].pop();
        }

     while( t[ p ] <= curt and wid[ 1 ].size() < k1 and p <= n )
       {
         //cout<<"added "<<p<<" "<<curt<<"\n";
         wid[ 1 ].push( t[ p ++ ] );
         intime[ 1 ].push( curt );
       }
    
     curt = INF ;
     if( intime[ 3 ].size() > 0 and curt > intime[ 3 ].front() + t3 )
       curt = intime[ 3 ].front() + t3;
     if( intime[ 2 ].size() > 0 and wid[ 3 ].size() < k3 and curt > intime[ 2 ].front() + t2 )
       curt = intime[ 2 ].front() + t2;
     if( intime[ 1 ].size() > 0 and wid[ 2 ].size() < k2 and curt > intime[ 1 ].front() + t1 )
       curt = intime[ 1 ].front() + t1;
     if( p <= n and wid[ 1 ].size() < k1 )
       curt = curt < t[ p ] ? curt : t[ p ];

     //cout<<curt<<"\n";
     //cin.get();
    }
  
  cout<<tmax<<"\n";

  return ;
}

int main()
{

  init();

  work();
  
  return 0;
}
