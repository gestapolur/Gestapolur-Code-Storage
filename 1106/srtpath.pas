program floyd;
var
   i,j,k,u,v,n,m : integer;
   f		 : array[1..350,1..350] of longint;
const 
   INF = 1 shl 20;

begin
   readln( n , m );
   for i := 1 to n do
      for j := i + 1 to n do
	 begin
	    f[ i , j ] := INF;
	    f[ j , i ] := INF;
	 end;
   for i := 1 to m do
   begin
      read( u , v );
      readln(f[ u , v ]);
   end;
   for k := 1 to n do
      for i := 1 to n do
	 for j := 1 to n do
	    if ( i <> j ) and ( j <> k ) and ( k <> i )and( f[ i , j ] > f[ i , k ] + f[ k , j ])
	       then f[ i , j ] := f[ i , k ] + f[ k , j ];
   writeln( f[ 1 , n ] );
end.
