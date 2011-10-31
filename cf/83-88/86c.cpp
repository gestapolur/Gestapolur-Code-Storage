#include<iostream>
#include<string>
#define MAXN 100005
using namespace std;

string ste;
string w[ MAXN ];
int m;

void init()
{
  int i , len , pre = 0 ;
  getline( cin , ste );
  len = ste.size();
  // gen word
  for( i = 0 ; i < len ;  ++ i )
    if( ste[ i ] == ' ' )
      {
        ++ m ;
        for( ; pre < i ; ++ pre )
          w[ m ].push_back( ste[ pre ]);
        pre = i + 1 ;
      }
  ++ m ;
  for( ; pre < len ; ++ pre )
    w[ m ].push_back( ste[ pre ] );

  //for( i = 1 ; i <= m ; ++ i ) cout<<w[ i ]<<"\n";

  return ;
}
// 1 fe 0 me
int checkn( int x )
{

  if( w[ x ].size() < 3 ) return -1;

  int tn = w[ x ].size();

  if(tn > 3 and  w[ x ][ tn - 1 ] == 'a' and w[ x ][ tn - 2 ] == 'r' and w[ x ][ tn - 3 ] == 't' and w[ x ][ tn - 4 ] == 'e')
    return 1 ;

  if( w[ x ][ tn - 1 ] == 'r' and w[ x ][ tn - 2 ] == 't' and w[ x ][ tn - 3 ] == 'e' )
    return 0 ;

  return -1 ;
}

int checka( int x )
{

  if( w[ x ].size() < 4 ) return -1 ;

  int tn = w[ x ].size();

  if( tn > 4 and w[ x ][ tn - 1 ] == 'a' and w[ x ][ tn - 2 ] == 'l' and w[ x ][ tn - 3 ] == 'a' and w[ x ][ tn - 4 ] == 'i' and w[ x ][ tn - 5 ] == 'l')
    return 1;

  if( w[ x ][ tn - 1 ] == 's' and w[ x ][ tn - 2 ] == 'o' and w[ x ][ tn - 3 ] == 'i' and w[ x ][ tn - 4 ] == 'l' )
    return 0;

  return -1;
}

int checkv( int x )
{
  if( w[ x ].size() < 6 ) return -1 ;
  int tn = w[ x ].size();
  if( w[ x ][ tn - 1 ] == 's' and w[ x ][ tn - 2 ] == 'e' and w[ x ][ tn - 3 ] == 't' and w[ x ][ tn - 4 ] == 'i' and w[ x ][ tn - 5 ] == 'n' and w[ x ][ tn - 6 ] == 'i')
    return 1;
  if( w[ x ][ tn - 1 ] == 's' and w[ x ][ tn - 2 ] == 'i' and w[ x ][ tn - 3 ] == 't' and w[ x ][ tn - 4 ] == 'i' and w[ x ][ tn - 5 ] == 'n' and w[ x ][ tn - 6 ] == 'i')
    return 0;
  return -1;
}

bool work()
{
  int i , non = 0 , tmp , nv = 0 , na = 0 ;
  int gen;// 0 me 1 fe
  for( i = 1 ; i <= m ; ++ i )
    {
      tmp = checkn( i );
      if( tmp not_eq -1 )
        {
          if( non > 0 ) return false;
          non = i; gen = tmp ;
        }
    }
  //cout<<m<<" "<<non<<"!!!\n";
  //if( non == 0 ) return false;
  if( m > 1 )
    {
      if( non == 0 ) return false;
      for( i = 1 ; i < non  ; ++ i )
        if( checka( i ) not_eq gen )
          return false;
        else ++ na;
      
      for( i = non + 1 ; i <= m ; ++ i )
        if( checkv( i ) not_eq gen )
          return false;
        else ++ nv;
      if(( na == 0 and nv not_eq 0  ) or ( na not_eq 0  and nv == 0 ) ) return false;
    }
  else
    {
      if( checkn( 1 ) not_eq -1 or checkv( 1 ) not_eq -1 or checka( 1 ) not_eq -1 ) return true;
      return false;
    }
  return true ;
}

int main()
{
  //input gen word
  init();
  
  if( work() ) cout<<"YES\n";
  else cout<<"NO\n";
  return 0;
}
