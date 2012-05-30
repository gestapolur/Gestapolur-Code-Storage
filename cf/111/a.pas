program cf_111_a;

const
   MAXN = 100;
var
   n   : integer;
   sum : longint;
   a   : array[1..MAXN] of integer;
     
procedure main;
var
   i , j , k : integer;
begin 
   readln( n );
   for i := 1 to n do
   begin
      read( a[ i ] );
      inc( sum , a[ i ] );
   end;
   readln;
   
   
   for i := 1 to n do
      for j := 1 to i - 1 do
         if a[ i ] < a[ j ] then
         begin
            k := a[ i ] ; a[ i ] := a[ j ] ; a[ j ] := k;
         end;
   i := 1 ; k := 0 ;
   
   while( i <= n ) do
   begin
      if ( k + a[ i ] <= sum - a[ i ] ) then
         inc( k , a[ i ] )
      else
         break ;
      inc( i );
   end;
   
   writeln( i );

end;

begin
   main;
end.