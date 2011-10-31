program floyd;
const
   MAXN	= 10000;
   INF	=  200000000;
var
   f	 : array [ 1..MAXN , 1..MAXN ] of longint;
   i,j,k : longint;
   n,m	 : longint;
   
begin
   readln( n , m );

   for i := 1 to n do
   begin
      f[ i , i ] := 0;
      for j := i + 1  to n do
      begin
	 f[ i , j ] := INF;
	 f[ j , i ] := INF;
      end;
   end;
   
   for i := 1 to m do
   begin
      readln( j , k , f[ j , k ]);
      f[ k , j ] := f[ j , k ];
   end;

   for k := 1 to n do
      for i := 1 to n do
	 for j :=1 to n do
	    if ( i<> j) and (j <> k) and (k <> i) and ( f[ i , j ] > f[ i , k ] + f[ k , j ]) then
	       f[ i , j ] := f[ i , k ] + f[ k , j ];
   for i := 1 to n do
      write(f[ 1 , i ],' ');
   writeln;
   
end.