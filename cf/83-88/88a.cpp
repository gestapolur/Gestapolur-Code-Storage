//88
#include<iostream>
using namespace std;

int n , m , ans ;

void cnt( int st , int ed )
{
  bool up ;
  up = not ( ( ans / ( n - 1 ) ) & 1 );
  cout<<"turn "<<up<<" "<<ans<<" "<<st<<"\n";
  
  if( up and st < ed )
    ans += ed - st ;
  else if( not up and st < ed )
    ans += st + ed - 2 ;
  else if( up and st > ed )
    ans += ( 2 * n - st - ed ) ;
  else if( not up and st > ed )
    ans += st - ed ;
  
  return ;
}

int main()
{
  int i , si , ti , fi , ei ;

  cin>>m>>n;

  for( i = 1 ; i <= m ; ++ i )
    {
      cin>>si>>fi>>ti;
      if( si not_eq fi )
        {
          ans = ti;
          ei = ti % n + 1  ;
          cnt( ei , si );
          
          cnt( si , fi );
      
          cout<<ans<<"\n";
        }
      else
        cout<<"0\n";
    }
  return 0;
}
