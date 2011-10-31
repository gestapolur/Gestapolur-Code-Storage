//86
#include<iostream>
using namespace std;

long long ta , b , a ;

int main()
{
  int cnt = 0 ;
  cin>>ta>>b;
  a = ta;
  while( a <= b )
    {
      if( a == b )
        {
          cout<<"YES\n"<<cnt<<"\n";
          return 0;
        }
      a = a * ta;
      ++ cnt;
    }
  cout<<"NO\n";
  return 0;
}
