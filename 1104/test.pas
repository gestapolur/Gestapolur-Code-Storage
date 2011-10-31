{$ASSERTIONS+}

uses graph;

type
   complex=record
      re:real;
      im:real;
   end;

operator * (a:complex; b:complex) c:complex;
begin
   c.re := a.re*b.re - a.im*b.im;
   c.im := a.im*b.re + a.re*b.im;
end;

operator + (a:complex; b:complex) c:complex;
begin
   c.re := a.re + b.re;
   c.im := a.im + b.im;
end;

var
   z,c:complex;
   gd,gm,i,j,k:integer;
begin
   gd:=D8bit;
   gm:=m640x480;
   InitGraph(gd,gm,'');
   Assert(graphResult=grOk);

   c.re:=-0.75;
   c.im:=0;
   for i:=-300 to 300 do
   for j:=-200 to 200 do
   begin
      z.re:=i/200;
      z.im:=j/200;
      for k:=0 to 200 do
      begin
         if sqrt(z.re*z.re + z.im*z.im) >2 then break
         else z:=(z*z)+c;
      end;
      PutPixel(i+300,j+200,k)
   end;

   readln;
   CloseGraph;
end.