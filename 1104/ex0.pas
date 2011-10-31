program ex0;
type aph = (a,b,c,d) ;
var
   tmp : array [ aph ] of integer;
   i   : aph;
   k   : integer;
begin
   k := 0;
   for i := a to d do
   begin
      tmp[ i ] := k;
      k := k + 2;
   end;
     
   for i := a to d do
      write(tmp[ i ],' ');
   writeln;
end.