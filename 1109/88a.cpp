#include<iostream>
using namespace std;

int n , m ;

int main()
{
  int s , f , t , i , e , ans ;
  cin>>n>>m;
  for( i = 1 ; i <= n ; ++ i )
    {
      cin>>s>>f>>t;
      if( s not_eq f )
        {
          e = t % ( 2 * ( m - 1 ) ) ;
          ans = t ;
          if( e < m )//up
            { 
              ++ e;
              if( s >= e )//up 
                {
                  ans += s - e;
                  if( f >= s )//up
                    ans += f - s ;
                  else
                    ans += 2 * ( m - s ) + s - f ;
                }
              else 
                {
                  ans += 2 * ( m - e ) + e - s ;
                  if( s >= f )//down
                    ans += s - f;
                  else //up
                    ans += 2 * ( s - 1 ) + f - s ;  
                }
            }
          else//down
            {
              e = m - 1 - e % m ;
              if( e >= s )// down
                {
                  ans += e - s;
                  if( s >= f )//down
                    ans += s - f;
                  else 
                    ans += 2 * ( s - 1 ) + f - s ;
                }
              else //up
                {
                  ans += 2 * ( e - 1 ) + s - e ; 
                  if( s <= f )//up
                    ans += f - s ;
                  else//down
                    ans += 2 * ( m - s ) + s - f ;
                }
            }
        }
      else ans = t ;
      cout<<ans<<"\n";
    }
  return 0;
}
