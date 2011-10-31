//SRM 497 DIV1 250
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class PermutationSignature
{
public:
  vector <int> reconstruct(string signature)
  {
    int i,j,n;
    //vector < int > ans;
    //vector < int > tmp;
    n = signature.size();
    vector < bool > hash ( n + 1 );
    vector < int > ans ( n + 1 );
    vector < int > nores;
    ans[ 0 ] = 1;
    for(i = 1 ; i <= n ; ++ i)
      hash[ i ] = false;
    hash[ 1 ] = true;
    for(i = 1 ; i <= n ; ++ i)
      {
	if(signature[ i - 1 ] == 'D')
	  {
	    ans[ i ] = ans[ i - 1 ];
	    do{
	      ++ans[ i - 1];
	    }while(hash[ ans[ i - 1]] and ans[ i - 1 ] <= n);
	    if(ans[ i - 1] > n + 1)
	      break;
	    else
	      hash[ ans[ i - 1] ] = true;
	    j = i - 1;
	    while(signature[ j - 1 ] == 'D' and ans[ j ] > ans[ j - 1])
	      {int tmp = ans[ j ] ; ans[ j ] = ans[ j - 1 ] ; ans[ j - 1 ] = tmp; --j ;}
	  }
	else
	  {
	    ans[ i ] = ans[ i - 1];
	    do{
	      ++ans[ i ];
	    }while(hash[ ans[ i ] ] and ans[ i ] <= n );
	    
	    if(ans[ i ] > n + 1)
	      break;
	    else
	      hash[ ans[ i ] ] = true;
	  }
      }
    for(j = 0 ;j <= n ; ++ j)
      cout<<ans[ j ]<<" ";
    cout<<"\n";
    if(i < n ) 
      return nores;
    else
      return ans;
  }
};

PermutationSignature test;


int main()
{
  string c;
  cin>>c;
  test.reconstruct( c );
  return 0;
}
