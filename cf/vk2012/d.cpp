#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#include<list>
#define MAXN 20002
using namespace std;

int n;
long long even , odd , ans;

list <int> a;

void init()
{
  cin>>n;
  int tmp;
  for( int i = 1 ; i <= n ; ++ i )
    {
      cin>>tmp;
      a.push_back( tmp );
    }

  return ;
}

void work()
{
  list <int>::iterator val , tmp ;
  int i , cnte , cnto ;
  //cout<<a.size()<<"\n";
  if( a.size() <= 5 )
    {
      for( val = a.begin() ; val not_eq a.end() ; ++ val )
        ans += *val;
      
    }
  else
    while( a.size() > 5 )
      {
        cnte = 0 ; cnto = 0 ;
        odd = 0 ; even = 0 ;
        i = 0 ; val = a.begin();
        n = a.size();
        //cout<<n<<"\n";

        while( i <= n )
          {
            ++ i ;
            if( i > n ) break; 

            if( i % 2 == 1 )
              { even += *val; ++ cnte; }
            else
              { odd += *val; ++ cnto; }
          
            //cout<<*val<<"\n";
            ++ val;
          }

        //cout<<cnte<<" "<<cnto<<"-\n";

        //cout<<odd<<" "<<even<<"\n";
        if( odd >= 0 and even >= 0 )
          { ans = odd + even ; break; }
        else if( odd <= 0 and even <= 0 )
          {
            if( odd < even )
              ans = odd;
            else
              ans = even;
            break;
          }
        else 
          {
            if( cnte == 3 and cnto == 2 and even <= 0 )
              { ans = even + odd ; break ; }
          
            if( odd > 0 ) ans = odd;
            else ans = even;
          
            i = 0 ; val = a.begin();
            while( val not_eq a.end() )
              {
                ++ i;
                tmp = val ;
                ++ val;
              
                if( ( i % 2 == 1 and even <= 0 ) or ( i % 2 == 0 and odd < 0 ) )
                  a.erase( tmp );
              }

            /*
              cout<<ans<<" "<<a.size()<<"\n";
              for( list <int>::iterator x = a.begin() ; x not_eq a.end() ; ++ x )
              cout<<*x<<" "; cout<<"\n";
            */
          }
        
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
