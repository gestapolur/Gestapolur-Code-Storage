program dijkstra;

const
   MAXN	= 1005;
   INF =  214148;
var
   n,m	: longint;
   w	: array [1..MAXN,1..MAXN] of longint;
   mark	: array [1..MAXN] of longint;
   vis	: array [1..MAXN] of boolean;
procedure dijkstra(s: longint );
var
   i , j , k , mint : longint;
begin
   for i := 1 to n do
      vis[ i ] := false;
   
   for i := 1 to n do
      if w[ s , i ] > 0 then
	 mark[ i ] := w[ s , i ]
      else
	 mark[ i ] := INF;
   mark[ s ] := 0 ;

   {
   for i := 1 to n do
      begin
	 for j := 1 to n do
	    write(w[ i , j ],' ');
	 writeln;
      end;
   }
   
   for i := 1 to n do
   begin
      mint := INF; k := 0 ;
      for j := 1 to n do
	 if (not vis[ j ] ) and (mint > mark[ j ]) then
	 begin
	    mint := mark[ j ] ; k := j ;
	 end;
      vis[ k ] := true;
      write(k,' ',mark[ k ]);
      for j := 1 to n do
	 if ( w[ k , j ] <> 0 ) and ( mark[ j ] > mark[ k ] + w[ k , j ] ) then
	    mark[ j ] := mark[ k ] + w[ k , j ];
      
      writeln;
   end;
   
   for i := 1 to n do
      write(mark[ i ] , ' ');
   writeln;
   
end;

procedure init();
var
   i , j , u , v : longint;
begin
   
   readln( n , m );
   
   for i := 1 to n do
      for j := 1 to n do
	 w[ i , j ] := 0 ;
	 
   for i := 1 to m do
   begin
      read(u,v);
      readln(w[ u , v ]);
   end;
   
end;

begin
   init();
   dijkstra( 1 );
end.