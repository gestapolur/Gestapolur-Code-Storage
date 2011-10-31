#include<iostream>
#define MAXN 1000006
using namespace std;

class treenode
{
public:
  int sum , l , r , t ;
};

treenode node[ MAXN ];
int n , m , a , b,;

void create( int l , int r , int s )
{
  node[ s ].l = l , node[ s ].r = r , node[ s ].sum = 0 ;
  if( l not_eq r )
    {
      mid = l + r >> 1;
      create( l , mid , s << 1 );
      create( mid + 1 , r , ( s << 1 ) + 1 );
    }
  return ;
}

void insert( int l , int r , int s )
{
  if( node[ s ].l == l and node[ s ].r == r and node[ s ].sum not_eq 2 )
    {
      node[ s ].sum = 1;
      node[ s << 1 ].sum = 1 ;
      node[ ( s << 1 ) + 1 ].sum = 1 ;
    }
  else
    node[ s ].sum = 2;

  if ( node[ s ].l == node[ s ].r ) 
    return ;
   
  int mid = (node[ s ].l + node[ s ].r) shr 1; 
  
  if ( mid >= r )
    insert( l , r , s << 1 ); 
  else if ( mid < l ) 
    insert( l , r , ( s << 1 )  + 1  ); 
  else 
    {
      insert( l , mid , s << 1  ); 
      insert( mid + 1 , r , ( s << 1 ) + 1 ); 
    } 

  if ( node[ s shl 1 ].sum = node[ s shl 1 or 1 ].sum ) 
    node[ s ].sum = node[ s shl 1 ].sum; 
  return ;
}

int find( int l , int r , int s ); 
{
  
  if ( ( node[ s ].l == l ) and ( node[ s ].r == r ) and ( node[ s ].sum not_eq 2 ) ) 
    {
      if ( node[ s ].sum == 1 ) 
	 
      else 
	 exit( 0 ); 
   end; 
   if node[ s ].l = node[ s ].r then 
      exit( 0 ) 
   else 
   begin 
      mid := (node[ s ].l + node[ s ].r) shr 1 ; 
      if mid >= r then 
	 exit(find( l , r , s shl 1 )) 
      else if mid < l then 
	 exit(find( l , r , s shl 1 + 1 )) 
      else 
	 exit(find( l , mid , s shl 1 ) + find( mid + 1 , r , s shl 1 + 1 )) 
   end; 
end; 

int main()
{ 
  whilecin>>n; 
      create( 1 , n , 1 ); 
      for i := 1 to m do 
      begin 
	 readln(cin,a,b); 
	 writeln(cout,find(a,b,1)); 
	 insert(a,b,1); 
      end; 
      writeln(cout); 
   end; 
end.
