program test;
var
   x : integer;
begin
   readln( x );
   while x > 0 do
   begin
      writeln(x - x div 10 * 10 );
      x := x div 10 ;
   end;
end.