program divisibility_poj1745;
var
   f	   : array [0..10000,0..100] of boolean;
   a	   : array [1..10000] of integer;
   i,j,n,k : integer;
begin
   readln( n , k );
   for i := 1 to n do
   begin
      read( a[ i ] );
      a[i] := ( a[ i ] mod k + k ) mod k;             
   end;
   readln;
   
   for i := 1 to n do
      for j := 0 to k do
	 f[ i , j ] := FALSE;
   
   f[ 1 , a[ 1 ] ] := TRUE;
   for i := 2 to n do
      for j := 0 to k - 1 do
	 if (f[ i - 1 , ( j - a[ i ] + k ) mod k ]) or (f[ i - 1 , ( j + a[ i ] ) mod k ]) then   
	    f[ i , j ] := TRUE;
              
   if(f[ n , 0 ] ) then
      writeln('Divisible')
   else
      write('Not divisible');
end.