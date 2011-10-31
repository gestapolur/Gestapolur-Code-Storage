#include<iostream>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<vector>
#define MAXN 10006
using namespace std;

int n , k ,mint ;
string ca; 
int a[ MAXN ] , sv[ MAXN ];
int sa[ 30 ][ MAXN ];

void work( int x )
{
  int csd = 0 , cnt = 0 ;
  int rec[ MAXN ];
  int del = 0 , cl = x , cr = x , dl = 1 , dr = 1 ;
  int i ;
  //cout<<"!!!\n";
  while( cnt < k )
    {
      if( ( cl < 0 or cl > 9 or dl > sa[ cl ][ 0 ] ) and ( cr < 0 or cr > 9 or dr > sa[ cr ][ 0 ] ) )
        { ++ del; dl = 1 , dr = 1 ; cl = x - del ; cr = x + del ;}      
    
      //cout<<del<<" "<<cl<<" "<<cr<<" "<<dr<<" "<<dl<<" "<<x<<" "<<cnt<<" ";
      //if( cr > 0 ) cout<<"r "<<sa[ cr ][ 0 ]; if( cl > 0 ) cout<<"l "<<sa[ cl ][ 0 ]; 
      //cout<<"\n";
      //cin.get();
      if( (( ( cl >= 0 and cl <= 9 ) and dl <= sa[ cl ][ 0 ] ) or ( ( cr >= 0 and cr <= 9 ) and dr <= sa[ cr ][ 0 ] )) )
        {
      

          if( ( cl >= 0 and cl <= 9 and dl <= sa[ cl ][ 0 ] ) and ( cr >= 0 and cr <= 9 and dr <= sa[ cr ][ 0 ] ) )
            {
              if( cl not_eq cr )
                {
                  if( sa[ cl ][ dl ] < sa[ cr ][ dr ] )
                    rec[ ++ cnt ] = sa[ cl ][ dl ] , ++ dl ;
                  else rec[ ++ cnt ] = sa[ cr ][ dr ] , ++ dr;
                }
              else
                {
                  rec[ ++ cnt ] = sa[ cl ][ dl ] , ++ dl ;
                  ++ dr ;
                }
              csd += del ;
            }
          else if( cl >= 0 and cl <= 9 and dl <= sa[ cl ][ 0 ] ) 
            {rec[ ++ cnt ] = sa[ cl ][ dl ] ; ++ dl; csd += del ; }
          else if( cr >= 0 and cr <= 9 and dr <= sa[ cr ][ 0 ] ) 
            {rec[ ++ cnt ] = sa[ cr ][ dr ] ; ++ dr; csd += del ; }
        
        }
    
    }
  //test
  /*
  int b[ MAXN ];
  for( i = 1 ; i <= n ; ++ i )
    b[ i ] = a[ i ];
  for( i = 1 ; i <= k ; ++ i )
    b[ rec[ i ] ] = x ;
  cout<<csd<<"\n";
  for( i = 1 ; i <= n ; ++ i )
    cout<<b[ i ]<<" ";
  cout<<"\n";
  */
  if( csd < mint )
    {
      mint = csd ;
      for( i = 1 ; i <= n ; ++ i )
        sv[ i ] = a[ i ];
      //cout<<"!";for( i = 1 ; i <= k ; ++ i ) cout<<rec[ i ]<<" ";cout<<"\n";
      for( i = 1 ; i <= k ; ++ i )
        sv[ rec[ i ] ] = x ;
    }
  else if( csd == mint )
    {
      int b[ MAXN ];
      for( i = 1 ; i <= n ; ++ i )
        b[ i ] = a[ i ];
      for( i = 1 ; i <= k ; ++ i )
        b[ rec[ i ] ] = x ;
      for( i = 1 ; i <= n ; ++ i )
        if( sv[ i ] < b[ i ] ) return ;
        else if( sv[ i ] > b[ i ] ) break;
      for( i = 1 ; i <= n ; ++ i )
        sv[ i ] = b[ i ] ;
    }
  return ;
}

int main()
{
  int i , j ; 
  mint = 2141483647;
  cin>>n>>k;
  cin>>ca;
  for( i = 1 ; i <= n ; ++ i )
    {
      a[ i ] = ca[ i - 1 ] - 48 ;
      sa[ a[ i ] ][ ++ sa[ a[ i ] ][ 0 ] ] = i ;
    }
  //for( i = 1 ; i <= n ; ++ i ) cout<<a[ i ]<<" ";cout<<"\n";
  //for( i = 0 ; i <= 9 ; ++ i ) cout<<sa[ i ][ 0 ]<<" ";cout<<"\n";
  //return 0; 
  for( i = 0 ; i <= 9 ; ++ i )
    if( sa[ i ][ 0 ] > 0 )
      work( i );
  cout<<mint<<"\n";
  for( i = 1 ; i <= n ; ++ i )
    cout<<sv[ i ];
  cout<<"\n";
  return 0;
}
