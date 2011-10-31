program csu_monthyJun_C;

var
   x,k : longint;

begin
   while not eof do
   begin
      readln( x );
      k := 1 ;
      while (x and 1 = k) and ( x > 2 ) do 
      begin
	 dec( x , x shr 1 );
	 k := k xor 1 ;
      end;
      if x = 2 then
	 writeln('Oh,It''','s a fix number')
      else
	 writeln('Sorry,It isn''','t a fix number');
   end;
end.