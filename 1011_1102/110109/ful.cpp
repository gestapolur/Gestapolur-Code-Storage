//Newton's Method
//think about some failure case
#include<iostream>
#include<cmath>
#define MAXN 1001
using namespace std;

int a[MAXN];
int ap[MAXN];
int n;//the highest times of equation

double fun1(double x)//f(x)
{
  int i;
  double res = 0.0000000;
  for(i = 1 ; i <= n ; ++ i)
    {
      res = res + a[i]*pow(x,i - 1);
      //cout<<"pow : "<<i<<" "<<a[i]*pow(x,i - 1)<<"\n";
    }
  return res;
}

double fun2(double x)//f'(x)
{
  int i;
  double res = 0.0000000;
  for(i = 2 ; i <= n ; ++ i)
    {
      res = res + ap[i]*pow(x,i - 2);
      //cout<<"pow : "<<ap[i]<<" "<<ap[i]*pow(x,i - 2)<<"\n";
    }
  return res;
}

int main()
{
  int i,opt; 
  double tmp;
  cout.setf(ios::showpoint);
  cout.setf(ios::fixed);
  cout.precision(5);
  cin>>n;
  //input like a0*x^0 + a1*x^1 + ... an*x^n = 0
  for(i = 1 ;i <= n ; ++ i)
    {
      cin>>a[i];
      ap[i] = a[i]*(i - 1);
    }
  opt = 100;
  i = 0;
  tmp = 0;
 
  while(i < opt)
    {
      //cout<<"before : "<<tmp<<" "<<fun1(tmp)<<" "<<fun2(tmp)<<"\n";
      tmp = tmp - fun1(tmp)/fun2(tmp);
      cout<<tmp<<"\n";
      ++i;
    }
  cout<<tmp<<"\n";
  return 0;
}
