//SRM 498 DIV1 250
#include<iostream>
using namespace std;

class AdditionGame
{
public:
  int gb(int a, int b , int c)
  {
    int bigest = 0,mark = 0;
    if(a > b)
      bigest = a , mark = 1;
    else
      bigest = b , mark = 2;
    if(c > bigest)
      bigest = c , mark = 3;
    return mark;
  }

  int getMaximumPoints(int A, int B, int C, int N)
  {
    int maxn = 0 , maxs = 1 , point = 0;
    while(N > 0)
      {
	maxs = gb(A,B,C);
	if(maxs == 1)
	  {
	    point += A;
	    if(A >= 1)
	      --A;
	  }
	else if(maxs == 2)
	  {
	    point += B;
	    if(B >= 1)
	      --B;
	  }
	else
	  {
	    point += C;
	    if(C >= 1)
	      --C;
	  }
	--N;
      }
    return point ;
  }
};

AdditionGame test;

int main()
{
  int a,b,c,n;
  cin>>a>>b>>c>>n;
  cout<<test.getMaximumPoints(a,b,c,n)<<"\n";
 
  return 0;
}
