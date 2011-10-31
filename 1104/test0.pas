program test;
var
   root : longint;

procedure f(x : longint );
begin
   if root <> x then
      root := x ;
      x := 2;
end;

begin
   readln(root);
   writeln( root );
   f(1);
   writeln( root );
end.