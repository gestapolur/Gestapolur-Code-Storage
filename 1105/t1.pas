program a;
var
   c : char;
   i : integer;

begin
   c := 'A';
   for i := 1 to 26 do
   begin
      write(c,' ');
      c := char(integer(c) + 1) ;
   end;
   writeln;
end.