{state compression test 0} 
program sc0;
const MAXC = 2000000;
var
	f : array [0..MAXC] of longint;
	i,j,finc,n : longint;

begin
  f[ 0 ] := 1;
  readln( n );
  finc := 0;
  for i := 1 to n   do
    finc := finc or (1 shl i);

  for i := 1 to finc do
    for j := 1 to n + 1 do
      if ((i shr ( j - 1 )) and 1) = 1 then 
      f[ i ] := f[ i ] +  f[i xor (1 shl (j - 1))];

  writeln(f[ finc ]);
end.