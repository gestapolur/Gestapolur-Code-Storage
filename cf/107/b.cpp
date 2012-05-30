#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#define MAXN 102
using namespace std;

class person
{
public:
  string name;
  int n;
  string num[ MAXN ];
  int p , g , t;
};

person a[ MAXN ];
int n;

void init()
{
  
  cin>>n;

  for( int i = 1 ; i <= n ; ++ i )
    {
      cin>>a[ i ].n>>a[ i ].name;
      a[ i ].t = 0 , a[ i ].p = 0 , a[ i ].g = 0;
      for( int j = 1 ; j <= a[ i ].n ; ++ j )
        {
          cin>>a[ i ].num[ j ];
          if( a[ i ].num[ j ][ 0 ] == a[ i ].num[ j ][ 1 ] and a[ i ].num[ j ][ 1 ] == a[ i ].num[ j ][ 3 ] and a[ i ].num[ j ][ 3 ] == a[ i ].num[ j ][ 4 ] and a[ i ].num[ j ][ 4 ] == a[ i ].num[ j ][ 6 ] and a[ i ].num[ j ][ 6 ] == a[ i ].num[ j ][ 7 ] )
            ++ a[ i ].t ;
          else if( a[ i ].num[ j ][ 0 ] > a[ i ].num[ j ][ 1 ] and a[ i ].num[ j ][ 1 ] > a[ i ].num[ j ][ 3 ] and a[ i ].num[ j ][ 3 ] > a[ i ].num[ j ][ 4 ] and a[ i ].num[ j ][ 4 ] > a[ i ].num[ j ][ 6 ] and a[ i ].num[ j ][ 6 ] > a[ i ].num[ j ][ 7 ] )
            ++ a[ i ].p;
          else
            ++ a[ i ].g;
        }
    }

  return ;
}

void work()
{
  int mp , mg , mt , nt , ng , np ;
  mp = 0 , mg = 0 , mt = 0 ;
  np = 0 , ng = 0 , nt = 0 ;

  for( int i = 1 ; i <= n ; ++ i )
    {
      mp = mp > a[ i ].p ? mp : a[ i ].p;
      mg = mg > a[ i ].g ? mg : a[ i ].g;
      mt = mt > a[ i ].t ? mt : a[ i ].t;
    }
  
  for( int i = 1 ; i <= n ; ++ i )
    {
      if( a[ i ].t == mt ) ++ nt ;
      if( a[ i ].p == mp ) ++ np;
      if( a[ i ].g == mg ) ++ ng;
    }

  /*
  for( int i = 1 ; i <= n ; ++ i )
    cout<<a[ i ].t<<" "<<a[ i ].p<<" "<<a[ i ].g<<"\n";
  */
  //cout<<mt<<" "<<mp<<" "<<mg<<"\n";

  cout<<"If you want to call a taxi, you should call: ";
  for( int i = 1 ; i <= n ; ++ i )
    if( a[ i ].t == mt )
      {
        cout<<a[ i ].name;
        -- nt ;
        if( nt == 0 ) { cout<<"."; break;}
        else cout<<", ";
      }
  cout<<"\n";
  cout<<"If you want to order a pizza, you should call: ";
  for( int i = 1 ; i <= n ; ++ i )
    if( a[ i ].p == mp )
      {
        cout<<a[ i ].name;
        -- np ;
        if( np == 0 ) { cout<<"."; break;}
        else cout<<", ";
      }
  cout<<"\n";
  cout<<"If you want to go to a cafe with a wonderful girl, you should call: ";
  for( int i = 1 ; i <= n ; ++ i )
    if( a[ i ].g == mg )
      {
        cout<<a[ i ].name;
        -- ng ;
        if( ng == 0 ) { cout<<"."; break;}
        else cout<<", ";
      }
  cout<<"\n";
  return ;

}

int main()
{

  init();

  work();
  
  return 0;
}
