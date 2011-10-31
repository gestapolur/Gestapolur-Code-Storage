#include<iostream>
#include<vector>
#define MAXN 501
using namespace std;

bool hash[ MAXN ];
bool ex[ MAXN ];

class SRMCards
{
public:
  int maxTurns(vector <int> cards)
  {
    int i,n,csd,ans = 0 ;
    n = cards.size();
    for( i = 0 ; i < n ; ++ i)
      ex[ cards[ i ] ] = true;
 
    while( 1 )
      {
	csd = -1 ;
	for(i = 0 ; i < n ; ++ i)
	  if( not hash[ cards[ i ] ] and 
	      ( ex[ cards[ i ] - 1] | ex[ cards[ i ] + 1] ) == false)
	    {csd = i ; break;}
	  else if(not hash[ cards[ i ] ] and 
	      ( ex[ cards[ i ] - 1 ] ^ ex[ cards[ i ] + 1 ] ) == true )
	    {csd = i ; break;}
	  else if(not hash[ cards[ i ] ] )
	    {csd = i ; break;}
	if(csd == -1 ) return ans;
	hash[ cards[ csd ] ] = true;
	hash[ cards[ csd ] + 1 ] = true;
	hash[ cards[ csd ] - 1 ] = true;
	++ans;
      }
  }  
};

SRMCards test;

int main()
{
  vector <int> a;
  int i,n,tmp;
  cin>>n;
  for(i = 0 ; i < n ; ++ i)
    {
      cin>>tmp;
      a.push_back(tmp);
    }
  cout<<test.maxTurns(a)<<"\n";
  return 0;
}
