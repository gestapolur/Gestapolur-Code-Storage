#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
using namespace std;

class RotatedClock
{
public:
  string change( int x )
  {
    string z ;
    char c[ 2 ];
    c[ 0 ] =  x / 10 + 48  ;c[ 1 ] =  x - ( x / 10 * 10 ) + 48  ;
    //cout<<c[ 0 ]<<" "<<c[ 1 ]<<"\n";
    z = string( c );
    return z;
  }
  string getEarliest(int hourHand, int minuteHand)
  {
    string ans = "";
    int h = hourHand , m = minuteHand , th , tm , ah = 13 , am = 59;
    for( int i = 1 ; i <= 12 ; ++ i )
      {
	h = ( h + 30 ) % 360;
	m = ( m + 30 ) % 360;
	th = h % 30;
	tm = m % 360 ;
	
	if( fabs( double( th ) / 30 - double( tm )  / 360 )  < 1e-10 )
	  {
	    th = h / 30;
	    tm = m / 6;
	    //cout<<th<<" "<<tm<<"\n";
	    if( ah > th or ( ah == th and am > tm ))
	      { ah = th ; am = tm;}
	  }
      }
    //cout<<ah<<" "<<am<<"\n";
    if( ah not_eq 13 )
      ans = change( ah ) + ":" + change( am ); 
    return ans;
  }
};

RotatedClock test;

int main()
{
  int tx , ty ;
  cin>>tx>>ty;
  cout<<test.getEarliest( tx , ty )<<"\n";
  return 0;
}
