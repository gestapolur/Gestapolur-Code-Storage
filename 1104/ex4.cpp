//GCJ 2010 ROUND 1 C
#include<iostream>
using namespace std;

int l,p,c,n;

bool check(int l , int r , int rst)
{
  if(rst == 1)
    {
      if(l * c >= r)
	return true;
      else
	return false;
    }
  else
    {
      int x = ;
      return (check(l,x) & check(rst - 1))
    }
}

int main()
{
  int k,i;
  for()
  return 0;
}
