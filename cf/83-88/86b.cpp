#include<iostream>
#include<string>
#include<algorithm>
#define MAXN 17
using namespace std;

int n , m , con , ans ;
bool w[ MAXN ][ MAXN ];
string a[ MAXN ] , s[ MAXN ] , ts[ MAXN ] ;
int ns[ MAXN ];

int main()
{
  int i , j , k;
  string t , u , v ;
  int nu , nv , cnt ;
  bool sign;
  cin>>n>>m;

  for( i = 1 ; i <= n ; ++ i )
    cin>>a[ i ];

  for( i = 1 ; i < n ; ++ i )
    for( j = i + 1 ; j <= n ; ++ j )
      if( a[ i ] > a[ j ] )
        { t = a[ i ] ; a[ i ] = a[ j ] ; a[ j ] = t;}

  for( i = 1 ; i <= m ; ++ i )
    {
      cin>>u>>v;
      for( j = 1 ; j <= n ; ++ j )
        if( u == a[ j ] )
          {nu = j;break;}
      for( j = 1 ; j <= n ; ++ j )
        if( v == a[ j ] )
          {nv = j ; break; }
      w[ nu ][ nv ] = true;
      w[ nv ][ nu ] = true;
    }

  con = ( 1 << n ) + 1 ;
  //cout<<con<<"\n";
  /*
  for( i = 1 ; i <= n ; ++ i )
    {
      for( j = 1 ; j <= n ; ++ j )
        cout<<w[ i ][ j ]<<" ";
      cout<<"\n";
    }
  */
  //cout<<con<<"\n";
  for( i = 1 ; i <= con ; ++ i )
    {
      cnt = 0 ;
      for( j = 0 ; j < n ; ++ j )
        {
          /*
          if( i == 9 )
            cout<<( ( i >> j ) & 1 )<<" ";
          */
          if( ( i >> j ) & 1 == 1 )
          {
            sign = true;
            if( cnt > 0 )
              for( k = 1 ; k <= cnt ; ++ k )
                if( w[ ns[ k ] ][ j + 1 ] == true )
                  {sign = false ; break;}
            if( not sign ) break;
            ns[ ++ cnt ] = j + 1 ;
          }
        }//cout<<"\n";
      if( cnt > ans )
        {
          ans = cnt;
          for( j = 1 ; j <= cnt ; ++ j )
            s[ j ] = a[ ns[ j ] ];
        }
    }

  for( i = 1 ; i < ans ; ++ i )
    for( j = i + 1 ; j <= ans ; ++ j )
      if( s[ i ] > s[ j ] )
        { t = s[ i ] ; s[ j ] = s[ i ] ; s[ i ] = t;}

  cout<<ans<<"\n";
  for( i = 1 ; i <= ans ; ++ i ) 
    cout<<s[ i ]<<"\n";

  return 0;
}
