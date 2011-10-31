program a_monthyjun;
var
   st	       : array[ 1..1000 ] of integer;
   r,b,d,n     : integer;
   i,j	       : integer;
   tot,stp,edp,divs : integer;

function check(i : integer):boolean;
begin
   while i > 0 do
   begin
      if i - i div 10 * 10 = 7 then
	 exit( true );
      i := i div 10;
   end;
   check := false;
end; { check }

begin
   tot := 0 ;
   for i := 1 to 1000 do
   begin
      if ( i mod 7 = 0 ) or ( check( i ) ) then
      begin
	 inc( tot );
	 st[ tot ] := i;
      end;
   end;
   {for i := 1 to tot do write(st[ i ],' ');}
   while not eof do
   begin
      readln(r,b,d,n);
      stp := 1;
      while st[ stp ] <> d do
	 inc( stp );
      edp := stp + n ;
      divs := st[ edp ]
      writeln(st[ n ]);
   end;
end.