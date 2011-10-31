/*TCO 10 */
#include<iostream>
#include<string>
#define MAXN 52
using namespace std;

class GirlsAndBoys
{
public:
  int sortThem(string row)
  {
    int swp = 0,ans;
    int i,j,n;
    string tmp,t;

    n = row.size();

    tmp = row;
    swp = 0;
    for(i = 1 ; i < n ; ++ i)
      if(tmp[i] == 'G')
	{
	  j = i;
	  while(tmp[j] not_eq tmp[j - 1] and j > 0)
	    {
	      tmp[j] = 'B';
	      tmp[j - 1] = 'G';
	      swp++;
	      --j;
	    }
	}

    ans = swp;

    tmp = row;
    swp = 0;
    for(i = 1 ; i < n ; ++ i)
      if(tmp[i] == 'B')
	{
	  j = i;
	  while(tmp[j] not_eq tmp[j - 1] and j > 0)
	    {
	      tmp[j] = 'G';
	      tmp[j - 1] = 'B';
	      swp++;
	      --j;
	    }
	}

    if(ans > swp) ans = swp;

    return ans;
  }
};

GirlsAndBoys test;

int main()
{
  string a;
  cin>>a;
  cout<<test.sortThem(a)<<"\n";
  return 0;
}
