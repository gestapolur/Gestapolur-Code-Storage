#include<iostream>
#include<queue>
using namespace std;

class node
{
public:
  int a , b;
};

queue < node > q;

int main()
{
  node x , y ;
  x.a = 1 , x.b = 2;
  
  q.push( x );
  
  y = q.front();
  cout<<y.a<<" "<<y.b<<"\n";

  return 0;
}
