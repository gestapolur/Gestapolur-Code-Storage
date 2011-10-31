program SPFA;
const
   MAXN	= 10000;
   INF	=  20000000;
var
   n,m	      : longint;
   w	      : array[ 1..MAXN , 1..MAXN ] of longint;
   mark	      : array[ 1..MAXN ] of longint;
   inq	      : array[ 1..MAXN ] of boolean;
   q	      : array[ 1..3*MAXN ] of longint;
   rear,front : longint;
   i,j,u,v    : longint;
	      
procedure bfs(x: longint );
begin
   for i := 1 to n do
      begin
	 mark[ i ] := INF;
	 inq[ i ] := false;
      end;
   mark[ 1 ] := 0 ;
   rear := 1 ; front := 0 ;
   q[ 1 ] := 1 ; inq[ 1 ] := true;
   
   repeat
      inc( front );
      v := q[ front ];
      inq[ v ] := false;
      for i := 1 to n do
	 if (mark[ v ] <> INF) and (mark[ i ] > mark[ v ] + w[ v , i ]) then
	 begin
	    mark[ i ] := mark[ v ] + w[ v , i ];
	    if inq[ i ] = false then
	    begin
	       inc( rear );
	       q[ rear ] := i;
	       inq[ i ] := true;
	    end;
	 end;
   until rear <= front;

   for i := 1 to n do
      write(mark[ i ] , ' ');
   writeln;
   
end; { bfs }

begin
   readln( n , m );
   for i := 1 to n do
   begin
      w[ i , i ] := 0;
      for j := i + 1 to n do
      begin
	 w[ i , j ] := INF;
	 w[ j , i ] := INF;
      end;
   end;
   for i := 1 to m do
   begin
      readln( u , v , w[ u , v ] );
      w[ v , u ] := w[ u , v ]; 
   end;

   bfs( 1 );
   
end.