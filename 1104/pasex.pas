program pasex ;
const s	=  'abcdefg';
var a,b	: integer ;
   c,d	: real ;
   {e	: char ;}
   
begin
   {
   readln(a,b);
   writeln('hello ',a+b);
   }
   {output size}
   {
   Randomize;
   c := random(10); 
   writeln(c:0:3);
   }
   {
   readln(a);
   case a of
     0 : begin
	    writeln('x');
	 end;
     1 : begin
	    writeln('y');
	 end;
   else begin writeln('z'); end;
   end;
   }
   {
   a := 0 ;
   repeat
      a += 2;
   until a = 10;
   writeln(a);
   }
end.