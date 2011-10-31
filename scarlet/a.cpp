#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#define MAXN 20
#define MAXH 19911113
#define INF 2141483647
using namespace std;

int n , m ;
int org[ MAXN ];

class state
{
public:
  int s[ MAXN ];
  bool pres[ MAXN ][ MAXN ];
  int step;
};

class hashx
{
public:
  int s[ MAXN ];
  int step;
  hashx *next;
};

state *q[ 1 << 22 ] ;

hashx *hash[ MAXH ] = { NULL };

bool check( int s[ ] )
{
  for( int i = 1 ; i <= n ; ++ i )
    for( int j = 1 ; j <= m ; ++ j )
      if( ( ( s[ i ] >> j ) & 1 ) == 1  ) { return false ;}
  return true ;
}

bool hashc( int p[ ] , int step )
{
  int hashsum = 0 ;
  for(int i = 1 ; i <= n ; ++ i )
    hashsum = ( hashsum + p[ i ] * p[ i ] ) % MAXH ;
  /*
  for( int i = 1 ; i <= n ; ++ i ) cout<<p[ i ]<<" "; cout<<"\n";
  cout<<hashsum<<"\n";
  */
  if( hash[ hashsum ] == NULL )
    {
      hash[ hashsum ] = new hashx ;
      for(int i = 1 ; i <= n ; ++ i )
        hash[ hashsum ]->s[ i ] = p[ i ] ;
      hash[ hashsum ]->next = NULL;
      hash[ hashsum ]->step = step;
    }
  else
    {
      int i ;
      hashx *q = NULL;
      q = hash[ hashsum ] ;
      while( q not_eq NULL )
        {
          for( i = 1 ; i <= n ; ++ i )
            if( q->s[ i ] not_eq p[ i ] ) 
              break;
          if( i == n + 1 )
            {
              if( q->step <= step )
                return true;
              q->step = step;
              return false ;
            }
          q = q->next ;
        }
      q = new hashx ;
      q->step = step ;
      for( i = 1 ; i <= n ; ++ i )
        q->s[ i ] = p[ i ];
      q->next = hash[ hashsum ];
      hash[ hashsum ] = q ;
    }
  return false ;
}

void work()
{
  int i , j; 
  int rear , front , ans = INF ;
  int tmp[ MAXN ];
  state *p ;
  rear = 1 , front = 0 ;
  memset( q , 0 , sizeof( q ) );
  q[ 1 ] = new state ;
  for( i = 1 ; i <= n ; ++ i ) q[ 1 ]->s[ i ] = org[ i ] ;
  for( i = 1 ; i <= n ; ++ i )
    for( j = 1 ; j <= m ; ++ j )
      q[ 1 ]->pres[ i ][ j ] = false ;
  q[ 1 ]->step = 0 ;
  /*
 for( i = 1 ; i <= n ; ++ i )
    {
      for( j = m ; j >= 1 ; -- j )
        cout<<( ( q[ 1 ].s[ i ] >> j ) & 1 )<<" ";
      cout<<"\n";
    }
  cout<<"--------\n";cin.get();
  */
  hashc( q[ 1 ]->s , 0 );
  //cout<<"@@@\n";
  do{
    p = q[ ++ front ] ;
    //test
    /*
    cout<<p->step<<"\n";
    for( i = 1 ; i <= n ; ++ i ) cout<<p->s[ i ]<<" "; cout<<"\n"; 
    for( i = 1 ; i <= n ; ++ i )
      {
        for( j = m ; j >= 1 ; -- j )
          cout<<( ( p->s[ i ] >> j ) & 1 )<<" ";
        cout<<"\n";
      }
    */
    //cout<<"--------\n";cin.get();
    
    if( check( p->s ) )
      {
        ans = p->step < ans ? p->step : ans ;
        break;
        //cout<<"!\n";
      }
    else
      {
        for( i = 1 ; i <= n ; ++ i )
          tmp[ i ] = p->s[ i ];
        for( i = 1 ; i <= n ; ++ i )
          for( j = 1 ; j <= m ; ++ j )
            if( not p->pres[ i ][ j ] and p->step + 1 < ans )
              {
                tmp[ i ] ^= ( 1 << j ) ; tmp[ i ] ^= ( 1 << j + 1 ); tmp[ i ] ^= ( 1 << j - 1 );
                tmp[ i + 1 ] ^= ( 1 << j ); tmp[ i - 1 ] ^= ( 1 << j );
                //for( int k = 1 ; k <= n ; ++ k ) cout<<tmp[ i ]<<" "; cout<<"\n";
                //for( int k = 1 ; k <= n ; ++ k ) cout<<p->s[ i ]<<" "; cout<<"\n";
                if( not hashc( tmp , ( p->step + 1 ) ) 
                    and ( tmp[ i ] not_eq p->s[ i ] or ( i + 1 <= n and tmp[ i + 1 ] not_eq p->s[ i + 1 ] ) or ( i > 1 and tmp[ i - 1 ] not_eq p->s[ i - 1 ] ) ) )
                  {
                    q[ ++ rear ] = new state ;
                    q[ rear ]->step = p->step + 1 ;
                    for( int k = 1 ; k <= n ; ++ k )
                      q[ rear ]->s[ k ] = tmp[ k ];
                    for( int k = 1 ; k <= n ; ++ k )
                      for( int v = 1 ; v <= m ; ++ v )
                        q[ rear ]->pres[ k ][ v ] = p->pres[ k ][ v ];
                    q[ rear ]->pres[ i ][ j ] = true ;
                    /*
                    cout<<"new "<<i<<" "<<j<<"\n";
                    for( int k  = 1 ; k <= n ; ++ k )
                      {
                        for( int v = m ; v >= 1 ; -- v )
                          cout<<( ( q[ rear ]->s[ v ] >> k ) & 1 )<<" ";
                        cout<<"\n";
                      }
                    */
                  }
                tmp[ i ] ^= ( 1 << j ) ; tmp[ i ] ^= ( 1 << j + 1 ); tmp[ i ] ^= ( 1 << j - 1 );
                tmp[ i + 1 ] ^= ( 1 << j ); tmp[ i - 1 ] ^= ( 1 << j );              
              }
      }
  }while( front < rear );
  
  if( ans not_eq INF )
    cout<<"You have to tap "<<ans<<" tiles.\n";
  else
    cout<<"Damaged billboard.\n";
  return ;
}

bool init()
{
  cin>>n>>m;
  char ch; 
  if( n == 0 and m == 0 ) return false ;
  memset( org , 0 , sizeof( org ) );
  memset( hash , 0 , sizeof( hash ) );
  //cout<<"done\n";return false; 
  cin.get();
  for( int i = 1 ; i <= n ; ++ i )
    {
      for( int j = 1 ; j <= m ; ++ j )
        {
          ch = cin.get();
          if( ch == 'X' )
            org[ i ] |= ( 1 << j ) ; 
        }
      cin.get();
    }
  
  //for( int i = 1 ; i <= n ; ++ i ) cout<<org[ i ]<<"\n";
  for( int i = 1 ; i <= n ; ++ i )
    {
      for( int j = m ; j >= 1 ; -- j )
        cout<<( ( org[ i ] >> j ) & 1 )<<" ";
      cout<<"\n";
    }
  
  return true ;
}

int main()
{
  while( init() )
    work();
  
  return 0;
}
