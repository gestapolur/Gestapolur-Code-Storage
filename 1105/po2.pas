program postoffice_poj1160;
var
   c		 : array [ 0..300 , 0..300 ] of longint;
   f		 : array [ 0..30 , 0..300 ] of longint;
   pos		 : array [ 0..300 ] of longint;
   v,p		 : integer;
   i,j,k,mid : integer;
   min		 : longint;
begin
   { init }
   readln( v , p );
   for i := 1 to v do
      read( pos[ i ] );
   readln;
   
   for i := 1 to v do
   begin
      c[ i , i ] := 0;
      for j := i to v do
      begin
	 c[ i , j ] := 0 ;
	 mid := ( i + j ) shr 1 ;
	 for k := i to mid - 1 do
	    c[ i , j ] := c[ i , j ] + pos[ mid ] - pos[ k ];
	 for k := mid + 1 to j do
	    c[ i , j ] := c[ i , j ] + pos[ k ] - pos[ mid ];
      end;
   end;
   
   for i := 0 to p do
      for j := 0 to v do
	 f[ i , j ] := 0;
   
   for i := 0 to v do
      f[ 1 , i ] := c[ 1 , i ];
   { dp }
   for i := 2 to p do
      for j := i to v do
      begin
	 min := 3000000;
	 for k := i - 1 to j - 1 do
	    if min > f[ i - 1 , k ] + c[ k + 1  , j ] then
	       min := f[ i - 1 , k ] + c[ k + 1 , j ];
	 f[ i , j ] := min;
      end;
   writeln(f[ p , v ]);
end.