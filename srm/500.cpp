//520
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

class SRMCodingPhase
{
public:
  int countScore(vector <int> p, vector <int> s, int k)
  {
    int i , j , tmp , tmax = 0 ; 
    for( i = 0 ; i <= k ; ++ i )
      for( j = 0 ; j <= k - i ; ++ j )
        {
          int t1 , t2 , t3 , p1 , p2 , p3 ;
          t1 = s[ 0 ] - i ; t2 = s[ 1 ] - j , t3 = s[ 2 ] - ( k - i - j );
          p1 = p[ 0 ] - 2 * t1;
          p2 = p[ 1 ] - 4 * t2;
          p3 = p[ 2 ] - 8 * t3;
          if( p1 <= 0 ) { t1 = 0 , p1 = 0 ; }
          if( p2 <= 0 ) { t2 = 0 , p2 = 0 ; }
          if( p3 <= 0 ) { t3 = 0 , p3 = 0 ; }
          if( t1 + t2 + t3 <= 75 ) tmp = p1 + p2 + p3 ;
          else
            {
              tmp = 0 ;
              if( t1 + t2 <= 75 ) tmp = p1 + p2 ;
              if( t2 + t3 <= 75 and tmp < p2 + p3 ) tmp = p2 + p3 ;
              if( t1 + t3 <= 75 and tmp < p1 + p3 ) tmp = p1 + p3 ;
              if( t1 <= 75 and tmp < p1 ) tmp = p1 ;
              if( t2 <= 75 and tmp < p2 ) tmp = p2 ;
              if( t3 <= 75 and tmp < p3 ) tmp = p3 ;
            }
          tmax = tmp > tmax ? tmp : tmax ;
        }
    return tmax ;
  }
};

int main()
{
  return 0 ;
}
