{
program ex1;
const
   MAXN	= 10000;
var 
   i,j,n : longint;
   f	 : array [ 0..MAXN , 0..MAXN ] of longint;
	 
begin
   readln(n);
   f[ 0 , 1 ] := 1 ;
   f[ 1 , 0 ] := 1 ;
   for i := 1 to n do
      for j := 1 to n do
	 f[ i , j ] := f[ i , j - 1 ] + f[ i - 1 , j ];
   writeln(f[ n , n ]);
end.
}

{
program test;
var
   i , j : integer;
   f	 : array[1..50,1..50] of real;
begin
   Randomize;
   for i := 1 to 10 do
   begin
      for j := 1 to 10 do
      begin
	 f[ i , j ] := random(i + j);
	 write(f[ i , j ]:0:3,' ');
      end;
      writeln;
   end;
end.
}
{
program func;

function work(x	:  integer) : integer;
begin
   if x > 100 then
   begin
      x := x - 10;
      work:= 1
   end
   else if x < 100 then
      work := 2
   else
      work := 3;
end;

var
   x : integer;
begin 
   repeat
      readln(x);
      writeln(work(x));
   until x = 0;
   
end.
}

program qucik_sort;
var
   n : longint;
   i : longint;
   a : array[1..1000] of longint;

procedure qsort(i , j : longint );
var
   m,n,t,k : longint;
begin 
   if i < j then
   begin
      m := i ; n := j ; k := a[ i + j shr 1 ];
      while m <= n do
      begin
	 while a[ m ] < k do
	    m := m + 1;
	 while a[ n ] > k do
	    n := n - 1;
	 if m <= n then
	 begin
	    t := a[ m ] ;
	    a[ m ] := a[ n ] ;
	    a[ n ] := t ;
	    m := m + 1 ;
	    n := n - 1;
	 end;
      end;
      qsort( i , n );
      qsort( m , j );
   end;
end; { qsort }

begin
   readln(n);
   for i := 1 to n do
      read(a[ i ]);
   readln;
   
   qsort( 1 , n );
   
   for i := 1 to n do
      write(a[ i ],' ');
   writeln;
end.