#include<iostream>
#include<string>
#define MAXN 1002
using namespace std;

int n , q , m ;
int fr[ MAXN ][ MAXN ] ;
string a[ MAXN ] , b[ MAXN ] , p[ MAXN ];

class hashtree
{
public:
  hashtree *child[ 27 ];
};

hashtree *root = NULL ;

bool intree( string x )
{
  bool sign = false;
  int i = 0 ;
  int len = x.size();
  hashtree *p = root;

  do{
    if( p->child[ x[ i ] - 'a' ] == NULL )
      {
        hashtree *nd = new hashtree;
        p->child[ x[ i ] - 'a' ] = nd ;
        sign = true;
      }
    else
      p = p->child[ x[ i ] - 'a' ];
    ++ i ;
  }while( i < len );

  return sign;

}

int find( string x )
{
  int l , r , mid;
  l = 1 , r = m;
  do{
    mid = l + r >> 1 ;
      if( p[ mid ] == x ) return mid;
      else if( p[ mid ] > x ) r = mid;
      else l = mid + 1 ;
  }while( l < r );
}

void sort( int i , int j )
{
  if( i >= j ) return ;
  int m , n ;
  string k , t;
  m = i , n = j , k = p[ i + j >> 1 ];
  while( m <= n )
    {
      while( p[ m ] < k ) ++ m ;
      while( p[ n ] > k ) -- n ;
      if( m <= n )
        {
          t = p[ m ] ; p[ m ] = p[ n ] ; p[ n ] = t;
          ++ m , --n;
        }
    }

  sort( i , n );
  sort( m , j );

  return ;
}

void work()
{
  int i ;

  //init tree
  root = new hashtree ;
  for( i = 0 ; i <= 26 ; ++ i )
    root->child[ i ] = NULL;

  //tree , find all person 
  cin>>n>>q;
  m = 0 ;
  for( i = 1 ; i <= n ; ++ i )
    {
       cin>>a[ i ]>>b[ i ];
       if ( intree( a[ i ] ) )
        p[ ++ m ] = a[ i ];
       if ( intree( b[ i ] ) )
         p[ ++ m ] = b[ i ];
    }

  //sort person
  sort( 1 , m );

  //build rel
  int fa , fb;
  for( i = 1 ; i <= n ; ++ i )
    {
      fa = find( a[ i ] ) ; fb = find( b[ i ] );
      fr[ fa ][ ++ fr[ fa ][ 0 ] ] = fb;
      fr[ fb ][ ++ fr[ fb ][ 0 ] ] = fa;
    }

  return ;
}

void output()
{
  string fd ;
  int per;
  for( int i = 1 ; i <= q ; ++ i )
    {
      cin>>fd;
      per = find( fd );
      for( int j = 1 ; j <= m ; ++ j )
      
    }
  for( int i = 1 ; i <= m ; ++ i ) fr[ i ][ 0 ] = 0 ;
  return ;
}



int main()
{
  int t , tt ;

  cin>>t;
  tt = 0 ;

  while( t -- )
    {
      ++ tt;

      work();
      
      cout<<"Case "<<tt<<":\n";
      
      output();

    }
  return 0;
}
