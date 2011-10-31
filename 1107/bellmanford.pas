program bellman_ford;
const
   MAXN	= 10000;
   MAXE	= MAXN*MAXN;
   INF	= 20000000;
var
   n,m	 : longint;
   w,u,v : array[ 1..MAXE ] of longint;
   d	 : array[ 1..MAXN ] of longint;
   i,j	 : longint;

procedure bellmanford(x	: longint );
begin
   for i := 1 to n do
      d[ i ] := INF;
   d[ x ] := 0 ;
   
   for i := 1 to n do
   begin
      for j := 1 to 2*m do
	 if (d[ u[ j ] ] <> INF ) and (d[ v[ j ] ] > d[ u[ j ] ] + w[ j ]) then
	    d[ v[ j ] ] := d[ u[ j ] ] + w[ j ];
   end;
   
   for i := 1 to n do
      write( d[ i ] , ' ');
   writeln;
end; { bellmanford }


begin
   readln( n , m );
   i := 1 ;
   while (i < 2 * m ) do
   begin
      readln( u[ i ] , v[ i ] , w[ i ] );
      inc( i );
      u[ i ] := v[ i - 1 ] ; v[ i ] := u[ i - 1 ] ; w[ i ] := w[ i - 1 ] ; 
      inc( i );
   end;

   bellmanford( 1 );
   
end.