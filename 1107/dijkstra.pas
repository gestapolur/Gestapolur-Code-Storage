program dijkstra;
const
   MAXN	= 10000;
   INF	= 200000000;
var 
   n,m	   : longint;
   mark	   : array[ 1..MAXN ] of longint;
   w	   : array[ 1..MAXN , 1..MAXN] of longint;
   ins	   : array[ 1..MAXN ] of boolean;
   i,j,u,v : longint;
   
procedure dijkstra(x : longint );
var i,j,k,min : longint;
begin
   for i := 1 to n do
   begin
      mark[ i ] := w[ x , i ];
      ins[ x ] := false;
   end;
   
   ins[ x ] := true;
   
   for i := 1 to n do
   begin
      k := 0 ; min := INF ;
      for j := 1 to n do
	 if (not ins[ j ]) and (min > mark[ j ])
	    then begin
	       min := mark[ j ];
	       k := j ;
	    end;

      ins[ k ] := true;
      
      for j := 1 to n do
	 if mark[ j ] > mark[ k ] + w[ k , j ] then
	    mark[ j ] := mark[ k ] + w[ k , j ];
   end;
   
   for i := 1 to n do
      write(mark[ i ] , ' ');
   writeln;
end;

begin
   readln(n,m);
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
      readln( u , v , w[ u , v ]);
      w[ v , u ] := w[ u , v ];
   end;

   dijkstra( 1 );
      
end.