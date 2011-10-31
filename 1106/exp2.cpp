#include<iostream>
using namespace std;

char team(int x )//返回数字对应的B队成员
{
  if(x == 1 ) return 'X';
  else if( x == 2 ) return 'Y';
  else return 'Z';
  return x ;
}

int main()
{
  int i,j,k;
  //枚举所有的对战情况
  for( i = 1 ; i <= 3 ; ++ i )
    {
      //某种对战情况
      for( j = 1 ; j <= 3 ; ++ j )
	for( k = 1 ; k <= 3 ; ++ k )
	  {
	    if( i != 1 )//表示A队三人分别对战的情况,A不和X比赛
	      cout<<" A vs "<<team( i )<<"\n";
	    cout<<" B vs "<<team( j )<<"\n";
	    if( k != 1 && k != 3 )//C对战的人不为X,Z
	      cout<<" C vs "<<team( k )<<"\n";
	  }
    }
  return 0;
}
