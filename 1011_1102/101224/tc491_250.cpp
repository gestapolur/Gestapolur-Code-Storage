#include<iostream>
using namespace std;

class OneDigitDifference
{
public:
  int change(string x)
  {
    int n,ans = 0;
    n = x.size();
    for(int i = 0 ; i < n ; ++ i)
      ans = ans*10 + (x[i] - 48); 
    return ans;
  }

  int getSmallest(int N)
  {
    string a;
    char tmp;
    int s,t,rec = N;
    a = N;
    s = a.size();
    
    for(i = 0 ;i < s ; ++ i)
      {
	a[ i ] = N - 48;
	N = N / 10;
      }
    cout<<a<<"\n";
    for(int i = 0 ;i < s ; ++ i)
      {
	tmp = a[i];
	a[i] = '0';
	t = change(a);
	cout<<a<<"\n";
	if(t < rec)
	  rec = t;
	a[i] = tmp;
      }

    return rec ;
  }
};

OneDigitDifference test;

int main()
{
  int n;
  cin>>n;
  cout<<test.getSmallest(n)<<"\n";
  return 0;
}
