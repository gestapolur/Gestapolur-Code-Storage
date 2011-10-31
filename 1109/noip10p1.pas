program noip2010t1;
const
   MAXN = 1005;
   MAXM = 105;
var 
   q,a                  : array[1..MAXN] of integer;
   hash                 : array[1..MAXM] of boolean;
   m , n , rear , front : integer;

procedure init();
var
   i : integer;
begin
   readln( n , m );
   for i := 1 to n do
      read( a[ i ] );
   readln;
end; { init }

procedure work();
begin
   rear := 1 ; front := 0;
   do
   i:=1;
until ( front = rear );
end; { work }


begin
   
   init();

   work();
   
end.
