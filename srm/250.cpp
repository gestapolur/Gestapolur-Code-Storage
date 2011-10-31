//520
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#define MAXN 53
using namespace std;

class SRMRoomAssignmentPhase
{
public:
  int countCompetitors(vector <int> a, int k)
  {
    vector < int > b = a;
    int r[ MAXN ];
    int i , j , n ;
    n = a.size();
    for( i = 0 ; i < n ; ++ i )
      r[ i ] = i ;
    for( i = 0 ;i < n - 1 ; ++ i )
      for( j = i + i  ;j < n ; ++ j )
        if(  a[ i ] < a[ j ] )
          { 
            int t = a[ i ] ; a[ i ] = a[ j ] ; a[ j ] = t; 
            t = r[ i ] ; r[ i ] = r[ j ] ; r[ j ] = t;
          }
    int cnt ; 
    for( i = 0 ; i < n ; ++ i )
      if( r[ i ] == 0 )
        return ( i ) % k + 1;
  }
};

int main()
{
  return 0;
}
