program post_office;
const
   MAXN	= 301;
   INF	=  3000000;
var	
   n , m , k	 : integer ;
   a		 : array [ 1..MAXN ] of integer ;
   w		 : array [ 0..MAXN , 0..MAXN ] of integer ;
   f		 : array [ 0..MAXN , 0..31 , 0..MAXN ] of longint;
   i , j , v , t : integer ;
   s1		 : longint ;
begin
   readln( n , k );
   for i := 1 to n do
      read( a[ i ] );
   readln;
   { init }
   for i := 1 to n do
   begin
      w[ i , i ] := 0 ;
      for j := i + 1  to n do
      begin;
	 w[ i , j ] := a[ j ] - a[ i ];
	 w[ j , i ] := w[ i , j ];
      end;
   end;
   
   for i := 0 to n do
      for j := 0 to k do
	 for v := 0 to n do
	    f[ i , j , v ] := INF;

   for i := 1 to n do
      for j := 1 to i do
      begin
	 f[ i , 1 , j ] := 0 ;
	 
	 for v := 1 to i  do
	    f[ i , 1 , j ] := f[ i , 1 , j ] + w[ v , j ];
      end;

   {dynamic programming}
   for i := 1 to n do
   begin
      m := k;
      if m > i then m := i;
      for j := 2 to m do
	 begin
	    for v := 1 to i - 1 do
	       f[ i , j , v ] := f[ i - 1 , j , v ] + w[ v , i ];
	    
	    for v := 1 to i - 1 do
	    begin
	       s1 := 0 ;
	       for t := v + 1 to i - 1 do
		  if w[ v , t ] > w[ t , i ] then
		     s1 := s1 - w[ v , t ] + w[ t , i ];
	       if f[ i , j , i ] > f[ i - 1 , j - 1 , v ] + s1 then
		  f[ i , j , i ] := f[ i - 1 , j - 1 , v ] + s1;
	    end;
	 end;
   end;
   { test }
   {for i := 1 to n do write(f[n,k,i],' ');writeln;}
   for i := 1 to n do
      if f[ n , k , 0 ] > f[ n , k , i ] then
	 f[ n , k , 0 ] := f[ n , k , i ];
   writeln(f[ n , k , 0 ]);
end.