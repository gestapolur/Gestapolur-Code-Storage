//poj 3768 AC
#include<iostream>
#include<string>
#include<cmath>
using namespace std;

//ifstream cin("test.in");
//ofstream cout("ans.out");

int n,m,lv;
string ch[ 6 ];
string tc[ 3005 ];

void cal(int lev , int sr , int sc , int er , int ec , int wide , bool sign)//wide is block wide
{
  int i,j;

  if(lev == 1 and sign )
    for(i = 0 ; i < n ; ++ i)
      for(j = 0 ; j < n ; ++ j)
	tc[sr + i ].push_back(ch[ i ][ j ]);
  else if( lev == 1 and not sign)
    for(i = 0 ; i < n ; ++ i)
      for(j = 0 ; j < n ; ++ j)
	tc[sr + i ].push_back(' ');
  else if( sign )
    for(i = 1 ; i <= n ; ++ i)
      for(j = 1 ; j <= n ; ++ j)
	if( ch[ i - 1 ][ j - 1] not_eq ' ')
	  cal(lev - 1 , sr + ( i - 1 ) * wide , sc + ( j - 1 ) * wide , i * wide , j * wide , wide / n , true);
	else
	  cal(lev - 1 , sr + ( i - 1 ) * wide , sc + ( j - 1 ) * wide , i * wide , j * wide , wide / n , false);
  else //not sign
    for(i = 1 ; i <= n ; ++ i)
      for(j = 1 ; j <= n ; ++ j)
	cal(lev - 1 , sr + ( i - 1 ) * wide , sc + ( j - 1 ) * wide , i * wide , j * wide , wide / n , false);
  
  return ;
}

void clr()
{
  int i,j;
  for(i = 0 ; i < m ; ++ i)
    tc[ i ] = "";
  for(i = 0 ; i < n ; ++ i)
    ch[ i ] = "";
  return ;
}

int main()
{
  int i , j;

  while( 1 )
    {
      cin>>n;
      if(n == 0)
	return 0;
      
      cin.get();
      for(i = 0 ; i < n ; ++ i)
	{
	  for(j = 1 ; j <= n ; ++ j)
	    ch[ i ].push_back(cin.get());
	  cin.get();
	}
      /*
      for(i = 0 ; i < n ; ++ i)
	cout<<ch[ i ]<<"-\n";
      */
      
      cin>>lv;
      m = pow(n,lv);
      //cout<<m<<"\n";
      cal(lv , 0 , 0 , m - 1 , m - 1 , m / n , true);

      for(i = 0 ; i < m ; ++ i)
	cout<<tc[ i ]<<"\n";
      clr();
      
    }
  return 0;
}
