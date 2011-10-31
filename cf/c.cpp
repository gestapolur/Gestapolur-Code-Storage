#include<iostream>
//#include<vector>
//#include<cstring>
//#include<cstdlib>
//#include<cstdio>
//#include<cmath>
using namespace std;

long long sum = 0 ;
int st[ 30 ];

bool check( int x )
{
  int y ;
  do{
    y = x % 10;
    if( y not_eq 4 and y not_eq 7 ) return false ;
    x /= 10;
  }while( x > 0 );
  return true ;
}

inline long long make( int x , bool sign )
{
  int len ; 
  long long y ;
  //memset( st , 0 , sizeof( st ) );
  len = 0 , y = 0 ;
  do{
    st[ ++ len ] = x % 10 ;
    x /= 10 ;
  }while( x > 0 );
  //for( int i = 1 ; i <= len ; ++ i ) cout<<st[ i ]<<" "; cout<<"\n";
  for( int i = 1 ; i <= len ; ++ i )
    {
      if( st[ i ] < 4 ) { st[ i ] = 4 ; if( not sign ) break ; }
      else if( st[ i ] < 7 ) { st[ i ] = 7 ; if( not sign ) break ;}
      else
        {
          ++ st[ i + 1 ] ;
          if( i == len ) ++ len;
          for( int j = i ; j > 0 ; -- j ) st[ j ] = 4 ;
        }
    }
  //for( int i = 1 ; i <= len ; ++ i ) cout<<st[ i ]<<" "; cout<<"\n";
  for( int i = len ; i > 0 ; -- i )
    y = y * 10 + st[ i ];
  //cout<<y<<"\n";
  return y;
}

void init()
{
  long long l , r ;
  long long tmp ;
  cin>>l>>r;
  //scanf( "%I64d%I64d" , &l , &r );
  tmp = l ;
  if( not check( l ) )
    {
      //cout<<"!!!\n";
      tmp = make( tmp , true );
      if( l == r ) sum = tmp;
    }
  else
    {
      sum = l;
      tmp = make( tmp , false );
    }
  //cout<<tmp<<"!!!\n";
  //cin.get();cin.get();
  if( tmp < r )
    {
      sum = ( tmp - l + 1 ) * tmp;
      l = tmp ; 
      do{
        tmp = make( l , false );
        if( tmp < r )
          sum = sum +  ( tmp - l ) *  tmp ;
        else
          sum = sum + ( r - l )  *  tmp  ;
        //cout<<l<<" "<<r<<" "<<tmp<<"\n";
        l = tmp;
      }while( l < r );
    }
  else
    sum += ( r - l ) * tmp ;
  //printf( "%I64d\n" , sum );
  cout<<sum<<"\n";
  return ;
}

int main()
{
  init();
  return 0;
}
