program ex2;
type node = record
	       x,y   : integer;
	       c     : record
		    x,y : integer; 
		    end;	       
	       end;								   
var
   a : node;
   
begin
   with a do
   begin
      readln(x,y);
      writeln(x,' ',y,' ',c.x,' ',c.y);
   end;
end.
	    {
	    var
	    a : set of 0..11;
	    b : set of 0..11;
	    i : integer;
	       
begin
   {a := [0..1];
   b := [10];}
   a := [];
   for i := 1 to 12 do
      a := a + [ i ];
   for i := 1 to 12 do
      if i in a then
	 write(i,' ');
   writeln;
end.
}
