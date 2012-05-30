#include<iostream>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<vector>
#define MAXN 100002
using namespace std;

string s , p ;
int n , m , ans ;

class node
{
public:
  int cnt[ 27 ];
  int q;
};

node sum[ MAXN ];

int qut[ 27 ];

void init()
{
  cin>>s>>p;
  n = s.size();
  m = p.size();
  return ;
}

void work()
{
  int i , j , tmp ;
  bool sign = true ;
  if( m > n )
    {cout<<"0\n"; return ;}
  for( i = 0 ; i < n ; ++ i )
    {
      if( i > 0 )
        {
          for( j = 0 ; j < 26 ; ++ j )
            sum[ i ].cnt[ j ] = sum[ i - 1 ].cnt[ j ];
          sum[ i ].q = sum[ i - 1 ].q ;
        }
      
      if( s[ i ] not_eq '?' )
        ++ sum[ i ].cnt[ s[ i ] - 'a' ] ;
      else
        ++ sum[ i ].q ;
    }

  for( i = 0 ; i < m ; ++ i )
    ++ qut[ p[ i ] - 'a' ];

  tmp = sum[ m - 1  ].q;
  for( j = 0 ; j < 26 ; ++ j )
    if( sum[ m - 1 ].cnt[ j ] <= qut[ j ] )
      {
        //cout<<char(j+'a')<<" "<<sum[ i ].cnt[ j ]<<" "<<sum[ i - m ].cnt[ j ]<<"\n";
        if( sum[ m - 1 ].cnt[ j ] < qut[ j ])
          {
            tmp -= ( qut[ j ] - sum[ m - 1 ].cnt[ j ] );
            if( tmp < 0 )
              { sign = false ; break;}
          }
      }
    else
      { sign = false ; break ; }
  if( sign )
    ++ ans;

  for( i = m ; i < n ; ++ i )
    {
      tmp = sum[ i ].q - sum[ i - m ].q;
      //cout<<i<<" "<<i-m+1<<" "<<tmp<<"\n";
      sign = true;
      for( j = 0 ; j < 26 ; ++ j )
        if( sum[ i ].cnt[ j ] - sum[ i - m ].cnt[ j ] <= qut[ j ] )
          {
            //cout<<char(j+'a')<<" "<<sum[ i ].cnt[ j ]<<" "<<sum[ i - m ].cnt[ j ]<<"\n";
            if( sum[ i ].cnt[ j ] - sum[ i - m ].cnt[ j ] < qut[ j ])
              {
                tmp -= ( qut[ j ] - ( sum[ i ].cnt[ j ] - sum[ i - m ].cnt[ j ] ) );
                if( tmp < 0 )
                  { sign = false ; break;}
              }
          }
        else
          { sign = false ; break ; }
      if( sign )
        ++ ans;
    }
  
  cout<<ans<<"\n";

  return ;
}

int main()
{
  
  init();
  
  work();

  return 0;
}
