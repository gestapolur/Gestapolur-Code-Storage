#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<cstdio>
using namespace std;

double n;

int main()
{
  cin>>n;
  n += 1;
  cout<<(int(( n / 3 ) / 12))<<" "<<(int( int( n / 3 ) % 12 ))<<"\n";
  return 0;
}
